#include <iostream>
#include <cmath>
using namespace std;

double getInput();
double area(double,double,double,double);
double semiPerimeter(double,double,double);
void display(double,double);

int main(){
	cout << "Enter value of A,B and C which is each length of triangle\n";
	double a,b,c,Area,S;
	cout << "A  :  ";
	a = getInput();
	cout << "B  :  ";
	b = getInput();
	cout << "C  :  ";
	c = getInput();
	S = semiPerimeter(a,b,c);
	Area = area(a,b,c,S);
	display(Area,S);
}

double getInput(){
	double num;
	do{
		cin >> num;
		if(num <= 0){
			cout << "ERROR! Enter only positive number!\n";
		}
	}while(num <= 0);
	
	return num;
}
double area(double a,double b,double c,double s){
	double A;
	A = (s*(s-a)*(s-b)*(s-c));
	A = sqrt(A);
	return A;
}
double semiPerimeter(double a, double b, double c){
	double s;
	s = (a+b+c)/2;
	return s;
}
void display(double area, double semiPerimeter){
	cout << "\nThe Area is " <<  area << "\nThe semi perimeter is " << semiPerimeter;
}


