#include "priorityQueue.h"
using namespace std;
//enqueue
front=-1;
rear=-1;
size = 10;
void priorityQueue:: enqueue(int x){
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

int priorityQueue:: dequeue(){
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

void priorityQueue:: display()  
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

/*
void menu(){
    cout<<"1. enqueue"<<endl;
    cout<<"2. dequeue"<<endl;
    cout<<"3. display"<<endl;
}
*/

/*
int main(int argc, char const *argv[])
{
    priorityQueue p;
menu();
    int choice;
    cout<<"Enter choice: ";
    cin>>choice;

    while(choice!=0){
        switch(choice){
            case 1: {
                int val;
                cout<<"Enter: ";
                cin>>val;
                p.enqueue(val);

            }break;

            case 2: {p.dequeue(); }break;
            case 3: {p.display(); }break;
        
    }
        menu();
        cout<<"Enter choice: ";
        cin>>choice;
    }

    return 0;
}
*/
