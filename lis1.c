#include <stdio.h>
#include <stdlib.h>
void lis(int *array, int n) {
	int *queue = (int *) malloc(n * sizeof(int));
	int len = 0;
	for (int i = 0; i < n; ++i) {
		int v = array[i];
		if (len == 0 || array[i] > queue[len - 1]) {
			queue[len] = v;
			++len;
		} else if (array[i] < queue[0]) {
			queue[0] = v;
		} else {
			int l = 0, u = len;
			while (u > l) {
				int m = (l + u) / 2;
				int mv = queue[m]; 
				if ( v == mv) break;
				if (v > mv) {
					l = m + 1;
					continue;
				}
				if (queue[m - 1] < v) {
					queue[m] = v;
					break;
				} else {
					u = m -1;
				}
			}
		}
	}
	for (int i = 0; i < len; ++i) {
		printf("%d ", queue[i]);
	}
	printf("\n%d\n", len);
	free(queue);
}
int main()
{
	int arr[] = {2, 3, 1, 5, 4, 8, 7, 6, 9};
	lis(arr, 9);
	int arr1[] = {1,2,3,4,5,6,7,8,9};
	lis(arr1,9);
	int arr2[] = {9,8,7,6,5,4,3,2,1};
	lis(arr2, 9);
	return 0;
}
