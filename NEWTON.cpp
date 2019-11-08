#include<iostream>
#include<string>
#include"coef.h"
using namespace std;

int main()
{
	cout<<"Explaination of commands:\n\n";
	cout<<"?input number-of-point x0 y0 x1 y1...xn yn /Input a new series of points.\n";
	cout<<"?add xn+1 yn+1 /Add a new point.\n";
	cout<<"?get x /Get the estimated value of f on x.\n";
	cout<<"?quit\n";
	cout<<"--------------------------------------------------------------------------\n";
	cout<<"Please follow the input format\nFormat:number-of-point x0 y0 x1 y1...xn yn\n";
	coef Polo; string command;
	Polo.input();
	cout<<"?";
	cin>>command;
	while(command!="quit"){
		if (command=="input")Polo.input();
		else if(command=="get"){
			double x;
			cin>>x;
			cout<<Polo.OutputValue(x)<<endl;
		}
		else if(command=="add"){
			double xx,yy;
			cin>>xx>>yy;
			Polo.Add(xx,yy);
			cout<<"Point added successfully!\n";
		}
		else cout<<"error: unknown command line!\n";
		cout<<"?";
		cin>>command;
	}
	return 0;
}
