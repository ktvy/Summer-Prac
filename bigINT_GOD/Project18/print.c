#include "Header.h"

void conclusion(char* str, NUMBER* a) {
	printf("%s", str);
	if (a->sign == '-') {
		printf_s("%c", a->sign);
	}
	printf("%0x ", a->bigNum[a->size - 1], a->size);
	if (a->size > 1) {
		int i;
		for (i = a->size - 2; i > 0; i--) {
			printf_s("%0.8x ", a->bigNum[i]);
		}
		printf_s("%0.8x ", a->bigNum[i]);
	}
	printf("\n\n");
}