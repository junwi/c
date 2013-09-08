#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

const size_t BUFFLEN = 100000000;

void copy(register char *from, register char *to, register int count)
{
	int n = (count + 7) / 8;
	switch (count % 8) {
		case 0: do { *to++ = *from++;
		case 7: *to++ = *from++;
		case 6: *to++ = *from++;
		case 5: *to++ = *from++;
		case 4: *to++ = *from++;
		case 3: *to++ = *from++;
		case 2: *to++ = *from++;
		case 1: *to++ = *from++;
		} while (--n);
	}
}

void copy1(register char * from, register char *to, register int count)
{
	while(count--) {
		*to++ = *from++;
	}
}

int main()
{
	struct timeval begin, end;
	char *from = (char *) malloc(BUFFLEN * sizeof(char));
	char *to = (char *) malloc(BUFFLEN * sizeof(char));
	memset(from, '1', BUFFLEN * sizeof(char));
	gettimeofday(&begin, NULL);
	copy1(from, to, BUFFLEN);
	gettimeofday(&end, NULL);
	if(!strncmp(from, to, BUFFLEN)) {
		printf("done!");
	}
	printf("duff's device, microseconds: %ld\n", end.tv_sec * 1000000 + end.tv_usec - begin.tv_sec * 1000000 - begin.tv_usec);
	memset(to, '2', BUFFLEN);
	gettimeofday(&begin, NULL);
	copy(from, to, BUFFLEN);
	gettimeofday(&end, NULL);
	if(!strncmp(from, to, BUFFLEN)) {
		printf("done!");
	}
	printf("normal: microseconds: %ld\n", end.tv_sec * 1000000 + end.tv_usec - begin.tv_sec * 1000000 - begin.tv_usec);
	free(from);
	free(to);

	return 0;
}
