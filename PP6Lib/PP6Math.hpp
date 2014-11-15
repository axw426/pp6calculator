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

double threevector(double a, double b, double c);

double fourvector(double a, double b, double c, double d);

double invariantmass(double a, double b, double c, double d, double w, double x, double y, double z);

void swap(double& a, double& b);

void sort(double* a, double* index, int size);

void error();

void randomgen(double& mean, double& standev);

void readfile();

//////declarations end/////////////



#endif //  PP6Math
