#include<iostream>

using namespace std;
#include<string.h>
#define SIZE 10

class record{
public:
	int key;
	char value[20];
};

class Hash{
public:
	record items[SIZE];
	int chain[SIZE];
	
	Hash(){
		for(int i=0;i<SIZE;i++){
			chain[i]=-1;
			items[i].key=0;
			strcpy(items[i].value,"--------------");
		}
	}
	
	void insert(){
		record r;
		cout<<"Enter the key "<<endl;
		cin>>r.key;
		cout<<"Enter the value"<<endl;
		cin>>r.value;
		
		int k = r.key%10;
		int pre = k;
		
		for(int i=0;i<SIZE;i++){
			if(items[k].key==0){
				items[k]=r;
				if(pre!=k) chain[pre]=k;
				return;
			}
			else{
				k++;
				k=k%SIZE;
			}
			pre=k-1;
		}
		cout<<"Hashtable is full"<<endl;
	}
	
	void display(){
		for(int i=0;i<SIZE;i++){
			cout<<i<<"\t"<<items[i].key<<"\t"<<items[i].value<<"\t"<<chain[i]<<endl;
		}
	}
	
	void find(){
		int num;
		cout<<"Enter the key you want to find"<<endl;
		cin>>num;
		
		int k = num%SIZE;
		while(k!=-1){
			if(items[k].key==num){
				cout<<"Entered key exists in dictionsry at index "<<k<<endl;
				return;
			}
			else{ k= chain[k]; }
		}
		cout<<"Your entered key does not exists in record."<<endl;
	}
	
	void del(){
		int num,pre=0,ch=0;
		cout<<"Enter the key you want to delete"<<endl;
		cin>>num;
		
		int k = num%SIZE;
		while(k!=-1){
			if(items[k].key==num){
				items[k].key=0;
				strcpy(items[k].value,"----");
				
				if(pre!=k){
					chain[pre]=chain[k];
				}
				else chain[pre]=-1;
				chain[k]=-1;
				return;
			}
			else{ 
				pre=k;
				ch=chain[pre];
				k= chain[k]; 
			}
			
		}
		cout<<"Your entered key does not exists in record."<<endl;
	}
};

int main(){
	Hash h;
	h.insert();
	h.insert();
	h.insert();
	h.display();
	h.find();
	h.del();
	h.display();
	return 0;
}
