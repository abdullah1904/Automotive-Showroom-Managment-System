#include <iostream>
#include <Windows.h>
#include <string>
#include <stdlib.h>
#include "Showroom.h"
using namespace std;
// Utility Functions Definations
void setColor(int code) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), code);
}
void header(){
	cout << "  --: Automotive Showroom :--" << endl;
}
void clear(){
	system("cls");
}
// Authorization Class Definations
user::user(string u, string p){
	this->username=u;
	this->password=p;
}
bool user::check(string u, string p){
	return u == this->username && p == this->password ? true :  false;
}
string user::getUserName() {
	return username;
}
string user::getPassword() {
	return password;
}
// Vehicle Class Definations
vehicle::vehicle(string c, string m, int ec, int p){
	this->company = c;
	this->model = m;
	this->engineCapacity = ec;
	this->price = p;
}
// Car Class Definations
Car::Car(string c, string m, string f, string t, int ec, int p, int y):vehicle(c,m,ec,p){
	this->fuelType = f;
	this->transmission = t;
	this->yearOfManufacture = y;
}
void Car::get(){
	cout<<" -- Enter Car Details :--"<<endl<<endl;
	cout<<"Enter Car Company: ";
	getline(cin>>ws,this->company);
	cout<<"Enter Car Model: ";
	getline(cin>>ws,this->model);
	cout<<"Enter Car Fuel Type: ";
	getline(cin>>ws,this->fuelType);
	cout<<"Enter Car Transmission: ";
	getline(cin>>ws,this->transmission);
	cout<<"Enter Car Engine Capacity: ";
	cin>>this->engineCapacity;
	cout<<"Enter Car Year of Manufacture: ";
	cin>>this->yearOfManufacture;
	cout<<"Enter Car Price: ";
	cin>>this->price;
}
void Car::display(){
	cout<<"  --: Car Details :-- "<<endl<<endl;
	cout<<"Car Company: "<<this->company<<endl;
	cout<<"Car Model: "<<this->model<<endl;
	cout<<"Car Price: "<<this->price<<endl;
	cout<<"Car Fuel Type: "<<this->fuelType<<endl;
	cout<<"Car Transmission: "<<this->transmission<<endl;
	cout<<"Car Engine Capacity: "<<this->engineCapacity<<endl;
	cout<<"Car Year of Manufacture: "<<this->yearOfManufacture<<endl;
}
// Showroom Class Definations
showRoom::showRoom(string o, string c) {
	this->owner = o;
	this->city = c;
	users.push_back(user("Abdullah", "abdullah1904"));
	users.push_back(user("Mahreen", "mahreen"));
	users.push_back(user("Sufiyan", "sufiyan"));
	cars.push_back(Car("Mercedes Benz","S Class","Electric","Automatic",1200,5110000,2023));
}
bool showRoom::login(){
	string n,p;
	setColor(9);
	header();
	setColor(10);
	cout<<"Welcome! Enter Username and Password"<<endl<<endl;
	setColor(9);
	cout<<"Enter Username: ";
	setColor(10);
	getline(cin>>ws,n);
	setColor(9);
	cout<<"Enter Password: ";
	setColor(10);
	getline(cin>>ws,p);
	for(int i =0;i<users.size();i++){
		if(users[i].check(n, p)) {
			return true;
		}
	}
	return false;
}
void showRoom::menu(){
	char dummy;
	menu:
	clear();
	setColor(3);
	header();
	setColor(15);
	cout<<"  --: MENU :--"<<endl<<endl;
	setColor(3); cout<<"A)"; setColor(15); cout<<" Billing"<<endl;
	setColor(3); cout<<"B)"; setColor(15); cout<<" Cars"<<endl;
	setColor(3); cout<<"C)"; setColor(15); cout<<" Bikes"<<endl;
	setColor(3); cout<<"D)"; setColor(15); cout<<" Users"<<endl;
	setColor(3); cout<<"E)"; setColor(15); cout<<" About"<<endl;
	setColor(3); cout<<"F)"; setColor(15); cout<<" Exit"<<endl<<endl;
	setColor(3); cout<<"Select Option: "; 
	setColor(15);
	cin>>dummy;
	switch (dummy){
		case 'a':
		case 'A': this->bill();
		break;
		case 'b':
		case 'B': this->car();
		break;
		case 'c':
		case 'C': this->bike();
		break;
		case 'd':
		case 'D': this->User();
		break;
		case 'e':
		case 'E': this->about();
		break;
		case 'f':
		case 'F': clear(); exit(0);
		break;
		default: clear(); setColor(4); cout << "Invalid Option! Enter Valid option..." << endl; setColor(15); system("pause");
	}
	goto menu;
}
void showRoom::bill(){
	char dummy;
	bill:
	clear();
	setColor(3);
	header();
	setColor(15);
	cout<<"  --: BILLING :--"<<endl<<endl;
	cout<<"Select the Vehicle which Customer Purchased: "<<endl;;
	setColor(7); cout<<"A)"; setColor(12); cout<<" Car"<<endl;
	setColor(7); cout<<"B)"; setColor(12); cout<<" Bike"<<endl;
	setColor(7); cout<<"C)"; setColor(12); cout<<" Print Bill"<<endl;
	setColor(7); cout<<"D)"; setColor(12); cout<<" Go Back to Menu"<<endl<<endl;
	setColor(7); cout<<"Select Option: "; 
	setColor(12); cin>>dummy;
	switch (dummy){
		case 'a':
		case 'A': ;
		break;
		case 'b':
		case 'B': ;
		break;
		case 'c':
		case 'C': ;
		break;
		case 'd':
		case 'D': return;
		break;
		default: clear(); setColor(4); cout << "Invalid Option! Enter Valid option..." << endl; setColor(15); system("pause");
	}
	goto bill;
}
void showRoom::car(){
	char dummy;
	cars:
	clear();
	setColor(7);
	header();
	setColor(12);
	cout<<"  --: CARS :--"<<endl<<endl;
	setColor(7); cout<<"A)"; setColor(12); cout<<" Add Car"<<endl;
	setColor(7); cout<<"B)"; setColor(12); cout<<" Show Cars"<<endl;
	setColor(7); cout<<"C)"; setColor(12); cout<<" Search Car"<<endl;
	setColor(7); cout<<"D)"; setColor(12); cout<<" Delete Car"<<endl;
	setColor(7); cout<<"E)"; setColor(12); cout<<" Update Car"<<endl;
	setColor(7); cout<<"F)"; setColor(12); cout<<" Go Back to Menu"<<endl<<endl;
	setColor(7); cout<<"Select Option: "; 
	setColor(12);
	cin>>dummy;
	switch (dummy){
		case 'a':
		case 'A': ;
		break;
		case 'b':
		case 'B': ;
		break;
		case 'c':
		case 'C': ;
		break;
		case 'd':
		case 'D': ;
		break;
		case 'e':
		case 'E': ;
		break;
		case 'f':
		case 'F': return;
		break;
		default: clear(); setColor(4); cout << "Invalid Option! Enter Valid option..." << endl; setColor(15); system("pause");
	}
	goto cars;
}
void showRoom::bike(){
	char dummy;
	bikes:
	clear();
	setColor(7);
	header();
	setColor(12);
	cout<<"  --: BIKES :--"<<endl<<endl;
	setColor(7); cout<<"A)"; setColor(12); cout<<" Add Bike"<<endl;
	setColor(7); cout<<"B)"; setColor(12); cout<<" Show Bikes"<<endl;
	setColor(7); cout<<"C)"; setColor(12); cout<<" Search Bike"<<endl;
	setColor(7); cout<<"D)"; setColor(12); cout<<" Delete Bike"<<endl;
	setColor(7); cout<<"E)"; setColor(12); cout<<" Update Bike"<<endl;
	setColor(7); cout<<"F)"; setColor(12); cout<<" Go Back to Menu"<<endl<<endl;
	setColor(7); cout<<"Select Option: "; 
	setColor(12);
	cin>>dummy;
	switch (dummy){
		case 'a':
		case 'A': ;
		break;
		case 'b':
		case 'B': ;
		break;
		case 'c':
		case 'C': ;
		break;
		case 'd':
		case 'D': ;
		break;
		case 'e':
		case 'E': ;
		break;
		case 'f':
		case 'F': return;
		break;
		default: clear(); setColor(4); cout << "Invalid Option! Enter Valid option..." << endl; setColor(15); system("pause");
	}
	goto bikes;
}
void showRoom::User(){
	char dummy;
	Users:
	clear();
	setColor(7);
	header();
	setColor(12);
	cout<<"  --: USERS :--"<<endl<<endl;
	setColor(7); cout<<"A)"; setColor(12); cout<<" Add User"<<endl;
	setColor(7); cout<<"B)"; setColor(12); cout<<" Show Users"<<endl;
	setColor(7); cout<<"C)"; setColor(12); cout<<" Search User"<<endl;
	setColor(7); cout<<"D)"; setColor(12); cout<<" Delete User"<<endl;
	setColor(7); cout<<"E)"; setColor(12); cout<<" Go Back to Menu"<<endl<<endl;
	setColor(7); cout<<"Select Option: "; 
	setColor(12);
	cin>>dummy;
	switch (dummy){
		case 'a':
		case 'A': ;
		break;
		case 'b':
		case 'B': ;
		break;
		case 'c':
		case 'C': ;
		break;
		case 'd':
		case 'D': ;
		break;
		case 'e':
		case 'E': return;
		break;
		default: clear(); setColor(4); cout << "Invalid Option! Enter Valid option..." << endl; setColor(15); system("pause");
	}
	goto Users;
}
void showRoom::about(){
	clear();
	setColor(3);
	header();
	setColor(15);
	cout<<"  --: About Showroom :--"<<endl<<endl;
	cout<<"Owner Name: "<<this->owner<<"\t\t\t"<<"Showroom Station: "<<this->city<<endl;
	cout<<"Share Holder: Ms. Mahreen Farooq\tPartner: Mr. Mirza Sufiyan Ahmad"<<endl<<endl;
	cout<<"Total Number of Cars: "<<cars.size()<<"\t\t\t"<<"Total Number of Bikes: "<<"N/A"<<endl<<endl;
	system("pause");
	return;
}