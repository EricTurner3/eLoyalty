#include <iostream>
#include <string>
using namespace std;
/*
      _                       _ _         
     | |                     | | |        
  ___| |     ___  _   _  __ _| | |_ _   _ 
 / _ \ |    / _ \| | | |/ _` | | __| | | |
|  __/ |___| (_) | |_| | (_| | | |_| |_| |
 \___|______\___/ \__, |\__,_|_|\__|\__, |
                   __/ |             __/ |
                  |___/             |___/ 
				  
eLoyalty Card Management System
*/

//For While Loop
int loggingIn = 1;
//Login Variables
string username;
string pass;
char entry;
//Register Variable
string confirmPass;


//eLoyalty Program Base (Eric)
int main() {
    cout << "Welcome to eLoyalty." << endl;
	
	while(loggingIn == 1)
	{
		cout << " Type 'L' to Login or 'R' to Register: ";
		cin >> entry;
		
		switch (entry){
			case L: login();
					loggingIn = 0; //Terminates the Login loop to allow next step to activate.
				break;
			case R: register(); //After registration, the loop resets to allow user to login
					cout << 
				break;
			case default:
				cout << "Invalid Selection. Please try again." << endl;
	
		}
	}
	
	//Todo: Stuff after logging in
	
    return 0;
}

//Login Method (Zavier)
void login(){
cout << "Login: " << endl;
//Todo Login method, possibly access a database?
}

//Registration Method (Zavier)
void register(){
cout << "Registration: " << endl;
//Todo register method, make sure you use a if statement to make sure password & confirm password are the same. if so then store, otherwise retry (While loop!!)
}

