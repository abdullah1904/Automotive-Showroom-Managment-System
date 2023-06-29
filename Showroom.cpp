#include "Showroom.h"
#include <string>
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
using namespace std;
// Utility Functions Definations
void setColor(int code) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), code);
}
void header(){
	cout<<"                _                        _   _              _____ _                                             "<<endl;
	cout<<"     /\\        | |                      | | (_)            / ____| |                                          "<<endl;
	cout<<"    /  \\  _   _| |_ ___  _ __ ___   ___ | |_ ___   _____  | (___ | |__   _____      ___ __ ___   ___  _ __ ___  "<<endl;
	cout<<"   / /\\ \\| | | | __/ _ \\| '_ ` _ \\ / _ \\| __| \\ \\ / / _ \\  \\___ \\| '_ \\ / _ \\ \\ /\\ / / '__/ _ \\ / _ \\| '_ ` _ \\ "<<endl;
	cout<<"  / ____ \\ |_| | || (_) | | | | | | (_) | |_| |\\ V /  __/  ____) | | | | (_) \\ V  V /| | | (_) | (_) | | | | | |"<<endl;
	cout<<" /_/    \\_\\__,_|\\__\\___/|_| |_| |_|\\___/ \\__|_| \\_/ \\___| |_____/|_| |_|\\___/ \\_/\\_/ |_|  \\___/ \\___/|_| |_| |_|"<<endl;
	cout << endl;
}
void clear(){
	system("cls");
}
void printBill(vector<Car> C, vector<Bike> B){
	string name;
	int total = 0;
	clear();
	setColor(7);
	header();
	setColor(12);
	cout<<"  --: BILL :--"<<endl<<endl;
	setColor(12);cout<<"Enter Customer Name: ";setColor(7);getline(cin>>ws,name);
	clear();
	setColor(7);
	header();
	setColor(12);
	cout<<"  --: BILL :--"<<endl<<endl;
	setColor(12);cout<<"Customer Name: ";setColor(7);cout<<name<<endl<<endl;
	setColor(12);cout<<"Cars: "<<endl;
	for(int i =0; i<C.size();i++){
		total += C[i].getPrice();
		cout<<i+1<<endl<<"\t";
		setColor(12);cout<<"Car Company: ";setColor(7);cout<<C[i].getCompany()<<endl;
		cout<<"\t";
		setColor(12);cout<<"Car Model: ";setColor(7);cout<<C[i].getModel()<<endl;
		cout<<"\t";
		setColor(12);cout<<"Car Price: ";setColor(7);cout<<C[i].getPrice()<<endl;
	}
	setColor(12);cout<<endl<<"Bikes: "<<endl;
	for(int i =0; i<B.size();i++){
		total += B[i].getPrice();
		cout<<i+1<<endl<<"\t";
		setColor(12);cout<<"Bike Company: ";setColor(7);cout<<C[i].getCompany()<<endl;
		cout<<"\t";
		setColor(12);cout<<"Bike Model: ";setColor(7);cout<<C[i].getModel()<<endl;
		cout<<"\t";
		setColor(12);cout<<"Bike Price: ";setColor(7);cout<<C[i].getPrice()<<endl;
	}
	cout<<endl;
	setColor(12);cout<<"Total No. of Items: ";setColor(7);cout<<C.size()+B.size()<<endl;
	setColor(12);cout<<"Total Price: ";setColor(7);cout<<total<<endl;
	setColor(12);
	cout<<"\n\t -------------------------------------------------- \t\n"<<endl;
	system("pause");
	return;
}
// Authorization Class Definations
user::user(string u, string p){
	this->username=u;
	this->password=p;
}
void user::set(string u,string p){
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
vehicle::vehicle(string c, string m, string col,int ec, int p){
	this->company = c;
	this->model = m;
	this->color = col;
	this->engineCapacity = ec;
	this->price = p;
}
string vehicle::getCompany(){
	return this->company;
}
string vehicle::getModel(){
	return this->model;
}
int vehicle::getPrice(){
	return this->price;
}
// Car Class Definations
Car::Car(string c, string m, string col, string f, string t, int ec, int p, int y):vehicle(c,m,col,ec,p){
	this->fuelType = f;
	this->transmission = t;
	this->yearOfManufacture = y;
}
void Car::set(Car o){
	this->company = o.company;
	this->model = o.model;
	this->color = o.color;
	this->engineCapacity = o.engineCapacity;
	this->price = o.price;
	this->fuelType = o.fuelType;
	this->transmission = o.transmission;
	this->yearOfManufacture = o.yearOfManufacture;
}
void Car::get(){
	setColor(7);
	cout<<" -- Enter Car Details :--"<<endl<<endl;
	setColor(7);cout<<"Enter Car Company: ";
	setColor(12);getline(cin>>ws,this->company);
	setColor(7);cout<<"Enter Car Model: ";
	setColor(12);getline(cin>>ws,this->model);
	setColor(7);cout<<"Enter Car Color: ";
	setColor(12);getline(cin>>ws,this->color);
	setColor(7);cout<<"Enter Car Fuel Type: ";
	setColor(12);getline(cin>>ws,this->fuelType);
	setColor(7);cout<<"Enter Car Transmission: ";
	setColor(12);getline(cin>>ws,this->transmission);
	setColor(7);cout<<"Enter Car Engine Capacity: ";
	setColor(12);cin>>this->engineCapacity;
	setColor(7);cout<<"Enter Car Year of Manufacture: ";
	setColor(12);cin>>this->yearOfManufacture;
	setColor(7);cout<<"Enter Car Price: ";
	setColor(12);cin>>this->price;
}
void Car::display(){
	setColor(7);
	cout<<"  --: Car Details :-- "<<endl<<endl;
	setColor(7);cout<<"Car Company: ";setColor(12);cout<<this->company<<endl;
	setColor(7);cout<<"Car Model: ";setColor(12);cout<<this->model<<endl;
	setColor(7);cout<<"Car Price: ";setColor(12);cout<<this->price<<endl;
	setColor(7);cout<<"Car Fuel Type: ";setColor(12);cout<<this->fuelType<<endl;
	setColor(7);cout<<"Car Transmission: ";setColor(12);cout<<this->transmission<<endl;
	setColor(7);cout<<"Car Engine Capacity: ";setColor(12);cout<<this->engineCapacity<<endl;
	setColor(7);cout<<"Car Year of Manufacture: ";setColor(12);cout<<this->yearOfManufacture<<endl;
}
// Bike Class Definations 
Bike::Bike(string c, string m, string col, int ec, int p, int y):vehicle(c,m,col,ec,p){
	this->yearOfManufacture = y;
}
void Bike::set(Bike o){
	this->company = o.company;
	this->model = o.model;
	this->color = o.color;
	this->engineCapacity = o.engineCapacity;
	this->price = o.price;
	this->yearOfManufacture = o.yearOfManufacture;
}
void Bike::get(){
	setColor(7);
	cout<<" -- Enter Bike Details :--"<<endl<<endl;
	setColor(7);cout<<"Enter Bike Company: ";
	setColor(12);getline(cin>>ws,this->company);
	setColor(7);cout<<"Enter Bike Model: ";
	setColor(12);getline(cin>>ws,this->model);
	setColor(7);cout<<"Enter Bike Color: ";
	setColor(12);getline(cin>>ws,this->color);
	setColor(7);cout<<"Enter Bike Engine Capacity: ";
	setColor(12);cin>>this->engineCapacity;
	setColor(7);cout<<"Enter Bike Year of Manufacture: ";
	setColor(12);cin>>this->yearOfManufacture;
	setColor(7);cout<<"Enter Bike Price: ";
	setColor(12);cin>>this->price;
}
void Bike::display(){
	setColor(7);
	cout<<"  --: Bike Details :-- "<<endl<<endl;
	setColor(7);cout<<"Bike Company: ";setColor(12);cout<<this->company<<endl;
	setColor(7);cout<<"Bike Model: ";setColor(12);cout<<this->model<<endl;
	setColor(7);cout<<"Bike Price: ";setColor(12);cout<<this->price<<endl;
	setColor(7);cout<<"Bike Engine Capacity: ";setColor(12);cout<<this->engineCapacity<<endl;
	setColor(7);cout<<"Bike Year of Manufacture: ";setColor(12);cout<<this->yearOfManufacture<<endl;
}
// Showroom Class Definations
showRoom::showRoom(string o, string c) {
	this->owner = o;
	this->city = c;
	users.push_back(user("Abdullah", "abdullah1904"));
	users.push_back(user("Mahreen", "mahreen"));
	users.push_back(user("Sufiyan", "sufiyan"));
	cars.push_back(Car("Mercedes-Maybach", "S 680 4MATIC","White","Petrol","Automatic",5980,470000,2022));
	cars.push_back(Car("Honda","Civic","Black","Petrol","Manual",1500,1280,2017));
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
	setColor(3); cout<<"F)"; setColor(15); cout<<" Log Out"<<endl;
	setColor(3); cout<<"G)"; setColor(15); cout<<" Exit"<<endl<<endl;
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
		case 'F': return;
		break;
		case 'g':
		case 'G': clear(); exit(0);
		break;
		default: clear(); setColor(4); cout << "Invalid Option! Enter Valid option..." << endl; setColor(15); system("pause");
	}
	goto menu;
}
void showRoom::bill() {
	string c,m;
	char dummy;
	vector<Car> billC;
	vector<Bike> billB;
	bill:
	clear();
	setColor(7);
	header();
	setColor(12);
	cout<<"  --: BILLING :--"<<endl<<endl;
	setColor(12);cout<<"Enter Company of a Vehicle which Customer Purchased: ";setColor(7);getline(cin>>ws,c);
	setColor(12);cout<<"Enter Model of a Vehicle which Customer Purchased: ";setColor(7);getline(cin>>ws,m);
	cout<<endl;
	for(int i =0; i<cars.size();i++){
		if(c == cars[i].getCompany() && m == cars[i].getModel()){
			billC.push_back(cars[i]);
			setColor(15);cout<<endl<<"Successfully Added..."<<endl<<endl;
			setColor(7);system("pause");
			goto options;
		}
	}
	for(int i =0; i<bikes.size();i++){
		if(c == bikes[i].getCompany() && m == bikes[i].getModel()){
			billB.push_back(bikes[i]);
			setColor(7);cout<<endl<<"Successfully Added..."<<endl<<endl;
			system("pause");
			goto options;
		}
	}
	clear();
	setColor(4);
	cout<<"Sorry! This Vehicle is not in our Collection..."<<endl;
	setColor(15);
	system("pause");
	options:
	clear();
	setColor(7);
	header();
	setColor(12);
	cout<<"  --: BILLING :--"<<endl<<endl;
	setColor(12);cout<<"A) ";setColor(7);cout<<"Add New"<<endl;
	setColor(12);cout<<"B) ";setColor(7);cout<<"Print Bill"<<endl<<endl;
	setColor(12); cout<<"Select Option: "; 
	setColor(7);cin>>dummy;
	switch(dummy){
		case 'a':
		case 'A': goto bill;
		case 'b':
		case 'B': printBill(billC,billB);
		default: clear(); setColor(4); cout << "Invalid Option! Enter Valid option..." << endl; setColor(15); system("pause");
	}
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
		case 'A': this->addCar();
		break;
		case 'b':
		case 'B': this->showCars();
		break;
		case 'c':
		case 'C': this->searchCar();
		break;
		case 'd':
		case 'D': this->deleteCar();
		break;
		case 'e':
		case 'E': this->updateCar();
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
		case 'A': this->addBike();
		break;
		case 'b':
		case 'B': this->showBikes();
		break;
		case 'c':
		case 'C': this->searchBike();
		break;
		case 'd':
		case 'D': ;
		break;
		case 'e':
		case 'E': this->updateBike();
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
		case 'A': this->addUser();
		break;
		case 'b':
		case 'B': this->showUsers();
		break;
		case 'c':
		case 'C': this->searchUser();
		break;
		case 'd':
		case 'D': this->deleteUser();
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
	cout<<"  --: ABOUT SHOWROOM :--"<<endl<<endl;
	setColor(3);cout<<"Owner Name: ";setColor(15);cout<<this->owner<<"\t\t\t";setColor(3);cout<<"Showroom Station: ";setColor(15);cout<<this->city<<endl;
	setColor(3);cout<<"Share Holder: ";setColor(15);cout<<"Ms. Mahreen Farooq\t";setColor(3);cout<<"Partner: ";setColor(15);cout<<" Mr. Mirza Sufiyan Ahmad"<<endl<<endl;
	setColor(3);cout<<"Total Number of Cars: ";setColor(15);cout<<cars.size()<<"\t\t\t";setColor(3);cout<<"Total Number of Bikes: ";setColor(15);cout<<bikes.size()<<endl<<endl;
	setColor(3);cout<<"Description:\n";
	setColor(15);cout<<"\tHello Abdullah"<<endl<<endl;
	system("pause");
	return;
}
void showRoom::addCar(){
	clear();
	setColor(12);
	header();
	setColor(7);
	cout<<"  --: NEW CAR :--"<<endl<<endl;
	cars.push_back(Car());
	cars[cars.size()-1].get();
	setColor(7);cout<<endl<<"Successfully Added New Car..."<<endl<<endl;
	setColor(7);system("pause");
	return;
}
void showRoom::showCars(){
	clear();
	setColor(12);
	header();
	setColor(7);
	cout<<"  --: CARS :--"<<endl<<endl;
	for(int i =0; i<cars.size();i++){
		cars[i].display();
		cout<<endl;
	}
	cout<<endl<<endl;setColor(7);system("pause");
	return;
}
void showRoom::searchCar(){
	string c,m;
	clear();
	setColor(12);
	header();
	setColor(7);
	cout<<"  --: SEARCH CAR :--"<<endl<<endl;
	setColor(12);cout<<"Enter Company of a Car to Search: ";setColor(7);getline(cin>>ws,c);
	setColor(12);cout<<"Enter Model of a Car to Search: ";setColor(7);getline(cin>>ws,m);
	cout<<endl;
	for(int i =0; i<cars.size();i++){
		if(c == cars[i].getCompany() && m == cars[i].getModel()){
			cars[i].display();
			cout<<endl;setColor(7);system("pause");
			return;
		}
	}
	clear();
	setColor(4);
	cout<<"Sorry! This Car is not in our Cars Collection..."<<endl;
	setColor(15);
	system("pause");
	return;
}
void showRoom::deleteCar(){
	string c,m;
	clear();
	setColor(12);
	header();
	setColor(7);
	cout<<"  --: REMOVE CAR :--"<<endl<<endl;
	setColor(12);cout<<"Enter Company of a Car to Delete: ";setColor(7);getline(cin>>ws,c);
	setColor(12);cout<<"Enter Model of a Car to Delete: ";setColor(7);getline(cin>>ws,m);
	cout<<endl;
	for(int i = 0; i<cars.size();i++){
		if(c == cars[i].getCompany() && m == cars[i].getModel()){
			for(int j = i; j<cars.size()-1;j++)
				cars[j].set(cars[j+1]);
			cars.resize(cars.size()-1);
			setColor(15);cout<<endl<<"Successfully Car Removed..."<<endl<<endl;
			setColor(7);system("pause");
			return;
		}
	}
	clear();
	setColor(4);
	cout<<"Invalid Car Company or Model! This Car is Not in Our Record. Enter Valid Car Company or Model..."<<endl;
	setColor(15);
	system("pause");
	return;
}
void showRoom::updateCar(){
	string c,m;
	clear();
	setColor(12);
	header();
	setColor(7);
	cout<<"  --: UPDATE CAR :--"<<endl<<endl;
	setColor(12);cout<<"Enter Company of a Car to Update  Car Details: ";setColor(7);getline(cin>>ws,c);
	setColor(12);cout<<"Enter Model of a Car to Update Car Details: ";setColor(7);getline(cin>>ws,m);
	cout<<endl;
	for(int i =0; i<cars.size();i++){
		if(c == cars[i].getCompany() && m == cars[i].getModel()){
			cars[i].get();
			cout<<endl;setColor(7);system("pause");
			return;
		}
	}
	clear();
	setColor(4);
	cout<<"Sorry! This Car is not in our Cars Collection..."<<endl;
	setColor(15);
	system("pause");
	return;
}
void showRoom::addBike(){
	clear();
	setColor(12);
	header();
	setColor(7);
	cout<<"  --: NEW BIKE :--"<<endl<<endl;
	bikes.push_back(Bike());
	bikes[bikes.size()-1].get();
	setColor(7);cout<<endl<<"Successfully Added New Bike..."<<endl<<endl;
	setColor(7);system("pause");
	return;
}
void showRoom::showBikes(){
	clear();
	setColor(12);
	header();
	setColor(7);
	cout<<"  --: BIKES :--"<<endl<<endl;
	for(int i =0; i<bikes.size();i++){
		bikes[i].display();
		cout<<endl;
	}
	cout<<endl<<endl;setColor(7);system("pause");
	return;
}
void showRoom::searchBike(){
	string c,m;
	clear();
	setColor(12);
	header();
	setColor(7);
	cout<<"  --: SEARCH BIKE :--"<<endl<<endl;
	setColor(12);cout<<"Enter Company of a Bike to Search: ";setColor(7);getline(cin>>ws,c);
	setColor(12);cout<<"Enter Model of a Bike to Search: ";setColor(7);getline(cin>>ws,m);
	cout<<endl;
	for(int i =0; i<bikes.size();i++){
		if(c == bikes[i].getCompany() && m == bikes[i].getModel()){
			bikes[i].display();
			cout<<endl;setColor(7);system("pause");
			return;
		}
	}
	clear();
	setColor(4);
	cout<<"Sorry! This Bike is not in our Bikes Collection..."<<endl;
	setColor(15);
	system("pause");
	return;
}
void showRoom::deleteBike(){
	string c,m;
	clear();
	setColor(12);
	header();
	setColor(7);
	cout<<"  --: REMOVE BIKE :--"<<endl<<endl;
	setColor(12);cout<<"Enter Company of a Bike to Delete: ";setColor(7);getline(cin>>ws,c);
	setColor(12);cout<<"Enter Model of a Bike to Delete: ";setColor(7);getline(cin>>ws,m);
	cout<<endl;
	for(int i = 0; i<bikes.size();i++){
		if(c == bikes[i].getCompany() && m == bikes[i].getModel()){
			for(int j = i; j<bikes.size()-1;j++)
				bikes[j].set(bikes[j+1]);
			bikes.resize(bikes.size()-1);
			setColor(15);cout<<endl<<"Successfully Bike Removed..."<<endl<<endl;
			setColor(7);system("pause");
			return;
		}
	}
	clear();
	setColor(4);
	cout<<"Invalid Bike Company or Model! This Bike is Not in Our Record. Enter Valid Bike Company or Model..."<<endl;
	setColor(15);
	system("pause");
	return;
}
void showRoom::updateBike(){
	string c,m;
	clear();
	setColor(12);
	header();
	setColor(7);
	cout<<"  --: UPDATE BIKE :--"<<endl<<endl;
	setColor(12);cout<<"Enter Company of a Bike to Update  Car Details: ";setColor(7);getline(cin>>ws,c);
	setColor(12);cout<<"Enter Model of a Bike to Update Car Details: ";setColor(7);getline(cin>>ws,m);
	cout<<endl;
	for(int i =0; i<bikes.size();i++){
		if(c == bikes[i].getCompany() && m == bikes[i].getModel()){
			bikes[i].get();
			cout<<endl;setColor(7);system("pause");
			return;
		}
	}
	clear();
	setColor(4);
	cout<<"Sorry! This Bike is not in our Bikes Collection..."<<endl;
	setColor(15);
	system("pause");
	return;
}
void showRoom::addUser(){
	string u,p;
	clear();
	setColor(12);
	header();
	setColor(7);
	cout<<"  --: NEW USER :--"<<endl<<endl;
	setColor(12);cout<<"Enter New Username: ";setColor(7);getline(cin>>ws,u);
	setColor(12);cout<<"Enter New Password: ";setColor(7);getline(cin>>ws,p);
	users.push_back(user(u,p));
	setColor(7);cout<<endl<<"Successfully Added New User..."<<endl<<endl;
	setColor(7);system("pause");
	return;
}
void showRoom::showUsers(){
	clear();
	setColor(12);
	header();
	setColor(7);
	cout<<"  --: USERS :--"<<endl<<endl;
	setColor(12);cout<<"Users: ";
	for(int i =0; i<users.size();i++){
		cout<<endl;setColor(12);cout<<"\t"<<i+1<<") ";setColor(7);cout<<users[i].getUserName();
	}
	cout<<endl<<endl;setColor(7);system("pause");
	return;
}
void showRoom::searchUser(){
	string u,p,s;
	clear();
	setColor(12);
	header();
	setColor(7);
	cout<<"  --: SEARCH USER :--"<<endl<<endl;
	setColor(12);cout<<"Enter Your Username: ";setColor(7);getline(cin>>ws,u);
	setColor(12);cout<<"Enter Your Password: ";setColor(7);getline(cin>>ws,p);
	setColor(12);cout<<"Enter Username to Search: ";setColor(7);getline(cin>>ws,s);
	cout<<endl;
	for(int i =0; i<users.size();i++){
		if(u == "Abdullah" && p == "abdullah1904" && s == users[i].getUserName()){
			setColor(12);cout<<"Username: ";setColor(7);cout<<users[i].getUserName()<<endl;
			setColor(12);cout<<"Password: ";setColor(7);cout<<users[i].getPassword()<<endl<<endl;
			setColor(7);system("pause");
		return;
		}
		else if(u != "Abdullah" && p != "abdullah1904" && s == users[i].getUserName()){
			setColor(12);cout<<"NOTE: ";setColor(7);cout<<"\n\tGiven Username is in our record but sorry we can't share information with you.";
			cout<<endl<<endl;setColor(7);system("pause");
			return;
		}
	}
	clear();
	setColor(4);
	cout<<"Sorry! This User is not in our Record..."<<endl;
	setColor(15);
	system("pause");
	return;
}
void showRoom::deleteUser(){
	string u;
	clear();
	setColor(12);
	header();
	setColor(7);
	cout<<"  --: REMOVE USER :-- "<<endl<<endl;
	setColor(12);cout<<"Enter Username to Remove: ";setColor(7);getline(cin>>ws,u);
	if(u == "Abdullah"){
		clear();
		setColor(4);
		cout<<"Invalid Username! This User is Admin. Enter Valid Username..."<<endl;
		setColor(15);
		system("pause");
		return;
	}
	for(int i = 0; i<users.size();i++){
		if(u == users[i].getUserName()){
			for(int j = i; j<users.size()-1;j++)
				users[j].set(users[j+1].getUserName(),users[j+1].getPassword());
			users.resize(users.size()-1);
			setColor(15);cout<<endl<<"Successfully User Removed..."<<endl<<endl;
			setColor(7);system("pause");
			return;
		}
	}
	clear();
	setColor(4);
	cout<<"Invalid Username! This User is Not in Our Record. Enter Valid Username..."<<endl;
	setColor(15);
	system("pause");
	return;
}