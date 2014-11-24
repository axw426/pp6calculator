#include "PP6Math.hpp"
#include "FileReader.hpp"
#include "fourvectorlib.hpp"
#include "threevectorlib.hpp"
#include "particlelib.hpp"
#include "ParticleInfo.hpp"
#include <iostream>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <string>

///define all functions



int ParticleInfo::i_getPDG(std::string a) const
{PartStringInt::const_iterator p = particlePDG.find(a);
if(p != particlePDG.end()) { return (*p).second ;}
  else return 0;
}

double ParticleInfo::i_getCharge(std::string a) const 
{PartStringDouble::const_iterator p = particlecharge.find(a);
if(p != particlecharge.end()) { return (*p).second ;}
  else return 0;
}

double ParticleInfo::i_getMass(std::string a) const 
{PartStringDouble::const_iterator p = particlemassGeV.find(a);
if(p != particlemassGeV.end()) { return (*p).second ;}
  else return 0;
} 

double ParticleInfo::i_getMassGev(std::string a) const 
{PartStringDouble::const_iterator p = particlemassGeV.find(a);
if(p != particlemassGeV.end()) { return (*p).second/1000 ;}
  else return 0;
} 

std::string ParticleInfo::i_getName(int a) const 
{PartIntString::const_iterator p = particlename.find(a);
if(p != particlename.end()) { return (*p).second ;}
  else return 0;
}




