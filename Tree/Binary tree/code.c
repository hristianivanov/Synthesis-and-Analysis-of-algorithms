#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
	int key;
	struct tree* left;
	struct tree* right;
} Tree;

void InsertNode(char x, struct tree** v)
{
	if (*v != NULL)
	{
		if (x < (*v)->key)
			InsertNode(x, &(*v)->left);
		else
			if (x > (*v)->key)
				InsertNode(x, &(*v)->right);
	}
	else
	{
		(*v) = (struct tree*)malloc(sizeof(struct tree));
		(*v)->key = x;
		(*v)->left = NULL;
		(*v)->right = NULL;
	}
}