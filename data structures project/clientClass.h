#ifndef CLIENTCLASS_H
#define CLIENTCLASS_H
#include <iostream>
#include "Address.h"
#include "packageClass.h"
# define V 60
using namespace std;

class clientClass{
public:
	//client
	string cfname;
	string clname;
	int phoneNumC;
	int id;
	Address c;
	packageClass p[V];
	//reciever
	string rfname;
	string rlname;
	int phoneNumR;
	Address r;

public:
	void setRPhoneNum(int pn){
		phoneNumR=pn;
	}
	void setSPhoneNum(int pn){
		phoneNumC=pn;
	}
	void setSendersAddress(Address a){
		c=a;
	}
	void setRecieversAddress(Address a){
		r=a;
	}
	string getName(){
		return cfname+" "+clname;
	}
	string getid(){
		return id;
	}
	string getRecieversName(){
		return cfname+" "+clname;
	}
	Address getSendersAddress(){
		return c;
	}

	Address getReceiversAddress(){
		return r;
	}

	//client methods
	//1)register
	//2)login
	//3)add a new package for delivery
	//4)view bill associated with a package
	//5)view package's delivery status and if its delivered shows the shortest path it took to be delivered
	//6)can deliver faster by paying more->it will bring the package to start of the packages having same weight

};
#endif