#include <iostream>

struct Node {
	int val;
	Node* next;
};

void push(Node* n);
Node* pop(Node* n);
void print(Node* n);
void freeList(Node** n);

int main()
{
	Node* head = new Node;
	head->next = nullptr;
	head->val = 0;

	int ch = 1;
	while (ch)
	{
		ch = 0;
		std::cout << "1) Inserisci \n";
		std::cout << "2) Togli \n";
		std::cout << "3) Stampa \n";
		std::cout << "4) Libera Memoria \n";
		std::cout << "0) Esci \n";
		std::cin >> ch;
		switch (ch)
		{
		case 0: 
			std::cout << "Exiting...";
			break;
		case 1:
			push(head);
			break;
		case 2:
			head = pop(head);
			break;
		case 3:
			print(head);
			break;
		case 4:
			freeList(&head);
			break;
		default:
			break;
		}
	}
	return 0;
}

void push(Node* n)
{
	int x;
	std::cout << "Inserisci un valore: ";
	std::cin >> x;
	if (!n->val && n->next == nullptr)
	{
		n->val = x;
	}
	else
	{
		Node* p = new Node;
		p->val = x;
		p->next = nullptr;
		Node* q = n;
		while (q->next != nullptr)
		{
			q = q->next;
		}
		q->next = p;
	}
}

Node* pop(Node* n)
{
	int idx, cnt = 0;
	Node* p = new Node;
	Node* q = n;

	std::cout << "Inserisci indice: ";
	std::cin >> idx;
	while (q->next != nullptr)
	{
		cnt++;
		q = q->next;
	}

	if (!cnt)
	{
		if (!idx)
		{
			if (n->val != 0)
			{
				n->val = 0;
			}
		}
	}
	else
	{
		if (idx > 0 && idx <= cnt)
		{
			q = n;
			for (int i = 0; i < idx - 1; ++i)
			{
				q = q->next;
			}
			p = q->next;
			q->next = p->next;
		}
	}
	delete p;
	if (!idx)
	{
		n = n->next;
	}
	return n;
}

void print(Node* n)
{
	Node* p = n;

	while (p != nullptr)
	{
		std::cout << p->val << " ";
		p = p->next;
	}
	std::cout << std::endl;
}

void freeList(Node** n) 
{
	Node* x = *n;
	while (*n != nullptr)
	{
		x = *n;
		*n = (*n)->next;
		std::cout << "Deleting " << x->val << std::endl;
		delete x;
	}
	*n = nullptr;
}