#include <iostream>

class BST {

	struct node {
		int data;
		node *left, *right;
	};

	node* root;
	
	node* makeEmpty(node* t) {
		if (t == NULL)
			return NULL;
		{
			makeEmpty(t->left);
			makeEmpty(t->right);
			delete t;
		}
		return NULL;
	}

	node* insert(int x, node* t)
	{
		if (t == NULL)
		{
			t = new node;
			t->data = x;
			t->left = t->right = NULL;
		}
		else if (x < t->data)
			t->left = insert(x, t->left);
		else if (x > t->data)
			t->right = insert(x, t->right);
		return t;
	}

	node* findMin(node* t)
	{
		if (t == NULL)
			return NULL;
		else if (t->left == NULL)
			return t;
		else
			return findMin(t->left);
	}

	node* findMax(node* t) {
		if (t == NULL)
			return NULL;
		else if (t->right == NULL)
			return t;
		else
			return findMax(t->right);
	}

	node* remove(int x, node* t) {
		node* temp;
		if (t == NULL)
			return NULL;
		else if (x < t->data)
			t->left = remove(x, t->left);
		else if (x > t->data)
			t->right = remove(x, t->right);
		else if (t->left && t->right)
		{
			temp = findMin(t->right);
			t->data = temp->data;
			t->right = remove(t->data, t->right);
		}
		else
		{
			temp = t;
			if (t->left == NULL)
				t = t->right;
			else if (t->right == NULL)
				t = t->left;
			delete temp;
		}

		return t;
	}

	void inorder(node* t) {
		if (t == NULL)
			return;
		inorder(t->left);
		std::cout << t->data << " ";
		inorder(t->right);
	}

	node* find(node* t, int x) {
		if (t == NULL)
			return NULL;
		else if (x < t->data)
			return find(t->left, x);
		else if (x > t->data)
			return find(t->right, x);
		else
			return t;
	}

public:
	BST() {
		root = NULL;
	}

	~BST() {
		root = makeEmpty(root);
	}

	void insert(int x) {
		root = insert(x, root);
	}

	void remove(int x) {
		root = remove(x, root);
	}

	void display() {
		inorder(root);
		std::cout << std::endl;
	}

	void search(int x) {
		root = find(root, x);
	}
};

int main() {
	BST *t = new BST();
	int ch = 1, val;

	while (ch)
	{
		ch = 0;
		std::cout << "1) Inserisci " << std::endl;
		std::cout << "2) Rimuovi" << std::endl;
		std::cout << "3) Ricerca " << std::endl;
		std::cout << "4) Visualizza " << std::endl;
		std::cout << "0) Esci" << std::endl;
		std::cin >> ch;
		switch (ch)
		{
		case 0:
			std::cout << "Exiting..." << std::endl;
			break;
		case 1:
			std::cout << "Inserisci un valore: \t";
			std::cin >> val;
			t->insert(val);
			break;
		case 2:
			std::cout << "Inserisci un valore: \t";
			std::cin >> val;
			t->remove(val);
			break;
		case 3:
			std::cout << "Inserisci un valore: \t";
			std::cin >> val;
			t->search(val);
			break;
		case 4:
			t->display();
			break;
		default:
			break;
		}
	}

	delete t;
	return 0;
}