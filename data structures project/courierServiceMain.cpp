#include <iostream>
#include <iostream>
#include "binarySearch.h"
#include "randomNumberGenerator.h"
#include "priorityQueue.h"
#include "maxHeap.h"
#include "minHeap.h"
#include <ctime>
#include <limits.h>
#include <string>
#include <bits/stdc++.h>
//#include "clientClass.h"
//#include "Address.h"
#define V 60;
#define P 7
using namespace std;

struct packageClass;
struct packagePriorityQueue;
/////////////////////////////////////////////////////////////////////////////////////////////////
//OBJECTS
maxHeap h1;
minHeap h2;

////////////////////////////////////////////////////////////////////////////////////////////////

struct Address{
	string street;
	string city;
};

////////////////////////////////////////////////////////////////////////////////////////////////
struct clientClass{

	//client
	string cfname;
	string clname;
	string password;
	int phoneNumC;
	int id;
	Address* c;
	packagePriorityQueue* p;

void toString(){
		cout<< "Name: "<< cfname<<endl;
		cout<< "Id: "<< id << endl;
		cout<< "<=Address=> "<<endl;
		cout<<" City: "<<c->city<<endl;
		cout<<" Street: "<<c->street<<endl;
		cout<<"Phone Number: "<<phoneNumC<<endl;
}
};

///////////////////////////////////////////////////////////////////////////////////////////////
struct packageClass{
	string packageName;
	double weight;
	int packageID;
	int distance;
	string date;
	string path;
	//reciever details
	string rfname;
	string rlname;
	int phoneNumR;
	Address* r;

	void generateBill(clientClass* c){
	//200 per kg
	int cost=200*weight;

	cout<<"+=======================================================+"<<endl;
	cout<<"|                       Bill Details                    |"<<endl;
	cout<<"+=======================================================+"<<endl;
	cout<<"|   Package Name: "<<packageName<<"                     |"<<endl;
	cout<<"|   PackageID:    "<<packageID<<"                       |"<<endl;
	cout<<"|   Cost per Kg: "<<cost<<"                             |"<<endl;
	cout<<"|   Sender's Name: "<<c->cfname<<""<<c->clname<<"         |"<<endl;
	cout<<"|   Sender's Phone Number"<<c->phoneNumC<<"             |"<<endl;

	cout<<"|   Date of Delivery: "<<date<<"                       |"<<endl;
	cout<<"|   Reciever's Address: "<<r->city<<"                   |"<<endl;
	cout<<"|                       "<<r->street<<"                 |"<<endl;
	cout<<"|   Reciever's Phone Number: "<<phoneNumR<<"            |"<<endl;
	cout<<"|   Distance Travelled by the Package: "<<distance<<"   |"<<endl;
	cout<<"+=======================================================+"<<endl;
}

void toString(clientClass* cc){
		cout<< "Package Name: "<< packageName<<endl;
		cout<< "Package Id: "<< packageID << endl;
		cout<<"+================+"<<endl;
		cout<<"|Sender's Details|"<<endl;
		cout<<"+================+"<<endl;
		cout<< "Sender's Name: "<<cc->cfname<<""<<cc->clname<<endl;
		cout<<" Sender's Phone Number"<<cc->phoneNumC<<endl;
		cout<<endl;
		cout<<"+=================+"<<endl;
		cout<<"|Reciver's Details|"<<endl;
		cout<<"+=================+"<<endl;
		cout<< "Reciever's Name: "<<rfname<<" "<<rlname<<endl;
		cout<<" Reciever's Phone Number: "<<phoneNumR<<endl;
		cout<<" Date of Delivery: "<<date<<endl;
		cout<<endl;
		cout<<"+==================+"<<endl;
		cout<<"|Reciever's Address|"<<endl;
		cout<<"+==================+"<<endl;
	  cout<<"<=Address=> "<<endl;
		cout<<" City: "<<r->city<<endl;
		cout<<" Street: "<<r->street<<endl;
		cout<<endl;
		cout<<"+================+"<<endl;
		cout<<"|Sender's Address|"<<endl;
		cout<<"+================+"<<endl;
		cout<<"<=Address=> "<<endl;
		cout<<" City: "<<cc->c->city<<endl;
		cout<<" Street: "<<cc->c->street<<endl;
		cout<<endl;
		cout<<"+=================================+"<<endl;
		cout<<"|Distance Travelled By the Package|"<<endl;
		cout<<"+=================================+"<<endl;
		cout<<"Distance: "<<distance<<" KM"<<endl;
		cout<<"+=========================+"<<endl;
		cout<<"|Path Taken by the Package|"<<endl;
		cout<<"+=========================+"<<endl;
		cout<<"Path: "<<path<<endl;


}
void display(){
		cout<< "Package Name: "<< packageName<<endl;
		cout<< "Package Id: "<< packageID << endl;
		cout<<endl;
		cout<<"+=================+"<<endl;
		cout<<"|Reciver's Details|"<<endl;
		cout<<"+=================+"<<endl;
		cout<< "Reciever's Name: "<<rfname<<" "<<rlname<<endl;
		cout<<" Reciever's Phone Number: "<<phoneNumR<<endl;
		cout<<" Date of Delivery: "<<date<<endl;
		cout<<endl;
		cout<<"+==================+"<<endl;
		cout<<"|Reciever's Address|"<<endl;
		cout<<"+==================+"<<endl;
	  cout<<"<=Address=> "<<endl;
		cout<<" City: "<<r->city<<endl;
		cout<<" Street: "<<r->street<<endl;
		cout<<endl;
		cout<<"+=================================+"<<endl;
		cout<<"|Distance Travelled By the Package|"<<endl;
		cout<<"+=================================+"<<endl;
		cout<<"Distance: "<<distance<<" KM"<<endl;
		cout<<"+=========================+"<<endl;
		cout<<"|Path Taken by the Package|"<<endl;
		cout<<"+=========================+"<<endl;
		cout<<"Path: "<<path<<endl;
}
};


