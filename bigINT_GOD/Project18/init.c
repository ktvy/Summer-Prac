#include "Header.h"

int check(char* str) {

	int sign = 0;
	if (str[0] == '-' || str[0] == '+') {
		sign = 1;
	}
	for (int i = sign; str[i] != '\0'; i++) {
		if ((str[i] >= 48 && str[i] <= 57) || (str[i] >= 65 && str[i] <= 70) || (str[i] >= 97 && str[i] <= 102)) {
			continue;
		}
		else {
			printf("Invalid input\n");
			return 1;
		}
	}
	return 0;
}

void initialization(char number[], NUMBER* mass) {
	int s = 0; 
	if (number[0] == '+' || number[0] == '-') {
		mass->sign = number[0];
		s++;
	}
	else {
		mass->sign = '+';
	}
	for (s; number[s] == '0' && s < (strlen(number) - 1); s++);
	size_t strSize = strlen(number) - s;
	int whole = strSize / 8;  int rest = strSize % 8;
	mass->size = (rest) ? whole + 1 : whole;
	mass->bigNum = (unsigned int*)malloc((mass->size) * sizeof(unsigned int));
	int it = 0;
	char word[9];
	for (int i = 0; i < whole; i++) {
		memcpy(word, number + strlen(number) - ((i + 1) * 8), 8);
		word[8] = '\0';
		mass->bigNum[it++] = strtoul(word, NULL, 16);
	}
	memcpy(word, number + (strlen(number) - (whole * 8) - rest), rest);
	word[rest] = '\0';
	mass->bigNum[it] = strtoul(word, NULL, 16);
}
