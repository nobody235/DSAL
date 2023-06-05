#include<iostream>
using namespace std;

struct node{
	int data;
    struct	node*left;
	struct node*right;
};
node*newNode(int key)
{
	node*temp=new node;
	temp->data=key;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
node*insert(node*root,int data)
{
	if(root==NULL){
	root=newNode(data);
    }
	else{
		if(data<root->data){
		root->left=insert(root->left,data);
	    }
	    else{
	    	root->right=insert(root->right,data);
	    }
	    return root;
		}
}
node*traverse(node*root){
	if(root==NULL){
	    return root;
    }
	else{

	traverse(root->left);
	cout<<root->data<<" ";
   	traverse(root->right);
    }
}
node*min(node*root){
	while(root->left!=NULL){
		root=root->left;
    cout<<"Minimum element is"<<root->data;
	}
}
int main(){
	struct node*root=NULL;

	int ch,ele,n;
	char b;
	do{
		cout<<"*********menu*********";
		cout<<"\n 1 INSERT \n 2 FIND MIN"<<endl;
		cout<<"Enter your choice";
		cin>>ch;
		switch(ch){
			case 1:
			    cout<<"Enter the number of elements";
				cin>>n;
				int r;
				cout<<"enter the root node";
				cin>>r;
				root=insert(root,r);
				for(int i=1;i<n;i++){
					cout<<"Enter the elements";
					cin>>ele;
					insert(root,ele);
					traverse(root);
				}
				break;
			case 2:
				min(root);
				break;
			default:
			cout<<"invalid choice";
		}
		cout<<"do you want to continue";
		cin>>b;
	}while(b!='n');
	return 0;
}
