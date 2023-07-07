#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define ROW 10
#define COL 10

char sym[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZàáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûüışÿÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß";

char arr[ROW][COL];

void init_arr() {
	int len;

	for (int i = 0; i < ROW; i++) {
		len = rand() % (COL)+1;
		for (int j = 0; j < len; j++)
			arr[i][j] = sym[rand() % 128];
	}
}
void print_arr() {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++)
			printf("%c", arr[i][j]);

		printf("\n");
	}
	printf("--------\n");
}


int my_strcmp(char* s1, char* s2) {
	char* p1 = s1;
	char* p2 = s2;

	while (*p1 != NULL && *p2 != NULL && p1 - s1 < COL && p2 - s2 < COL) {
		if (*p1 > *p2) return 1;
		if (*p1 < *p2) return -1;
		p1++;
		p2++;
	}
	return 0;

}

int my_strncmp(char* s1, char* s2, int n) {
	char* p1 = s1;
	char* p2 = s2;
	for (int i = 0; i < n && i<COL; i++) {
		if (*p1 > *p2) return 1;
		if (*p1 < *p2) return -1;
		p1++;
		p2++;
	}
	return 0;
}
int my_strcmpi(char* s1, char* s2) {
	char* p1 = s1;
	char* p2 = s2;
	int k1, k2;

	while (*p1 != NULL && *p2 != NULL && p1 - s1 < COL && p2 - s2 < COL) {
		k1 = (*p1 >= 'a' && *p1 <= 'z') ? 32 : 0;
		k2 = (*p2 >= 'a' && *p2 <= 'z') ? 32 : 0;

		if ((*p1 - k1) >(*p2 - k2)) return 1;
		if ((*p1 - k1) < (*p2 - k2)) return -1;
		p1++;
		p2++;
	}
	return 0;

}

int my_strncmpi(char* s1, char* s2, int n) {
	char* p1 = s1;
	char* p2 = s2;
	int k1, k2;

	for (int i = 0; i < n && i < COL; i++) {
		k1 = (*p1 >= 'a' && *p1 <= 'z') ? 32 : 0;
		k2 = (*p2 >= 'a' && *p2 <= 'z') ? 32 : 0;

		if ((*p1 - k1) >(*p2 - k2)) return 1;
		if ((*p1 - k1) < (*p2 - k2)) return -1;
		p1++;
		p2++;
	}
	return 0;

}

void my_sort(int first, int last, int f_cmp(char* s1, char* s2))

{

	if (first < last)
	{
		int left = first, right = last;
		int m = first;
		char* middle = arr[m];
		do
		{
			while (f_cmp(arr[left], middle) < 0) left++;
			while (f_cmp(arr[right], middle) > 0) right--;
			if (left <= right)
			{

				if (left< right && f_cmp(arr[left], arr[right]) > 0) {
					char t;
					for (int i = 0; i < COL; i++) {
						t = arr[left][i];
						arr[left][i] = arr[right][i];
						arr[right][i] = t;
					}
				}
				left++;
				right--;
				
			}
		} while (left <= right);
		my_sort(left, last, f_cmp);
		my_sort(first, right, f_cmp);
		      
	}


}




int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	init_arr();
	print_arr();
	printf("----------------------------------------------------\n");
	my_sort(0, ROW - 1, my_strcmp);
	print_arr();
	system("pause");
}