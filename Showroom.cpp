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
void user::set(string u ,string p){
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
void vehicle::set(string c, string m, int ec,int p){
	this->company = c;
	this->model = m;
	this->engineCapacity = ec;
	this->price = p;
}
// Car Class Definations
car::car(string c, string m, string f, string t, int ec, int p, int y):vehicle(c,m,ec,p){
	this->fuelType = f;
	this->transmission = t;
	this->yearOfManufacture = y;
}
void car::get(){
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
void car::display(){
	cout<<"  --: Car Details :-- "<<endl<<endl;
	cout<<"Car Company: "<<this->company<<endl;
	cout<<"Car Model: "<<this->model<<endl;
	cout<<"Car Price: "<<this->price<<endl;
	cout<<"Car Fuel Type: "<<this->fuelType<<endl;
	cout<<"Car Transmission: "<<this->transmission<<endl;
	cout<<"Car Engine Capacity: "<<this->engineCapacity<<endl;
	cout<<"Car Year of Manufacture: "<<this->yearOfManufacture<<endl;
}
void car::set(string c, string m, string f, string t, int ec, int p, int y){
	vehicle::set(c,m,ec,p);
	this->fuelType = f;
	this->transmission = t;
	this->yearOfManufacture = y;
}
// Showroom Class Definations
showRoom::showRoom(string o, string c) {
	this->owner = o;
	this->city = c;
	users.push_back(user("Abdullah", "abdullah1904"));
	users.push_back(user("Mahreen", "mahreen"));
	users.push_back(user("Sufiyan", "sufiyan"));
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
char showRoom::menu(){
	char dummy;
	menu:
	clear();
	setColor(3);
	header();
	setColor(15);
	cout<<"  --: MENU :--"<<endl;
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
		case 'F': exit(0);
		break;
		default: clear(); setColor(4); cout << "Invalid Option! Enter Valid option..." << endl; setColor(15); system("pause");
	}
	goto menu;
}