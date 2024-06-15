#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>

void bus_company_f();
void driver_f();
void user_f();
void bus_company_login();
void bus_company_signup();
void bus_company_homepage(char []);
void driver_login();
void driver_signup();
void driver_homepage(char []);
void user_login();
void user_signup();
void user_homepage(char []);

struct bus_company
{
	char username[50];
	char pass[50];
	char name[50];
	int bus_number;
	char destinations[3][50];
};

struct driver
{
	char username[50];
	char pass[50];
	char real_name[100];
	char license_number[20];
	int experience;
	char recruit_status;
};

struct user
{
	char username[50];
	char pass[50];
	char real_name[100];
	char card[20];
	int age;
	char citizen_no[20];
};

int main()
{
	int user_choice,i;
	top:
	system("cls");
	printf("\n\n\t\t\t\t\t\t\tMeroGaadi");
	printf("\n\n\n\t\t\t\t\t  Nepal\'s 1st multipurpose Driving App!");
	printf("\n\n\n\t\t\t\t\t\t\tEnter As:");
	printf("\n+----------------------------------------------------------------------------------------------------------------------+");
	printf("\n\n\n\t  1. Bus Company");
	printf("\t\t\t\t2.Driver");
	printf("\t\t\t\t3. User");
	printf("\n\t     [Press 1]");
	printf("\t\t\t\t\t[Press 2]");
	printf("\t\t\t\t[Press 3]");
	printf("\n\n\n\n+----------------------------------------------------------------------------------------------------------------------+");
	printf("\n\n\n\t\t\t\t\t\t  Enter you choice: ");
	scanf("%d",&user_choice);
	switch (user_choice)
	{
		case 1:
			bus_company_f();
		break;
		case 2:
			driver_f();
		break;
		case 3:
			user_f();
		break;
		default:
			printf("\n\n\t\t\t\t\t\t     Invalid Input\n\t\t\t\t\t\t    Redirecting");
			for(i=5;i>=1;i--)
			{
				printf(".");
				Sleep(1000);
			}
			goto top;
	}
	return 0;
}


void bus_company_f()
{
	char register_choice,i;
	top:
	system("cls");
	printf("\n\n\n\t\t\t\t\t\t\tBus Company");
	printf("\n\n+----------------------------------------------------------------------------------------------------------------------+");
	printf("\n\n\t\t\t\t\t\t    Already Registered?");
	printf("\n\n\n\t\t\t\t\t\t\t    Yes\n\t\t\t\t\t\t    [Press 'y' or 'Y']");
	printf("\n\n\n\t\t\t\t\t\t\t     No\n\t\t\t\t\t\t    [Press 'n' or 'N']");
	printf("\n\n\n\t\t\t\t\t\t\t<-- Back\n\t\t\t\t\t\t    [Press 'e' or 'E']");
	printf("\n\n\n\t\t\t\t\t\t   Enter your choice:");
	fflush(stdin);
	scanf("%c",&register_choice);
	switch (register_choice)
	{
		case 'y':
		case 'Y':
			bus_company_login();
		break;
		case 'n':
		case 'N':
			bus_company_signup();
		break;
		case 'e':
		case 'E':
			printf("\n\n\t\t\t\t\t\tRedirecting to Home Page");
			for(i=5;i>=1;i--)
			{
				printf(".");
				Sleep(1000);
			}
			main();
		break;
		default:
			printf("\n\n\t\t\t\t\t\t     Invalid Input\n\t\t\t\t\t\t    Redirecting");
			for(i=5;i>=1;i--)
			{
				printf(".");
				Sleep(1000);
			}
			goto top;
	}
}

