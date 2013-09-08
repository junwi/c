#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printNumber(int a[], int lena, int dot, int n);
int multiply(int a[], int lena, int b[], int lenb, int result[])
{
	int i, j;
	for (i = 1; i <= lena; ++i) {
		for (j = 1; j <= lenb; ++j) {
			result[i+j-1] += a[i]*b[j];
			if (result[i+j-1] > 9) {
				result[i+j] += result[i+j-1] / 10;
				result[i+j-1] = result[i+j-1] % 10;
			}
		}
	}
	if (result[lena+lenb] > 0) return lena+lenb;
	return lena+lenb-1;
}

void printNumber(int a[], int lena, int dot, int n) {
	int i, end;
	while (lena > 0 && a[lena] == 0) --lena;
	if (lena == 0) {
		putchar('0');
		putchar('\n');
		return;
	}
	if (dot == -1) {
		while (lena > 0) putchar('0'+a[lena--]);
		putchar('\n');
		return;
	}
	dot *= n;
	end = 1;
	while (end < lena && a[end] == 0) ++end;
	if (dot > lena) {
		putchar('.');
		for (i = dot; i > lena; --i) {
			putchar('0');
		}
	}
	for (i = lena; i >= end; --i) {
		if (i == dot) putchar('.');
		putchar('0'+a[i]);
	}
	while (i-- > dot) {
		putchar('0');
	}
	putchar('\n');
}

int main()
{
	int a[9999], b[9999], result[9999];
	char s[7];
	int n, lena, lenb;
	while ((scanf("%s %d", s, &n)) != EOF) {
		int dot = -1;
		int len = strlen(s);
		int i = 0, j = len;
		while (j-- > 0) {
			if (s[j] != '.') {
				++i;
				a[i] = b[i] = s[j] - '0';
			} else dot = i;
		}
		j = n;
		lena = lenb = i;
		while (--j > 0) {
			memset(result, 0, (lena+lenb+1) * sizeof(result[0]));
			lena = multiply(a, lena, b, lenb, result);
			memcpy(a, result, (lena+1) * sizeof(a[0]));
		}
		printNumber(a, lena, dot, n);
	}

	return 0;
}
