#pragma once
#include <exception> //�쳣���� 
using namespace std; 

struct MyException : public exception
{
  const char * what () const throw ()
  {
    return "Division by zero condition!";
  }
};