void bus_company_login()
{
	system("cls");
	struct bus_company b;
	int i,count=0;
	char userName[50],Pass[50];
	FILE *ptr;
	ptr = fopen("bus_company_login.bin","rb");
	if(ptr==NULL)
	{
		printf("\n\n\n\n\n\t\t\t\t\t  There is no bus company registered!");
		printf("\n\n\n\t\t\t\t\t     Redirecting to SigUp page");
		for(i=5;i>=1;i--)
		{
			printf(".");
			Sleep(1000);
		}
		bus_company_signup();
	}
	printf("\n\n\n\t\t\t\t\t\t\tBus Company");
	printf("\n\n\t\t\t\t\t\t\t Login Page");
	printf("\n\n+----------------------------------------------------------------------------------------------------------------------+");
	reenter:
	fflush(stdin);
	printf("\n\n\t\t\t\t\t\tEnter Username: ");
	gets(userName);
	fflush(stdin);
	printf("\n\n\t\t\t\t\t\tEnter Password: ");
	gets(Pass);
	while(!feof(ptr))
	{	
		fread(&b,sizeof(b),1,ptr);
		if(strcmp(b.username,userName)==0)
		{
			if(strcmp(b.pass,Pass)==0)
			{
				bus_company_homepage(b.username);
			}	
		}	
	}
	printf("\t\t\t\t\t  incorrect id or password! enter again");
	count++;
	if(count>=2)
	{
		printf("\n\n\t\t\t\t\t\t  Too many attempts!\n\n\t\t\t\t\t    Redirecting to Homepage!");
		for(i=5;i>=1;i--)
		{
			printf(".");
			Sleep(1000);
		}
			main();
	}
	goto reenter;
}

void bus_company_signup()
{
	system("cls");
	int i;
	struct bus_company b,temp_read;
	FILE *ptr;
	ptr = fopen("bus_company_login.bin","ab+");
	if(ptr == NULL)
	{
		printf("\n\n\n\n\t\t\t\t\tError in the server!Please Try again");
		for(i=5;i>=1;i--)
		{
			printf(".");
			Sleep(1000);
		}
		main();
	}
	printf("\n\n\n\t\t\t\t\t\t\tBus Company");
	printf("\n\n\t\t\t\t\t\t\tSignUp Page");
	printf("\n\n+----------------------------------------------------------------------------------------------------------------------+");
	fflush(stdin);
	printf("\n\n\t\t\t\t\t\tEnter Username: ");
	gets(b.username);
	fflush(stdin);
	pass_reenter:
	printf("\n\n\t\t\t\t\t\tEnter Password: ");
	gets(b.pass);
	if(strlen(b.pass)<8)
	{
		printf("\n\n\t\t\t\tPassword Length must be >7 and <50 characters! Try Again");
		goto pass_reenter;
	}
	system("cls");
	printf("\n\n\n\t\t\t\t\t\t\tBus Company");
	printf("\n\n\t\t\t\t\t\t\tSignUp Page");
	printf("\n\n+----------------------------------------------------------------------------------------------------------------------+");
	reenter_name:
	fflush(stdin);
	printf("\n\n\t\t\t\t\t\tEnter Name: ");
	gets(b.name);
	for(i=0;b.name[i]!='\0';i++)
	{
		if(!((b.name[i]>=65&&b.name[i]<=90)||(b.name[i]>=97&&b.name[i]<=122)||b.name[i]==' '))
		{
			printf("\n\n\t\t\t\tName of company can only be alphabets and space!");
			goto reenter_name;
		}
	}
	printf("\n\n\t\t\t\t\t\tTotal bus number: ");
	scanf("%d",&b.bus_number);
	system("cls");
	printf("\n\n\n\t\t\t\t\t\t\tBus Company");
	printf("\n\n\t\t\t\t\t\t\tSignUp Page");
	printf("\n\n+----------------------------------------------------------------------------------------------------------------------+");
	printf("\n\n\t\t\t\t\t\tEnter bus destinations:\n\n\t\t\t\t\t[Only 3 destinations are available currently]");
	for(i=0;i<3;i++)
	{
		fflush(stdin);
		printf("\n\n\t\t\t\t\tEnter destination %d: ",i+1);
		gets(b.destinations[i]);
	}
	fwrite(&b,sizeof(b),1,ptr);
	fclose(ptr);
	system("cls");
	printf("\n\n\n\t\t\t\t\t\t\tCongratulations!");
	printf("\n\n\n\t\t\t\t\tYour comapny has been successfully registered!");
	printf("\n\n\n\t\t\t\t\t\tLogin Now!");
	printf("\n\n\n\t\t\t\t\t\tRedirecting");
	for(i=5;i>=1;i--)
	{
		printf(".");
		Sleep(1000);
	}
	bus_company_login();
}

