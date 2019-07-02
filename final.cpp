//**************************************
//HEADER FILES USED IN THE PROGRAM ARE
//**************************************
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>
#include<windows.h>
using namespace std;
void gotoxy(int x, int y)
{
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h,c);
}
class payroll
{
char name[30];
char idno[20];
char desg[20];
char address[100];
char phoneno[20];
int year;
int month,day;
float basic,gradepay,hra;
float da,ta,pf;
double allowance;
float loan,ptax;
float itax,lic,deduction;
char grade,insurance;
float netsalary;


public:
void salaryslip();
payroll() //Default constructor
{
strcpy(name,"XYZ");
strcpy(idno,"121");
strcpy(desg,"ABC");
strcpy(address,"123abc");
strcpy(phoneno,"1111111111");
year=1900;
month=1;
day=1;
basic=0;
gradepay=0;
hra=0;
da=0;
ta=0;
pf=0;
allowance=0;
loan=0;
ptax=0;
itax=0;
lic=0;
deduction=0;
grade='A';
insurance='Y';
netsalary=0;

}
char * retname()
{
return name;
}
char * retidno()
{
 return idno;
}
float retsalary()
{
return netsalary;
}
int retgrade()
{
return grade;
}
void calculate();
void show();
void get();


};

//**************************************************
//FUNCTION TO CALCULATE THE DETAILS OF THE EMPLOYEE
//**************************************************

void payroll::calculate()
{
double c=200000.0;
double d=500000.0;

hra=(0.2)*(basic+gradepay);
da=(1.08)*(basic+gradepay);
ta=1600;
allowance=hra+da+ta;
if(((basic+allowance)*12)<=c)
{
grade='A';
ptax=200;
pf=(0.1*basic);
deduction=pf+loan+itax+ptax+lic;
}
else
 if(((basic+allowance)*12)>c && ((basic+allowance)*12)<=d)
 {
 grade='B';
 ptax=200;
 pf=0.1*basic;
 itax=(0.1)*(basic+allowance);
 deduction=pf+loan+itax+ptax+lic;
 }
 else
  if(((basic+allowance)*12)>d)
  {
  grade='C';
  ptax=200;
  pf=0.1*basic;
  itax=(0.2)*(basic+allowance);
  deduction=pf+loan+itax+ptax+lic;
  }

netsalary=(basic+allowance)-deduction;
}

void payroll::salaryslip()
{
system("cls");
calculate();
cout<<"\t\tBRAHMOTECH INDIA PVT. LTD.";
cout<<"\nName: ";
cout<<name;
cout<<"\nID number: ";
cout<<idno;
cout<<"\nDesignation: ";
cout<<desg;
cout<<"\nDate of joining: "<<day<<"-"<<month<<"-"<<year;
cout<<"\nGrade: ";
cout<<grade;
cout<<"\nBasic: ";
cout<<basic;
cout<<"\nGrade pay: ";
cout<<gradepay;
cout<<"\n-----------------------------------------------------------------------------" ;
cout<<"\nAllowance:";
cout<<"\nHRA: " ;
cout<<hra;
cout<<"\nDA: ";
cout<<da;
cout<<"\nTA: " ;
cout<<ta;
cout<<"\n\n\n-----------------------------------------" ;
cout<<"\nTotal allowance: ";
cout<<allowance;
cout<<"\n-----------------------------------------" ;
gotoxy(42,10);
cout<<"Deductions:";
gotoxy(42,11);
cout<<"PF: "<<pf ;
gotoxy(42,12);
cout<<"Loan: "<<loan;
gotoxy(42,13);
cout<<"Professional tax: "<<ptax;
gotoxy(42,14);
cout<<"Income tax: "<<itax;
if(insurance=='Y'|| insurance=='y')
{
gotoxy(42,15);
cout<<"Monthly premium: ";
cout<<lic;
}
else
{
gotoxy(42,15);
cout<<"Monthly premium: 0" ;
}
gotoxy(42,16);
cout<<"------------------------------------" ;
gotoxy(42,17);
cout<<"Total deduction: "<<deduction;
gotoxy(42,18);
cout<<"------------------------------------" ;
cout<<"\n\n\t\tNet Salary: ";
cout<<netsalary;
cout<<endl;
}
//*********************************************
//FUNCTION TO SHOW THE DETAILS OF THE EMPLOYEE
//*********************************************

