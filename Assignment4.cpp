#include<iostream>
#include<string.h>
using namespace std;

class node{
public:
	char data;
	node* left;
	node* right;
	
	node(){
		data=' ';
		left=NULL;
		right = NULL;
	}
};

class stack{
public:
	node* arr[20];
	int top;
	
	stack(){
		top=-1;
	}
	
	void push(node* n){
		arr[++top] = n;
	}
	
	node* pop(){
		return arr[top--];
	}
	
	bool isEmpty(){
		if(top==-1) return true;
		else return false;
	}
};

class tree{
public:
	node* root;
	
	void expression(char prefix[]){
		stack s ;
		node* t1;node* t2;
		int len = strlen(prefix);
		
		for(int i=len-1;i>=0;i--){
			root = new node();
			if(isalpha(prefix[i])){
				root->data=prefix[i];
				s.push(root);
			}
			else if(prefix[i]=='+' || prefix[i]=='-' || prefix[i]=='*' || prefix[i]=='/'){
				t1=s.pop();
				t2=s.pop();
				root->data=prefix[i];
				root->left=t1;
				root->right=t2;
				s.push(root);
			}
		}
		root=s.pop();
	}
	
	void postorder(node* root){
		node* temp=root;
		stack s1,s2;
		s1.push(temp);
		
		while(!s1.isEmpty()){
			temp = s1.pop();
			s2.push(temp);
			if(temp->left!=NULL){ s1.push(temp->left); }
			if(temp->right!= NULL){ s1.push(temp->right); }
		}
		
		while(!s2.isEmpty()){
			temp=s2.pop();
			cout<<temp->data<< " ";
		}
	}
	
	void del(node* r){
		if(r==NULL){
			return;
		}
		
		del(r->left);
		del(r->right);
		
		cout<<"\n deleting node :"<<r->data<<endl;
		delete r;
	}
};

int main(){
	char prefix[30];
	
	cout<<"Enter the expression :"<<endl;
	cin>>prefix;
	
	tree t;
	
	cout<<"Postorder of entered expression is "<<endl;
	t.expression(prefix);
	
	t.postorder(t.root);
	t.del(t.root);
}
