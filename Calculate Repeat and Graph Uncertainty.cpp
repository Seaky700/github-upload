#include <iostream>
#include <string>
#include <sstream>
#include<conio.h>
#include<math.h>
using namespace std;

void least_square_method(int l);
//function that print the data inside a stored arrays
void print_array(double arg[], int l){
	for (int n = 0; n < l; ++n){
		cout << arg[n] << "  ";
	}
	cout << '\n';
}


double Sum(double arg[],int l)
{
	double result_1, result_2;
	for (int n = 0; n < l; ++n)
	{
		result_1 += arg[n];
	}
	//result_1 = result_1 / l;
	return (result_1);
}


double Sum_square(double arg [],int l)
{
	double result_2=0;
	for (int n = 0; n < l; ++n)
	{
		result_2 = result_2 + (arg[n] * arg[n]);
	}	
	return (result_2);
}

double Variance(double sum, double sum2, int l)
{
	double result = 0;
	result = sum2/(l-1) - sum*sum/l/(l-1);
	result = pow(result, 0.5);
	return (result);
}

int main(){
	
	start:
	string Input_type;
	int Choose_type=0 ;
	
	do{
		
		cout << "Choose which calculation. "<<endl;
		cout << "1) Uncertainty for Repeating Value. " <<endl
			 << "2) Uncertaity for Graph (Least Square Method)" <<endl;
		getline(cin,Input_type);
		stringstream(Input_type) >> Choose_type;
		
	}while (Choose_type < 1 or Choose_type > 2);
	
	if (Choose_type == 1){
		goto Calculate_Standard_Deviation;
	}else{
		cout << "How many Data ? \n";
		
		string get_value, get_reply;
		int data_length;
		
		getline(cin,get_value);
		stringstream(get_value) >> data_length;
		
		least_square_method(data_length);
		
		do{
			
			cout << "Want to Continue ? (Y/N)";
			getline(cin,get_reply);
			if (get_reply == "Y" || get_reply == "y"){
				cout <<endl;
				goto start;
			}
			else{
				cout << "Thanks for using "<<endl;
				cout << "Powered by Jiande."<<endl;
			}
		}while (get_reply != "Y" || get_reply != "y" || get_reply != "N" || get_reply != "n");
		
		
	}

	
	Calculate_Standard_Deviation: 
	//Get the value
	string in_value;
	int data, num_data;
	int count = 0;
	double sum, mean, sum_square, variance;
	//Determin how much number of data.
	cout << "How many Data ?"<<'\n';
	getline(cin,in_value);
	stringstream(in_value) >> num_data;
	double class_1[num_data];
	//Looping until it filled all the data
	for(int n=0; n < num_data; ++n){
		cout << n + 1 << " Value " << '\n';
		getline(cin,in_value);
		stringstream(in_value) >> class_1[n];
	}
	
/*	print_array(class_1, num_data);  */
	sum = Sum(class_1, num_data);
	mean = sum/num_data;
	sum_square = Sum_square(class_1, num_data);
	variance = Variance(sum, sum_square, num_data);
	cout << "\nAverage is "<<mean <<" and sum of square is "<<sum_square << " and sum is "<<sum <<endl;
	cout << "Your uncertianty is approximate "<<variance <<endl;
	cout << endl;
	
	reply:
	cout << "Still want continue? "<<endl;
	cout << "Enter Y for Yes and N for No"<<endl;
	string my_reply;
	cin >> my_reply;
	cout << endl;
	if (my_reply == "Y" or my_reply== "y")
	{
		cin.ignore();
		goto start;
	}
	else if (my_reply == "N" or my_reply == "n")
	{
		cout << "Thanks for using "<<endl;
		cout << "Powered by Jiande."<<endl;
	}
	else
	{
		cout << "INVALID INPUT!!!(Only accept Y/N) "<<endl;
		goto reply;

	}
	
}

void least_square_method(int l)
{
	string get_value;
	double X[l], Y[l];
	double sumX=0, sumY=0;
	double meanX=0, meanY=0;
	double squareX=0, squareY=0;
	double sumXY=0;
	double delta=0, mxC=0, YmxC=0, YmxC2=0, variance2=0;
	double m=0, C=0, un_m=0, un_C=0, var_m=0, var_C=0;
	
	//Get X-axis value
	cout << "\nEnter X value \n";
	for (int n = 0;n < l; n++){
		
		printf("%d Value \n",n+1);
		getline(cin,get_value);
		stringstream(get_value) >> X[n];
		sumX += X[n];
		squareX += X[n]*X[n];
	}
	
	//Get Y-asix value
	cout << "\nEnter Y value \n";
	for (int n = 0;n < l; n++){
		
		printf("%d Value \n",n+1);
		getline(cin,get_value);
		stringstream(get_value) >> Y[n];
		sumY += Y[n];
		squareY += Y[n]*Y[n];
	}
	
	//Calculate mean X and Y
	meanX = sumX/l;
	meanY = sumY/l;
	printf("Mean X is %.3f, Mean Y is %.3f \n", meanX, meanY);
	
	//Calculate Delta
	delta = l*squareX - (sumX * sumX);
	
	//calculate submation of xy
	for (int n = 0; n < l; n++){
		
		sumXY += X[n] * Y[n];
	}
	printf("Delta is %.3f, Submation of X is %.3f, Submation of Y is %.3f, Submation of X square is %.3f, Submation of XY is %.3f\n"
		,delta, sumX, sumY, squareX, sumXY);
	
	//calculate Gradient and Y-intercept
	m = (l*sumXY - sumX*sumY)/delta;
	C = (squareX*sumY - sumX*sumXY)/delta;
	
	//Calculate Variance
	for(int n=0; n<l; n++){
		
		mxC = (m*X[n] + C);
		YmxC2 += (Y[n]-mxC) * (Y[n]-mxC);
		//YmxC2 += YmxC*YmxC;
	}
	cout <<endl;
	variance2 = (YmxC2)/(l-2);
	
	//Calculate uncertainty of gradient and y-intercept
	var_m = l * (variance2/delta);
	var_C = (variance2/delta)*squareX;
	un_m = pow(var_m, 0.5);
	un_C = pow(var_C, 0.5);
	
	printf("Varaince is %.3f, Submation of Y-mx+C ^2 is %.3f\n", variance2, YmxC2);
	printf("Gradient = %.3f +- %.3f, Y-intercept = %.3f +- %.3f\n\n", m, un_m, C, un_C);
	
}
