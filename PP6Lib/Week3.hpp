#ifndef Week3
#define Week3
#include <cmath>
#include <iostream>

class FourVector{
public:
  //constructors
  FourVector() {f_x=0; f_y=0; f_z=0; f_ct=0;} 
  FourVector(const double x, const double y, const double z,const double ct);

  ///member functions
  void boost(double B) const
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

  void length() const
  {
  double invariant;
  invariant = f_ct*f_ct-threevector(f_x,f_y,f_z);
  std::cout<<"The invariant length is: "<<invariant<<"\n\n";
  }

  //member variables
  double f_x; //x
  double f_y; //y
  double f_z; //z
  double f_ct; //ct
};  


FourVector* createFourVector();

void destroyFourVector(FourVector *&fv);


  



#endif //  Week3
