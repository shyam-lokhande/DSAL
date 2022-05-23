#include<iostream>
using namespace std;

class node{
public:
	int data;
	node *left,*right;
	int rbit,lbit;
	
	node(){
		left=right=NULL;
		rbit=lbit=0;
	}
};

class tbt{
public:
	node *head,*root;
	
	node* inscc(node* n){
		if(n->rbit!=0){
			return n->right;
		}
		n=n->right;
		while(n->lbit!=0){
			n=n->right;
		}
		return n;
	}
	
	
	void inorder(){
		node* p;
		p=root;
		while(p->lbit!=0){
			p=p->left;
		}
		while(p!=head){
			cout<<p->data<<" ";
			p=inscc(p);
		}
	}
	
	
	void create(){
		node *pre,*p;
		int d,ch;
		head = new node();
		head->data=100;
		head->lbit=head->rbit=1;
		head->left=root;
		head->right=head;
		root= new node();
		cout<<"Enter the data you want to insert :"<<endl;
		cin>>d;
		root->data=d;
		root->left=head;
		root->right=head;
		while(true){
			cout<<"Do you want to insert more ? t1.yes 2.no"<<endl;
			cin>>ch;
			if(ch==2){
				break;
			}
			cout<<"Enter the data you want to insert :"<<endl;
			cin>>d;
			pre = root;
			while(pre!=NULL){
				pre=insert(pre,d);
			}
		}
		p=root;
		while(p->rbit!=0){
			p=p->right;
		}
		p->right=head;
	}
	
	
	node* insert(node* p,int val){
		node *newNode,*pre;
		pre=p;
		if(val>pre->data && pre->rbit==1){
			pre=pre->right;
			return pre;
		}
		if(val<pre->data && pre->lbit==1){
			pre=pre->left;
			return pre;
		}
		if(val<pre->data && pre->lbit==0){
			
			newNode=new node();
			newNode->data=val;
			newNode->left=pre->left;
			pre->left=newNode;
			pre->lbit==1;
			newNode->right=pre;
			return NULL;
		}
		if(val>pre->data && pre->rbit==0){
			
			newNode=new node();
			newNode->data=val;
			pre->rbit=1;
			newNode->right=pre->right;
			pre->right=newNode;
			newNode->left=pre;
			return NULL;
		}
	}
};

int main(){
	tbt n;
	n.create();
	n.inorder();
}
