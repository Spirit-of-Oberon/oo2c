
void QuickSort(int a[], int m, int n) {
	int i, j, v, x;

	if (n > m) {
		i = m-1; j = n; v = a[n];
		while (1) {
			do {
				++i;
			} while (a[i] < v);
			do {
				--j;
			} while (a[j] > v);
			if (i >= j)
				break;
        	x = a[i]; a[i] = a[j]; a[j] = x;
		}
      	x = a[i]; a[i] = a[n]; a[n] = x;
		QuickSort (a, m, j);
		QuickSort (a, i+1, n);
	}
}

void BubbleSort(int a[], int size) {
	int i, j, temp;

	for (i=size-2; i>=0; --i)
		for (j=0; j<=i; j++)
			if (a[j] < a[j+1]) {
				temp = a[j]; a[j] = a[j+1]; a[j+1] = temp;
			}
}

void OOC_SortC_init0(void) { }

