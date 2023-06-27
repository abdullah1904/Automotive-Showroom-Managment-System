#ifndef Showroom
#define Showroom
// Header Files
#include <string>
#include <vector>
#include <fstream>
// Utility Functions
void header();
void clear();
void setColor(int);
void error();
// Authorization Class
class user{
public:
    user(std::string="", std::string="");
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
    vehicle(std::string="", std::string="",int=00,int=00);
    virtual void get() = 0;
    virtual void display() = 0;
    virtual void set(std::string,std::string,int,int);
protected:
    std::string company, model;
    int engineCapacity, price;
};
// Car Class
class car:public vehicle{
public:
    car(std::string="",std::string="",std::string="",std::string="",int=00,int=00,int=00);
    void get();
    void display();
    void set(std::string,std::string,std::string,std::string,int,int,int);
private:
    std::string fuelType, transmission;
    int yearOfManufacture;
};
// Showroom Class
class showRoom {;
public:
    showRoom(std::string="", std::string="");
    ~showRoom();
    bool login();
    char menu();
private:
    std::string owner, city;
    std::vector<user> users;
};



#endif