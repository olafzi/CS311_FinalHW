// CS311 Yoshii - Final program
//-----------------------------------------------

//============================================
// Name: Olaf Zielinski
// File type: client finalClient.cpp
//===========================================

using namespace std;
#include "htable.h"
#include "elem.h"
#include <iostream>
#include <fstream>

void showMenu();
htable processFile();
el_t addManually();

int main()
{
  htable table; //empty table object

  int choice = 1;
  int userkey;
  el_t blank; // used to check if it found anything. 
  el_t elem; // for adding a new one. 

  while(choice != 0){
    showMenu();
    
    cout << "Enter Command:" << endl;
    cin >> choice;
    
    switch(choice){

    case 1:{ // add from file
	table=	processFile(); 
	break;
      } //end case1
      
    case 2:{ // manually add
	cout << "Please be careful. Manually adding a car to the list is a lenghty process and is prone to mistakes.";
	cout << "Are you sure you want to continue? (Y/N): ";
	  char c;
	cin >> c;
	if(c=='N')
	  break;
	else{
	  table.add(addManually());
	  cout << "Added!." << endl;
	  break;
	}
    } //end case2
      
    case 3:{ // find by key
	cout << "Please enter the key for the car you're looking for: ";
	cin >> userkey;
	if( table.find(userkey) == blank) // if not found
	  {
	    cout << " The car with key " << userkey << " wasn't found." << endl;
	    break;
	  }
	else // if found
	  {
	    cout << "Found " << userkey << ": "
		 << table.find(userkey) << endl;
	  } // end if
	break;
      } //end case3
      
    case 4:{ // display of the entire table
	cout << "Table:" << endl;
	table.displayTable();
	break;
      } //end case4
      
    case 0:{
	cout << "Exiting." << endl;
	cout << "Thank you!" << endl;
	break;
      } //end case0
      
    default:{
      cout << "Invalid choice. Please try again. " << endl;
      break;
    }
      
    } // end switch
    
  } //end while loop
  
} //end main

void showMenu(){
  cout << "MENU:  " << endl
       << "------------------------------------------------" << endl
       << "TYPE: 1 (add from file)        to add a list of cars from a file. " << endl
       << "TYPE: 2 (add manually)         to add a car manually." << endl
       << "TYPE: 3 (find)                 to find a car." << endl
       << "TYPE: 4 (display)              to display entire table." << endl
       << "TYPE: 0 (exit)                 to exit the program. " << endl
       << "------------------------------------------------" << endl;
}

htable processFile(){

  htable atable; //to store the elements
  int count=0; //to count how many objects have been added.
  
  ifstream fin;
  string brand, model, type, colour;
  int key, prodyear, price, doors, cylinders;
  char config;
  float displ;

  cout << "Processing the file." << endl;
  
  fin.open("cars.txt");
  
  if(!fin){  //If not opened correctly, display error.	\
    
    cout << "Couldn't open the file." << endl;
    return atable;
  }

//reading the data                                                                    \
                                                                                                    
  while(!fin.eof()){
                                                                                                 
  fin >> key >> brand >> model >> prodyear >> price >> doors >> type >> colour >> displ >> config >> cylinders;
  
  el_t elem (key, brand, model, prodyear, price, doors, type, colour, displ, config, cylinders);

  atable.add(elem);
  count++;
 }

 cout << "Successfully added " << count << " cars to the table." << endl;
 atable.displayTable();
 return atable;
}

el_t addManually(){

  string brand, model, type, colour;
  int key, prodyear, price, doors, cylinders;
  char config;
  float displ;

  cout << "Adding. Please type in" << endl;
  cout << "Key: ";
  cin >> key;
  cout << "Brand: ";
  cin >> brand;
  cout << "Model: ";
  cin >> model;
  cout << "Production Year: ";
  cin >> prodyear;
  cout << "The MSRP: ";
  cin >> price;
  cout << "How many doors?: ";
  cin >> doors;
  cout << "What's the body type?: ";
  cin >> type;
  cout << "What's the paint colour?: ";
  cin >> colour;
  cout << "What's the displacement?: ";
  cin >> displ;
  cout << "What's the engine configuration? (S/V/W/X/O): ";
  cin >> config;
  cout << "How many cylinders?: ";
  cin >> cylinders;

  el_t elem(key, brand, model, prodyear, price, doors, type, colour, displ, config, cylinders);
  return elem;

}
