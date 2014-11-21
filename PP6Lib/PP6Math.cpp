#include "PP6Math.hpp"
#include "FileReader.hpp"
#include "fourvectorlib.hpp"
#include "threevectorlib.hpp"
#include"particlelib.hpp"
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
  double event[2000];
  double p_x[2000];
  double  p_y[2000];
  double  p_z[2000];
  double energy[2000];
  std::string name[2000], Data_Source[2000];
  FileReader f("/home/aw/mpagspp6/observedparticles.dat");
  FourVector muonfv[2000], antimuonfv[2000];
  int i=0; 
  int counter=0;
  int anticounter=0;
  int antimuoneventnumber[2000],muoneventnumber[2000];
 
  const double muonmass=0.1056583715;

  if(f.isValid()){ std::cout<<"valid input file\n\n";
    while (f.nextLine()) { //reads each line 

      event[i] = f.getFieldAsDouble(1);
      name[i] = f.getFieldAsString(2);
      p_x[i] = f.getFieldAsDouble(3);
      p_y[i] = f.getFieldAsDouble(4);
      p_z[i] = f.getFieldAsDouble(5);
      Data_Source[i] = f.getFieldAsString(6);
     
      if (Data_Source[i]=="run4.dat" && name[i]== "mu-")
	{
	  Particle p(12,p_x[counter],p_y[counter],p_z[counter],muonmass);	 	
	  p.p_Energy();
	  energy[counter]=p.p_getEnergy();
	  muoneventnumber[counter]=event[i];

	  FourVector fv(p_x[counter],p_y[counter],p_z[counter],energy[counter]);
	  fv.f_length();
	  muonfv[counter]=fv;
	  	  
	  counter++;
	}
     
      if (Data_Source[i]=="run4.dat" && name[i]== "mu+")
	{
	  Particle p(-12,p_x[anticounter],p_y[anticounter],p_z[anticounter],muonmass);	 
	  p.p_Energy();
	  energy[anticounter]=p.p_getEnergy();
	  antimuoneventnumber[anticounter]=event[i];

	  FourVector fv(p_x[anticounter],p_y[anticounter],p_z[anticounter],energy[anticounter]);
	  antimuonfv[anticounter]=fv;
	  antimuonfv[anticounter].f_length();
	  anticounter++;
	} 

      if (f.inputFailed()){std::cout<<"Incorrect input file\n";
	break;}
      i++;
    } ///end of file reading
        
    int* muonPairIndex(new int[counter*anticounter]);
    double* invariantmasses(new double[counter*anticounter]);
    for(int i=0;i<counter;i++) //sum over muons
      {
	for(int j=0;j<anticounter;j++) //sum over antimuons
	  {
	    FourVector temp = muonfv[i]+antimuonfv[j];
	    temp.f_length();
	    invariantmasses[i*counter+j]=temp.f_getLength();
	    muonPairIndex[i*counter+j] = i*counter+j;
	  }
      }
   
    std::cout<<"There are "<<counter<<" muon events\n";
    std::cout<<"There are "<<anticounter<< " anti muon events\n\n";
  
    associative_sort(invariantmasses, muonPairIndex, counter*anticounter);

   
    std::cout<<"The top ten invariant masses are: \n";
    for (int i=0;i<10;i++)
      {
		int muonIndex(muonPairIndex[i] % counter);
		int antimuonIndex((muonPairIndex[i]-muonIndex)/counter);
	std::cout<<invariantmasses[muonPairIndex[i]]<<" with muon from event "<<muoneventnumber[muonIndex]<<" and antimuon from event "<<antimuoneventnumber[antimuonIndex]<<std::endl;
      } 
    }///end of "if file is valid"
}
/////All functions defined//////////////

