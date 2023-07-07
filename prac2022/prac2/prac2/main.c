#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <sys\stat.h>
#include <string.h>

#define SIZE 128

#pragma warning(disable : 4996)
char buf[SIZE];
int my_strncmp(char* s1, char* s2, int n) {
	int k = 0;
	for (int i = 0; i < n; i++)
		if (*(s1 + i) - *(s2 + i) == 0) k++;
	if (k == n) return 1;
	else return 0;
}

int main(int argc, char** argv)
{
	if (argc != 5) return 1;
	int f_in = open(argv[1], O_RDONLY);
	int f_out = creat(argv[2], S_IWRITE);
	char* p1 = argv[3];
	int len1 = strlen(p1);
	char* p2 = argv[4];
	int len2 = strlen(p2);
	while (!eof(f_in)) {
		for (int j = 0; j < SIZE; j++) buf[j] = 0;
		read(f_in, buf, sizeof(buf));
		for (int i = 0; i < sizeof(buf); i++) {
			if (buf[i] != *p1) {
				if (buf[i] != 0) write(f_out, buf + i, 1);
				continue;
			}
			if (i + len1 <= SIZE) {
				if (my_strncmp(buf + i, p1, len1)) {
					write(f_out, p2, len2);
					i += len1 - 1;
				}
				else {
					write(f_out, buf + i, 1);
					continue;
				}
			}
			else {
				int k = 0;
				int j = 0;
				for (k = 0, j = i; j < SIZE; j++, k++)
					buf[k] = buf[j];
				for (int j = k; j < SIZE; j++) buf[j] = 0;
				read(f_in, buf + k, SIZE - k - 1);
				i = -1;
			}

		}

	}
	close(f_out);

	return 0;
}
