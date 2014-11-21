#ifndef fourvectorlib
#define fourvectorlib
#include <cmath>
#include <iostream>

class FourVector{
public:
  //constructors
  FourVector() {f_x=0; f_y=0; f_z=0; f_ct=0;} 
  FourVector(const double x, const double y, const double z,const double ct);
  FourVector(const FourVector& other);
 
  ///operator overloads
  FourVector& operator+=(const FourVector& rhs);

  FourVector& operator=(const FourVector& rhs);
 
  FourVector& operator-=(const FourVector& rhs);

  FourVector& operator*=(const FourVector& rhs);

 ///member functions
  
  void f_boost(double B) const;

  void f_length();

  double f_getXValue() const;
  double f_getYValue() const;
  double f_getZValue() const;
  double f_getCTValue() const;
  double f_getLength() const;

  void f_changeX(FourVector fv,double x) const;
  void f_changeY(FourVector fv, double y) const;
  void f_changeZ(FourVector fv, double z) const;
  void f_changeCT(FourVector fv, double ct) const; 

private:
  double length;
  double f_x; //x
  double f_y; //y
  double f_z; //z
  double f_ct; //ct
  

};  //end of class

FourVector operator+(const FourVector& lhs, const FourVector& rhs);
FourVector operator-(const FourVector& lhs, const FourVector& rhs);
FourVector operator*(const FourVector& lhs, const FourVector& rhs);

#endif //  fourvector
