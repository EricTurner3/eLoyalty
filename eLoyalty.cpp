#include <iostream>
#include <string>
#include <fstream>

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
Chan - File Management/Creation
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
int cardsOnFile;
//Register Variable
string confirmPass;




//This is where the program goes after logged in succesfully (Jake & Josh)
void home() 
{
    /* Psuedo Code
    Welcome user by name so cout "Welcome " << currentUser
    Show the user how many cards are displayed on file (each user should have their own file based on their username (eric.xml) to store cards
    Have a switch statement followed by options on what to do. Aka press 1 to view cards, press 2 to add a card, press 3 to delete a card
    Josh you can do the barcode adding method so you know what to do on the userFile() method
    Jake just create the shell and stuff (switch statement) and make it seem like a user-friendly thing with questions & easily displayed data
    
    */
    cout << ""<< endl;
    cout << "Welcome" << currentUser;
    cout << "--------"<< endl;
}

//Management of the card storage file (Chan & Josh)
void userFile()
{
    /*Psuedo Code
    This method needs to create and maintain an xml file (if you can do it in a diff format go for it), properly laid out, for card storage
    After registration, this is called to create the empty shell of a file
    This will be called by home() as well to add or remove cards
    Cards need to have an id number (randomly generated on add) so you can just say remove card id 375 to delete it.
    Display out success/error messages ex Success! Card has been added, ID number is: xxx" then return to home method()
    Josh, just do anything pertaining to the cards/barcodes ie, interpreting the data.
    */
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
    signin.open ("login.txt");
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


