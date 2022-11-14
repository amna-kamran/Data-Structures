#include <iostream>
using namespace std;
int u,v=0;
#define V 4

//initializing the matrix to zero
void intializing(int arr[][V]){
	int i, j;
	for(int i=0; i<V;i++){
		for(int j=0; j<V; j++){
			arr[i][j]=0;
		}
	}
}

//adding edges
void addEdge(int arr[][V], int i, int j){
	arr[i][j]=1;
	arr[j][i]=1;
}

//printing the matrix
void displayMatrix(int arr[][V]){
	for(int i=0; i<V; i++){
		for(int j=0; j<V; j++){
			cout<<arr[i][j];
		}
		cout<<endl;
	}
}