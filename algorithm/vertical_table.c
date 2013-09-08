#include <stdio.h>

void vertical_table(int *array, int n)
{
	if (n <= 0) return;
	int max = *array;
	for (int i = 1; i < n; ++i) {
		if (max < array[i]) max = *(array + i);
	}
	printf("%d\n", max);
	for (int i = max; i > 0; --i) {
		for (int j = 0; j < n; ++j) {
			if (array[j] < i) printf(" ");
			else printf("*");
		}
		printf("\n");
	}
}
int main() {
	int array[] = {0,1,0,3,4,5,0,9};
	vertical_table(array, 8);
	return 0;
}