void bus_company_homepage(char username[])
{
	system("cls");
	int user_count=0,i,user_choice;
	FILE *ptr;
	ptr = fopen("bus_company_login.bin","rb+");
	if(ptr == NULL)
	{
		printf("\n\n\n\n\t\t\t\t\tError in the server!Please Try again");
		for(i=5;i>=1;i--)
		{
			printf(".");
			Sleep(1000);
		}
		main();
	}
	retry:
	printf("\n\n\n\t\t\t\t\t\t\tBus Company");
	printf("\n\n\t\t\t\t\t\t  Welcome User %s!",username);
	printf("\n\n+----------------------------------------------------------------------------------------------------------------------+");
	printf("\n\n\t\t\t\t\t\t\t  Features");
	printf("\n\n\n\t  1.Recruit Driver");
	printf("\t\t\t\t2.Increase Buses");
	printf("\t\t\t   3. Active Buses");
	printf("\n\t     [Press 1]");
	printf("\t\t\t\t\t  [Press 2]");
	printf("\t\t\t\t     [Press 3]");
	printf("\n\n\n\t        4.Log Out");
	printf("\t\t\t\t\t\t\t\t5.Settings");
	printf("\n\t         [Press 4]");
	printf("\t\t\t\t\t\t\t\t  [Press 5]");
	printf("\n\n\n\n+----------------------------------------------------------------------------------------------------------------------+");
	printf("\n\n\n\t\t\t\t\t\t  Enter you choice: ");
	fflush(stdin);
	scanf("%d",&user_choice);
	switch (user_choice)
	{
		case 1:
			printf("hello1");
		break;
		case 2:
			printf("hello2");
		break;
		case 3:
			printf("hello3");
		break;
		case 4:
			system("cls");
			printf("\n\n\n\n\t\t\t\t\t\t\tLogging Out");
			for(i=5;i>=1;i--)
			{
				printf(".");
				Sleep(1000);
			}
			main();
		break;
		case 5:
			printf("hello4");
		break;
		default:
			printf("\n\n\t\t\t\t\t\tInvalid Input! Try again");
			for(i=5;i>=1;i--)
			{
				printf(".");
				Sleep(1000);
			}
			system("cls");
			goto retry;
			
	}
}

void driver_f()
{
	char register_choice,i;
	top:
	system("cls");
	printf("\n\n\n\t\t\t\t\t\t\tDriver\'s Hub");
	printf("\n\n+----------------------------------------------------------------------------------------------------------------------+");
	printf("\n\n\t\t\t\t\t\t    Already Registered?");
	printf("\n\n\n\t\t\t\t\t\t\t    Yes\n\t\t\t\t\t\t    [Press 'y' or 'Y']");
	printf("\n\n\n\t\t\t\t\t\t\t     No\n\t\t\t\t\t\t    [Press 'n' or 'N']");
	printf("\n\n\n\t\t\t\t\t\t\t<-- Back\n\t\t\t\t\t\t    [Press 'e' or 'E']");
	printf("\n\n\n\t\t\t\t\t\t   Enter your choice:");
	fflush(stdin);
	scanf("%c",&register_choice);
	switch (register_choice)
	{
		case 'y':
		case 'Y':
			driver_login();
		break;
		case 'n':
		case 'N':
			driver_signup();
		break;
		case 'e':
		case 'E':
			printf("\n\n\t\t\t\t\t\tRedirecting to Home Page");
			for(i=5;i>=1;i--)
			{
				printf(".");
				Sleep(1000);
			}
			main();
		break;
		default:
			printf("\n\n\t\t\t\t\t\t     Invalid Input\n\t\t\t\t\t\t\tRedirecting");
			for(i=5;i>=1;i--)
			{
				printf(".");
				Sleep(1000);
			}
			goto top;
	}
}

