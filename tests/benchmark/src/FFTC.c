#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Complex {
	float re, im;
} complex;

#define usecomplexlib 0

static unsigned int order=0, cosinc;
float * sintbl = NULL;

void
BitRev(complex *  a, unsigned int size)
{
	unsigned int i, irev, carry, s2;
	complex temp;

	s2 = size / 2;
	irev = 0;
	for (i=0; i<size; i++) {
		if (i<irev) {	/* swap contents r[i] <--> r[irev] */
			temp = a[i]; a[i] = a[irev]; a[irev] = temp;
		};
		carry = s2;
		while (carry && carry<=irev) { /* propagate carry */
			irev -= carry; carry /= 2;
		};
		irev += carry;
	}
}

void
GenTable(unsigned int n)
{
	float mult; unsigned int i;
	unsigned int tsize;

	tsize=n/4*3+1;
	if (sintbl) {free(sintbl); sintbl=NULL;}
	if (!sintbl) sintbl=(float *) malloc(sizeof(float)*tsize);
	if (!sintbl) {
		printf("No memory for sin table\n");
		exit(1);
	}
	mult = 2*M_PI/n;
	for (i=0; i<tsize; i++) sintbl[i] = sin(mult*i);
	cosinc = n/4;
	order = n;
}

/*************************************************************************
** FFT(a, size, dir) - compute Fast Fourier Transform					**
**   a		array [0..size-1] of complex input data						**
**   dir	transform direction (-1 = forward, 1 = inverse)				**
** Performs in-place complex FFT. Input data in array <a> are			**
** overwritten with transformed result. Both input and output are in	**
** normal order.														**
*************************************************************************/

void
FFT(complex * a, unsigned int n, unsigned char fwd)
{
	unsigned int idx, idxstep, i, i2, j, k, m;
	complex b, w, ai, ai2;

	if (order!=2*n) GenTable(2*n);

	BitRev(a, n);

	k=1; idxstep = 2*n;
	while (k<n) {
		m = k;
		k *= 2; idxstep /= 2;
		j = 0; idx = 0;
		while (j<m) {
			/* cset(w, sintbl[idx+cosinc], sintbl[idx]*fwd?-1:1); */
			w.re=sintbl[idx+cosinc];
			w.im=-sintbl[idx]; if (!fwd) w.im=-w.im;
			i = j;
			while (i<n) {
				i2 = i+m;
#if	usecomplexlib
				cmul(&w, &a[i2], &b);
				csub(&a[i], &b, &a[i2]);
				cadd(&a[i], &b, &a[ i]);
#else
				ai2=a[i2]; ai=a[i];
				b.re=w.re*ai2.re-w.im*ai2.im;
				b.im=w.re*ai2.im+w.im*ai2.re;
				a[i2].re=ai.re-b.re; a[i2].im=ai.im-b.im;
				a[i].re=ai.re+b.re;  a[i].im=ai.im+b.im;
#endif
				i = i + k;
			}; /* for i*/
			j = j + 1;
			idx = idx + idxstep;
		}; /* for j */
	}; /* for k */

	if (!fwd)
		for (i=0; i<n; i++) {
			a[i].re /= n; a[i].im /= n;
		}
}

complex b, w;

void Butterfly(complex * ai, complex * ai2) {
	b.re=w.re*ai2->re-w.im*ai2->im;
	b.im=w.re*ai2->im+w.im*ai2->re;
	ai2->re=ai->re-b.re; ai2->im=ai->im-b.im;
	ai->re=ai->re+b.re;  ai->im=ai->im+b.im;
}

void
FFT2(complex * a, unsigned int n, unsigned char fwd)
{
	unsigned int idx, idxstep, i, i2, j, k, m;

	if (order!=2*n) GenTable(2*n);

	BitRev(a, n);

	k=1; idxstep = 2*n;
	while (k<n) {
		m = k;
		k *= 2; idxstep /= 2;
		j = 0; idx = 0;
		while (j<m) {
			/* cset(w, sintbl[idx+cosinc], sintbl[idx]*fwd?-1:1); */
			w.re=sintbl[idx+cosinc];
			w.im=-sintbl[idx]; if (!fwd) w.im=-w.im;
			i = j;
			while (i<n) {
				i2 = i+m;
				Butterfly(&a[i], &a[i2]);
				i = i + k;
			}; /* for i*/
			j = j + 1;
			idx = idx + idxstep;
		}; /* for j */
	}; /* for k */

	if (!fwd)
		for (i=0; i<n; i++) {
			a[i].re /= n; a[i].im /= n;
		}
}


/*************************************************************************
** IFFT(a, size) - compute Inverse FFT using forward FFT				**
**   a		array [0..size-1] of complex input data						**
*************************************************************************/

void
IFFT(complex * a, unsigned int size)
{
	unsigned int i;

	for (i=0; i<size; i++) a[i].im = -a[i].im;
	FFT(a, size, 1);
	for (i=0; i<size; i++) {
		a[i].im = -a[i].im/size;
		a[i].re = a[i].re/size;
	}
}

/*************************************************************************
** RFFT(r, c, size) - Efficient FFT for real-valued data				**
**   r		array [0..size-1] of real input data						**
**   c		array [0..size/2-1] of complex output data					**
** Array <c> receives the <size>/2 complex point transform of real data	**
** in <r> computed via length <size>/2 FFT.								**
*************************************************************************/

void
RFFT(float * r, unsigned int size, int fwd)
{
	unsigned int s2, i;
	complex t, tn, x, y, w, *c;

	c = (complex *) r;

	s2 = size / 2;
	if (fwd) {
		FFT(c, s2, 1);
		c[s2] = c[0];
	} else {
		if (order!=size) GenTable(size);
		for (i=0; i<s2; i++)
			c[i].im=-c[i].im;
	}

	for (i=0; i<=s2/2; i++) {
#if	usecomplexlib
		crdiv(&c[i], 2, &t); crdiv(&c[s2-i], 2, &tn);
		tn.im = -tn.im;
		cadd(&tn, &t, &x); csub(&tn, &t, &y);
		cset(&w, sintbl[i], sintbl[i+cosinc]);
/*    arg = pi*i/s2; cset(w, sin(arg), cos(arg)); */
		cmul(&w, &y, &w);
		cadd(&x, &w, &c[i]); csub(&x, &w, &w); w.im = -w.im;
		c[s2-i] = w;
#else
		complex sum, dif, w, prod;
		int i2;
		i2=s2-i;

		sum.re=(c[i].re+c[i2].re)/2; sum.im=(c[i].im-c[i2].im)/2;
		dif.re=(c[i2].re-c[i].re)/2; dif.im=(-c[i2].im-c[i].im)/2;
		w.re=sintbl[i]; w.im=sintbl[i+cosinc];
		prod.re=w.re*dif.re-w.im*dif.im;
		prod.im=w.re*dif.im+w.im*dif.re;
		c[i].re=sum.re+prod.re; c[i].im=sum.im+prod.im;
		c[i2].re=sum.re-prod.re; c[i2].im=prod.im-sum.im;
#endif
	};
	if (!fwd) {
		FFT(c, s2, 1);
		for (i=0; i<s2; i++) {
			c[i].im = -c[i].im/s2;
			c[i].re = c[i].re/s2;
		}
	}
}

void OOC_FFTC_open() {
}

