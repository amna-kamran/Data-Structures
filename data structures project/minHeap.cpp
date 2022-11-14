//heap implementation
#ifndef MINHEAP_H
#define MINHEAP_H
#include <iostream>
using namespace std;

class minHeap{
public:
//getting a global array
int heap[500];
int size=-1;



//designing a min heap
//1) enqueing new elements
//2) dequeing minimum value
void heapify();
void enqueue(int x){
	//1) condition to check whether the queue is empty
	//2) we use a loop to determine the empty spot. We store that spots index somewhere and enqueues the element there
	//3) after enqueing the element we will compare it with the parent 
	if(heap==NULL){
		size++;
		heap[size]=x;
	}else{
		size++;
		heap[size]=x;
		heapify();
		
	}
}

void heapify(){
	int parent = (size-1)/2;
	int child = size;
	int temp=0;
	//swapping
	while(heap[child]<heap[parent]){
		
		temp=heap[parent];
		heap[parent]=heap[child];
		heap[child]=temp;
		
		child = parent;
		parent = (parent-1)/2;
		
	
}
}

void display(){
	for(int i=0; i<=size; i++){
		cout<<heap[i]<<endl;
	}
}

void dequeue(){
	if(size==-1){
		cout<<"Nothing to dequeue"<<endl;
	}else{
		cout<< heap[0]<<endl;
		heap[0]=heap[size];
		size--;
	}
}
};

#endif