void driver_login()
{
	system("cls");
	struct driver d;
	int i,count=0;
	char userName[50],Pass[50];
	FILE *ptr;
	ptr = fopen("driver_login.bin","rb");
	if(ptr==NULL)
	{
		printf("\n\n\n\n\n\t\t\t\t\t\tThere is no driver registered!");
		printf("\n\n\n\t\t\t\t\t     Redirecting to SigUp page");
		for(i=5;i>=1;i--)
		{
			printf(".");
			Sleep(1000);
		}
		driver_signup();
	}
	printf("\n\n\n\t\t\t\t\t\t\tDriver\'s Hub");
	printf("\n\n\t\t\t\t\t\t\t Login Page");
	printf("\n\n+----------------------------------------------------------------------------------------------------------------------+");
	reenter:
	fflush(stdin);
	printf("\n\n\t\t\t\t\t\tEnter Username: ");
	gets(userName);
	fflush(stdin);
	printf("\n\n\t\t\t\t\t\tEnter Password: ");
	gets(Pass);
	while(!feof(ptr))
	{	
		fread(&d,sizeof(d),1,ptr);
		if(strcmp(d.username,userName)==0)
		{
			if(strcmp(d.pass,Pass)==0)
			{
				driver_homepage(d.username);
			}	
		}	
	}
	printf("\t\t\t\t\t  incorrect id or password! enter again");
	count++;
	if(count>=2)
	{
		printf("\n\n\t\t\t\t\t\t  Too many attempts!\n\n\t\t\t\t\t\tRedirecting to Home Page");
		for(i=5;i>=1;i--)
		{
			printf(".");
			Sleep(1000);
		}
			main();
	}
	goto reenter;
}

void driver_signup()
{
	system("cls");
	int i;
	struct driver d,temp_read;
	FILE *ptr;
	ptr = fopen("driver_login.bin","ab+");
	if(ptr == NULL)
	{
		printf("\n\n\n\n\t\t\t\t\tError in the server!Please Try again");
		for(i=5;i>=1;i--)
		{
			printf(".");
			Sleep(1000);
		}
		main();
	}
	printf("\n\n\n\t\t\t\t\t\t\tDriver\'s Hub");
	printf("\n\n\t\t\t\t\t\t\tSignUp Page");
	printf("\n\n+----------------------------------------------------------------------------------------------------------------------+");
	fflush(stdin);
	printf("\n\n\t\t\t\t\t\tEnter Username: ");
	gets(d.username);
	fflush(stdin);
	pass_reenter:
	printf("\n\n\t\t\t\t\t\tEnter Password: ");
	gets(d.pass);
	if(strlen(d.pass)<8)
	{
		printf("\n\n\t\t\t\tPassword Length must be >7 and <50 characters! Try Again");
		goto pass_reenter;
	}
	system("cls");
	printf("\n\n\n\t\t\t\t\t\t\tBus Company");
	printf("\n\n\t\t\t\t\t\t\tSignUp Page");
	printf("\n\n+----------------------------------------------------------------------------------------------------------------------+");
	reenter_name:
	fflush(stdin);
	printf("\n\n\t\t\t\t\t    Enter Full Name: ");
	gets(d.real_name);
	for(i=0;d.real_name[i]!='\0';i++)
	{
		if(!((d.real_name[i]>=65&&d.real_name[i]<=90)||(d.real_name[i]>=97&&d.real_name[i]<=122)||d.real_name[i]==' '))
		{
			printf("\n\n\t\t\t\tName of person can only be alphabets and space!");
			goto reenter_name;
		}
	}
	fflush(stdin);
	printf("\n\n\t\t\t\t\t    Total license number: ");
	gets(d.license_number);
	printf("\n\n\t\t\t\t\t  Total experience years: ");
	scanf("%d",&d.experience);
	d.recruit_status = 'n';
	fwrite(&d,sizeof(d),1,ptr);
	fclose(ptr);
	system("cls");
	printf("\n\n\n\t\t\t\t\t\t\tCongratulations!");
	printf("\n\n\n\t\t\t\t\tYour account has been successfully registered!");
	printf("\n\n\n\t\t\t\t\t\tLogin Now!");
	printf("\n\n\n\t\t\t\t\t\tRedirecting");
	for(i=5;i>=1;i--)
	{
		printf(".");
		Sleep(1000);
	}
	driver_login();
}