void payroll::show()
{
calculate();
cout<<"\nName of the Employee: ";
cout<<name;
cout<<"\nID number of "<<name<<": ";
cout<<idno;
cout<<"\nDesignation: ";
cout<<desg;
cout<<"\nAddress of "<<name<<": ";
cout<<address;
cout<<"\nPhone number: ";
cout<<phoneno;
cout<<"\nDate of joining: "<<day<<"-"<<month<<"-"<<year;
cout<<"\nBasic: ";
cout<<basic;
cout<<"\nGrade pay: ";
cout<<gradepay;
cout<<"\n\nAllowance:";
cout<<"\nHRA: " ;
cout<<hra;
cout<<"\nDA: ";
cout<<da;
cout<<"\nTA: " ;
cout<<ta;
cout<<"\nTotal allowance: ";
cout<<allowance;
cout<<"\n\nDeductions:";
cout<<"\nPF: " ;
cout<<pf;
if(loan==0)
{
cout<<"\nLoan amount is: 0 ";
}
else
cout<<"\nLoan amount is: "<<loan;
cout<<"\nProfessional tax: ";
cout<<ptax;
cout<<"\nIncome tax: ";
cout<<itax;
cout<<"\nTotal deduction: "<<deduction;
cout<<"\nGrade: ";
cout<<grade;
if(insurance=='Y'|| insurance=='y')
{
cout<<"\nInsurance: Yes\nMonthly premium: ";
cout<<lic;
}
else
{
cout<<"\nNo insurance." ;
}
cout<<"\n\nNet Salary: ";
cout<<netsalary;
cout<<endl;
}

//*********************************************
//FUNCTION TO GET THE DETAILS OF THE EMPLOYEE
//*********************************************

void payroll::get()
{
cout<<"\nEnter the name of the Employee: ";
gets(name);
cout<<"Enter the ID number of "<<name<<": ";
gets(idno);
cout<<"Enter the designation: ";
gets(desg);
cout<<"Enter the address of "<<name<<": ";
gets(address);
cout<<"Enter the phone number: ";
cin>>phoneno;
cout<<"Enter the date of joining";
cout<<"\nYear: ";
cin>>year;
if(year<1900 || year>2015)
{
do
{
 cout<<"Enter valid year: ";
 cin>>year;
}
while(year<1900 || year>2015);
}
cout<<"Month: ";
cin>>month;
if(month<1|| month>12)
{
do
{
 cout<<"Enter valid month: ";
 cin>>month;
}
while(month<1|| month>12);
}
cout<<"Day: " ;
cin>>day;
if(((month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) && (day<1 || day>31)) || ((month==4 || month==6 || month==9 || month==11) && (day<1 || day>30)) || (month==2) && (day<1||day>28))
{
do
{
cout<<"Enter valid day: ";
cin>>day;
}
while(((month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) && (day<1 || day>31)) || ((month==4 || month==6 || month==9 || month==11) && (day<1 || day>30)) || (month==2) && (day<1||day>28)) ;
}
cout<<"Enter Basic: ";
cin>>basic;
cout<<"Enter grade pay: ";
cin>>gradepay;
cout<<"Enter loan amount: ";
cin>>loan;
cout<<"Does the employee have an insurance:(Y/N) ";
cin>>insurance;
if(insurance=='Y'|| insurance=='y')
{
cout<<"Enter the monthly premium: ";
cin>>lic;
}
}


void hscreen()
{
system("cls");
cout<<"\n\n\n\t\t  * * * * * * * * * * * * * * * * * * * * * *";
cout<<"\n\t\t  *                 WELCOME                 *";
cout<<"\n\t\t  *         BRAHMOTECH INDIA PVT. LTD.      *";
cout<<"\n\t\t  *                                         *";
cout<<"\n\t\t  *\tPlease choose your option:          *"<<endl;
cout<<"\t\t  *\t1. Add new employee.                *"<<endl;
cout<<"\t\t  *\t2. Display.                         *"<<endl;
cout<<"\t\t  *\t3. Salary slip.                     *"<<endl;
cout<<"\t\t  *\t4. Modify employee's details.       *"<<endl;
cout<<"\t\t  *\t5. Delete employee's details.       *"<<endl;
cout<<"\t\t  *\t6. Quit.                            *";
gotoxy(18,15);
cout<<" *                                         *";
gotoxy(18,16);
cout<<" *                                         *";
gotoxy(25,16);
cout<<"Input:";
cout<<"\n\t\t  * * * * * * * * * * * * * * * * * * * * * *";
}

