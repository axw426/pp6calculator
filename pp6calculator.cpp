#include <iostream>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <vector>

//Our files
#include "PP6Math.hpp"
#include "FileReader.hpp"
#include "fourvectorlib.hpp"
#include "threevectorlib.hpp"
#include "particlelib.hpp"
#include "ParticleInfo.hpp"


//////////////////This forms the interface for the calculator////////////


int main(){

//Define variables

double a,b,B,c,d,w,x,y,z,ct,input,output,output2, pos, neg, topchoice,mean,standev;
char choice;
double array[1000];
int size;
 int index[2000];
//variables defined

////Start of main body//////////////

  std::cout<<"Welcome to the calculator\n";
  
  while(true) ///top level interface///
    {
      std::cout<< "Which weeks function would you like to access?\n [1] Week 1\n [2] Week 2\n [3] Week 3\n [4] Week 4\n [0] quit\n";
      std::cin>>topchoice;
      std::cout<<"\n\n";

      if(input == 0) {break;}
      if(!std::cin){error(); continue;}


      if(topchoice==1){ ///first menu////
	while(true)
	  {std::cout<<"Which function would you like to do?\n";
	   std::cout<<" [1] Addition\n [2] Subtraction\n [3] Multiplication\n [4] Division\n [5] Find intercepts\n [6] Solve quadratic\n [7] Length of 3-vector\n [8] Length of 4-vector\n [9] Calculate invariant mass\n [0] Quit\n";

	   std::cin>>input;
	   std::cout<<std::endl;

	   if(input == 0) {break;}
	   if(!std::cin){error(); continue;}

     //Cases With two inputs
	   while(input<=5){       //cases with two input numbers  
	     while(input==5)
	       {std::cout<<"Insert m then c for line of form y=mx+c\n";
		 break;}
	
	     std::cout<<"First number: ";
	     std::cin>>a;
	     std::cout<<"\n";

	     if(!std::cin){error(); continue;}
 
	     std::cout<<"Second Number: ";
	     std::cin>>b;
	     std::cout<<"\n";

	     if(!std::cin){error(); continue;}

	     if(input==1)
	       {output=add(a,b);
	        std::cout<<"Answer is "<<output<<"\n\n";}

	     else if(input==2)
	       {output=subtract(a,b);
		std::cout<<"Answer is "<<output<<" \n\n";}

	     else if(input==3)
	       {output=multiply(a,b);
		std::cout<<"Answer is "<<output<<" \n\n";}
     
	     else if(input==4)
	       {if(b==0)
		   {std::cout<<"Can't divide by zero!!!\n\n";
		     break;}
		 output=divide(a,b);
		 std::cout<<"Answer is "<<output<<" \n";}
 
	     else if(input==5)
	       {if (a==0)
		   {std::cout<<"There is no x-intercept\n\n";
		     std::cout<<"The y-intercept is "<< b<<"\n\n";
		     break;}
		 if (b==0)
		   {std::cout<<"X-intercept = Y-intercept = 0\n\n";
		     break;}
		 output=x_intercept(a,b);
		 output2=y_intercept(b);
		 std::cout<<"X-intercept = "<<output<<" \n";
		 std::cout<<"Y-intercept = "<<output2<<"\n \n";
	       }

	     break; }// break out of choices 1-5


//////////end of two input cases/////////////

//////////start of three input cases///////////
       
	   while(input>=6 && input<=7){    

	     if (input==6)
	       {std::cout<<"Enter coefficents a, b then c for equation ax^2 + bx + c = 0\n";}
	     else {std::cout<<"Enter vector components\n";}

	     std::cout<<"First number: ";
	     std::cin>>a;
	     std::cout<<"\n\n";

	     if(!std::cin){error(); continue;}

	     std::cout<<"Second number: ";
	     std::cin>>b;
	     std::cout<<"\n\n";
 
	     if(!std::cin){error(); continue;}

	     std::cout<<"Third number: ";
	     std::cin>>c;
	     std::cout<<"\n\n";

	     if(!std::cin){error(); continue;}

	     if (input==6)
	       {if (quadratic(a,b,c,pos,neg)==true) 
		   {
		   std::cout<<"positive root is "<<pos<<std::endl;
		   std::cout<<"negative root is "<<neg<<"\n\n"; }
		 else {std::cout<<"The roots are imaginary\n\n";}}

	   
	     if(input==7)
	       {ThreeVector tv(a,b,c);
		 tv.t_magnitude();
	       }

	     break;} //break out of choice 6 and 7

 //////////end of three input functions/////////////

	   while(input==8)    //4-vector
	     {
	       std::cout<<"Enter p1, p1, p2 and E\n";
	       std::cout<<"P1 = ";
	       std::cin>>a;
	       std::cout<<"\n\n";
	       if(!std::cin){error(); continue;
	       }
 
	       std::cout<<"P1 =";
	       std::cin>>b;
	       std::cout<<"\n\n";
	       if(!std::cin){error(); continue;}

	       std::cout<<"P2 = ";
	       std::cin>>c;
	       std::cout<<"\n\n";
	       if(!std::cin){error(); continue;}

	       std::cout<<"E = ";
	       std::cin>>d;
	       std::cout<<"\n\n";
	       if(!std::cin){error(); continue;}


	       FourVector fv(a,b,c,d);
	       fv.f_length();
	      
	       break;}//break out of choice 8

	   while(input==9)
	     {
	       std::cout<<"First E: ";
	       std::cin>>a;
	       std::cout<<"\n\n";
	       if(!std::cin){error(); continue;}

	       std::cout<<"First P1: ";
	       std::cin>>b;
	       std::cout<<"\n\n";
	       if(!std::cin){error(); continue;}


	       std::cout<<"First P2: ";
	       std::cin>>c;
	       std::cout<<"\n\n";
	       if(!std::cin){error(); continue;}


	       std::cout<<"First P3: ";
	       std::cin>>d;
	       std::cout<<"\n\n";
	       if(!std::cin){error(); continue;}


	       std::cout<<"Second E: ";
	       std::cin>>w;
	       std::cout<<"\n\n";
	       if(!std::cin){error(); continue;}
	       
	       std::cout<<"Second P1: ";
	       std::cin>>x;
	       std::cout<<"\n\n";
	       if(!std::cin){error(); continue;}
	       
	       std::cout<<"Second P2: ";
	       std::cin>>y;
	       if(!std::cin){error(); continue;}
	       
	       std::cout<<"Second P3: ";
	       std::cin>>z;
	       std::cout<<"\n\n";
	       if(!std::cin){error(); continue;}

	       FourVector fv1(a,b,c,d);
	       FourVector fv2(w,x,y,z);
	       FourVector product=fv1*fv2;
	       product.f_length();
	       
	       break;}//break out of choice 9
	   break;}//end of week 1 choices
	input=1; } ///end of week 1 interface 

      ////////////////week 2///////////////
      if(topchoice==2){ //week two interface
	while(true){
	  std::cout<<"Which function would you like to do?\n";
	  std::cout<<" [1] Sort Array\n [2] RandomGen\n [3] Analyse File\n [0] Quit\n\n";
	  
	  std::cin>>input;
	  std::cout<<std::endl;
	  
	  if(input == 0) {break;}
	  if(!std::cin){error(); continue;}
	  
	  while(input == 1)
	    {
	      std::cout<<"Enter the size of your array\n";
	      std::cin>>size;
	      std::cout<<std::endl;
	      if(!std::cin){error(); continue;}
	      std::cout<<"enter your numbers"<<std::endl;
	      for(int i=0;i<size;i++)
		{std::cout<<"Enter number "<<i<<": ";
		  std::cin>>array[i];
		  std::cout<<"\n";
		}
	      sort(array, index, size);
	      for(int i=0;i<size;i++)
		{std::cout<<array[i]<<" \n";}
	      break;} ///break out of choice 10
	  
	  while(input == 2)
	    {randomgen(mean, standev);
	      std::cout<<"Energy= "<<mean<< "  with standard deviation= "<<standev<<"\n";
	      
	      break;}///break out of option 2
	  
	  while(input==3)///file analysis
	    {readfile();
	      
	      break;}
	  
	  break; } //end of week two choices loop
	input=1;} // end of week two interface 
      
      
      if (topchoice==3) ///start of week three interface
	{ while(true){
	    std::cout<<"Which function would you like to do?\n";
	    std::cout<<"[1] Boost a 4-Vector Along z\n [2] Calculate 4-Vector Length\n [0] Quit\n\n";

	    std::cin>>input;
	    if(input == 0) {break;}
	    if(!std::cin){error(); continue;}

	    std::cout<<"Enter the elements of your 4-vector and boost factor\n\n";
	
	    std::cout<<"x: ";
	    std::cin>>x;
	    std::cout<<"\n";
	    if(!std::cin){error(); continue;}
	    
	    std::cout<<"y: ";
	    std::cin>>y;
	    std::cout<<"\n";
	    if(!std::cin){error(); continue;}
	    
	    std::cout<<"z: ";
	    std::cin>>z;
	    std::cout<<"\n";
	    if(!std::cin){error(); continue;}
	    
	    std::cout<<"ct: ";
	    std::cin>>ct;
	    std::cout<<"\n";
	    if(!std::cin){error(); continue;}
	    
	    std::cout<<"B: ";
	    std::cin>>B;
	    std::cout<<"\n";
	    if(!std::cin){error(); continue;}
	    
	    FourVector fv(x,y,z,ct);
	    
	    while(input==1)
	      {
		fv.f_boost(B);
		break;
	      }
	    
	    while(input==2)
	      {
		fv.f_length();
		break;
	      }
	    
	    break;}//end of week three choices
	  input=1;} //end of week three interface
      
      while(topchoice==4)	
	{
	  while(true){
	    std::cout<<"Which function would you like to do?\n";
	    std::cout<<" [1] Read File\n [2] View PDG Table\n [0] Quit\n\n";
	  
	 
	    std::cin>>input;
	    if(input == 0) {break;}
	    if(!std::cin){error(); continue;}

	    while(input==1)
	      {
		readfile();
		break;
	      }

	    while(input==2)
	      {
		std::cout<<"Here is the PDG Table\n\n";
		std::vector<std::string> Particlename;
		std::vector<double> PDG_ID, charge, mass;
		FileReader f("/home/aw/mpagspp6/pdg.dat");
		if(f.isValid()){ std::cout<<"valid input file\n\n";
		  while (f.nextLine()) { //reads each line 
		    Particlename.push_back(f.getField<std::string>(1));
		    PDG_ID.push_back(f.getField<double>(2));
		    charge.push_back(f.getField<double>(3));
		    mass.push_back(f.getField<double>(4));

		    if (f.inputFailed()){std::cout<<"Incorrect input file\n";
		      break;}
		  } //end of file reading

		  int i= mass.size();
		  for(auto j=0;j<i; j++)
		    {std::cout<<Particlename[j]<<" "<<PDG_ID[j]<<" "<<charge[j]<<" "<<mass[j]<<"\n\n";
		    }
		} 
		break;}//end of pdg table
	    break;} //end of week 4 choices
	  input=1;
	  break;}///end of week four interface

      std::cout<<"Would you like to do another calculation? [y/n]: ";
      std::cin>>choice;
      if(choice=='y')
	{continue;}
      else{break;}
      
    } // end of top level interface while loop
  std::cout<<"Goodbye\n";
  
  return 0;
}






