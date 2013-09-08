#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void qSort(void *base, size_t num, size_t width, int (*cmp) (void *, void *));
static void swap(void *a, void *b, size_t width);
static void sort1(char *lo, char *hi, size_t width, int (*cmp) (void *, void *));

void qSort(void *base, size_t num, size_t width, int (*cmp) (void *, void *))
{
	if (num < 2) return;
	char *lo = base;
	char *hi = lo + (num - 1) * width;
	sort1(lo, hi, width, cmp);
}
void sort1(char *lo, char *hi, size_t width, int (*cmp) (void *, void *))
{
	if (lo >= hi) return;
	char *tlo = lo;
	char *thi = hi;
	char *mid = lo + (hi - lo) / width / 2 * width;
	swap(tlo, mid, width);
	lo += width;
	while (lo <= hi) {
		while (lo <= hi && cmp(lo, tlo) <= 0) {
			lo += width;
		}
		while (cmp(hi, tlo) > 0) hi -= width;
		if (lo < hi) {
			swap(lo, hi, width);
		}
	}
	swap(tlo, hi, width);
	hi -= width;
	sort1(tlo, hi, width, cmp);
	sort1(lo, thi, width, cmp);
}
void swap(void *a, void *b, size_t width)
{
	char *ba = (char *) a;
	char *bb = (char *) b;
	while (width-- > 0) {
		char temp = *ba;
		*ba++ = *bb;
		*bb++ = temp;
	}
}
int cmp(int *a, int *b)
{
	return *a - *b;
}
void printIntArray(int *a, int n)
{
	for (int i = 0; i < n; ++i) {
		printf("%d, ", a[i]);
	}
	putchar('\n');
}
void qSort2(int array[], int n)
{
	if (n < 2) return;
	int lo = 0, hi = n - 1;
	int mid = lo + (hi - lo) / 2;
	int m = array[mid];
	array[mid] = array[0];
	array[0] = m;
	while (lo <= hi) {
		while (lo <= hi && array[lo] <= m) ++lo;
		while (array[hi] > m) --hi;
		if (lo < hi) {
			int t = array[lo];
			array[lo] = array[hi];
			array[hi] = t;
		}
	}
	array[0] = array[hi];
	array[hi] = m;
	--hi;
	qSort2(array, hi + 1);
	qSort2(array + lo, n - lo);
}
void qSort3(int array[], int n)
{
	if (n < 2) return;
	int i = 1, j = 1;
	for (; i < n; ++i) {
		if (array[i] <= array[0]) {
			int t = array[j];
			array[j] = array[i];
			array[i] = t;
			++j;
		}
	}
	--j;
	int t = array[j];
	array[j] = array[0];
	array[0] = t;
	qSort3(array, j);
	qSort3(array + j + 1, n - j - 1);
}
void bubbleSort1(int array[], int n)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j < n; ++j) {
			if (array[j] < array[j - 1]) {
				int t = array[j];
				array[j] = array[j - 1];
				array[j - 1] = t;
			}
		}
	}
}
void bubbleSort2(int array[], int n)
{
	for (int i = n - 1; i > 0; --i) {
		for (int j = 1; j <= i; ++j) {
			if (array[j] < array[j - 1]) {
				int t = array[j];
				array[j] = array[j - 1];
				array[j - 1] = t;
			}
		}
	}
}
void bubbleSort3(int array[], int n)
{
	for (int i = n - 1; i > 0; --i) {
		int flag = 0;
		for (int j = 1; j <= i; ++j) {
			if (array[j] < array[j - 1]) {
				int t = array[j];
				array[j] = array[j - 1];
				array[j - 1] = t;
				flag = 1;
			}
		}
		if (!flag) {
			printf("stop when i=%d.\n", i);
			break;
		}
	}
}
void selectionSort(int array[], int n)
{
	for (int i = n - 1; i > 0; --i) {
		int m = 0;
		for (int j = 1; j <= i; ++j) {
			if (array[j] > array[m]) m = j;
		}
		int t = array[m];
		array[m] = array[i];
		array[i] = t;
	}
}
void heapSort(int array[], int n)
{
	int heap[n];
	int index = 0;
	for (int i = 0; i < n; ++i) {
		heap[index] = array[i];
		int t = index++;
		while ( t > 0) {
			int f = (t+1)/2-1;
			if (heap[t] >= heap[f]) break;
			int temp = heap[t];
			heap[t] = heap[f];
			heap[f] = temp;
			t = f;
		}
	}
	for (int i = 0; i < n; ++i) {
		array[i] = heap[0];
		heap[0] = heap[--index];
		int t = 0;
		while (t < index) {
			int left = (t+1)*2-1;
			if (left >= index) break;
			int right = (t+1)*2;
			int child;
			if (right >= index) child = left;
			else child = (heap[left] < heap[right] ? left : right);
			if (heap[t] <= heap[child]) break;
			int v = heap[t];
			heap[t] = heap[child];
			heap[child] = v;
			t = child;
		}
	}
}
int main()
{
	void (*sort) (int *, int) = heapSort;
	int a[20];
	int n = sizeof(a) / sizeof(int);
	int b[n];
	srand(time(NULL));
	int c[] = {};
	for (int i = 0; i < n; ++i) {
		a[i] = (int) rand() % 100;
//		a[i] = c[i];
		b[i] = a[i];
	}
	sort(a, n);
	printIntArray(b, n);
	printIntArray(a, n);
	int t = a[0];
	for (int i = 0; i < n; ++i) {
		if (a[i] < t) {
			printf("error\n");
			return 1;
		}
		t = a[i];
	}
	printf("success\n");
	return 0;
}
