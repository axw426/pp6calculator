#include "PP6Math.hpp"
#include "FileReader.hpp"
#include "fourvectorlib.hpp"
#include "threevectorlib.hpp"
#include <iostream>
#include <climits>
#include <cmath>
#include <cstdlib>

///define all functions


ThreeVector:: ThreeVector(const double x, const double y, const double z)
  : t_x(x),t_y(y),t_z(z)
{}

ThreeVector::ThreeVector(const ThreeVector& other)
  :t_x(other.t_x), t_y(other.t_y), t_z(other.t_z)
{}

double ThreeVector::t_getXValue() const 
{return t_x;}

double ThreeVector::t_getYValue() const 
{return t_y;}

double ThreeVector::t_getZValue() const 
{return t_z;}
 

void ThreeVector::t_changeX(ThreeVector tv, double x) const
{tv.t_x=x;}

void ThreeVector::t_changeY(ThreeVector tv, double y) const
{tv.t_y=y;}

void ThreeVector::t_changeZ(ThreeVector tv, double z) const
{tv.t_z=z;}


void ThreeVector::t_magnitude()
{
  magnitude=t_x*t_x+t_y*t_y+t_z*t_z;

  std::cout<<"The invariant length is: "<<magnitude<<"\n\n";
}

///operator overloads////
ThreeVector& ThreeVector::operator+=(const ThreeVector& rhs)
  {
    t_x += rhs.t_x; 
    t_y += rhs.t_y;
    t_z += rhs.t_z;
    return *this;
  }

ThreeVector& ThreeVector::operator=(const ThreeVector& rhs)
  {
    if (&rhs != this)
      {
	t_x = rhs.t_x;
	t_y = rhs.t_y;
	t_z = rhs.t_z;
      }
    return *this;
  }

ThreeVector operator+(const ThreeVector& lhs, const ThreeVector& rhs)
{
  ThreeVector temp(lhs);
  temp +=rhs;
  return temp;
}

ThreeVector& ThreeVector::operator-=(const ThreeVector& rhs)
  {
    t_x -= rhs.t_x; 
    t_y -= rhs.t_y;
    t_z -= rhs.t_z;
    return *this;
  }

ThreeVector operator-(const ThreeVector& lhs, const ThreeVector& rhs)
{
  ThreeVector temp(lhs);
  temp -=rhs;
  return temp;
}
