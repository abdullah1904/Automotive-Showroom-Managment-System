#include <iostream>
#include <vector>
#include "Showroom.h"
using namespace std;
int main() {
	showRoom s1("Abdullah", "Lahore");
	login:
	setColor(10);
	clear();
	if(s1.login()){
		clear();
		s1.menu();
		goto login;
	}
	else{
		clear();
		setColor(4);
		cout<<"Invalid Username or Password! Enter Valid Username or Password..."<<endl;
		setColor(15);
		system("pause");
		clear();
		goto login;
	}
	return 0;
}
