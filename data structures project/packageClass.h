#ifndef PACKAGECLASS_H
#define PACKAGECLASS_H
#include <iostream>
#include "Date.h"
#include "clientClass.h"
using namespace std;

class packageClass{
public:
	string packageName;
	double weight;
	Date date;
	int packageID;
	int distance;

void generateBill(string c, string s, string h){
	//200 per kg
	int cost=200*weight;

	cout<<"+===========================================+"<<endl;
	cout<<"|            Bill Details                   |"<<endl;
	cout<<"+===========================================+"<<endl;
	cout<<"|   Package Name: "<<packageName<<"        |"<<endl;
	cout<<"|   PackageID:    "<<packageID<<"          |"<<endl;
	cout<<"|   Cost per Kg: "<<cost<<"                |"<<endl;
	cout<<"|   Sender's Address: "<<c<<"|"<<endl;
	cout<<"|                     "<<s<<"|"<<endl;
	cout<<"|                     "<<h<<"|"<<endl;
}
};
#endif