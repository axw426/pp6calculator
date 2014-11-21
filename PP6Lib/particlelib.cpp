#include "PP6Math.hpp"
#include "FileReader.hpp"
#include "fourvectorlib.hpp"
#include "threevectorlib.hpp"
#include "particlelib.hpp"
#include <iostream>
#include <climits>
#include <cmath>
#include <cstdlib>

///define all functions


Particle:: Particle(const double PDG, const double px, const double py, const double pz,const double mass)
  : p_PDG(PDG),p_px(px),p_py(py),p_pz(pz),p_mass(mass)
{}

Particle::Particle(const Particle& other)
  :p_PDG(other.p_PDG),p_px(other.p_px), p_py(other.p_py), p_pz(other.p_pz), p_mass(other.p_mass)
{}

Particle:: Particle(const double PDG, ThreeVector& tv,const double mass)
  :p_PDG(PDG), p_px(tv.t_getXValue()), p_py(tv.t_getYValue()),p_pz(tv.t_getZValue()),p_mass(mass)
{}

double Particle::p_getPDG() const
{return p_PDG;}

double Particle::p_getPX() const 
{return p_px;}

double Particle::p_getPY() const 
{return p_py;}

double Particle::p_getPZ() const 
{return p_pz;}

double Particle::p_getMass() const 
{return p_mass;} 

double Particle::p_getEnergy() const 
{return energy;} 

double Particle::p_getFourMomentum() const
{FourVector fv(p_px, p_py, p_pz, energy);
  fv.f_length(); 
  return fv.f_getLength();}

double Particle::p_getThreeMomentum() const
{ThreeVector tv(p_px, p_py, p_pz);
  return tv.t_magnitude();}

FourVector Particle::p_getFourVector() const
{FourVector fv(p_px, p_py, p_pz, energy);
  return fv;}

void Particle::p_changePDG(Particle p, double PDG) const
{p.p_PDG=PDG;}

void Particle::p_changePX(Particle p, double px) const
{p.p_px=px;}

void Particle::p_changePY(Particle p, double py) const
{p.p_py=py;}

void Particle::p_changePZ(Particle p, double pz) const
{p.p_pz=pz;}

void Particle::p_changeMass(Particle p, double mass) const
{p.p_mass=mass;}

void Particle::p_changeThreeMomentum(Particle p, ThreeVector tv)const
{p.p_px=tv.t_getXValue();
  p.p_py=tv.t_getYValue();
  p.p_pz=tv.t_getZValue();}
  
void Particle::p_changeThreeMomentum(Particle p, double px, double py,double pz) const
{p.p_px=px;
  p.p_py=py;
  p.p_pz=pz;
}


void Particle::p_Energy()
{
  energy= sqrt(p_px*p_px+p_py*p_py+p_pz*p_pz+p_mass*p_mass);
}




