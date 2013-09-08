#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char s[10];
	int n, dot, i, j, k, l, lena, lenb, a[9999], b[9999], c[9999];
	
	while ((scanf("%s %d", s, &n)) != EOF) {
		dot = -1;
		j = strlen(s);
		i = 0;
		while (j-- > 0) {
			if (s[j] != '.') {
				++i;
				a[i] = b[i] = s[j] - '0';
			} else {
				dot = i;
			}
		}
		j = n;
		lena = lenb = i;
		while (--j > 0) {
			memset(c, 0, (lena+lenb+1) * sizeof(c[0]));
			for (k = 1; k <= lena; ++k) {
				for (l = 1; l <= lenb; ++l) {
					c[k+l-1] += a[k]*b[l];
					if (c[k+l-1] > 9) {
						c[k+l] += c[k+l-1] / 10;
						c[k+l-1] = c[k+l-1] % 10;
					}
				}
			}
			lena = lena+lenb;
			memcpy(a, c, (lena+1) * sizeof(c[0]));
		}
		i = lena;
		while (i > 0 && a[i] == 0) --i;
		if (i == 0) {
			putchar('0');
			putchar('\n');
			continue;
		}
		dot *= n;
		j = 1;
		while (a[j] == 0) ++j;
		if (dot > i) {
			putchar('.');
			k = dot;
			while (k-- > i) {
				putchar('0');
			}
		}
		for (; i >= j; --i) {
			if (i == dot) putchar('.');
			putchar('0'+a[i]);
		}
		for (;i > dot && i > 0; --i) putchar('0');
		putchar('\n');
	}
	return 0;
}