void driver_homepage(char username[])
{
	system("cls");
	int user_count=0,i,user_choice;
	FILE *ptr;
	ptr = fopen("driver_login.bin","rb+");
	if(ptr == NULL)
	{
		printf("\n\n\n\n\t\t\t\t\tError in the server!Please Try again");
		for(i=5;i>=1;i--)
		{
			printf(".");
			Sleep(1000);
		}
		main();
	}
	retry:
	printf("\n\n\n\t\t\t\t\t\t\tDriver\'s Hub");
	printf("\n\n\t\t\t\t\t\t  Welcome User %s!",username);
	printf("\n\n+----------------------------------------------------------------------------------------------------------------------+");
	printf("\n\n\t\t\t\t\t\t\t  Features");
	printf("\n\n\n\t  1.Apply Job");
	printf("\t\t\t\t\t2.Report");
	printf("\t\t\t    3. Active/Inactive Bus");
	printf("\n\t     [Press 1]");
	printf("\t\t\t\t\t[Press 2]");
	printf("\t\t\t\t   [Press 3]");
	printf("\n\n\n\t\t  4.Log Out");
	printf("\t\t\t\t\t\t\t\t  5.Seetings");
	printf("\n\t           [Press 4]");
	printf("\t\t\t\t\t\t\t\t  [Press 5]");
	printf("\n\n\n\n+----------------------------------------------------------------------------------------------------------------------+");
	printf("\n\n\n\t\t\t\t\t\t  Enter you choice: ");
	fflush(stdin);
	scanf("%d",&user_choice);
	switch (user_choice)
	{
		case 1:
			printf("hello1");
		break;
		case 2:
			printf("hello2");
		break;
		case 3:
			printf("hello3");
		break;
		case 4:
			system("cls");
			printf("\n\n\n\n\t\t\t\t\t\t\tLogging Out");
			for(i=5;i>=1;i--)
			{
				printf(".");
				Sleep(1000);
			}
			main();
		break;
		case 5:
			printf("hello4");
		break;
		default:
			printf("\n\n\t\t\t\t\t\tInvalid Input! Try again");
			for(i=5;i>=1;i--)
			{
				printf(".");
				Sleep(1000);
			}
			system("cls");
			goto retry;
	}
}

