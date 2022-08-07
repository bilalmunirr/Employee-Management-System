#include <iostream>
#include <iomanip>
#include<string.h>
#include<fstream>
#include<conio.h>

using namespace std;

#include "admin.h"
#include "employee.h"




void scr()
{
		system("cls");
		system("color 8e");
	cout<<"\t\t************************************************************************************"<<endl;
	cout<<"\t\t#############		WELCOME TO EMPLOYEE MANAGEMENT SYSTEM	####################"<<endl;
	cout<<"\t\t************************************************************************************\n\n"<<endl;
}








void admin()
{
	int n=0,sel;
	n=admin_login();
					
	
	if(n == 1)
	{
	do
	{
		scr();	
		cout<<"\t\t\t1. Manage Employee."<<endl;
		cout<<"\t\t\t2. Allowance Criteria. "<<endl;
		cout<<"\t\t\t3. Upcoming Events."<<endl;
		cout<<"\t\t\t4. Employee Work History."<<endl;
		cout<<"\t\t\t5. Logout.";
		cout<<"\n\t\t\tSelect One of the above option";
		cin>>sel;
	switch(sel)
	{
		case 1:
			scr();
			int select;
			cout<<"\t\t\t1. View Specific Employee."<<endl;
			cout<<"\t\t\t2. View all Employee."<<endl;
			cout<<"\t\t\t3. Add Employee."<<endl;
			cout<<"\t\t\t4. Update Employee Info."<<endl;
			cout<<"\t\t\t5. Delete Employee."<<endl;
			cout<<"\t\t\t6. Back to Admin Menu."<<endl;
			cout<<"\n\t\t\t Select One of the above option";
			cin>>select;
			switch(select)
			{

				case 1:
					view_sp_emp();
					break;
				case 2:
					view_all_emp();
					break;
			
				case 3:
					employee_add();
					break;
				case 4:
					employee_edit();
					break;
				case 5:
					employee_remove();
					break;
	
				case 6:
					cout<<"Back to Admin Menu";
					break;
				default:
					cout<<"Unfortunately Option not Available. Please Select Valid Option.";


			
			}
			
			break;

		case 2:
			scr();
			allowance_criteria();
			break;
		case 3:
			scr();
			upcoming_events();
			break;
		case 4:
			scr();
			emp_work_history();
			break;

		case 5:
			scr();
			break;
		default:
			cout<<"Unfortunately Option not Available. Please Select Valid Option.";

	}
		
		
	}
	while(sel!=5);
	}
	
	
	else
	{
		cout<<" Can't Find Admin, Maybe You entered wrong Password";
	}
}






void employee_main(int index){
	scr();
	int sel;
	do
	{
		scr();
		cout<<"\t\t\t1. Your Information."<<endl;
		cout<<"\t\t\t2. Employee Allowance."<<endl;
		cout<<"\t\t\t3. Update Information."<<endl;
		cout<<"\t\t\t4. Logout.";
		cout<<"\n\t\t\t Select One of the above option";
		cin>>sel;
	switch(sel)
	{
		case 1:
			emp_info(index);
			break;

		case 2:
			emp_allownce();
			break;
		case 3:
			emp_edit(index);
			break;

		case 4:
			break;
		default:
			cout<<"\t\t\tUnfortunately Option not Available. Please Select Valid Option.";

	}
		
	}
	while(sel!=4);
}










