// HEADER FILE

#include<iostream>
using namespace std;


// BLUEPRINT

class account
{
	int acccountnumber;
	char name[50];
	int deposit;
	char type;

	public:
		void create_account();	//function to get data from user
		void show_account() const;	//function to show data on screen
		void modify();	//functiodn to add new data
		void dep(int);	//function to accept amount and add to balance amount
		void draw(int);	//function to accept amount and subtract from balance amount
		void report() const;	//function to show data in tabular format
		int returnaccountnumber() const;	//function to return account number
		int returndeposit() const;	//function to return balance amount
		char returntype() const;	//function to return type of account
}; 

void account::create_account()
{
	cout<<"\nEnter The Account No. :";
	cin>>acccountnumber;
	cout<<"\n\nEnter The Name of The Account Holder : ";
	cin.ignore();
	cin.getline(name,50);

	cout<<"\nEnter Type of The Account (C/S) : ";
	cin>>type;
	type=toupper(type);
	cout<<"\nEnter The Initial Amount(>=500 for Saving and >=1000 for current ) : ";
	cin>>deposit;
	cout<<"\n\n\nAccount Created..";
}

void account::show_account() const
{
	cout<<"\nAccount No. : "<<acccountnumber;
	cout<<"\nAccount Holder Name : ";
	cout<<name;
	cout<<"\nType of Account : "<<type;
	cout<<"\nBalance amount : "<<deposit;
}

void account::modify()
{
	cout<<"\nAccount No. : "<<acccountnumber;
	cout<<"\nModify Account Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nModify Type of Account : ";
	cin>>type;
	type=toupper(type);
	cout<<"\nModify Balance amount : ";
	cin>>deposit;
}

void account::dep(int x)
{
	deposit+=x;
}
	
void account::draw(int x)
{
	deposit-=x;
}
	
void account::report() const
{
	cout<<acccountnumber<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<deposit<<endl;
}
	
int account::returnaccountnumber() const
{
	return acccountnumber;
}

int account::returndeposit() const
{
	return deposit;
}

char account::returntype() const
{
	return type;
}

// FUNCTION DECLARATION

void write_account();	//function to write record in binary file
void display_sp(int);	//function to display account details given by user
void modify_account(int);	//function to modify record of file
void delete_account(int);	//function to delete record of file
void display_all();		//function to display all account details
void deposit_withdraw(int, int); // function to desposit/withdraw amount for given account
void intro();	//introductory screen function

// MAIN

int main() 
{

	char ch;
	int num;
	intro();
	do
	{
		system("cls");

		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. NEW ACCOUNT";
		cout<<"\n\n\t02. DEPOSIT AMOUNT";
		cout<<"\n\n\t03. WITHDRAW AMOUNT";
		cout<<"\n\n\t04. BALANCE ENQUIRY";
		cout<<"\n\n\t05. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\n\t06. CLOSE AN ACCOUNT";
		cout<<"\n\n\t07. MODIFY AN ACCOUNT";
		cout<<"\n\n\t08. EXIT";
		cout<<"\n\n\tSelect Your Option (1-8) ";
		cin>>ch;

		system("cls");

		switch(ch)	
		{
		case '1':
			write_account();
			break;
		case '2':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 1);
			break;
		case '3':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 2);
			break;
		case '4': 
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			display_sp(num);
			break;
		case '5':
			display_all();
			break;
		case '6':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			delete_account(num);
			break;
		 case '7':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			modify_account(num);
			break;
		 case '8':
			cout<<"\n\n\tThanks for using bank managemnt system";
			break;
		 default :cout<<"\a";
		}
	}
}

// INTRO FUNCTION
void intro()
{
	cout<<"\n\n\n\t  BANK";
	cout<<"\n\n\tMANAGEMENT";
	cout<<"\n\n\t  SYSTEM";
	cout<<"\n\n\n\nMADE BY : your name";
	cout<<"\n\nSCHOOL : your school name";
	cin.get();
}
