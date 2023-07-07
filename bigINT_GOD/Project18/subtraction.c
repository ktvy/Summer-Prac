#include "Header.h"

NUMBER sub(NUMBER* A, NUMBER* B, int flag, int INEQ) {
	NUMBER result;
	if (A->sign != B->sign) {
		if (flag == 0) {
			char SignResult = ' ';
			if ((INEQ == 1 && A->sign == '-') || (INEQ == 2 && A->sign == '-')) {
				SignResult = '-';
			}
			else {
				SignResult = '+';
			}
			result = add(A, B, 1, INEQ);
			result.sign = SignResult;
			return result;
		}
	}
	else {
		if ((INEQ == 1 && A->sign == '+') || (INEQ == 2 && A->sign == '-') || (INEQ == 0)) {
			if (INEQ == 0) {
				result.size = 1;
				result.sign = '+';
				result.bigNum = (unsigned int*)calloc(result.size, sizeof(unsigned int));
				return result;
			}
			result.sign = '+';
		}
		else {
			result.sign = '-';
		}
		if (INEQ == 2) {
			NUMBER* tmp = A;
			A = B;
			B = tmp;
		}
	}
	result.size = A->size;
	result.bigNum = (unsigned int*)malloc(result.size * sizeof(unsigned int));
	int size_b = B->size;
	unsigned int* copy = (unsigned int*)malloc(A->size * sizeof(unsigned int));
	memcpy(copy, A->bigNum, A->size * sizeof(unsigned int));
	for (int i = 0; i < result.size; i++) {
		if (size_b) {
			int hopalong = i;
			if ((copy[i] - B->bigNum[i]) > copy[i]) {
				while (hopalong == i || copy[hopalong] == 0) {
					hopalong++;
				}
				copy[hopalong]--;
				hopalong--;
				while (hopalong != i) {
					copy[hopalong--] = UINT_MAX;
				}
			}
			result.bigNum[i] = copy[i] - B->bigNum[i];
			size_b--;
		}
		else {
			result.bigNum[i] = copy[i];
		}
	}
	return result;
}