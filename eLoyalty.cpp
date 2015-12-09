#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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

/* Group Roles
Eric - Pseudo code and program base
Zavier - Login/ Register Methods
Josh - Barcode & Cards
Jake - User Hub Method

*/

//For While Loop
int loggingIn = 1;
//Login Variables
string username;
string password;
int entry;
//Home screen Variables
string currentUser;
//Used for number generation
int result, digitIndex, curDigit;
int resultNum;
int numResultsWanted = 10;
//Used for deciding which company to generate barcodes for
int company, Target, Target2, Walmart, Walmart2;
int TargetCount = 0;
int WalmartCount = 0;
int more = 1;


//Management of the card storage file (Josh)
void userFile(string user, int cardType, int cardNumber)
{
    ofstream outputFile;
    outputFile.open("DataFile.txt", ios::out | ios::in | ios::app);
    cout << "Now writing data to a file" <<endl;
    
    //cardType 1 is Target and 2 is Walmart
    outputFile << user << ":" << cardType <<":" << cardNumber <<endl;
    
    outputFile.close();
    cout << "Username and Card Choice saved!"<<endl;
    return;
}

//This is where the program goes after logged in succesfully (Jake & Josh)
void home() 

//Barcode generation (Jake)
{

  cout << "" <<endl;
  cout << "Welcome " << currentUser << " to eLoyalty!" <<endl;
  while(more==1)
{
  cout <<""<<endl;
  cout << "Is your number from Target or Walmart? Enter 1 or 2 to make a choice." << endl;
  cin >> company;
  
  if (company == 1)
  
  {
    cout << "Please enter the loyalty card number." << endl;
    cin >> Target;
    TargetCount++; //AutoIncrementing number on how many target cards
    Target2 = TargetCount; 
    userFile(currentUser,Target2,Target);
    cout << "Your Target card count is " << Target2 << "." << endl;
    
  }
  
  else
  {
    cout << "Please enter the loyalty card number." << endl;
    cin >> Walmart;
    
    while()
    WalmartCount++; //AutoIncrementing number on how many walmart cards
    Walmart2 = WalmartCount;
    //Writes the current user, the index number of Walmart cards, and the card number
    userFile(currentUser,Walmart2,Walmart);
    cout << "Your Walmart card count is " << Walmart2 << "." << endl;
    
  }
  cout << "Would you like to add another card? Type 1 for yes and 0 for no" <<endl;
  cin >> more;
}
cout << "Cards added! Logging out..." <<endl;
 return;
}




//Registration Method (Zavier)
void reg(){
    cout << ""<< endl;
    cout << "User Registration " << endl;
    cout << "------------------"<< endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    fstream signin;
    signin.open ("login.txt", ios::out | ios::in | ios::app);
    signin << username << "::" << password << endl;

    signin.close();
    cout << "User registered." << endl;
    return;
}

//Login Method (Zavier)
void log(){
cout << "" << endl;
cout << "User Login " << endl;
cout << "----------" << endl;
cout << "Username: ";
cin >> username;
cout << "Password: ";
cin >> password;

string line;
ifstream loginfile ("login.txt");
string search = username + "::" + password;

	int linenumber = 0;
		while ( getline (loginfile,line) )
		{
			linenumber ++;
			if (line.find(search, 0) != string::npos) {
				cout << "logged in." << endl;
                currentUser = username;
                
                home();
			}
			else 
			{
				cout << "Incorrect Username or Password." << endl;
			}
		}
	loginfile.close();
return;
}

//eLoyalty Program Base (Eric)
int main() {
    cout << "Welcome to eLoyalty." << endl;
	
	while(loggingIn == 1)
	{
        cout << "" << endl;
		cout << " Type '1' to Login,  '2' to Register or '3' to Exit ";
		cin >> entry;
        cout << "" << endl;
		
		switch (entry){
			case 1: log();//Terminates the Login loop to allow next step to activate.
				break;
			case 2: reg(); //After registration, the loop resets to allow user to login
				break;
            case 3: return 0;
                break;
			default:
				cout << "Invalid Selection. Please try again." << endl;
	
		}
	}
}


