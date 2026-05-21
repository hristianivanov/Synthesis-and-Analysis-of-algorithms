#include <stdio.h>
#include <stdlib.h>

struct node {
	char key;
	struct node* left;
	struct node* right;
};

void readtree(struct node** p, char x) {
	char y, z;
	struct node* q1;
	struct node* q2;

	if (*p == NULL) {
		*p = (struct node*)malloc(sizeof(struct node));
		(*p)->key = x;
		(*p)->left = NULL;
		(*p)->right = NULL;
	}

	printf("\nVyvedi liav naslednik na %c (0 ako nqma): ", x);
	scanf_s(" %c", &z);

	if (z != '0') {
		q1 = (struct node*)malloc(sizeof(struct node));
		q1->key = z;
		q1->left = NULL;
		q1->right = NULL;
		(*p)->left = q1;
		readtree(&q1, z);
	}

	printf("\nVyvedi desen naslednik na %c (0 ako nqma): ", x);
	scanf_s(" %c", &y);

	if (y != '0') {
		q2 = (struct node*)malloc(sizeof(struct node));
		q2->key = y;
		q2->left = NULL;
		q2->right = NULL;
		(*p)->right = q2;
		readtree(&q2, y);
	}
}

void printtree(struct node* p, int delta) {
	if (p != NULL) {
		printtree(p->right, delta + 1);
		for (int i = 0; i < delta; i++)
			printf("\t");
		printf("%c\n", p->key);
		printtree(p->left, delta + 1);
	}
}

void preorder(struct node* p) {
	if (p) {
		printf("%c ", p->key);
		preorder(p->left);
		preorder(p->right);
	}
}

void inorder(struct node* p) {
	if (p) {
		inorder(p->left);
		printf("%c ", p->key);
		inorder(p->right);
	}
}

void postorder(struct node* p) {
	if (p) {
		postorder(p->left);
		postorder(p->right);
		printf("%c ", p->key);
	}
}

int eval(struct node* p) {
	if (p->left == NULL && p->right == NULL)
		return p->key - '0';

	int l = eval(p->left);
	int r = eval(p->right);

	if (p->key == '+') return l + r;
	if (p->key == '-') return l - r;
	if (p->key == '*') return l * r;

	return 0;
}

void printExpression(struct node* p) {
	if (p) {
		if (p->left || p->right) printf("(");
		printExpression(p->left);
		printf("%c", p->key);
		printExpression(p->right);
		if (p->left || p->right) printf(")");
	}
}

int main(void) {
	struct node* root = NULL;
	char x;

	printf("Vyvedi koren: ");
	scanf_s(" %c", &x);

	readtree(&root, x);

	printf("\nDurvoto:\n");
	printtree(root, 0);

	printf("\nPreorder: ");
	preorder(root);

	printf("\nInorder: ");
	inorder(root);

	printf("\nPostorder: ");
	postorder(root);

	printf("\n\nAritmetichen izraz: ");
	printExpression(root);
	printf(" = %d\n", eval(root));

	return 0;
}
