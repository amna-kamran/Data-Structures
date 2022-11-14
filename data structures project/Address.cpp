
#include <iostream>
using namespace std;

class Address{
public:

	string street;
	string city;

//constructors
	Address(){

		street="";
		city="";
	}
	Address(string s,string c){

		street=s;
		city=c;
	}


	void setStreet(string s){
		street=s;
	}
	void setCity(string c){
		city=c;
	}
	string getStreet(){
		return street;
	}
	string getCity(){
		return city;
	}
};

int main(int argc, char const *argv[])
{
	Address a = new Address();
	return 0;
}