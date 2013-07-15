#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

long fibonacci1(int);
long fibonacci2(int);
long fibonacci2_(int, long*);
int main(int argc, char** argv)
{
	int n = atoi(argv[1]);	
	struct timeval tv;
	gettimeofday(&tv, NULL);
	long time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	for (int i = 0; i < 1000; ++i) {
		fibonacci1(n);
	}
	gettimeofday(&tv, NULL);
	long time_end = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	printf("time passed:%ld\n", time_end - time);
	time = time_end;
	for (int i = 0; i < 1000; ++i) {
		fibonacci2(n);
	}
	gettimeofday(&tv, NULL);
	time_end = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	printf("time passed:%ld\n", time_end - time);
	return 0;
}
long fibonacci1(int n)
{
	if (n <= 1) return n;
	long a = 0, b = 1, c;
	for (int i = 2; i <= n; ++i) {
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}
long fibonacci2(int n)
{
	long* cache = (long*) malloc((n + 1) * sizeof(long));
	long f = fibonacci2_(n, cache);
	free(cache);
	return f;
}

long fibonacci2_(int n, long* cache)
{
	if (n <= 1) return n;
	if (cache[n]) return cache[n];
	if (n & 1)
	{
		int n_ = (n >> 1) + 1;
		long fn1 = fibonacci2(n_ - 1), fn = fibonacci2(n_);
		long f = fn1 * fn1 + fn * fn;
		cache[n] = f;
		return f;
	} else {
		int n_ = n >> 1;
		long fn1 = fibonacci2(n_ - 1), fn = fibonacci2(n_);
		long f = (2 * fn1 + fn) * fn;
		cache[n] = f;
		return f;
	}
}
