#include<iostream>
using namespace std;

class node {
     public:
         int data;
         node *left;
         node *right;
};

class Bst {
public:
        node *root;
    Bst () {
        root = NULL;
    }
    void create ();
    void insert ();
    void traverse(node*);
    void search (int key);
    void minimum ();
    int height (node*);
    void mirror (node*);
};

void Bst::create () {
    int ans;
    cout << "\nEnter number of keys to insert: ";
    cin >> ans;
    cout << '\n';
    while (ans--)
        insert();
}

void Bst::insert () {
    node *curr,*temp;
    cout << "Enter data: ";
    curr = new node;
    cin >> curr -> data;
    curr -> left = curr -> right = NULL;

    if (root == NULL)
        root = curr;

    else {
        temp = root;
        while (1) {
            if (curr -> data <= temp -> data) {
                if (temp -> left == NULL) {
                    temp -> left = curr;
                    break;
                }
                else
                    temp = temp -> left;
            }
            else {
                if (temp -> right == NULL) {
                    temp -> right = curr;
                    break;
                }
                else
                    temp = temp -> right;
            }
        }
    }
}

void Bst::traverse(node* root){

	if(root==NULL){
		return;
	}
	else{
			traverse(root->left);
			cout<<root->data<<" ";
			traverse(root->right);
	}
}

void Bst::minimum () {
    node *temp = root;
    int min;
    while (temp -> left != NULL) {
        min = temp -> data;
        temp = temp -> left;
        if (temp -> data<min)
            min = temp -> data;
        else
            temp = temp -> left;
    }
    cout << "\nMinimum number is: " << min;
}

int Bst::height (node *root) {
    if (root == NULL)
        return 0;

    else {
        if (height (root -> right) > height (root -> left))
            return (1 + height (root -> right));

        else
            return (1 + height (root -> left));
    }
}

void Bst::mirror (node *root) {
    if (root == NULL)
        return;

    else {
        mirror(root -> left);
        mirror(root -> right);
        swap(root -> left, root -> right);
    }
}

int main () {
    Bst b;
    int key,ch;
    do {
         cout << "\n------ MAIN MENU----- \n";
		cout << "\n\n1.Create \n2.Insert \n3.Minimum \n4.Height \n5.Mirror \n6. Exit\n";
        cout << "\n Enter Your choice  :\n";
        cin >> ch;
        switch (ch) {
            case 1:
                b.create ();
                break;
            case 2:
                cout << '\n';
                b.insert ();
                break;
            case 3:
                b.minimum ();
                break;
            case 4:
                cout << "\nHeight of tree: " << b.height (b.root);
                break;
            case 5:
                b.mirror (b.root);
                cout << "\nTree is now mirrored!!!"
                     << "\nInorder   traversal is:";
                b.traverse (b.root);
                break;
            case 6:
                cout << "Exited" << endl;
                break;
        }
    }while (ch < 6);
    return 0;
}
