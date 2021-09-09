// CS311 Yoshii - el_t for HW8 Hash Table
// Element type of a list node is defined here
// el_t can be changed by the client to fit its needs
//----------------------------------------------------
#ifndef ELEM_CPP
#define ELEM_CPP

#include "elem.h"

// blank element
el_t::el_t()
{
  key = 0;
  brand = " ";
  model = " ";
  prodyear = 0;
  price = 0;

  doors= 0;
  type = " ";
  colour = " ";

  displ = 0.0;
  config = ' ';
  cylinders = 0;
}

// initializing constructor to create an el_t object 
el_t::el_t(int akey, string abrand, string amodel, int apy, int aprice, int adoors, string atype, string acolour, float adispl, char aconfig, int acylinders)
{
  key = akey;
  brand = abrand;
  model = amodel;
  prodyear = apy;
  price = aprice;
  doors = adoors;
  type = atype;
  colour = acolour;
  displ = adispl;
  cylinders = acylinders;
}
  
// overload == for search based on the key part only
bool el_t::operator==(el_t OtherOne)
{
  if (key == OtherOne.key) return true; else return false;
}

// overload != for search based on the key part only
bool el_t::operator!=(el_t OtherOne)
{
  if (key != OtherOne.key) return true; else return false;
}

// overload cout 
ostream& operator<<(ostream& os, const el_t& E)  
{  
  os << E.key << "+" << E.brand;
  return os;  
}  
#endif 
