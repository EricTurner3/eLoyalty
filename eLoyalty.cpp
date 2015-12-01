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

/* Group Roles
Eric - Pseudo code and program base
Zavier - Login/ Register Methods
Chan - File Management/Creation (xml format would be easiest)
Josh - Barcode & Cards
Jake - User Hub Method

*/

//For While Loop
int loggingIn = 1;
//Login Variables
string username;
string pass;
char entry;
//Home screen Variables
string currentUser;
int cardsOnFile;
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
//Todo Login method
    /*Psuedo Code 
    Ask for user input for username and password
    Open the file of users and check if  the username is there and matches password
    if it does, set currentUser from the username variable, so the program can refer to them, then push to next method
    if it fails, recall the login method
    */
}

//Registration Method (Zavier)
void register(){
cout << "Registration: " << endl;
/*Psuedo Code
Ask for Username and password (we dont even need to worry about emails or that stuff tbh
Confirm password as well (if method to check that both passwords work, if else, recall method throw error to console "Passes dont match"
Also read the file and make sure username doesnt exist, if so, restart, throw error to console "User exists"
If all works, then call the login method for user to login and run userFile method
*/
}

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


