#include "Header.h"

int main(int argc, char *argv[]) {
	int ERROR_CHECK_A, ERROR_CHECK_B, INEQ;
	NUMBER A, B, WORK;
	if (argc == 3) {
		ERROR_CHECK_A = check(argv[1]);
		ERROR_CHECK_B = check(argv[2]);
		if (ERROR_CHECK_A != 1 && ERROR_CHECK_B != 1) {
			initialization(argv[1], &A);
			initialization(argv[2], &B);
			INEQ = compare(&A, &B);
			conclusion("Number 1: ", &A);
			conclusion("Number 2: ", &B);
			WORK = sub(&A, &B, 0, INEQ);
			conclusion("Subtraction: ", &WORK);
			WORK = add(&A, &B, 0, INEQ);
			conclusion("Addition: ", &WORK);
		}
		else {
			printf("Incorrect parameters passed!\n");
			return 1;
		}
		return 0;
	}
	else {
		printf("Argument was not passed\n");
		return 1;
	}
}