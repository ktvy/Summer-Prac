#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#include "tree_mass.h"

static size_t pos = 0;

void FreeMass(Mass** buffer)
{
	free(buffer);
	pos = 0;
}

Mass** InitMass(Mass** buffer, size_t elements)
{
	if (buffer != NULL)
	{
		printf("Array initialized!\n");
		exit(1);
	}
	buffer = (Mass**)malloc(sizeof(Mass*) * (elements));
	for (size_t i = 0; i < elements; ++i)
	{
		buffer[i] = (Mass*)malloc(sizeof(Mass));
		buffer[i]->key = "\0";
		buffer[i]->value = "\0";
	}
	if (*buffer == NULL)
	{
		printf("Couldn`t init associative array first\n");
		exit(1);
	}
	return buffer;
}

Mass** ApendMass(Mass** buffer, KeyType key, ValueType value, size_t kolvo)
{
	if (buffer == NULL)
	{
		printf("Array not initialized!\n");
		exit(1);
	}
	if (pos >= kolvo)
	{
		printf("The size of the array cannot exceeded!!!\n");
		return buffer;
	}
	for (size_t i = 0; i < pos; ++i)
		if (strcmp(key, buffer[i]->key) == 0)
			return buffer;
	buffer[pos]->key = key;
	buffer[pos]->value = value;
	++pos;
	return buffer;
}

Mass** DeleteMassElement(Mass** buffer, KeyType key)
{
	if (buffer == NULL)
	{
		printf("It`s not associative mass\n");
		exit(1);
	}
	size_t i = 0;
	while (strcmp(key, buffer[i]->key) != 0)
	{
		if (i == pos)
		{
			printf("Not Found!!!\n");
			return buffer;
		}
		++i;
	}
	buffer[i]->key = NULL;
	buffer[i++]->value = NULL;
	bool delete = false;
	if (i >= pos)
	{
		--pos;
		return buffer;
	}
	while (strcmp(buffer[i]->key, "\0") != 0)
	{
		delete = true;
		size_t j = i - 1;
		buffer[j]->key = buffer[i]->key;
		buffer[j]->value = buffer[i]->value;
		++i;
		if (i >= pos)
			break;
	}
	--pos;
	return buffer;
}

ValueType GetValueFromMass(Mass** buffer, KeyType key)
{
	int i = 0;
	while (strcmp(buffer[i]->key, key) != 0)
	{
		if (i == pos)
			return "Not found!!!\n";
		++i;
	}
	return buffer[i]->value;
}

void outputMass(Mass** m)
{
	for (size_t i = 0; i < pos; ++i)
	{
		if (m[i]->key != NULL && m[i]->value != NULL)
			printf("%s ", m[i]->key);
		printf("%s\n", m[i]->value);
	}
}