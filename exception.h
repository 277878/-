#pragma once
#include <exception> //Òì³£ÉùÃ÷ 
using namespace std; 

struct MyException : public exception
{
  const char * what () const throw ()
  {
    return "Division by zero condition!";
  }
};
