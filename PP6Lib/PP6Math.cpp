#include "PP6Math.hpp"
#include "FileReader.hpp"
#include "fourvectorlib.hpp"
#include "threevectorlib.hpp"
#include <iostream>
#include <climits>
#include <cmath>
#include <cstdlib>

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

double threevector(double a, double b, double c)
{
  return sqrt(a*a+b*b+c*c);
  }

double fourvector(double a, double b, double c, double d)
{
  double x;
  x =  threevector(b,c,d);
  //Not sure how to deal with imaginary numbers so will only use this to give the length squared for now and will deal with that later
  return (a*a-x*x);
}

double invariantmass(double a, double b, double c, double d, double w, double x, double y, double z)
{
  //assume there is a way to do this using vectors but not really necessary
  double E = add(a,w);
  double p1 = add(b,x);
  double p2 = add(c,y);
  double p3 = add(d,z);
  double ptotal = threevector(p1,p2,p3);
  return (E*E-ptotal*ptotal);
}

void swap(double& a, double& b)
{
  double temp1, temp2;

  temp1 = a;
  temp2 = b;

  b= temp1;
  a= temp2;
}

//marker
void sort(double* a, double* index, int size)
{
  for(int i=0;i<size;i++)
    {index[i]=0+i;}
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

void readfile(){
  double event[1000],  p_x[1000], p_y[1000], p_z[1000],P[1000];
  std::string name[1000], Data_Source[1000];
  FileReader f("/home/aw/mpagspp6/observedparticles.dat");

  if(f.isValid()){ std::cout<<"valid input file\n\n";
    while (f.nextLine()) { //reads each line
      int i=0; 

      event[i] = f.getFieldAsDouble(0);
      name[i] = f.getFieldAsString(2);
      p_x[i] = f.getFieldAsDouble(3);
      p_y[i] = f.getFieldAsDouble(4);
      p_z[i] = f.getFieldAsDouble(5);
      P[i] = threevector(p_x[i],p_y[i],p_z[i]);
      Data_Source[i] = f.getFieldAsString(6);
      if (f.inputFailed()){std::cout<<"Incorrect input file\n";
	break;}
      i++;
    } ///end of file reading
     
    ///these arrays are the labels for the events in which there is a mu- or mu+
    double muon[1000]; 
    double antimuon[1000];
    int counter=0;
    int counter2=0;
    for(int j=0; j<=1000; j++)
      {
	if (Data_Source[j]=="run4.dat" && name[j]== "mu-")
	  {muon[j]=event[j];
	    counter++;}
        if(Data_Source[j]=="run4.dat" &&  name[j]=="mu+")
	  {antimuon[j]=event[j];
	    counter2++;}}

    //want to know how many of each particle there are
    
    std::cout<<"There are "<<counter<<" muon events\n";
    std::cout<<"There are "<<counter2<< " anti muon events\n\n";
     
  
    // double muonmass = 0.1057;
   

  }///end of while loop
}

/////All functions defined//////////////

