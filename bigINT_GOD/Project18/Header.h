#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>


typedef struct bigint {
	unsigned int* bigNum;
	int size;
	char sign;
}NUMBER;

NUMBER sub(NUMBER* A, NUMBER* B, int flag, int INEQ);
int compare(NUMBER* A, NUMBER* B);
NUMBER add(NUMBER* a, NUMBER* b, int flag, int INEQ);
void conclusion(char* str, NUMBER* a);
void initialization(char number[], NUMBER* mass);
int check(char* str);