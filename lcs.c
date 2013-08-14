#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lcs(char*, char*);
void printLCS(int*, char*, int, int, int);
void lcs(char *a, char *b)
{
	int m = strlen(a);
	int n = strlen(b);
	int x[m+1][n+1];
	int *y = (int *) malloc(m*n*sizeof(int));
	for (int i = 0; i <= m; ++i) {
		x[i][0] = 0;
	}
	for (int j = 0; j <= n; ++j) {
		x[0][j] = 0;
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (a[i-1] == b[j-1]) {
				x[i][j] = x[i-1][j-1] + 1;
				y[i-1+(j-1)*m] = 0;
			} else {
				if (x[i-1][j] > x[i][j-1]) {
					x[i][j] = x[i-1][j];
					y[i-1+(j-1)*m] = 1;
				} else {
					x[i][j] = x[i][j-1];
					y[i-1+(j-1)*m] = -1;
				}
			}
			
		}
	}
	printLCS(y, a, m-1, n-1, m);
	printf("\n");

}
void printLCS(int *y, char *a, int i, int j, int m)
{
	if (i < 0 || j < 0) return;
	if (y[i+j*m] == 0) {
		printLCS(y, a, i - 1, j - 1, m);
		printf("%c", a[i]);
	} else if (y[i+j*m] == 1) {
		printLCS(y, a, i - 1, j, m);
	} else {
		printLCS(y, a, i, j - 1, m);
	}
}
int main()
{
	char *a = "ddd1a2a3a4a5a";
	char *b = "1b2b3b4b5b";
	lcs(a, b);
	return 0;
}
