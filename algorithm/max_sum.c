#include <stdio.h>

int maxSum(int array[], int n)
{
	int v, max;
	v = max = array[0];
	for (int i = 0; i < n; ++i) {
		if (v > 0) {
			v += array[i];
		} else if (array[i] > v) {
			v = array[i];
		}
		if (max < v) max = v;
	}
	return max;
}

int main()
{
	int array[] = {1, -3, 4, -3, 1, 2, 3};
	printf("%d\n", maxSum(array, 7));
	return 0;
}
