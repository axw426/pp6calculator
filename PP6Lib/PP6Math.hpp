#ifndef PP6Math
#define PP6Math


/////declarations/////////

double add(double a, double b);

double multiply(double a, double b);

double divide(double a, double b);

double subtract(double a, double b);

double x_intercept(double m, double c);

double y_intercept( double c);

bool quadratic(double a, double b, double c, double& pos, double& neg);

void swap(double& a, double& b);
void swap(int& a, int& b);

void sort(double* a, int* index, int size);
int associative_sort(double *arr, int *index, int size); //taken from solutions

void error();

void randomgen(double& mean, double& standev);

void readfile();

//////declarations end/////////////



#endif //  PP6Math
