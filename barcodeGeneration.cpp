#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;
//previous comments were trying something else and Cary asked me to leave them in because he wanted to test something
  int result, digitIndex, curDigit;
  int resultNum;
  int numResultsWanted = 10;
  string str_target = "Target";
  string str_walmart = "Walmart";
  int company;
  //int Walmart;
  //Walmart = stoi(str_target);
  //int Target; 
  //Target = stoi(str_walmart);
  //company = 1;
int main() 
{
  
  cout << "Is the barcode from Target or Walmart? Enter 1 or 2 to make your choice." << endl;
  cin >> company;

 if (company == 1) //checks company against the number one and executes code based on response from user.
{
// init rand seed
    srand(time(NULL));

    for (resultNum=0; resultNum<numResultsWanted; resultNum++)
{
    result = 0;
    for (digitIndex=0; digitIndex<4; digitIndex++)
{
  curDigit = rand() % 10;
  curDigit *= pow(10, digitIndex);
  result += curDigit;
}
  printf("Barcodes for Target: 1%d\n", result);
      
}
   return 0;
}
 else; //executes based on user response, number being 2.
{
    srand(time(NULL));

     for (resultNum=0; resultNum<numResultsWanted; resultNum++)
{
    result = 0;
    for (digitIndex=0; digitIndex<4; digitIndex++)
{
  curDigit = rand() % 10;
  curDigit *= pow(10, digitIndex);
  result += curDigit;
}
  printf("Barcodes for Walmart: 2%d\n", result);
}
}
}