void hscreen1()
{
system("cls");
gotoxy(22,5);
cout<<"***************************************";
gotoxy(22,6);
cout<<"***************************************";
gotoxy(28,8);
cout<<"PAYROLL MANAGEMENT SYSTEM           "<<endl;
gotoxy(22,10);
cout<<"   A Project by N.Nithin Srivatsav     ";
gotoxy(22,12);
cout<<"***************************************";
gotoxy(22,13);
cout<<"***************************************";
gotoxy(22,14);
cout<<"Press any key to continue.";
getch();
}




void getinfo()
{
payroll s;
ofstream out("Employee.dat",ios::binary | ios::app);
char a;
do
{
s.get();
out.write((char*)&s,sizeof(s));
cout<<"Do you want to enter more..?(Y/N): ";
cin>>a;
}
while(a=='Y' || a=='y');
out.close();
}

void showinfo()
{
payroll s1;
ifstream in1("Employee.dat",ios::binary);
in1.seekg(0);
in1.read((char*)&s1,sizeof(s1));
while(in1)
{
s1.show();
in1.read((char*)&s1,sizeof(s1));
cout<<"Press any key to continue..";
getch();
system("cls");
}
in1.close();
}

//**********************************************************
//FUNCTION TO SEARCH THE PAYSLIP OF THE EMPLOYEE USING NAME
//**********************************************************

void searchname()
{
char a[30];
int f=0;
cout<<"Enter the name of the employee to be searched and displayed: " ;
gets(a);
payroll s2;
ifstream in1("Employee.dat",ios::binary);
in1.seekg(0);
in1.read((char*)&s2,sizeof(s2));
while(in1)
{
if(strcmp(s2.retname(),a)==0)
{
f++;
s2.salaryslip();
}
in1.read((char*)&s2,sizeof(s2));
}
in1.close();
if(f==0)
{
cout<<"Sorry..Record not found.";
}
}

//***************************************************************
//FUNCTION TO SEARCH THE PAYSLIP OF THE EMPLOYEE USING ID NUMBER
//***************************************************************

void searchidno()
{
char a[30];
int f=0;
cout<<"Enter the name of the employee to be searched and displayed: " ;
gets(a);
payroll s2;
ifstream in1("Employee.dat",ios::binary);
in1.seekg(0);
in1.read((char*)&s2,sizeof(s2));
while(in1)
{
if(strcmp(s2.retidno(),a)==0)
{
f++;
s2.salaryslip();
}
in1.read((char*)&s2,sizeof(s2));
}
in1.close();
if(f==0)
{
cout<<"Sorry..Record not found.";
}
}

//**********************************************************
//FUNCTION TO DELETE THE DETAILS OF THE EMPLOYEE USING NAME
//**********************************************************
void delbyname()
{
int f=0;
payroll s4;
char n[30];
ofstream out("temp.dat",ios::binary);
ifstream in("Employee.dat",ios::binary);
in.seekg(0);
in.read((char*)&s4,sizeof(s4));
cout<<"\nEnter the name of the employee whose record is to be deleted: "<<endl;
cin>>n;
while(in)
{
	 if(strcmp(s4.retname(),n)==0)
	 {
		  f++;
		  cout<<"Record FOUND and DELETED..! "<<endl;
		  s4.show();
		  in.read((char*)&s4,sizeof(s4));
	 }
	else
	{
		 out.write((char*)&s4,sizeof(s4));
		 in.read((char*)&s4,sizeof(s4));

	}
}
in.close();
out.close();
remove("Employee.dat");
rename("temp.dat","Employee.dat");
if(f==0)
{
	 cout<<"Sorry.Record not found..!\n";
}
}


//***************************************************************
//FUNCTION TO DELETE THE DETAILS OF THE EMPLOYEE USING ID NUMBER
//***************************************************************


void delbyidno()
{
int f=0;
payroll s5;
char n[20];
ofstream out("temp.dat",ios::binary);
ifstream in("Employee.dat",ios::binary);
in.seekg(0);
in.read((char*)&s5,sizeof(s5));
cout<<"\nEnter the ID number of the employee whose record is to be deleted: "<<endl;
cin>>n;
while(in)
{
	 if(strcmp(s5.retidno(),n)==0)
	 {
		  f++;
		  cout<<"Record FOUND and DELETED..! "<<endl;
		  s5.show();

		  in.read((char*)&s5,sizeof(s5));
	 }
	else
	{
		 out.write((char*)&s5,sizeof(s5));
		 in.read((char*)&s5,sizeof(s5));
	}
}
in.close();
out.close();
remove("Employee.dat");
rename("temp.dat","Employee.dat");
if(f==0)
{
	 cout<<"Sorry. Record not found..!\n";
}
}


//**********************************************************
//FUNCTION TO MODIFY THE DETAILS OF THE EMPLOYEE USING NAME
//**********************************************************

