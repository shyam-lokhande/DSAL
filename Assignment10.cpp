#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

class student{
public:
	int rollno;
	char name[20],address[50],div[20];
	
	void accept(int key){
		cout<<"Enter your name : ";
		cin>>name;
		rollno=key;
		cout<<"Enter your div : ";
		cin>>div;
		cout<<"Enter your address : ";
		cin>>address;
	}
	
	void display(){
		cout<<name<<"\t\t"<<rollno<<"\t\t"<<div<<"\t\t"<<address<<endl;
	}
	
	bool search(int key){
		if(key==rollno) return true;
		else return false;
	}
};

int main(){
	fstream f,f1;
	student s;
	char a[]="abc.txt",b[]="tmp.txt",ch='y';
	int choice;
	
	
	
	while(true){
		cout<<"\n 1. add record \n 2. delete record \n 3. search record \n 4. display \n 5. exit"<<endl;
		cin>>choice;
		switch(choice){
			case 1:
				f.open("abc.txt",ios::in);
				int key; bool find;
				cout<<"\n Enter the roll number of the student you want to add in record : ";
				cin>>key;
				while(f.read((char*)&s,sizeof(s))){
					find= s.search(key);
					if(find) {cout<<"Record already exists"; break;}
					
				}
				f.close();
				f.open("abc.txt",ios::out|ios::app);
				if(!find){
					s.accept(key);
					f.write((char*)&s,sizeof(s));
				}
				f.close();
				break;
				
			case 2:
				f.open("abc.txt",ios::in);
				f1.open("tmp.txt",ios::out|ios::app);
				cout<<"\nEnter the roll number of the student you want to find in record : ";
				cin>>key;
				while(f.read((char*)&s,sizeof(s))){
					find= s.search(key);
					if(!find) f1.write((char*)&s,sizeof(s));
				}
				f.close();
				f1.close();
				remove(a);
				rename(b,a);
				break;
				
			case 3:
				f.open("abc.txt",ios::in);
				cout<<"\nEnter the roll number of the student you want to find in record : ";
				cin>>key;
				while(f.read((char*)&s,sizeof(s))){
					find= s.search(key);
					if(find) {s.display(); break;}
				}
				if(!find) cout<<"record not found .";
				f.close();
				break;
				
			case 4:
				f.open("abc.txt",ios::in);
				cout<<"----------- RECORDS ------------"<<endl;
				cout<<"Name\t\tRoll no\t\tDivision\t\tAddress\n";
				while(f.read((char*)&s,sizeof(s))){
					s.display();
				}
				f.close();
				break;
		}
		if(choice==5) break;
	}
	
}
