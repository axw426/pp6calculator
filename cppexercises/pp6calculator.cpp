#include <iostream>
#include <climits>
#include <cmath>

//Our files
#include "PP6Math.hpp"

int main(){

//Define variables

  double a,b,c,d,w,x,y,z,input,output,output2, pos, neg;
  char choice;
  int size;

//variables defined

/////////////////////////////////////////////////////////////////////////
////Start of main body
  std::cout<<"Welcome to the calculator\n";

  while(true)
    {

  std::cout<<"Which function would you like to do?\n";
   std::cout<<" [1] Addition\n [2] Subtraction\n [3] Multiplication\n [4] Division\n [5] Find intercepts\n [6] Solve quadratic\n [7] Length of 3-vector\n [8] Length of 4-vector\n [9] Calculate invariant mass\n [10] Order an array\n [0] Quit\n";

     std::cin>>input;
     std::cout<<std::endl;

     if(input == 0) {break;}

     /*else if (errorhandle()){continue;} */ //second error handle technique
       if(!std::cin)
     {
std::cout<<"Not a valid entry\n";
 std::cin.clear();
 std::cin.ignore(INT_MAX, '\n'); 
 continue;
 }
 ///////////////////////////////////////////////////////
       while(input<=5){       //cases with two input numbers  
	 while(input==5)
	   {std::cout<<"Insert m then c for line of form y=mx+c\n";
	     break;}
	
 std::cout<<"Insert first number\n";
 std::cin>>a;

 //error(a,q);

 if(!std::cin)
     {
std::cout<<"Not a valid entry\n";
 std::cin.clear();
 std::cin.ignore(INT_MAX, '\n'); 
 continue;
     }
 
 std::cout<<"Insert second number\n";
 std::cin>>b;

 //error(b,q);

if(!std::cin)
     {
std::cout<<"Not a valid entry\n";
 std::cin.clear();
 std::cin.ignore(INT_MAX, '\n'); 
 continue;
     }

 if(input==1)
   {output=add(a,b);
     std::cout<<"Answer is "<<output<<" \n";}

 else if(input==2)
   {output=subtract(a,b);
		    std::cout<<"Answer is "<<output<<" \n";}

     else if(input==3)
       {output=multiply(a,b);
std::cout<<"Answer is "<<output<<" \n";}
     
     else if(input==4)
       {if(b==0)
	   {std::cout<<"Can't divide by zero\n";
	     break;}
	 output=divide(a,b);
std::cout<<"Answer is "<<output<<" \n";}
 
     else if(input==5)
       {if (a==0)
	   {std::cout<<"There is no x-intercept\n";
	     std::cout<<"The y-intercept is "<< b<<std::endl;
	     break;}
	 if (b==0)
	   {std::cout<<"X-intercept = Y-intercept = 0\n";
	     break;}
	     output=x_intercept(a,b);
	     output2=y_intercept(a,b);
	     std::cout<<"X-intercept = "<<output<<" \n";
	     std::cout<<"Y-intercept = "<<output2<<" \n";
       }

 break; }  ///end of two input cases

       
 while(input>=6 && input<=7){     ///start of three input cases

   if (input==6)
     {std::cout<<"Enter coefficents a, b then c for equation ax^2 + bx + c = 0\n";}
   else {std::cout<<"Enter vector components\n";}

 std::cout<<"Insert first number\n";
 std::cin>>a;
 // error(a,q);

   if(!std::cin)
     {
std::cout<<"Not a valid entry\n";
 std::cin.clear();
 std::cin.ignore(INT_MAX, '\n'); 
 continue;
     }

 std::cout<<"Insert second number\n";
 std::cin>>b;
 //error(b,q)
 
 if(!std::cin)
     {
std::cout<<"Not a valid entry\n";
 std::cin.clear();
 std::cin.ignore(INT_MAX, '\n'); 
 continue;
     };

 std::cout<<"Insert third number\n";
 std::cin>>c;
 // error(c,q);

  if(!std::cin)
     {
std::cout<<"Not a valid entry\n";
 std::cin.clear();
 std::cin.ignore(INT_MAX, '\n'); 
 continue;
     }

 if (input==6)
   {if (quadratic(a,b,c,pos,neg)==true) {
std::cout<<"positive root is "<<pos<<std::endl;
std::cout<<"negative root is "<<neg<<std::endl; }
     else {std::cout<<"The roots are imaginary\n";}}

 if(input==7)
   {output=threevector(a,b,c);
     std::cout<<"The answer is "<<output<<std::endl;}

 break;} //end of three input functions

 while(input==8)    //4-vector
   {std::cout<<"Enter E, p1, p2 and p3\n";

 std::cout<<"Insert first entry\n";
 std::cin>>a;
 //error(a,q);

  if(!std::cin)
     {
std::cout<<"Not a valid entry\n";
 std::cin.clear();
 std::cin.ignore(INT_MAX, '\n'); 
 continue;
     }
 
 std::cout<<"Insert second entry\n";
 std::cin>>b;
 //error(b,q);
 
 if(!std::cin)
     {
std::cout<<"Not a valid entry\n";
 std::cin.clear();
 std::cin.ignore(INT_MAX, '\n'); 
 continue;
     }
 std::cout<<"Insert third entry\n";
 std::cin>>c;
 //error(c,q);

 if(!std::cin)
     {
std::cout<<"Not a valid entry\n";
 std::cin.clear();
 std::cin.ignore(INT_MAX, '\n'); 
 continue;
     }
 std::cout<<"Insert fourth entry\n";
 std::cin>>d;
 //error(d,q);

 if(!std::cin)
     {
std::cout<<"Not a valid entry\n";
 std::cin.clear();
 std::cin.ignore(INT_MAX, '\n'); 
 continue;
     }

 output=fourvector(a,b,c,d);
 if(output>=0)          //positive case
   {output2=sqrt(output);
     std::cout<<"The answer is "<<output2<<std::endl;}
 
else {output2=sqrt(-1*output);
  std::cout<<"The answer is "<<output2<<"i (though this isn't physical)"<<std::endl;}

break;}

 while(input==9)
   {
 std::cout<<"Insertfirst E\n";
 std::cin>>a;
 // error(a,q);

 if(!std::cin)
     {
std::cout<<"Not a valid entry\n";
 std::cin.clear();
 std::cin.ignore(INT_MAX, '\n'); 
 continue;
     }
 
 std::cout<<"Insert first P1\n";
 std::cin>>b;
 // error(b,q);

 if(!std::cin)
     {
std::cout<<"Not a valid entry\n";
 std::cin.clear();
 std::cin.ignore(INT_MAX, '\n'); 
 continue;
     }

 std::cout<<"Insert first P2\n";
 std::cin>>c;
 // error(c,q);

if(!std::cin)
     {
std::cout<<"Not a valid entry\n";
 std::cin.clear();
 std::cin.ignore(INT_MAX, '\n'); 
 continue;
     }

 std::cout<<"Insert first P3\n";
 std::cin>>d;
 //error(d,q);

 if(!std::cin)
     {
std::cout<<"Not a valid entry\n";
 std::cin.clear();
 std::cin.ignore(INT_MAX, '\n'); 
 continue;
     }

 std::cout<<"Insert second E\n";
 std::cin>>w;
 //error(w,q);

if(!std::cin)
     {
std::cout<<"Not a valid entry\n";
 std::cin.clear();
 std::cin.ignore(INT_MAX, '\n'); 
 continue;
     }
 
 std::cout<<"Insert second P1\n";
 std::cin>>x;
 //error(x,q);

 if(!std::cin)
     {
std::cout<<"Not a valid entry\n";
 std::cin.clear();
 std::cin.ignore(INT_MAX, '\n'); 
 continue;
     }

 std::cout<<"Insert second P2\n";
 std::cin>>y;
 //error(y,'q');

 if(!std::cin)
     {
std::cout<<"Not a valid entry\n";
 std::cin.clear();
 std::cin.ignore(INT_MAX, '\n'); 
 continue;
     }

 std::cout<<"Insert second P3\n";
 std::cin>>z;
 // error(z,q);

 if(!std::cin)
     {
std::cout<<"Not a valid entry\n";
 std::cin.clear();
 std::cin.ignore(INT_MAX, '\n'); 
 continue;
     }

 output=invariantmass(a,b,c,d,w,x,y,z);
 if(output>=0)
   {output2=sqrt(output);
     std::cout<<"The invariant mass is "<<output2<<std::endl;}
 else{std::cout<<"These numbers aren't physically possible, try again\n";}

     break;}
 ////array sorting

 while(input == 10)
   {
     std::cout<<"Enter the size of your array\n";
     std::cin>>size;
     std::cout<<std::endl;
       double array[size];
       std::cout<<"enter your numbers"<<std::endl;
       for(int i=0;i<size;i++)
	 {std::cout<<"Enter number "<<i<<std::endl;
	   std::cin>>array[i];
	 }
       sort(array, size);
       for(int i=0;i<size;i++)
	 {std::cout<<array[i]<<" \n";}
       break;}




//end of actual functions

 std::cout<<"Would you like to do another calculation? [y/n]\n";
  std::cin>>choice;
  if(choice=='y')
    {continue;}
  else{break;}
 } //end of while loop
 
   std::cout<<"Goodbye\n";
 
return 0;
}






