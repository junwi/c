#include <stdio.h>
int binary_search(int v, int *array, int n)
{
	int l = 0, h = n;
	while (h > l)
	{
		int m = (l + h) / 2;
		int t = array[m];
		if (t == v) return m;
		if (t < v)
		{
			l = m + 1;
			continue;
		}
		if (t > v)
		{
			h = m;
			continue;
		}
	}
	return -1;
}
int main()
{
	int array[] = {1,2,3,4};
	int m = binary_search(4, array, 4);
	printf("%d\n", m);
}
