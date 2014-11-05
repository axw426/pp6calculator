#include <iostream>
#include <climits>

int main(){
double a;
double b;
double product;
double sum;
 double subtract;
 double division;
int input;

 while(std::cin)
   {
  std::cout<<"This is a calculator. To quit press q"<<std::endl;
 std::cout<<"Insert first number\n";
std::cin>>a;
 if (!std::cin)
   { std::cout<<"error"<<std::endl;
     continue;}

 std::cout<<"Insert second number\n";
   std::cin>>b;
 if(!std::cin)
   {
     std::cout<<"That isn't a number"<<std::endl;
     continue;}
 else{
 if(b==0)
   {
     std::cout<<"Can't divide by zero"<<std::endl;
   }
 else{
 product =a*b;
 sum= a+b;
 subtract=a-b;
 division=a/b;

 std::cout<<"Which function would you like?"<<std::endl
	  <<"[1] product"<<std::endl
	  <<"[2] sum"<<std::endl
	  <<"[3] subtract"<<std::endl
	  <<"[4] divide"<<std::endl;
  std::cin>>input;

  if(input==1)
    {
      std::cout<<product<<std::endl;
   }
  else if(input==2)
    {
      std::cout<<sum<<std::endl;
    }
  else if(input==3)
    {
      std::cout<<subtract<<std::endl;
    }
  else if(input==4)
    {
      std::cout<<division<<std::endl;
    continue}
  else { std::cout<<"You didn't pick an option"<<std::endl; }
 }
 }
 break;
}


return 0;
}