void modbyname()
{
ifstream a("Employee.dat",ios::binary);
ofstream a1("temp.dat",ios::binary);
a.seekg(0);
int fd=0;
char r[30];
payroll s6;
cout<<"Enter the name of the employee to be edited."<<endl;
cin>>r;
a.read((char *)&s6,sizeof(s6));
while(a)
{ if(strcmp(s6.retname(),r)==0)
  {fd++;
	cout<<"\nThe record is found...\n";
	s6.get();
	a1.write((char *)&s6,sizeof(s6));
	a.read((char *)&s6,sizeof(s6));
	cout<<"The Record is modified.";
  }
  else
  {
	a1.write((char *)&s6,sizeof(s6));
	a.read((char *)&s6,sizeof(s6));
	}

 }
a1.close();
if(fd==0)
 cout<<"\nSorry record not found.";
a.close();
remove("Employee.dat");
rename("temp.dat","Employee.dat");

}


//***************************************************************
//FUNCTION TO MODIFY THE DETAILS OF THE EMPLOYEE USING ID NUMBER
//***************************************************************

void modbyidno()
{
ifstream a("Employee.dat",ios::binary);
ofstream a1("temp.dat",ios::binary);
a.seekg(0);
int fd=0;
char r[20];
payroll s7;
cout<<"Enter the IDno of the employee to be edited."<<endl;
cin>>r;
a.read((char *)&s7,sizeof(s7));
while(a)
{ if(strcmp(s7.retidno(),r)==0)
  {fd++;
	cout<<"\nThe record is found...\n";
	s7.get();
	a1.write((char *)&s7,sizeof(s7));
	a.read((char *)&s7,sizeof(s7));
	cout<<"The Record is modified.";
  }
  else
  {
	a1.write((char *)&s7,sizeof(s7));
	a.read((char *)&s7,sizeof(s7));
	}

 }
a1.close();
if(fd==0)
 cout<<"\nSorry record not found.";
a.close();
remove("Employee.dat");
rename("temp.dat","Employee.dat");

}

int nor()
{
int f=0;
payroll s5;
ifstream in("Employee.dat",ios::binary);
in.seekg(0);
in.read((char*)&s5,sizeof(s5));
while(in)
{
	 f++;
	 in.read((char*)&s5,sizeof(s5));

}
in.close();
return f;
}


int main()      //MAIN PROGRAMME
{
int f;
char a,b;
hscreen1();
do
{
hscreen();
gotoxy(31,16);
cin>>a;
system("cls");
switch (a)
{
case '1': f=nor();
			 getinfo();
			 cout<<"\nPress any key to continue.";
			 getch();
			 break;
case '2': f=nor();
			 if(f!=0)
			 {
			 showinfo();
			 }
			 else
			 cout<<"Sorry..There are no records in the file.";
			 cout<<"\nPress any key to continue.";
			 getch();
			 break;
case '3': f=nor();
			 if(f!=0)
			 {
			 cout<<"Search for salary slip by:\n1.Name\n2.ID Number"<<endl;
			 cin>>b;
			 if(b=='1')
			 searchname();
			 else
			  if(b=='2')
			  searchidno();
			  else
				cout<<"Wrong option.";
			 }
			 else
			 cout<<"Sorry..There are no records  in the file.";
			 cout<<"\nPress any key to continue.";
			 getch();
			 break;
case '4': f=nor();
			 if(f!=0)
			 {
			 cout<<"Modify by:\n1.Name\n2.ID Number"<<endl;
			 cin>>b;
			 if(b=='1')
			 modbyname();
			 else
			  if(b=='2')
				modbyidno();
				else
				 cout<<"Wrong option";
			 }
			 else
			 cout<<"Sorry..There are no records  in the file.";
			 cout<<"\nPress any key to continue.";
			 getch();
			 break;
case '5': f=nor();
			 if(f!=0)
			 {
			 cout<<"Delete by:\n1.Name\n2.ID Number"<<endl;
			 cin>>b;
			 if(b=='1')
			 delbyname();
			 else
			  if(b=='2')
				delbyidno();
				else
				 cout<<"Wrong option";
			 }
			 else
			 cout<<"Sorry..There are no records  in the file.";
			 cout<<"\nPress any key to continue.";
			 getch();
			 break;
default:	 if(a!='6')
			 {
			  cout<<"Wrong option!!\nPress any key to continue.";
			  getch();
			 }
			 else
			  {
			  gotoxy(37,11);
			  cout<<"THANK YOU";
			  }
}
}
while(a!='6');
return 0;
}
