#include "PP6Math.hpp"
#include <iostream>
#include <limits>
#include <cmath>

///////definitions start///////////

/////////functions///////////

double add(double a, double b)
{
  return a+b;
}

double multiply(double a, double b)
{
  return a*b;
}

double divide(double a, double b)
{
  return a/b;
}

double subtract(double a, double b)
{
  return a-b;
}

double x_intercept(double m, double c)
{
  return (-c)/m;
}

double y_intercept(double c)
{
  return c;  //somewhat pointless
}

bool quadratic(double a, double b, double c, double& pos, double& neg)
{pos =(-b+sqrt(b*b-4*a*c))/(2*a);
  neg = (-b-sqrt(b*b-4*a*c))/(2*a);
  if (b*b-4*a*c>=0){return true;}
  else {return false;}
}

double threevector(double a, double b, double c)
{
  return sqrt(a*a+b*b+c*c);
}

double fourvector(double a, double b, double c, double d)
{
  double x;
  x =  threevector(b,c,d);
  //Not sure how to deal with imaginary numbers so will only use this to give the length squared for now and will deal with that later
  return (a*a-x*x);
}

double invariantmass(double a, double b, double c, double d, double w, double x, double y, double z)
{
  //assume there is a way to do this using vectors but not really necessary
  double E = add(a,w);
  double p1 = add(b,x);
  double p2 = add(c,y);
  double p3 = add(d,z);
  double ptotal = threevector(p1,p2,p3);
    return (E*E-ptotal*ptotal);
}

void swap(double& a, double& b)
{
  double temp1, temp2;

  temp1 = a;
  temp2 = b;

  b= temp1;
  a=temp2;
}
//marker
void sort(double* a, double size)
{
  while(true)
    {bool noswap=true;
      for (int i=0; i<size-1; i++)
	{
	  if(a[i]<=a[i+1]){
	    swap(a[i],a[i+1]);
	    noswap=false;
	  }
	}
      if(noswap==true){break;}
    }
}


/*New error handler
bool errorhandle(bool test){
if(!test)
     {
std::cout<<"Not a valid entry\n";
 std::cin.clear();
 std::cin.ignore(INT_MAX, '\n');
 return true;}
 return false;}*/

/////All functions defined//////////////

