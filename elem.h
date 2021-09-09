// CS311 Yoshii - el_t for HW8 Hash Table
// Element type of a list node is defined here
// el_t can be changed by the client to fit its needs
//-----------------------------------------------------
#ifndef ELEM_H
#define ELEM_H

#include <iostream>
#include <string>
using namespace std;

class el_t
{
 private:
  int key;      //                                                                                                
  string brand;  //                                                                                               
  string model;
  int prodyear;
  int price;

  int doors;
  string type;
  string colour;

  float displ;
  char config;
  int cylinders;

 public:

  el_t();  // to create a blank el_t object                                                                       
  el_t(int, string, string, int, int, int, string, string, float, char, int); // to create an initialized el_t object                                                      

  bool operator==(el_t);  // overload == for search                                                               
  bool operator!=(el_t);  // overload != for search                                                               

  // this overloads cout for the el_t object                                                                      
  // This is a friend function since the receiver object is not el_t                                              
  friend ostream& operator<<(ostream&, const el_t&);

  friend class htable;  // client of this class is htable which needs access to the key part of el_t              

};

#endif
