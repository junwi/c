#include <stdio.h>
#include <stdlib.h>
void lis(int *arr, int n)
{
	int *result = (int *) malloc(sizeof(int) * n);
	result[0] = 1;
	printf("%d\n", result[0]);
	for (int i = 1; i < n; ++i)
	{
		result[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (arr[i] > arr[j] && result[i] < result[j] + 1)
			{
				result[i] = result[j] + 1;
			}
		}
		printf("%d\n", result[i]);
	}
}
int main()
{
	int arr[] = {2, 3, 1, 5, 4, 8, 7, 6, 9};
	lis(arr, 9);
	return 0;
}
