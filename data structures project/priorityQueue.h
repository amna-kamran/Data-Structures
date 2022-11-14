#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
using namespace std;

class priorityQueue{
public:
    int front=-1;
    int rear=-1;
    int size=10;
    int arr[10];
void enqueue(int x){
//condition isempty
int temp;
if(front==-1){
    front=0;
    rear=0;
    arr[rear]=x;

}else if((rear+1)%size==front){
    cout<<"Queue Full"<<endl;
}else{
    rear=(rear+1)%size;
    cout<<"Rear: "<<rear<<" X: "<<x<<endl;
    arr[rear]=x;
    int i=rear;
    while(arr[i]<arr[i-1]){
            temp=arr[i];
            arr[i]=arr[i-1];
            arr[i-1]=temp;
            i--;
    }
        cout<<arr[rear]<<endl;

}
}
int dequeue(){
if(front==-1){
    cout<<"Queue is empty, cannot queue"<<endl;
}else if(front==rear){
    int hehe = front;
    front=-1;
    rear=-1;
    return arr[hehe];
}else{
    return arr[rear--];
}
}    
void display()  
{  
    cout<<"Front: "<<front<<endl;
    cout<<"Rear: "<<front<<endl;
    int i=front;  
    if(front==-1 && rear==-1)  
    {  
        printf("\n Queue is empty..");  
    }  
    else  
    {   
        for(int i=front; i<rear; i=(i+1)%size) 
        {  
            cout<<arr[i]<<endl;  
            
        }  
    }
}
};
#endif