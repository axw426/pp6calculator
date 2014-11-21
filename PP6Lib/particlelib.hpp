#ifndef particlelib
#define particlelib
#include <cmath>
#include <iostream>

class Particle{
public:
  //constructors
  Particle() {p_PDG=0;p_px=0; p_py=0; p_pz=0; p_mass=0;} 
  Particle(const double PDG, const double px, const double py, const double pz,const double mass);
  Particle(const Particle& other);
 
 ///member functions
  
  void p_Energy();
  
  double p_getPDG() const;
  double p_getPX() const;
  double p_getPY() const;
  double p_getPZ() const;
  double p_getMass() const;
  double p_getEnergy() const;

  void p_changePDG(Particle p, double PDG) const;
  void p_changePX(Particle p, double px) const;
  void p_changePY(Particle p, double py) const;
  void p_changePZ(Particle p, double z) const;
  void p_changeMass(Particle p, double mass) const; 

private:
  double energy;
  double p_PDG; 
  double p_px; 
  double p_py; 
  double p_pz; 
  double p_mass; 
  

};  //end of class


#endif //  particle
