#include <iostream>
using namespace std;

class packageClass{
public:
	string packageName;
	double weight;
	Date date;
	int packageID;

void generateBill(clientClass c){
	//200 per kg
	int cost=200*weight;

	cout<<"+===========================================+"<<endl;
	cout<<"|            Bill Details                   |"<<endl;
	cout<<"+===========================================+"<<endl;
	cout<<"|   Package Name: "+<<packageName<<"        |"<<endl;
	cout<<"|   PackageID:    "+<<packageID<<"          |"<<endl;
	cout<<"|   Cost per Kg: "+<<cost<<"                |"<<endl;
	cout<<"|   Sender's Address: "<<c.getc().getCity()<<"|"<<endl;
	cout<<"|                     "<<c.getc().getStreet()<<"|"<<endl;
	cout<<"|                     "<<c.getc().getHome()<<"|"<<endl;
}
}