#ifndef particleinfolib
#define particleinfolib
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <map>

typedef std::map<std::string, int> PartStringInt;
typedef std::map<std::string, double>PartStringDouble;
typedef std::map<int, std::string> PartIntString;

class ParticleInfo
{
public:
  

  PartStringInt particlePDG;
  PartStringDouble particlecharge;
  PartStringDouble particlemassGeV;
  PartIntString particlename;

  //constructors
  ParticleInfo(std::string filename)
  {
    FileReader f(filename);
    if(f.isValid())
      {
	std::cout<<"valid input file\n\n";
	while (f.nextLine()) { //reads each line 

	  particlePDG.insert(std::make_pair(f.getField<std::string>(1),f.getField<int>(2))); ///map Name to PDG
	  particlecharge.insert(std::make_pair(f.getField<std::string>(1),f.getField<double>(3))); ///map Name to charge
	  particlemassGeV.insert(std::make_pair(f.getField<std::string>(1),f.getField<double>(4))); //map Name to mass(GeV) 
	  particlename.insert(std::make_pair(f.getField<int>(2),f.getField<std::string>(1))); //map PDG to name 

	  if (f.inputFailed()){std::cout<<"Incorrect input file\n";
	    break;}
	} 

    
      }  
  }

  ///functions
  int i_getPDG(std::string a) const;
  double i_getCharge(std::string a) const;
  double i_getMass(std::string a) const;
  std::string i_getName(int a) const;
  double i_getMassGeV(std::string a) const;
  


private:
  ParticleInfo(const ParticleInfo&);
 ParticleInfo& operator=(const ParticleInfo& rhs);

};//end of class
#endif //  particleinfolib
