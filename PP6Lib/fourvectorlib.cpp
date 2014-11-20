#include "PP6Math.hpp"
#include "FileReader.hpp"
#include "fourvectorlib.hpp"
#include "threevectorlib.hpp"
#include <iostream>
#include <climits>
#include <cmath>
#include <cstdlib>

///define all functions


FourVector:: FourVector(const double x, const double y, const double z,const double ct)
: f_x(x),f_y(y),f_z(z),f_ct(ct)
{}

FourVector::FourVector(const FourVector& other)
  :f_x(other.f_x), f_y(other.f_y), f_z(other.f_z), f_ct(other.f_ct)
{}

double FourVector::f_getXValue() const 
{return f_x;}

double FourVector::f_getYValue() const 
{return f_y;}

double FourVector::f_getZValue() const 
{return f_z;}

double FourVector::f_getCTValue() const 
{return f_ct;} 

double FourVector::f_getLength() const 
{return length;} 

void FourVector::f_changeX(FourVector fv, double x) const
{fv.f_x=x;}

void FourVector::f_changeY(FourVector fv, double y) const
{fv.f_y=y;}

void FourVector::f_changeZ(FourVector fv, double z) const
{fv.f_z=z;}

void FourVector::f_changeCT(FourVector fv, double ct) const
{fv.f_ct=ct;}
  

void FourVector::f_boost(double B) const
  {
  double zprime, ctprime, gamma;
  
  gamma = pow(sqrt(1-B),-1);
  ctprime = gamma*(f_ct - (B)*f_z);
  zprime = gamma*(f_z-(B)*f_ct);

  std::cout<<"The boosted values are:\n";
  std::cout<<"x'= "<<f_x<<"\n";
  std::cout<<"y'= "<<f_y<<"\n";
  std::cout<<"z'= "<<zprime<<"\n";
  std::cout<<"ct'= "<<ctprime<<"\n";
  }

void FourVector::f_length()
{
  length=f_ct*f_ct-f_x*f_x-f_y*f_y-f_z*f_z;
  std::cout<<"The invariant length is: "<<length<<"\n\n";
}



///operator overloads////
FourVector& FourVector::operator+=(const FourVector& rhs)
  {
    f_x += rhs.f_x; 
    f_y += rhs.f_y;
    f_z += rhs.f_z;
    f_ct += rhs.f_ct;
    return *this;
  }

FourVector operator+(const FourVector& lhs, const FourVector& rhs)
{
  FourVector temp(lhs);
  temp +=rhs;
  return temp;
}
FourVector& FourVector::operator=(const FourVector& rhs)
  {
    if (&rhs != this)
      {
	f_x = rhs.f_x;
	f_y = rhs.f_y;
	f_z = rhs.f_z;
	f_ct = rhs.f_ct;
      }
    return *this;
  }

FourVector& FourVector::operator*=(const FourVector& rhs)
{
  f_x *= rhs.f_x; 
  f_y *= rhs.f_y;
  f_z *= rhs.f_z;
  f_ct *= rhs.f_ct;
  return *this;
}

FourVector operator*(const FourVector& lhs, const FourVector& rhs)
{
  FourVector temp(lhs);
  temp *=rhs;
  return temp;
}


FourVector& FourVector::operator-=(const FourVector& rhs)
  {
    f_x -= rhs.f_x; 
    f_y -= rhs.f_y;
    f_z -= rhs.f_z;
    f_ct -= rhs.f_ct;
    return *this;
  }

FourVector operator-(const FourVector& lhs, const FourVector& rhs)
{
  FourVector temp(lhs);
  temp -=rhs;
  return temp;
}
