#include <iostream>
#include <iomanip>
#include<string.h>
#include<fstream>
#include<conio.h>
using namespace std;

#include "functions.h"
int admin_login()
{
	scr();
	bool check=false;
	string pass,pass_check;
	cout<<"\t\t\tAdmin Selected\n";
	cout<<"\n\t\t\tEnter Password:";
	getline(cin,pass);
	ifstream data;
	data.open("files\\admin_password.txt");
	if( data.is_open())
	{
	
		while(!data.eof()){
			getline(data,pass_check);
			if(pass==pass_check){
				cout<<"sucess:";
				check=true;
				break;
			}
		}
	}
	else
	{
		cout<<"\t\t\tFile not found!";
		
	}
	
	data.close();
		if(check)
		{
			return 1;
			}	
		else
		{
			return 0;
		}
}




//=============================================================

void view_sp_emp()
{
	scr();
	cin.ignore();

	string name,data;
	cout<<"\t\t\tEnter Name of Employee You want to see.";
	getline(cin,name);
	ifstream file;
	file.open("files\\employee_data.txt");
	if(file.is_open())
	{
		while(!file.eof())
		{
						
			file>>data;
			if(data==name)
				{

				for(int i=0; i<4; i++)
				{

						cout<<data<<"\t";
						file>>data;
					}
				}
		}
	}
	
	getch();
}


void view_all_emp()
{
	scr();
	cin.ignore();
	string data;
	ifstream file;
	file.open("files\\employee_data.txt");
	if(file.is_open())
	{
		cout<<"Name\tAge\tBasic_Sal\tCNIC";
		while(!file.eof())
		{
			getline(file,data);
			cout<<data<<endl;
		}
	}
	getch();
}

	



//=================================================================
















void employee_add()
{
	scr();
	string name,age,bsal,CNIC,experience,company,position,passw;
	ofstream file;
	ofstream hist;
	hist.open("files\\emp_history.txt",ios::app);
	file.open("files\\employee_data.txt",ios::app);
	cin.ignore();
	cout<<"\t\t\t----------------Personal Information-----------";
	cout<<endl<<"\t\t\tEnter name of employee: ";
	getline(cin,name);	
	cout<<endl<<"\t\t\tEnter age of employee: ";
	getline(cin,age);
	cout<<endl<<"\t\t\tEnter basic salary of employee: ";
	getline(cin,bsal);
	cout<<endl<<"\t\t\tEnter CNIC number of Employee : ";
	getline(cin,CNIC);
	file<<name<<"\t"<<age<<"\t"<<bsal<<"\t"<<CNIC<<endl;
	
	cout<<"\n\n\t\t\t----------------Work Information-------------";
	cout<<"\n\t\t\tNote: IF DIDN'T WORKED BEFORE JUST ANSWER NOTHING\n\n";
	cout<<"\t\t\tIn which Company do You work before: ";
	getline(cin,company);
	
	cout<<"\t\t\tHow Much Experience Do you have: ";
	getline(cin,experience);
	cout<<"\t\t\tOn what position(grade) you were working: ";
	getline(cin,position);
	hist<<name<<"\t"<<company<<"\t"<<experience<<"\t"<<position<<endl;
	hist.close();
	ofstream pass;
	pass.open("files\\emp_pass.txt",ios::app);
	cout<<"\t\t\tEnter Password for user.";
	getline(cin,passw);
	pass<<passw<<endl;
	pass.close();
	file.close();
	cout<<"\t\t\tPress any key to goback.";
	getch();
}