void user_f()
{
	char register_choice,i;
	top:
	system("cls");
	printf("\n\n\n\t\t\t\t\t\t\tUser\'s Hub");
	printf("\n\n+----------------------------------------------------------------------------------------------------------------------+");
	printf("\n\n\t\t\t\t\t\t    Already Registered?");
	printf("\n\n\n\t\t\t\t\t\t\t    Yes\n\t\t\t\t\t\t    [Press 'y' or 'Y']");
	printf("\n\n\n\t\t\t\t\t\t\t     No\n\t\t\t\t\t\t    [Press 'n' or 'N']");
	printf("\n\n\n\t\t\t\t\t\t\t<-- Back\n\t\t\t\t\t\t    [Press 'e' or 'E']");
	printf("\n\n\n\t\t\t\t\t\t   Enter your choice:");
	fflush(stdin);
	scanf("%c",&register_choice);
	switch (register_choice)
	{
		case 'y':
		case 'Y':
			user_login();
		break;
		case 'n':
		case 'N':
			user_signup();
		break;
		case 'e':
		case 'E':
			printf("\n\n\t\t\t\t\t\tRedirecting to Home Page");
			for(i=5;i>=1;i--)
			{
				printf(".");
				Sleep(1000);
			}
			main();
		break;
		default:
			printf("\n\n\t\t\t\t\t\t     Invalid Input\n\t\t\t\t\t\t    Redirecting");
			for(i=5;i>=1;i--)
			{
				printf(".");
				Sleep(1000);
			}
			goto top;
	}
}

void user_login()
{
	system("cls");
	struct user u;
	int i,count=0;
	char userName[50],Pass[50];
	FILE *ptr;
	ptr = fopen("user_login.bin","rb");
	if(ptr==NULL)
	{
		printf("\n\n\n\n\n\t\t\t\t\t\t  There is no user registered!");
		printf("\n\n\n\t\t\t\t\t     Redirecting to SigUp page");
		for(i=5;i>=1;i--)
		{
			printf(".");
			Sleep(1000);
		}
		user_signup();
	}
	printf("\n\n\n\t\t\t\t\t\t\tUser\'s Hub");
	printf("\n\n\t\t\t\t\t\t\t Login Page");
	printf("\n\n+----------------------------------------------------------------------------------------------------------------------+");
	reenter:
	fflush(stdin);
	printf("\n\n\t\t\t\t\t\tEnter Username: ");
	gets(userName);
	fflush(stdin);
	printf("\n\n\t\t\t\t\t\tEnter Password: ");
	gets(Pass);
	while(!feof(ptr))
	{	
		fread(&u,sizeof(u),1,ptr);
		if(strcmp(u.username,userName)==0)
		{
			if(strcmp(u.pass,Pass)==0)
			{
				user_homepage(u.username);
			}	
		}	
	}
	printf("\t\t\t\t\t  incorrect id or password! enter again");
	count++;
	if(count>=2)
	{
		printf("\n\n\t\t\t\t\t\t  Too many attempts!\n\n\t\t\t\t\t\tRedirecting to Homepage!");
		for(i=5;i>=1;i--)
		{
			printf(".");
			Sleep(1000);
		}
			main();
	}
	goto reenter;
}

