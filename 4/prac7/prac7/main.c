#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree_mass.h"

void part2()
{
	Tree* tree = NULL;
	unsigned int start_time = clock();
	for (int i = 0; i < 10000; i++) {
		char* key = (char*)malloc(sizeof(char) * 10);
		char* value = (char*)malloc(sizeof(char) * 10);
		key[9] = '\0';
		value[9] = '\0';
		for (int j = 0; j < 9; j++) {
			key[j] = ALPHABET[rand() % 62];
			value[j] = ALPHABET[rand() % 62];
		}
		InsertTree(&tree, key, value);
	}
	/*outputTree(tree);*/
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	printf("%lf\n", (double)search_time / 1000);


	start_time = clock();
	char* find = NULL;
	find = SearchValueByKey(&tree, tree->right->key);
	printf("%s\n\n", find);
	end_time = clock();
	search_time = end_time - start_time;
	printf("%u\n", search_time);


	start_time = clock();
	tree = DeleteTreeValueByKey(tree, tree->right->key);
	end_time = clock();
	search_time = end_time - start_time;
	printf("%u\n", search_time);
}

void part1()
{
	srand((unsigned int)time(0));
	Mass** m = NULL;
	size_t size = 10000;

	m = InitMass(m, size);
	unsigned int start_time = clock();
	for (int i = 0; i < size; i++) {
		char* key = (char*)malloc(sizeof(char) * 10);
		char* value = (char*)malloc(sizeof(char) * 10);
		key[9] = '\0';
		value[9] = '\0';
		for (int j = 0; j < 9; j++) {
			key[j] = ALPHABET[rand() % 62];
			value[j] = ALPHABET[rand() % 62];
		}
		m = ApendMass(m, key, value, size);
	}
	outputMass(m);
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	printf("%lf\n", (double)search_time / 1000);


	start_time = clock();
	char* find = NULL;
	find = GetValueFromMass(m, m[5]->key);
	printf("%s\n\n", find);
	end_time = clock();
	search_time = end_time - start_time;
	printf("%u\n", search_time);

	start_time = clock();
	m = DeleteMassElement(m, m[980]->key);
	end_time = clock();
	search_time = end_time - start_time;
	printf("%u\n", search_time);





	FreeMass(m);
}

int main()
{
	part1();
	part2();
	system("pause");
	return 0;
}