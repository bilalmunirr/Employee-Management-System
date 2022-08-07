#include<iostream>
using namespace std;

#include"functions\\functions.h"
#include"functions\\employee.h"

int main() {
	
	int n;
	do
	{
	
		scr();
	cout<<"\t\t\t 1. Admin\n\t\t\t 2. Employee\n\t\t\t 3. Exit\n\t\t\t Select Role:";
	cin>>n;
	cin.ignore();
	switch(n)
	{
		case 1:
			admin();
			break;
		case 2:
			emp_login();
			break;
		case 3:
			break;
		default:
			cout<<"Wrong Input.";
	}
	}
	while(n!=3);
	return 0;
}