void employee_remove()
{
	scr();
	cin.ignore();
	string name,data,tem;
	cout<<"\t\t\tEnter Name to remove(Note all person with this name will be removed)";
	getline(cin,name);
	ifstream file("files\\employee_data.txt");
	ofstream temp("files\\temp.txt" ,ios::app);
	while (!file.eof())
	{
			getline(file,data);
			tem=data;
		  	data.erase (data.begin()+name.length(), data.end());   // Making file line equal to given by user......
		  
		if(name.compare(data)==0)
		{
			cout<<"\t\t\tSuccessfully Removed!";
		}
		else{
				temp<<tem<<endl;
			
		}
	}
	file.close();
	temp.close();
	
	remove("files\\employee_data.txt");
	rename("files\\temp.txt","files\\employee_data.txt");
	
	cout<<"\t\t\tPress any key to goback.";
	getch();
}
void employee_edit()
{
	scr();
	cin.ignore();
	string ed_name,name,age,bsal,CNIC,tem,data;
	cout<<"\t\t\tEnter Name of Employee You want to Change: ";
	getline(cin,ed_name);
	ifstream file("files\\employee_data.txt");
	ofstream temp("files\\temp.txt" ,ios::app);
	while (!file.eof())
	{
			getline(file,data);
			tem=data;
		  	data.erase (data.begin()+ed_name.length(), data.end());   // Making file line equal to given by user......
		if(ed_name.compare(data)==0)
		{
			cout<<data;
			cout<<"\t\t\tRe-Enter All Info of Employee. "<<endl;
			cout<<"\n\t\t\tEnter Name: ";
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
		else{
				temp<<tem<<endl;
			
		}
	
}
	file.close();
	temp.close();

	remove("files\\employee_data.txt");
	int res;
	res = rename("files\\temp.txt","files\\employee_data.txt");
	if(res == 0)
	{
		cout<<"\n\t\t\tSuccessfully Updated!";
	}
	else
	{
		cout<<"\t\t\tCan't Update!";
	}
cout<<"\n\t\t\tPress any key to goback.";
getch();

}

void allowance_criteria()
{
	scr();
	cout<<"\n\n\t\t\tAllowance Criteria For Each Employee is 12.5% Of Their Basic Salary.\n2.5% of Which pay as a tax and remaining 10% is given as Allowances such as house,hospital, Transport etc. ";
	cout<<"\n\n\t\t\tPress any key to go back.";
	getch();
}


void upcoming_events()
{
	scr();
	int sel;
	string event;
	scr();
	cout<<"\t\t\t1. See Upcoming Events"<<endl;
	cout<<"\t\t\t2. Add Upcoming Evets"<<endl;
	cout<<"\t\t\t3. Back to Admin Menu"<<endl;
	cout<<"\t\t\tSelect one option.";
	cin>>sel;
	switch(sel)
	{
		case 1:
			{
			
			ifstream events;
			events.open("files\\events.txt");
			if(events.is_open())
			{
				
				
				
				
					cout<<"Name\tType\tDate";
					while(!events.eof())
					{
						getline(events,event);
						cout<<event<<endl;
					}

				
			}
			else
			{
				cout<<"\n\t\t\tFile not found!";
			}
			events.close();
			break;
			}
		case 2:
			{
			cin.ignore();
			ofstream event;
			string name,type,date;
			event.open("files\\events.txt");
			if(event.is_open())
			{
			
			cout<<"\t\t\tEnter Event Name: ";
			getline(cin,name);
			cout<<"\t\t\tEnter Event Type: ";
			getline(cin,type);
			cout<<"\t\t\tEnter Event Date: ";
			getline(cin,date);
			
			event<<name<<"\t"<<type<<"\t"<<date<<endl;
			}
			event.close();
			cout<<"\n\t\t\tSuccessfully Added!";
			break;
		}
		case 3:
			break;
		default:
			cout<<"O\n\t\t\tption Not available.";
			break;
			
	}
	cout<<"\t\t\tPress any key to go back to Admin Menu.";
	getch();

}



void emp_work_history()
{
	scr();
	int sel;
	string data;
	scr();
	
	cout<<"Note that: This Section Include the Record of Employee of previous companies where employee used to work.";
	cout<<"\n\n\t\t\t1. See All Employees History"<<endl;
	cout<<"\t\t\t2. See Specific Employee History"<<endl;
	cout<<"\t\t\t3. Back to Admin Menu"<<endl;
	cout<<"\t\t\tSelect one option.";
	cin>>sel;
	switch(sel)
	{
		case 1:
			{
						
			ifstream history;
			history.open("files\\emp_history.txt");
			if(history.is_open())
			{
				
				
				
				
					cout<<"Name\tCompany\tExperience\tPosition";		
					while(!history.eof())
					{
						getline(history,data);
						cout<<data<<endl;
					}

				
			}
			else
			{
				cout<<"\t\t\tFile not found!";
			}
			history.close();
			break;
			}
		case 2:
			{
			cin.ignore();
			string name,data;
			ifstream history;
			history.open("files\\emp_history.txt");
			if(history.is_open())
			{
				cout<<"\t\t\tEnter Name of Employee. ";
				getline(cin,name);
				
				
				
							
					while(!history.eof())
					{
						history>>data;	
						cout<<"Name\tCompany\tExperience\tPosition";
						if(data==name)
						{

							for(int i=0; i<4; i++)
							{

								cout<<data<<"\t";
								history>>data;
							}
						}

					}

				
			}
			history.close();
			break;
		}
		case 3:
			break;
		default:
			cout<<"\t\t\tOption Not available.";
			break;
			
	}
	cout<<"Press any key to go back to Admin Menu.";
	getch();

}





