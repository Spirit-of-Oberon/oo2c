#include <string.h>

void ZeroArray1(float * a, int len) {
	int i=0;
	while (i < len) {
		a[i] = 0.0;
		i += 1;
	}
}

void ZeroArray2(float * a, int len) {
	int i=0;
	while (i < len) {
		a[i] = 0.0;
		a[i+1] = 0.0;
		i += 2;
	}
}

void ZeroArray4(float * a, int len) {
	int i=0;
	while (i < len) {
		a[i] = 0.0;
		a[i+1] = 0.0;
		a[i+2] = 0.0;
		a[i+3] = 0.0;
		i += 4;
	}
}

void ZeroArrayBlock(float * a, int len) {
	memset(a, 0, len * sizeof(float));
}

void CopyArray1(float * a, float * b, int len) {
	int i=0;
	while (i < len) {
		b[i] = a[i];
		i += 1;
	}
}

void CopyArray2(float * a, float * b, int len) {
	int i=0;
	while (i < len) {
		b[i] = a[i];
		b[i+1] = a[i+1];
		i += 2;
	}
}

void CopyArray4(float * a, float * b, int len) {
	int i=0;
	while (i < len) {
		b[i] = a[i];
		b[i+1] = a[i+1];
		b[i+2] = a[i+2];
		b[i+3] = a[i+3];
		i += 4;
	}
}

void CopyArrayBlock(float * a, float * b, int len) {
	memcpy(a, b, len * sizeof(float));
}

void AddArray1(float * a, float * b, int len) {
	int i=0;
	while (i < len) {
		b[i] = b[i] + a[i];
		i += 1;
	}
}

void AddArray2(float * a, float * b, int len) {
	int i=0;
	while (i < len) {
		b[i] = b[i] + a[i];
		b[i+1] = b[i+1] + a[i+1];
		i += 2;
	}
}

void AddArray4(float * a, float * b, int len) {
	int i=0;
	while (i < len) {
		b[i] = b[i] + a[i];
		b[i+1] = b[i+1] + a[i+1];
		b[i+2] = b[i+2] + a[i+2];
		b[i+3] = b[i+3] + a[i+3];
		i += 4;
	}
}

void OOC_ArrayC_open(void) { }

