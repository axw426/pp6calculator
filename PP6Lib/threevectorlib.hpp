#ifndef threevectorlib
#define threevectorlib
#include <cmath>
#include <iostream>

class ThreeVector{
public:
  //constructors
  ThreeVector() {t_x=0; t_y=0; t_z=0;} 
  ThreeVector(const double x, const double y, const double z);
  ThreeVector(const ThreeVector& other);
 
  ///operator overloads
  ThreeVector& operator+=(const ThreeVector& rhs);

  ThreeVector& operator=(const ThreeVector& rhs);
 
  ThreeVector& operator-=(const ThreeVector& rhs);
 ///member functions
  
  void t_magnitude();

  double t_getXValue() const;
  double t_getYValue() const;
  double t_getZValue() const;
  
  void t_changeX(ThreeVector tv, double x) const;
  void t_changeY(ThreeVector tv, double y) const;
  void t_changeZ(ThreeVector tv, double z) const;
  
private:
  double magnitude;
  double t_x; //x
  double t_y; //y
  double t_z; //z
  

};  //end of class

ThreeVector operator+(const ThreeVector& lhs, const ThreeVector& rhs);
ThreeVector operator-(const ThreeVector& lhs, const ThreeVector& rhs);


#endif //  threevector
