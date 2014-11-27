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
#include <iterator>
#include <algorithm>
#include <vector>
#include <map>

///////definitions start///////////

/////////functions///////////

double add(double a, double b)
{
  return a+b;
}

double multiply(double a, double b)
{
  return a*b;
}

double divide(double a, double b)
{
  return a/b;
}

double subtract(double a, double b)
{
  return a-b;
}

double x_intercept(double m, double c)
{
  return (-c)/m;
}

double y_intercept(double c)
{
  return c;  //somewhat pointless
}

bool quadratic(double a, double b, double c, double& pos, double& neg)
{pos =(-b+sqrt(b*b-4*a*c))/(2*a);
  neg = (-b-sqrt(b*b-4*a*c))/(2*a);
  if (b*b-4*a*c>=0){return true;}
  else {return false;}
}

void swap(double& a, double& b)
{
  double temp1, temp2;

  temp1 = a;
  temp2 = b;

  b= temp1;
  a= temp2;
}

void swap(int& a, int& b)
{
  int temp1, temp2;

  temp1 = a;
  temp2 = b;

  b= temp1;
  a= temp2;
}

//marker
void sort(double* a, int* index, int size)
{
  for(int i=0;i<size;i++)
    {index[i]=i;}
  while(true)
    {bool noswap=true;
      for (int i=0; i<size-1; i++)
	{
	  if(a[i]<=a[i+1]){
	    swap(a[i],a[i+1]);
	    swap(index[i],index[i+1]);
	    noswap=false;
	  }
	}
      if(noswap==true){break;}
    }
}


int associative_sort(double *arr, int *index, int size) //taken from solutions
{
  // create a temporary array to sort on so we only change the index array
  double *arr_t = new double[size];
  for (int i(0); i < size; i++)
    {
      arr_t[i] = arr[i];
    }
  // Perform a bubble sort on the given array
  bool done(true);
  while (true)
    {
      done = true;
      for (int i(0); i < size-1; ++i)
	{
	  if (arr_t[i] < arr_t[i+1])
	    {
	      swap(index[i], index[i+1]);
	      swap(arr_t[i], arr_t[i+1]);
	      done = false;
	    }
	}
      if (done)
	{
	  break;
	}
    }
  // delete temporary array, then return success
  delete [] arr_t;
  return 0;
}

void error()
{std::cout<<"Not a valid entry!!\n\n";
  std::cin.clear();
  std::cin.ignore(INT_MAX, '\n');
}

void randomgen(double& mean, double& standev){
  double mass[100];
  double p[100];
  double E[100];
  double meantemp=0;
  double standevtemp=0;

  for(int i=0; i<100; i++)
    {mass[i]=rand()%100;
      p[i]=rand()%100;
      E[i]=sqrt(p[i]*p[i]+mass[i]*mass[i]);
      meantemp+= E[i];
      standevtemp+= E[i]*E[i];}
  mean = meantemp/100;
  standev = sqrt(standevtemp/100 - mean*mean);} 

 
void readfile()
 {
   ParticleInfo PDG("/home/aw/mpagspp6/pdg.dat");
   std::vector<double> event, muonevent, antimuonevent;
   std::vector<ThreeVector> threevector;
   std::vector<FourVector> muonfv, antimuonfv;
   std::vector<std::string> name, datasource;
   int i=0;
   
   FileReader f("/home/aw/mpagspp6/observedparticles.dat");
   if(f.isValid()){ std::cout<<"valid input file\n\n";
     while (f.nextLine()) { //reads each line 
       
       ThreeVector tv(f.getFieldAsDouble(3),f.getFieldAsDouble(4),f.getFieldAsDouble(5));
       threevector.push_back(tv);
       name.push_back(f.getFieldAsString(2));
       datasource.push_back(f.getFieldAsString(6));
       
       if (datasource.at(i)=="run4.dat" && name.at(i)== "mu-")
	 { 
	   muonevent.push_back(f.getFieldAsInt(1));   
	   Particle p(PDG.i_getPDG("mu-"), threevector.at(i),PDG.i_getMassGeV("mu-")); 
	   p.p_Energy(); 
	   FourVector fv=p.p_getFourVector();
	   fv.f_length();
	   muonfv.push_back(fv); 
	 }
     
       if (datasource.at(i)=="run4.dat" && name.at(i)== "mu+")
	 {
	   antimuonevent.push_back(f.getFieldAsInt(1)); 
	   Particle p(PDG.i_getPDG("mu+"), threevector.at(i),PDG.i_getMassGeV("mu+"));
	   p.p_Energy(); //evaluate energy of particle
	   FourVector fv=p.p_getFourVector();
	   fv.f_length();
	   antimuonfv.push_back(fv); 
	 } 

       if (f.inputFailed()){std::cout<<"Incorrect input file\n";
	 break;}
       i++;
       } ///end of file reading

     std::vector<double> invariantmasses;
     std::vector<int> pairindex;
     std::vector<double>::iterator iter = muonevent.begin();
     std::vector<double>::iterator iterend = muonevent.end();
     std::vector<double>::iterator iter_antiend = antimuonevent.end();
     typedef std::map<double, int> indexer;
     indexer muonindex;
     indexer antimuonindex;

     for(int i=0; iter!=iterend; ++iter, i++) //sum over muons
       {
	 std::vector<double>::iterator iter_anti = antimuonevent.begin();
	 
	 for(int j=0; iter_anti!=iter_antiend ; ++iter_anti, j++) //sum over antimuons
	   {
	     FourVector temp = muonfv.at(i)+antimuonfv.at(j);
	     temp.f_length();
	     invariantmasses.push_back(temp.f_getLength());
	     muonindex.insert(std::make_pair(temp.f_getLength(),muonevent.at(i)));
	     antimuonindex.insert(std::make_pair(temp.f_getLength(),antimuonevent.at(j)));
	   }
       }  ///invariant mass vector and index created
       
     std::sort(invariantmasses.begin(), invariantmasses.end());
     std::reverse(invariantmasses.begin(), invariantmasses.end());

     std::cout<<"There are "<<muonevent.size()<<" muon events\n";
     std::cout<<"There are "<<antimuonevent.size()<< " anti muon events\n\n";
     std::cout<<"The top ten invariantmasses are: \n\n";
          
     for(int i=0; i<10; i++)
       { double a = invariantmasses.at(i);
	 std::cout<<a<<" with muon from event "<<(*muonindex.find(a)).second<<" and anti muon from event "<<(*antimuonindex.find(a)).second<<"\n";}
  
   }///end of "if file is valid"
 } 


/////All functions defined//////////////


