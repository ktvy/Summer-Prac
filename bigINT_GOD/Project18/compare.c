#include "Header.h"

int compare(NUMBER* A, NUMBER* B) {
	if (A->size > B->size) {
		return 1;
	}
	if (A->size < B->size) {
		return 2;
	}
	if (A->size == B->size) {
		for (int i = A->size - 1; i >= 0; i--) {
			if (A->bigNum[i] > B->bigNum[i]) {
				return 1;
			}
			if (A->bigNum[i] < B->bigNum[i]) {
				return 2;
			}
		}
	}
	return 0;
}
