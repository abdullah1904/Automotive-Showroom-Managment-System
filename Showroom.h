#ifndef Showroom
#define Showroom
// Header Files
#include <string>
#include <vector>
// Authorization Class
class user{
public:
    user(std::string="", std::string="");
    ~user();
    void set(std::string,std::string);
    bool check(std::string,std::string);
    std::string getUserName();
    std::string getPassword();
private:
    std::string username, password;
};
// Vehicle Class
class vehicle{
public: 
    vehicle(std::string="", std::string="",std::string="",int=00,int=00);
    ~vehicle();
    virtual void get() = 0;
    virtual void display() = 0;
    std::string getCompany();
    std::string getModel();
    int getPrice();
protected:
    std::string company, model,color;
    int engineCapacity, price;
};
// Car Class
class Car:public vehicle{
public:
    Car(std::string="",std::string="",std::string="",std::string="",std::string="",int=00,int=00,int=00);
    ~Car();
    void set(Car);
    void get();
    void display();
private:
    std::string fuelType, transmission;
    int yearOfManufacture;
};
// Bike Class
class Bike:public vehicle{
public:
    Bike(std::string="",std::string="",std::string="",int=00,int=00,int=00);
    ~Bike();
    void set(Bike);
    void get();
    void display();
private:
    int yearOfManufacture;
};
// Showroom Class
class showRoom {
public:
    showRoom(std::string="", std::string="");
    ~showRoom();
    bool login();
    void menu();
    // Menu Options
    void bill();
    void car();
    void bike();
    void User();
    void about();
    // Car Section Options
    void addCar();
    void showCars();
    void searchCar();
    void deleteCar();
    void updateCar();
    // Bike Section Options
    void addBike();
    void showBikes();
    void searchBike();
    void deleteBike();
    void updateBike();
    // User Section Options
    void addUser();
    void showUsers();
    void searchUser();
    void deleteUser();
private:
    std::string owner, city;
    std::vector<user> users;
    std::vector<Car> cars;
    std::vector<Bike> bikes;
};
// Utility Functions
void header();
void clear();
void setColor(int);
void printBill(std::vector<Car>, std::vector<Bike>);


#endif