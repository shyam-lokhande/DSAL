#include<iostream>
using namespace std;
#define SIZE 100

class Graph{
	public:
	int vertices,edges;
	int graph[SIZE][SIZE];
	int mst[SIZE][SIZE];
	int selected[SIZE][SIZE];
	int parent[SIZE];
	int cost;
	
	Graph(int v,int e){
		vertices = v;
		edges = e;
		for(int i=0;i<v;i++){
			parent[i]=i;
			for(int j=0;j<v;j++){
				mst[i][j]=0;
				selected[i][j]=0;
				graph[i][j]=0;
			}
		}
	}
	
	void create(){
		int weight;
		for(int i=0;i<vertices;i++){
			for(int j=i+1;j<vertices;j++){
				cout<<"Enter the distance between office no. "<<i<<" and "<<j<<endl;
				cin>>weight;
				graph[i][j]=graph[j][i]=weight;
			}
		}
	}
	
	void display(){
		cout<<"The graph is :"<<endl;
		for(int i=0;i<vertices;i++){
			for(int j=0;j<vertices;j++){
				cout<<graph[i][j]<<"\t";
			}
			cout<<endl;
		}
	}
	
	int findParent(int v){
		if(parent[v]==v){
			return v;
		}
		return findParent(parent[v]);
	}
	
	void kruskal(){
		int minW,minS,minD;
		int k=1;
		cost =0;
		
		while(k<=vertices){
			minW=100;
			for(int i=0;i<vertices;i++){
				for(int j=i+1;j<vertices;j++){
					if(graph[i][j] && !selected[i][j] && graph[i][j]<=minW){
						minW=graph[i][j];
						minS=i;
						minD=j;
					}
				}
			}
			
			if(findParent(minS)!=findParent(minD)){
				mst[minS][minD]=mst[minD][minS]=minW;
				parent[minD]=minS;
				selected[minS][minD]=selected[minD][minS]=1;
				cost+=mst[minS][minD];
			}
			k++;
		}
		
		displaymst();
	}
	
	void displaymst(){
		cout<<"The Minimum Spanning Tree is :"<<endl;
		for(int i=0;i<vertices;i++){
			for(int j=0;j<vertices;j++){
				cout<<mst[i][j]<<"\t";
			}
			cout<<endl;
		}
	}
};

int main(){
	int v,e;
	cout<<endl<<"Enter the number of vertices :";
	cin>>v;
	cout<<endl<<"Enter the number of edges :";
	cin>>e;
	Graph g(v,e);
	g.create();
	g.display();
	g.kruskal();
}
