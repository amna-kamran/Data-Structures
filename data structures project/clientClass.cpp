#include <iostream>
#include "Address.h"
#include "PackageClass.h"
using namespace std;

class clientClass{
private:
	//client
	string cfname;
	string clname;
	int phoneNum;
	Address c;
	PackageClass p;
	//reciever
	string rfname;
	string rlname;
	int phoneNum;
	Address r;

public:
	void setPhoneNum(string pn){
		phoneNum=pn;
	}
	void setAddress(Address a){
		c=s;
	}
	string getSendersName(){
		return cfname+" "+clname;
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

}