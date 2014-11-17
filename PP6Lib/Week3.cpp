#include "PP6Math.hpp"
#include "FileReader.hpp"
#include "Week3.hpp"
#include <iostream>
#include <climits>
#include <cmath>
#include <cstdlib>

///define all functions


FourVector:: FourVector(const double x, const double y, const double z,const double ct)
: f_x(x),f_y(y),f_z(z),f_ct(ct)
{}


void destroyFourVector( FourVector *&fv)
{
  if (fv) 
    {
      delete fv;
    }
  fv=0;
}

  


