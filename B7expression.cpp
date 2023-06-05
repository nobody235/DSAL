#include<iostream>
using namespace std;

struct node {
	char data;
	node *left, *right;
};


char* add(node** p, char* a)
{
	if (*a == '\0')
		return 0 ;
	while (1) {
		char* q = "null";
		if (*p == NULL) {

			node* nn = new node;
			nn->data = *a;
			nn->left = NULL;
			nn->right = NULL;
			*p = nn;
		}
		else {
			if (*a >= 'a' && *a <= 'z') {
				return a;
			}
			q = add(&(*p)->left, a + 1);
			q = add(&(*p)->right, q + 1);
			return q;
		}
	}
}

void inr(node* p)
{
	if (p == NULL) {
		return;
	}
	else {
		inr(p->left);
		cout << p->data << " ";
		inr(p->right);
	}
}

void postr(node* p)
{
	if (p == NULL) {
		return;
	}
	else {
		postr(p->left);
		postr(p->right);
		cout << p->data << " ";
	}
}

int main()
{
	node* s = NULL;
    char a[100];
    cout << "Enter the prefix expression." << endl;
    cin >> a;
	add(&s, a);
	cout << "The Infix expression is:\n ";
	inr(s);
	cout << "\n";
	cout << "The Postfix expression is:\n ";
	postr(s);
	return 0;
}
