#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

#pragma warning(disable:4996)

char sym[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";


typedef struct _my_lst {
	char str[100];
	struct _my_lst *next;
	struct _my_lst* prev;
} my_list;

my_list* first, *curr, *last;
bool init_flag;

void init_arr(int ROW, int COL) {
	int len;
	first = (my_list*)calloc(1, sizeof(my_list));
	last = (my_list*)calloc(1, sizeof(my_list));
	first->next = last;
	last->prev = first;
	first->prev = last->next = NULL;

	for (int i = 0; i < ROW; i++) {
		len = rand() % COL + 1;
		curr = (my_list*)calloc(1, sizeof(my_list));
		last->prev->next = curr;
		curr->prev = last->prev;
		curr->next = last;
		last->prev = curr;
		for (int j = 0; j < len; j++) {
			curr->str[j] = sym[rand() % 62];
		}

	}
	init_flag = true;
}
void print_arr() {

	curr = first->next;
	while (curr != last) {
		printf("%s\n", curr->str);
		curr = curr->next;
	}
	printf("\n");
}

int my_strcmp(char* s1, char* s2) {
	char* p1, *p2;
	p1 = s1;
	p2 = s2;
	while (*p1 != NULL && *p2 != NULL) {
		if (*p1 > *p2) return 1;
		if (*p1 < *p2) return -1;
		p1++;
		p2++;
	}
	if (*p1 == *p2) return 0;

}

my_list* maximum(my_list* l1, my_list* l2) {
	if (my_strcmp(l1->str, l2->str) >= 0) return l1;
	else return l2;
}

void my_sort(my_list* pbeg, my_list* pend)
{
	if ((pbeg) == (pend))
		return;
	my_list* pstart = pbeg->prev;
	my_list* pfinish = pend->next;
	my_list* sup = (pbeg);
	my_list* current = (pbeg)->next;
	my_list* help = current;
	my_list* end = pend->next;

	while (current != end)
	{
		help = current;
		current = current->next;
		if (maximum(sup, help) == sup) {
			help->prev->next = help->next;
			help->next->prev = help->prev;

			
			help->prev = sup->prev;
			sup->prev->next = help;
			help->next = sup;
			sup->prev = help;

		}
	}

	if ((pstart->next) != sup)
		my_sort(pstart->next, (sup->prev));


	if ((pfinish->prev) != sup)
		my_sort((sup->next), pfinish->prev);

}
void free_mem(void) {
	init_flag = false;
	curr = first->next;
	while (curr != last) {
		curr = curr->next;
		free(curr->prev);
	}
	free(last);
	free(first);

};

void menu(void) {
	int ans;
	int flag;
	do {
		flag = 0;
		printf("Выберите функцию: \n");
		printf("1 - Инициализация списка случайными значениями\n");
		printf("2 - Удаление всех элементов списка с освобождением памяти\n");
		printf("3 - Вывод всех элементов списка\n");
		printf("4 - Сортировка списка по неубыванию\n");
		printf("0 - Выход\n");
		printf("--> ");
		scanf("%d", &ans);
		system("cls");

		switch (ans) {
		case 0: if (init_flag) free_mem(); exit(0);
		case 1: if (!init_flag) {
			int row, col;
			printf("Введите количество строк: ");
			scanf("%d", &row);
			printf("Введите максимальную длину строки (не более 80): ");
			scanf("%d", &col);
			col = col < 81 ? col : 80;
			init_arr(row, col);
		}
				break;
		case 2: if (init_flag) free_mem(); break;
		case 3: if (init_flag) print_arr(); break;
		case 4: if (init_flag) my_sort(first->next, last->prev); break;

		default:
			printf("Неправильный выбор\n");
			flag = 1;
			break;
		}
	} while (1);

};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	menu();
}
