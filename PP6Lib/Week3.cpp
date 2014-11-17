#include "PP6Math.hpp"
#include "FileReader.hpp"
#include "Week3.hpp"
#include <iostream>
#include <climits>
#include <cmath>
#include <cstdlib>

///define all functions

void boost(FourVector fv, double B)
{double zprime, ctprime, gamma;
  
  gamma = pow(sqrt(1-B),-1);
  ctprime = gamma*(fv.ct - (B)*fv.z);
  zprime = gamma*(fv.z-(B)*fv.ct);

  std::cout<<"The boosted values are:\n";
  std::cout<<"x'= "<<fv.x<<"\n";
  std::cout<<"y'= "<<fv.y<<"\n";
  std::cout<<"z'= "<<zprime<<"\n";
  std::cout<<"ct'= "<<ctprime<<"\n";
}
void length(FourVector fv)
{double invariant;
invariant = fv.ct*fv.ct-threevector(fv.x,fv.y,fv.z);
  std::cout<<"The invariant length is: "<<invariant<<"\n\n";
}

  


