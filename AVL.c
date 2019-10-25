#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	int height;
};

int max(int a, int b);

int height(struct Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

int max(int a, int b)
{
	return (a > b)? a : b;
}

struct Node* newNode(int key)
{
	struct Node* node = (struct Node*)
		malloc(sizeof(struct Node));
		node->key = key;
		node->left = NULL;
		node->right = NULL;
		node->height = 1;
	return(node);
}

struct Node *rightRotate(struct Node *y)
{
	struct Node *x = y->left;
	struct Node *T2 = x->right;

	// Realiza rotação
	x->right = y;
	y->left = T2;

	// Atualiza alturas
	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;

	// Returna novo no
	return x;
}

struct Node *leftRotate(struct Node *x)
{
	struct Node *y = x->right;
	struct Node *T2 = y->left;

	// Realiza rotacao
	y->left = x;
	x->right = T2;

	// Atualiza alturas
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	// Returna novo no
	return y;
}

// Retorna fator de balanceamento de um no
int getBalance(struct Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

//Metodo inserir da AVL
struct Node* insert(struct Node* node, int key)
{
	/* 1. Insercao normal de arvores binarias */
	if (node == NULL)
		return(newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else
		return node;

	/* 2. Atualiza a altura */
	node->height = 1 + max(height(node->left),
						height(node->right));

	/* 3. Calcula o fator de balanceamento do no */
	int balance = getBalance(node);

	// Se no estiver desbalanceado, 4 casos podem existir

	// Caso esquerda esquerda
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	// Caso direita direita
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	// Caso esquerda direita
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Caso direita esquerda
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}

// A utility function to print preorder traversal
// of the tree.
// The function also prints height of every node
void preOrder(struct Node *root)
{
	if(root != NULL)
	{
		printf("%d ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}

/* Drier program to test above function*/
int main()
{
struct Node *root = NULL;

/* Constructing tree given in the above figure */
root = insert(root, 10);
root = insert(root, 20);
root = insert(root, 30);
root = insert(root, 40);
root = insert(root, 50);
root = insert(root, 25);
root = insert(root, 22);
root = insert(root, 12);
root = insert(root, 42);
root = insert(root, 18);
root = insert(root, 60);
root = insert(root, 54);

preOrder(root);
return 0;
}
