
#include <iostream>
#include "binarySearch.h"
#include "randomNumberGenerator.h"
#include "priorityQueue.h"
using namespace std;

//creating a linked list

struct  AVL
{
	AVL* left = NULL;
	AVL* right = NULL;
	string name;
	int id;

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
		cout<<p->name<<endl;
		cout<<p->id<<endl;
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
menu(){
	cout<<"1 insert"<<endl;
	cout<<"2 display inorder"<<endl;
	cout<<"3 delete"<<endl;
}

//=============================================================//
//deletion of a node
 AVL * deleteNode(AVL * r, string v) {
    // base case 
    if (r == NULL) {
      return NULL;
    }
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    else if (v.at(0) < r -> name.at(0)) {
      r -> left = deleteNode(r -> left, v);
    }
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (v.at(0) > r -> name.at(0)) {
      r -> right = deleteNode(r -> right, v);
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
        r -> right = deleteNode(r -> right, temp -> name);
        //deleteNode(r->right, temp->data); 
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

   AVL * recursiveSearch(AVL * r, string val) {
    if (r == NULL || r -> name == val)
      return r;

    else if (val.at(0) < r -> name.at(0))
      return recursiveSearch(r -> left, val);

    else
      return recursiveSearch(r -> right, val);
  }


  AVL * minValueNode(AVL * node) {
    AVL * current = node;
    /* loop down to find the leftmost leaf */
    while (current -> left != NULL) {
      current = current -> left;
    }
    return current;
  }

};
/*
int main(int argc, char const *argv[])
{
	menu();
	int choice;
	cout<<"Enter choice: ";
	cin>>choice;

	do{
		switch(choice){
			case 1: {
				AVL* curr = new AVL();
				cout<<"Enter name: ";
				cin>>curr->name;
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
			curr->id = id;

				root=insert(root, curr);} break;
			case 2: {inorderDisplay(root);} break;
			case 3:{
			string val;
			cout << "Enter VALUE of TREE NODE to DELETE in AVL: ";
      		cin >> val;
     		AVL* new_node = recursiveSearch(root, val);
      		if (new_node != NULL) {
        	root = deleteNode(root, val);
        	cout << "Value Deleted" << endl;
      		} else {
        	cout << "Value NOT found" << endl;
      		}
      		break;
			}
		}
		menu();
		cout<<"Enter choice: ";
		cin>>choice;

	}while(choice!=0);
	return 0;
}
*/

#endif