void user_signup()
{
	system("cls");
	int i;
	char card_choice;
	struct user u,temp_read;
	FILE *ptr;
	ptr = fopen("user_login.bin","ab+");
	if(ptr == NULL)
	{
		printf("\n\n\n\n\t\t\t\t\tError in the server!Please Try again");
		for(i=5;i>=1;i--)
		{
			printf(".");
			Sleep(1000);
		}
		main();
	}
	printf("\n\n\n\t\t\t\t\t\t\tUser\'s Hub");
	printf("\n\n\t\t\t\t\t\t\tSignUp Page");
	printf("\n\n+----------------------------------------------------------------------------------------------------------------------+");
	fflush(stdin);
	printf("\n\n\t\t\t\t\t\tEnter Username: ");
	gets(u.username);
	fflush(stdin);
	pass_reenter:
	printf("\n\n\t\t\t\t\t\tEnter Password: ");
	gets(u.pass);
	if(strlen(u.pass)<8)
	{
		printf("\n\n\t\t\t\tPassword Length must be >7 and <50 characters! Try Again");
		goto pass_reenter;
	}
	system("cls");
	printf("\n\n\n\t\t\t\t\t\t\tUser\'s Hub");
	printf("\n\n\t\t\t\t\t\t\tSignUp Page");
	printf("\n\n+----------------------------------------------------------------------------------------------------------------------+");
	reenter_name:
	fflush(stdin);
	printf("\n\n\t\t\t\t\t    Enter Full Name: ");
	gets(u.real_name);
	for(i=0;u.real_name[i]!='\0';i++)
	{
		if(!((u.real_name[i]>=65&&u.real_name[i]<=90)||(u.real_name[i]>=97&&u.real_name[i]<=122)||u.real_name[i]==' '))
		{
			printf("\n\n\t\t\t\tName of person can only be alphabets and space!");
			goto reenter_name;
		}
	}
	printf("\n\n\t\t\t\t\t    Enter your age: ");
	scanf("%d",&u.age);
	if(u.age<=22||u.age>=65)
	{
		fflush(stdin);
		printf("\n\n\t\t\t\t\t    Enter your card number: ");
		gets(u.card);
	}
	fflush(stdin);
	printf("\n\n\t\t\t\t\tEnter your cittizenship number: ");
	gets(u.citizen_no);
	fwrite(&u,sizeof(u),1,ptr);
	fclose(ptr);
	system("cls");
	printf("\n\n\n\t\t\t\t\t\t\tCongratulations!");
	printf("\n\n\n\t\t\t\t\tYour account has been successfully registered!");
	printf("\n\n\n\t\t\t\t\tLogin Now!");
	printf("\n\n\n\t\t\t\t\t\tRedirecting");
	for(i=5;i>=1;i--)
	{
		printf(".");
		Sleep(1000);
	}
	user_login();
}

void user_homepage(char username[])
{
	system("cls");
	int user_count=0,i,user_choice;
	FILE *ptr;
	ptr = fopen("user_login.bin","rb+");
	if(ptr == NULL)
	{
		printf("\n\n\n\n\t\t\t\t\tError in the server!Please Try again");
		for(i=5;i>=1;i--)
		{
			printf(".");
			Sleep(1000);
		}
		main();
	}
	retry:
	printf("\n\n\n\t\t\t\t\t\t\tUser\'s Hub");
	printf("\n\n\t\t\t\t\t\t    Welcome User %s!",username);
	printf("\n\n+----------------------------------------------------------------------------------------------------------------------+");
	printf("\n\n\t\t\t\t\t\t\t  Features");
	printf("\n\n\n\t  1.List of Bus");
	printf("\t\t\t\t\t2.Fare Amount");
	printf("\t\t\t    3. Report");
	printf("\n\t     [Press 1]");
	printf("\t\t\t\t\t  [Press 2]");
	printf("\t\t\t      [Press 3]");
	printf("\n\n\n\t\t  4.Log Out");
	printf("\t\t\t\t\t\t\t\t  5.Settings");
	printf("\n\t           [Press 4]");
	printf("\t\t\t\t\t\t\t\t  [Press 5]");
	printf("\n\n\n\n+----------------------------------------------------------------------------------------------------------------------+");
	printf("\n\n\n\t\t\t\t\t\t  Enter you choice: ");
	fflush(stdin);
	scanf("%d",&user_choice);
	switch (user_choice)
	{
		case 1:
			printf("hello1");
		break;
		case 2:
			printf("hello2");
		break;
		case 3:
			printf("hello3");
		break;
		case 4:
			system("cls");
			printf("\n\n\n\n\t\t\t\t\t\t\tLogging Out");
			for(i=5;i>=1;i--)
			{
				printf(".");
				Sleep(1000);
			}
			main();
		break;
		case 5:
			printf("hello4");
		break;
		default:
			printf("\n\n\t\t\t\t\t\tInvalid Input! Try again");
			for(i=5;i>=1;i--)
			{
				printf(".");
				Sleep(1000);
			}
			system("cls");
			goto retry;
	}
}
