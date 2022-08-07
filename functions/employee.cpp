#include <iostream>
#include <iomanip>
#include<string.h>
#include<fstream>
#include<conio.h>

using namespace std;
#include "functions.h"

int emp_login()
{
	scr();
	int n=0;
	string pass,pass_check;
	cout<<"\n\t\t\tEmployee Selected\n";
	cout<<"\n\n\t\t\tEnter Password:";
	getline(cin,pass);
	ifstream data;
	data.open("files\\emp_pass.txt");
	if( data.is_open())
	{
	
		while(!data.eof()){
			getline(data,pass_check);
		for(int i=0; i<7; i++)
			if(pass==pass_check){
				
				cout<<"\t\t\tSucess!";
				employee_main(n);
				break;
			}
			n++;
		}
	}
	else
	{
		cout<<"\t\t\tFile not found!";
	}
	
	data.close();

}






void emp_info(int index)
{
	scr();
	int n=0;
	string data;
	ifstream file;
	file.open("files\\employee_data.txt");
	if(file.is_open())
	{
		cout<<"Name\tAge\tBasic_Sal\tCNIC";
		while(!file.eof())
		{
			
			getline(file,data);
			if(n==index)
			{
				cout<<data<<endl;
				break;
			}
			n++;
		}
	}
	else
	{
		cout<<"\t\t\tFile Not Found!";
	}
		
	cout<<"\t\t\tPress Any Key to Go back";
	getch();
	
}

void emp_allownce()
{
	scr();
	int salary;
	float gross_salary,allowance,tax;
	cout<<"\t\t\tEnter Your Basic Salary.";
	cin>>salary;
	gross_salary = salary+ (salary*0.125);
	allowance = salary*0.10;
	tax = salary*0.025;
	
	cout<<"\t\t\tGross Salary --------> Rs."<<gross_salary<<endl;
	cout<<"\t\t\tAllowances --------> Rs."<<allowance<<endl;
	cout<<"\t\t\tBasic Salary --------> Rs."<<salary<<endl;
	cout<<"\t\t\tTax     --------> Rs."<<tax<<endl;
	cout<<"\t\t\t Press any key to goback.";
	getch();
 } 

void emp_edit(int index)
{
	scr();
	int n=0;
	string name,age,bsal,CNIC,pass,tem,data;
	ifstream file("files\\employee_data.txt");
	ofstream temp("files\\temp.txt" ,ios::app);
	while (!file.eof())
	{
		
		getline(file,data);
		if(n!=index)
		{
				temp<<data<<endl;
	}
		else{
			
				cin.ignore();
			cout<<"\t\t\tRe-Enter Your Info. "<<endl;
			cout<<"\t\t\tEnter Name: ";
			getline(cin,name);
			temp<<name<<"\t";
			cout<<"\t\t\tEnter Age. ";
			getline(cin,age);
			temp<<age<<"\t";
			cout<<"\t\t\tEnter Basic Salary. ";
			getline(cin,bsal);
			temp<<bsal<<"\t";

			cout<<"\t\t\tEnter CNIC. ";
			getline(cin,CNIC);
			temp<<CNIC<<endl;

			
			
		}
		n++;
}
	file.close();
	temp.close();

	remove("files\\employee_data.txt");
	int res;
	res = rename("files\\temp.txt","files\\employee_data.txt");
	if(res == 0)
	{
		cout<<"\n\t\t\tSuccessfully Updated.";
	}
	else
	{
		cout<<"\t\t\tCan't Update.";
	}
cout<<"\t\t\tPress any key to goback.";
getch();


}


