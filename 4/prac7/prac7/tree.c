#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree_mass.h"


void InsertTree(Tree** tree, KeyType key, ValueType value)
{
	if (*tree == NULL)
	{
		*tree = (Tree*)malloc(sizeof(Tree));
		(*tree)->key = key;
		(*tree)->value = value;
		(*tree)->left = NULL;
		(*tree)->right = NULL;
	}
	else
	{
		if (strcmp(key, (*tree)->key) < 0)
		{
			InsertTree(&((*tree)->left), key, value);
		}
		else if (strcmp(key, (*tree)->key) == 0)
		{
			return;
		}
		else
		{
			InsertTree(&((*tree)->right), key, value);
		}
	}
}


char* SearchValueByKey(Tree** tree, KeyType key)
{
	if (*tree == NULL)
	{
		printf("NOT FOUND!!!");
		return NULL;
	}
	if (strcmp(key, (*tree)->key) == 0)
		return (*tree)->value;
	if (strcmp(key, (*tree)->key) < 0)
		SearchValueByKey(&((*tree)->left), key);
	else
		SearchValueByKey(&((*tree)->right), key);
}


Tree* searchMin(Tree* tree)
{
	if (tree == NULL)
		return;
	if (tree->left == NULL)
		return tree;
	else
		searchMin(tree->left);
}

Tree* DeleteTreeValueByKey(Tree* tree, KeyType key)
{
	if (tree == NULL)
		return tree;
	if (strcmp(key, tree->key) < 0)
		tree->left = DeleteTreeValueByKey(tree->left, key);
	else if (strcmp(key, tree->key) > 0)
		tree->right = DeleteTreeValueByKey(tree->right, key);
	else
	{
		if (tree->left == NULL)
		{

			Tree* temp = tree->right;

			free(tree);

			return temp;

		}

		else if (tree->right == NULL)

		{

			Tree* temp = tree->left;

			free(tree);

			return temp;

		}

		Tree* temp = searchMin(tree->right);
		tree->key = temp->key;
		tree->right = DeleteTreeValueByKey(tree->right, temp->key);
	}
	return tree;
}

void DeleteTree(Tree* tree)
{
	if (tree->left)
		DeleteTree(tree->left);
	if (tree->right)
		DeleteTree(tree->right);
	free(tree);
}

void outputTree(Tree* tree)
{
	printf("%s %s\n", tree->key, tree->value);
	if (tree->left)
	{
		outputTree(tree->left);
	}
	if (tree->right)
	{
		outputTree(tree->right);
	}
}