////////////////////////////////////////////////////////////////////////////////////////////////
//DIJKSTRA

string nodes[P];

struct dijkstra{
bool visited[P];
string parent[P];
string path[P];
int distance;
string pathString;

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[])
{

	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < P; v++)
		if (visited[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

// A utility function to print the constructed distance array
void display(int dist[])
{
	cout <<"Vertex \t Distance from Source" << endl;
	for (int i = 0; i < P; i++)
		cout << i << " \t\t"<<dist[i]<< endl;
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstraMethod(int graph[P][P], int src, string city){
	addNodeNames();
	parent[0]="/";
	int dist[P]; // The output array. dist[i] will hold the shortest
	// distance from src to i

	// Initialize all distances as INFINITE and visited[] as false
	for (int i = 0; i < P; i++)
		dist[i] = INT_MAX, visited[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < P - 1; count++) {
		// Pick the minimum distance vertex from the set of vertices not
		// yet processed. u is always equal to src in the first iteration.
		int u = minDistance(dist);

		// Mark the picked vertex as visited
		visited[u] = true;

		// Update dist value of the adjacent vertices of the picked vertex.
		for (int v = 0; v < P; v++)

			// Update dist[v] only if is not in visited, there is an edge from
			// u to v, and total weight of path from src to v through u is
			// smaller than current value of dist[v]
			if (!visited[v] && graph[u][v] && dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v]){
				dist[v] = dist[u] + graph[u][v];
				parent[v]=nodes[u];
			}
	}

	// print the constructed distance array
	display(dist);
	distance = distanceFinder(dist, city);
}

void addNodeNames(){
	for(int i=0; i<P; i++){
		cout<<"Enter node "<<i<<" :";
		cin>>nodes[i];
	}
}
int findParentIndex(string s){
for(int i=0; i<P; i++)
	if(nodes[i]==s)
		return i;
}

//a method to find the distance string
string findPathTraveled(string st, string e, string parent[]){
	int index = findParentIndex(e);
	string s = parent[index]+""+e;
	string temp = parent[index];

	while(parent[index]!=st){
		index = findParentIndex(temp);
		s=parent[index]+""+s;
		temp=parent[index];
	}
	return s;
}
int distanceFinder(int dist[], string city){
	for(int i=0; i<P; i++){
		if(nodes[i]==city){
			return dist[i];
		}
	}
}
void dijkstraMain(string destination){
	int graph[P][P] = {
	{0,5,1,4,0,0,0},
	{5,0,0,8,0,6,0},
	{1,0,0,3,2,0,0},
	{4,8,3,0,0,8,0},
	{0,0,2,0,0,7,9},
	{0,6,0,8,7,0,0},
	{0,0,0,0,9,0,0}};
	cout<<"Here"<<endl;
	dijkstraMethod(graph, 0, destination);
	pathString =findPathTraveled(nodes[0],destination, parent);
}
};


////////////////////////////////////////////////////////////////////////////////////////////////



	//client methods
	//1)register
	//2)login
	//3)add a new package for delivery
	//4)view bill associated with a package
	//5)view package's delivery status and if its delivered shows the shortest path it took to be delivered
	//6)can deliver faster by paying more->it will bring the package to start of the packages having same weight


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//priority queue for a package
struct packagePriorityQueue{
int front=-1;
int rear=-1;
int size = 60;
packageClass* arr[60];
void enqueue(packageClass* p){

//condition isempty
packageClass* temp;
if(front==-1){
    front=0;
    rear=0;
    arr[rear]=p;

}else if((rear+1)%size==front){
    cout<<"Queue Full"<<endl;
}else{
    rear=(rear+1)%size;
    //cout<<"Rear: "<<rear<<" X: "<<x<<endl;
    arr[rear]=p;
    int i=rear;
    while(arr[i]->packageID<arr[i-1]->packageID){
            temp=arr[i];
            arr[i]=arr[i-1];
            arr[i-1]=temp;
            i--;
    }
        //cout<<arr[rear]<<endl;

}
}
packageClass* dequeue(){
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
};

void displayAllthePackages(packagePriorityQueue* p){
	packageClass* pc;
for(int i=p->front; i<=p->rear; i++){
	//p->arr[i]->display();
}	
}





















































///////////////////////////////////////////////////////////////////////////////////////////////
struct  AVL
{
	AVL* left = NULL;
	AVL* right = NULL;
	clientClass* c;
	//string name=c->cfname;
	//int id=c->id;
	string name;
	int id;

};
priorityQueue p;
randomNumberGenerator r;
binarySearch b;

//global variable root
AVL* root = NULL;
char cc;
char cp;
int i=0;
//==================//
//prototyping
AVL* insert(AVL* root, AVL* curr);
void inorderDisplay(AVL* a);
void preorderDisplay(AVL* b);
void postorderDisplay(AVL* c);
AVL* rightRotation(AVL* r);
AVL* leftRotation(AVL* r);
int balanceFactor(AVL* r);
AVL * recursiveSearch(AVL * r, string val);
AVL * deleteNode(AVL * r, string v);
AVL * minValueNode(AVL * node);
//===========================//


//insert method
AVL* insert(AVL*p, AVL* curr){
	i=0;
	if(p==NULL){
		p=curr;
		return p;
	}
	//
	int lcurr = curr->name.length();
	int lp = p->name.length();
	int size;
	if(lcurr<lp){
		size=lcurr;
	}else{
		size=lp;
	}
	for(int j=0; j<size-1; j++){
		if(curr->name.at(i) ==  p->name.at(i)){
			i++;
		}
	}
	if( curr->name.at(i) >  p->name.at(i)){
			p->right = insert(p->right, curr);
	}else if(curr->name.at(i) <  p->name.at(i)){
			p->left = insert(p->left, curr);
	}else{
		if(curr->id < p->id){
			p->left = insert(p->left, curr);
		}else{
			p->right = insert(p->right, curr);
		}
	}
	//=================================//
	//     CHECKING FOR IMBALANCE      //
	//=================================//
	//left-left
	if(balanceFactor(p)>1 && curr->name.at(0) < p->name.at(0)){
		return rightRotation(p);
	}
	//right-right
	if(balanceFactor(p)<-1&&curr->name.at(0) > p->name.at(0)){
		return leftRotation(p);
	}
	//left-right
	if(balanceFactor(p)>1&&curr->name.at(0) > p->name.at(0)){
		p->left = leftRotation(p->left);
		return rightRotation(p);
	}
	//right-left
	if(balanceFactor(p)<-1&&curr->name.at(0) < p->name.at(0)){
		p->right = rightRotation(p->right);
		return leftRotation(p);
	}
	return p;
}
//==========================//
void inorderDisplay(AVL*p){
	if(p!=NULL){
		inorderDisplay(p->left);
		p->c->toString();
		//cout<<p->id<<endl;
		inorderDisplay(p->right);

	}
}
//==========================//
void preorderDisplay(AVL*p){
	if(p!=NULL){
		cout<<p->name<<endl;
		preorderDisplay(p->left);
		preorderDisplay(p->right);
	}
}
//==========================//
void postorderDisplay(AVL*p){
	if(p!=NULL){
		postorderDisplay(p->left);	
		postorderDisplay(p->right);
		cout<<p->name<<endl;
	}
	
}
//==========================//
int calculateHeightOfTree(AVL* root){
	//int right=0;
	//int left=0;
	AVL* p =root;
	if(p==NULL){
		return -1;
	}
	else{
		int left=calculateHeightOfTree(p->left);
		int right=calculateHeightOfTree(p->right);
		if(right>left){
			return right+1;
		}
		else if(left>right){
			return left+1;
		}
	
	}
}
//===========================================================================//
int balanceFactor(AVL* p){
	if(p==NULL){
		return -1;
	}else{
		return calculateHeightOfTree(p->left)-calculateHeightOfTree(p->right);
	}
}
//===========================================================================//
AVL* rightRotation(AVL* y){
	//creating 2 pointers
	AVL* x = y->left;
	AVL* t2 = x->right;

	//rotation
	y->left = t2;
	x->right=y;
	return x;
}
//===========================================================================//
AVL* leftRotation(AVL* x){
	//creating 2 pointers
	AVL* y = x->right;
	AVL* t2 = y->left;

	//rotation
	x->right=t2;
	y->left = x;

	return y;
}


//=============================================================//
//deletion of a node
 AVL * deleteNode(AVL * r, int id) {
    // base case 
    if (r == NULL) {
      return NULL;
    }
    else if (id < r -> id) {
    	cout<<"here1"<<endl;
      r -> left = deleteNode(r -> left, id);
    }
    else if (id > r -> id) {
    	cout<<"here2"<<endl;
      r -> right = deleteNode(r -> right, id);
    }
    // if key is same as root's key, then This is the node to be deleted 
    else {
      // node with only one child or no child 
      if (r -> left == NULL) {
        AVL * temp = r -> right;
        delete r;
        return temp;
      } else if (r -> right == NULL) {
        AVL * temp = r -> left;
        delete r;
        return temp;
      } else {
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        AVL * temp = minValueNode(r -> right);
        // Copy the inorder successor's content to this node 
        r -> name = temp -> name;
        // Delete the inorder successor 
        r -> right = deleteNode(r -> right, temp->id);
        //deleteNode(r->right, temp->name); 
      }
    }

    int bf = balanceFactor(r);
    // Left Left Imbalance/Case or Right rotation 
    if (bf == 2 && balanceFactor(r -> left) >= 0)
      return rightRotation(r);
    // Left Right Imbalance/Case or LR rotation 
    else if (bf == 2 && balanceFactor(r -> left) == -1) {
      r -> left = leftRotation(r -> left);
      return rightRotation(r);
    }
    // Right Right Imbalance/Case or Left rotation	
    else if (bf == -2 && balanceFactor(r -> right) <= -0)
      return leftRotation(r);
    // Right Left Imbalance/Case or RL rotation 
    else if (bf == -2 && balanceFactor(r -> right) == 1) {
      r -> right = rightRotation(r -> right);
      return leftRotation(r);
    }

    return r;
  }

   AVL * recursiveSearch(AVL * r, string val, int d) {
   	//cout<<val<<" "<<d<<endl;
    if (r == NULL || (r -> name == val && r->id==d))
      return r;
    else if (val.at(0) < r -> name.at(0))
      return recursiveSearch(r -> left, val, d);
    else if (val.at(0) > r -> name.at(0))
      return recursiveSearch(r -> right, val, d);
    else if(d < r->id)
    	return recursiveSearch(r -> left, val, d);
    else if(d > r->id)
    	return recursiveSearch(r -> right, val, d);
  }

     AVL * recursiveSearchPackage(AVL * r, string val, int d) {
   	//cout<<val<<" "<<d<<endl;
    if (r == NULL || (r -> name == val && r->id==d))
      return r;
    else if (val.at(0) < r -> name.at(0))
      return recursiveSearch(r -> left, val, d);
    else if (val.at(0) > r -> name.at(0))
      return recursiveSearch(r -> right, val, d);
    else if(d < r->id)
    	return recursiveSearch(r -> left, val, d);
    else if(d > r->id)
    	return recursiveSearch(r -> right, val, d);
  }


  AVL * minValueNode(AVL * node) {
    AVL * current = node;
    /* loop down to find the leftmost leaf */
    while (current -> left != NULL) {
      current = current -> left;
    }
    return current;
  }


///////////////////////////////////////////////////////////////////////////////////////////
//ADMIN FUNCTIONS
void viewClientDetails(){
					string name;
					int id;
					string pass;
					cout<<"Enter customer's name: ";
					cin>>name;
					cout<<"Enter customer's id: ";
					cin>>id;
					AVL* n = recursiveSearch(root,name,id);

					if(n==NULL){
					cout<<"Customer Details not Found"<<endl;
					}else{
						n->c->toString();
						displayAllthePackages(n->c->p);
					}

}
void deletingClient(){
				string val;
				int id;
				cout << "Enter name to DELETE in AVL: ";
      	cin >> val;
 				cout << "Enter id to DELETE in AVL: ";
      	cin >> id;     		
     		AVL* new_node = recursiveSearch(root, val, id);
      	if (new_node != NULL) {
        root = deleteNode(root,id);
        cout << "Value Deleted" << endl;
      	} else if(new_node==NULL){
        cout << "Value NOT found" << endl;
      	}
}

bool customerLogin(){
					string name;
					int id;
					string pass;
					bool success = false;
					cout<<"Enter customer's name: ";
					cin>>name;
					cout<<"Enter customer's id: ";
					cin>>id;
					cout<<"Enter password: ";
					cin>>pass;
					AVL* n = recursiveSearch(root,name,id);

					if(n==NULL){
					cout<<"Customer Details not Found"<<endl;
					}else{

					while(n->c->password!=pass){
					cout<<"Enter password again: ";
					cin>>pass;	
					 if(n->c->password==pass){
						cout<<"Login Successful"<<endl;
						success=true;
						break;
					}else if(n->c->password!=pass){
						cout<<"Incorrect Password"<<endl;
					}				
					}if(n->c->password==pass)
					success=true;
				}
return success;
}

clientClass* customerRegistration(){
				Address* a ;
				clientClass* c ;
				priorityQueue p;
				string fname;
				string lname;
				string city;
				string street;
				string pass;
				int pn;

				cout<<"Enter First Name: ";
				cin>>fname;
				cout<<"Enter Last Name: ";
				cin>>lname;
				cout<<"Enter Phone Number: ";
				cin>>pn;
				cout<<"Enter City: ";
				cin>>city;
				cout<<"Enter Street: ";
				cin>>street;
				cout<<"Enter Password: ";
				cin>>pass;

				//////////////////////////////
				//id auto generated
				int id =r.randNum();
				if(p.front==-1){
					cout<<"hmm"<<endl;
					p.enqueue(id);
				}else{
				while(b.Search(p.arr,id,p.front,p.rear)==true){
					id =r.randNum();
				}
				p.enqueue(id);
			}
			////////////////////////////////
				a= new Address();
				c= new clientClass();


				 a->street=street;
				 a->city=city;

				 c->cfname=fname;
				 c->clname=lname;
				 c->phoneNumC=pn;
				 c->c=a;
				 c->id=id;
				 c->password=pass;
				
				AVL* curr = new AVL();
				curr->c=c;
				curr->name = fname;
				curr->id = id;

				c->toString();
				root=insert(root, curr);
		return c;
}

bool adminLogin(){
					string name;
					string pass;
					bool success = false;
					cout<<"Enter admin name: ";
					cin>>name;
					cout<<"Enter admin password: ";
					cin>>pass;

					while(pass!="admin"||name!="admin"){
						if(pass!="admin"){
						cout<<"Enter password again: ";
						cin>>pass;	
						}
						if(name!="admin"){
						cout<<"Enter name again: ";
						cin>>name;	
						}
					 if(pass=="admin"&&name=="admin"){
						cout<<"Login Successful"<<endl;
						success=true;
					}			
					}
						if(pass=="admin"&&name=="admin"){
						cout<<"Login Successful"<<endl;
						success=true;
					}
return success;
}
//================================================================//
void addPackageForDelivery(packageClass* p, clientClass* c){

	dijkstra* d=new dijkstra();
	Address* a=new Address();
	priorityQueue q;
	string city;
	time_t t = time(NULL);
 	tm* tPtr = localtime(&t);
 	p->date = to_string(tPtr->tm_mday)+""+ to_string((tPtr->tm_mon)+1)+""+to_string((tPtr->tm_year)+1900);

	cout<<"Enter Package Name: ";
	cin>>p->packageName;
	cout<<"Weight of the Package: ";
	cin>>p->weight;
	//////////////////////////////
	//id auto generated
	p->packageID =r.randNum();
	if(q.front==-1){
	//cout<<"hmm"<<endl;
	q.enqueue(p->packageID);
	}else{
		while(b.Search(q.arr,p->packageID,q.front,q.rear)==true){
				p->packageID =r.randNum();
			}
			q.enqueue(p->packageID);
	}
	////////////////////////////////
	cout<<"Enter Reciever's First Name: ";
	cin>>p->rfname;
	cout<<"Enter Reciever's Last Name: ";
	cin>>p->rlname;
	cout<<"Enter Reciever's Phone Number: ";
	cin>>p->phoneNumR;
	cout<<"Enter city for delivery: ";
	cin>>a->city;
	cout<<"Enter street for delivery: ";
	cin>>a->street;
	p->r=a;

	//distance travelled generated using dijkstra
	//cout<<"herehereheerheh"<<endl;
	d->dijkstraMain(p->r->city);
	p->distance=d->distance;
	p->path=d->pathString;
	cout<<"here12"<<endl;
	c->p->enqueue(p);
}
//================================================================//
void displayBillByPackageId(){}
void viewPackageDeliveryStatus(){}



menuMain(){
	cout<<"1. Admin Login"<<endl;
	cout<<"2. Customer Login"<<endl;
	cout<<"3. Customer Registeration"<<endl;
	cout<<"0. To Exit"<<endl;
}
menuAdmin(){
	cout<<"1. View Client Details"<<endl;
	cout<<"2. Check if a Package has been Delivered"<<endl;
	cout<<"3. Remove a Package from Delivery Queue"<<endl;
	cout<<"4. Deleting a Client"<<endl;
}
menuCustomer(){
	cout<<"1. Add a new Package for Delivery"<<endl;
	cout<<"2. Display Bill by Package ID"<<endl;
	cout<<"3. View Package Delivery Status"<<endl;
}








///////////////////////////////////////////////////////////////////////////////////////////
//Main
int main(int argc, char const *argv[])
{

menuMain();
int choiceMm;
cout<<"Choice: ";
cin>>choiceMm;

while(choiceMm!=0){
	switch(choiceMm){
		//admin
		case 1:{
			if(adminLogin()==true){
				menuAdmin();
				int choicemA;
				cout<<"Choice: ";
				cin>>choicemA;
				while(choicemA!=0){
				////////
				switch(choicemA){
				case 1:{viewClientDetails(); }break;
				case 2:{}break;
				case 3:{}break;
				//deleting a client
				case 4:{deletingClient();}break;
				}
				menuAdmin();
				cout<<"Choice for Admin: ";
				cin>>choicemA;
			}
			}else if(adminLogin()==false){cout<<"Login Failed";}

		}break;
		//======================================//
		//customer login
		case 2:{
		if(customerLogin()==true){
		//now displaying customer's optionsz
		menuCustomer();
		int choicemC;
		cout<<"Choice: ";
		cin>>choicemC;
		while(choicemC!=0){
			switch(choicemC){
				case 1:{}break;
				case 2:{}break;
				case 3:{}break;
			}
			menuCustomer();
			cout<<"Choice for menuCustomer: ";
			cin>>choicemC;
		}
			}else {cout<<"Login Failed"<<endl;}
		}break;
	//============================================//
	//customer registration
	case 3:{
  clientClass* cc = customerRegistration();
	//menu for customers
	menuCustomer();
	int choicemC;
	cout<<"Choice: ";
	cin>>choicemC;
	while(choicemC!=0){
			switch(choicemC){
				case 1:{
					packageClass* p = new packageClass();
					addPackageForDelivery(p,cc);
					p->toString(cc);
				}break;
				case 2:{displayBillByPackageId();}break;
				case 3:{viewPackageDeliveryStatus();}break;
			}
	menuCustomer();
	cout<<"Choice for menuCustomer: ";
	cin>>choicemC;
	}

	}break;
	}
	menuMain();
	cout<<"Choice for Main Menu: ";
	cin>>choiceMm;
}













}
///////////////////////////////////////////////////////////////////////////////////////////
