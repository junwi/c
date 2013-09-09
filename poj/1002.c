#include <stdio.h>

#define LEN 10000000

int table[LEN];
int main()
{
	int n, i, j, k, l;
	char a[300], *s;

	scanf("%d", &n);
	while (n-- > 0) {
		scanf("%s", a);
		for (s = a, i = 0; *s; ++s) {
			if (*s == '-') continue;
			if (*s >= '0' && *s <= '9') i = i*10 + (*s-'0');
			else if (*s >= 'A' && *s < 'Q') i = i*10 + (*s-'A')/3 + 2;
			else if (*s > 'Q' && *s <= 'Y') i = i*10 + (*s-'Q')/3 + 7;
		}
		table[i] += 1;
	}
	j = 0;
	for ( i = 0; i < LEN; ++i) {
		if (table[i] > 1) {
			j = 1;
			k = i;
			l = 1000000;
			while (l > 0) {
				putchar(k/l + '0');
				k %= l;
				l /= 10;
				if (l == 1000) putchar('-');
			}
			printf(" %d\n", table[i]);
		}
	}
	if (!j) printf("%s\n", "No duplicates.");
	return 0;
}
