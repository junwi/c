#include <stdio.h>
#include <string.h>

int kmp(char *str, char *p)
{
	int pn = strlen(p);
	int fail[pn];
	fail[0] = -1;
	for (int i = 0; i < pn - 1; ++i) {
		int k = fail[i];
		while (k > -1 && p[k+1] != p[i+1]) k = fail[k];
		if (p[k+1] == p[i+1]) fail[i+1] = k+1;
		else fail[i+1] = -1;
	}
	for (int i = 0, j = -1, k = 0; str[i]; ++i) {
		while (j > -1 && p[j+1] != str[i]) j = fail[j];
		if (p[j+1] == str[i]) {
			++j;
			if (!p[j+1]) return i - pn + 1;
		}
	}
	return -1;
}
int main()
{
	char *a = "acabaabaabcacaabc";
	char *b = "abaabcac";
	printf("%d\n", kmp(a, b));
	return 0;
}
