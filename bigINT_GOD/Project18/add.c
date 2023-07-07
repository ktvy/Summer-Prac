#include "Header.h"

NUMBER add(NUMBER* a, NUMBER* b, int flag, int INEQ) {
	struct bigint result;
	struct bigint null;
	null.size = 1;
	null.sign = "+";
	null.bigNum = (unsigned int*)calloc(null.size, sizeof(unsigned int));
	if (a->sign == b->sign) {
		result.sign = a->sign;
	} 
	else {
		if (flag == 0) {
			char SignResult = ' ';
			if ((INEQ == 1 && a->sign == '-') || INEQ == 2 && b->sign == '-') {
				SignResult = '-';
			}
			else {
				SignResult = '+';
			}
			result = (INEQ == 1) ? sub(a, b, 1, INEQ) : sub(b, a, 1, INEQ);
			result.sign = SignResult;
			return result;
		}
	}
	result.size = (a->size >= b->size) ? a->size + 1 : b->size + 1;
	if (result.size == 0) {
		return null;
	}
	result.bigNum = (unsigned int*)malloc(result.size * sizeof(unsigned int));
	result.bigNum[result.size - 1] = 0;
	int size_a = a->size;
	int size_b = b->size;
	int rest = 0;
	for (int i = 0; i < result.size - 1; i++) {
		if (size_a && size_b) {
			result.bigNum[i] = a->bigNum[i] + b->bigNum[i] + rest;
			rest = (result.bigNum[i] < a->bigNum[i] || result.bigNum[i] < b->bigNum[i] || ((result.bigNum[i] == a->bigNum[i] && b->bigNum[i] != 0) || (result.bigNum[i] == b->bigNum[i] && a->bigNum[i] != 0))) ? 1 : 0;
			size_a--;
			size_b--;
		}
		else if (size_a == 0 && size_b != 0) {
			result.bigNum[i] = b->bigNum[i] + rest;
			rest = (result.bigNum[i] < b->bigNum[i] || result.bigNum[i] < rest) ? 1 : 0;
			size_b--;
		}
		else if (size_b == 0 && size_a != 0) {
			result.bigNum[i] = a->bigNum[i] + rest;
			rest = (result.bigNum[i] < a->bigNum[i] || result.bigNum[i] < rest) ? 1 : 0;
			size_a--;
		}
	}
	if (rest == 0) {
		result.size -= 1;
		result.bigNum = realloc(result.bigNum, (result.size) * sizeof(unsigned int));
	}
	else {
		result.bigNum[result.size - 1] = rest;
	}
	return result;
}