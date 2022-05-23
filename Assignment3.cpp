#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* left;node* right;
	
	node(int val){
		left=right=NULL;
		data = val;
	}
};

class BTree{
public:
	node* root;
	
	node* insert(node* r,int val){
		if(r==NULL){
			r=new node(val);
		}
		else if(r->data<val){
			r->right=insert(r->right,val);
		}
		else if(r->data>val){
			r->left=insert(r->left,val);
		}
		else{
			cout<<"Same value can not be inserted twice in Binary Tree.";
		}
		return r;
	}
	
	void inorder(node* r){
		if(r==NULL){
			return;
		}
		else{
			inorder(r->left);
			cout<<r->data<<" "<<endl;
			inorder(r->right);
		}
	}
	
	int min(node* r){
		node* temp=r;
		while(temp->left!=NULL){
			temp=temp->left;
		}
		return temp->data;
	}
	
	bool search(node* r,int val){
		if(r->data==val) return true;
		else if(r->left==NULL && r->right==NULL){
			return false;
		}
		else if(r->data>val) return search(r->left,val);
		else return search(r->right,val);
	}
	
	void swap(node* r){
		if(r==NULL){
			return;
		}
		swap(r->left);
		swap(r->right);
		
		node* temp = r->left;
		r->left = r->right;
		r->right = temp;
	}
	
	int height(node* r){
		if(r==NULL) return -1;
		int lefth=height(r->left);
		int righth = height(r->right);
		
		if(lefth>righth) return lefth+1;
		else return righth+1;
	}
};

int main(){
	BTree b ;
	
	while(true){
		cout<<"Enter your choice from below.";
		cout<<"0. exit"<<endl;
		cout<<"1. Insert"<<endl;
		cout<<"2. longest path length"<<endl;
		cout<<"3. Minimum value"<<endl;
		cout<<"4. Invert"<<endl;
		cout<<"5. Search"<<endl;
		cout<<"6. display"<<endl;
		
		int choice ;
		cin>>choice;
		
		if(choice==0) break;
		
		switch(choice){
			case 1:
				cout<<"Enter the number of nodes to be inserted :"<<endl;
				int n;
				cin>>n;
				for(int i=0;i<n;i++){
					int num;
					cout<<"Enter the number"<<endl;
					cin>>num;
					b.root = b.insert(b.root,num);
				}
				break;
				
			case 2:
				cout<<"Height of the tree is : "<<b.height(b.root)<<endl;
				break;
				
			case 3:
				cout<<"Minimum value is : "<<b.min(b.root)<<endl;
				break;
				
			case 4:
				cout<<"The tree is inverted."<<endl;
				b.swap(b.root);
				break;
				
			case 5:
				cout<<"Enter the number you want to search :"<<endl;
				int num;
				cin>>num;
				if(b.search(b.root,num)) cout<<"Number is present in tree"<<endl;
				else cout<<"Number is not present in tree"<<endl;
				break;
				
			case 6:
				b.inorder(b.root);
				break;
		}
		
	}
}
