#include <iostream>
int u,v=0;
#define V 7
using namespace std;

//int matrix[V][V];
int m[V][V];

/*
-1514-1-1-1
5-1-18-16-1
1-1-132-1-1
483-1-18-1
-1-12-1-179
-16-187-1-1
-1-1-1-19-1-1
*/
int matrix[V][V]={
	{-1,5,1,4,-1,-1,-1},
	{5,-1,-1,8,-1,6,-1},
	{1,-1,-1,3,2,-1,-1},
	{4,8,3,-1,-1,8,-1},
	{-1,-1,2,-1,-1,7,9},
	{-1,6,-1,8,7,-1,-1},
	{-1,-1,-1,-1,9,-1,-1}};
string nodes[V];
int visited[V];
int cost[V];
string parent[V];
string path[V];
int index;


void dijkstra(string s, string e){
	//finding the starting and the ending node's index
	int snode,enode;
	for(int i=0; i<V; i++){
		if(nodes[i]==s){
			snode=i;
		}else if(nodes[i]==e){
			enode=i;
		}
	}
		visited[0]=snode;
		parent[0]="-";

	int min;
	int column;
	bool check=0;
	index=snode;
	cout<<1<<"=>";
	for(int i=0;i<V;i++){
		for(int j=0; j<V; j++){
			check=0;
			if(index==snode){
				m[index][j]=matrix[index][j];
			}else{
				cout<<"InsideOne"<<endl;
				//avoiding -1's
					if(matrix[index][j]!=-1){
						//cout<<"InsideTwo"<<endl;
						for(int p=0; p<V; p++){
							if(j==visited[p]){
							check=1;
							}
							//cout<<check<<endl;
						}
						if(check==0){
							m[index][j]=matrix[index][j]+min;
							/////////////////////////////
							cout<<"Inside"<<endl;
							}else{m[index][j]=-1;}
					}else{m[index][j]=matrix[index][j];}
			}
		}
		cout<<"INDEX: ";
		cout<<index<<endl;
		parent[i+1]=nodes[column];
		//changing the index
		for(int k=0; k<V; k++){
			if(m[index][k]!=-1){
				min=m[index][k];
				column=k;
				break;
			}
		}
		for(int k=0; k<V; k++){
			if(m[index][k]!=-1 && m[index][k]<min){
				column=k;
				min=m[index][k];
			}
		}
				cout<<"min: ";
		cout<<min<<endl;
		index=column;
		visited[i+1]=index;
	}

	//for the path
int ind=0;
int findPath=enode;
path[ind]=e;



}
void addNodeNames(){
	for(int i=0; i<V; i++){
		cout<<"Enter node "<<i<<" :";
		cin>>nodes[i];
	}
}
/*
void addNodeCost(){
for(int i=0; i<size; i++){
	for(int j=0; j<size; j++){
		cout<<"Add cost for going from node "<<nodes[i]<<" to node "<<nodes[j]<<" : ";
		cin>>matrix[i][j]; 
	}
}
}
*/
void display(){
cout<<"PATH"<<endl;
for(int i=0; i<V; i++){
		cout<<nodes[i]<<"->"<<parent[i];
	cout<<endl;
}
}

//initializing the matrix to zero
void intializing(int arr[][V]){
	int i, j;
	for(int i=0; i<V;i++){
		for(int j=0; j<V; j++){
			arr[i][j]=-1;
		}
	}
}

//adding edges
void addEdge(int arr[][V], string i, string j){
	int in,jn,cost;
	//looking for indexes of these nodes
	for(int k=0; k<V;k++){
		if(nodes[k]==i){
			in=k;
		}else if(nodes[k]==j){
			jn=k;
		}
	}
	cout<<"Enter cost: ";
	cin>>cost;
	arr[in][jn]=cost;
	arr[jn][in]=cost;
}

//printing the matrix
void displayMatrix(int matrix[V][V]){
	for(int i=0; i<V; i++){
		for(int j=0; j<V; j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}

void menu(){
	cout<<"1. add an edge"<<endl;
	cout<<"2.display matrix"<<endl;
	cout<<"3. find shortestdistance"<<endl;
}
int main(int argc, char const *argv[])
{
	//intializing(m);
	addNodeNames();
	int choice;
	menu();
	cout<<"Choice: ";
	cin>>choice;
	while(choice!=0){
		switch(choice){

		case 1: {
				string i,j;
				cout<<"First node: ";
				cin>>i;
				cout<<"Second node: ";
				cin>>j;
				cout<<"Add an edge: ";
				addEdge(matrix,i,j);
			}break;
		case 2:{
			displayMatrix(matrix);
			cout<<"HIMM"<<endl;
			displayMatrix(m);
			display();
		}break;
		case 3:{
			dijkstra("A","F");
		}break;
	}
	menu();
	cout<<"Choice: ";
	cin>>choice;
	}
	//addNodeCost();
	//display();
	return 0;
}

