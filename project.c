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
void change_bus_company(int);
void driver_login();
void driver_signup();
void driver_homepage(char []);
void change_driver(int);
void user_login();
void user_signup();
void user_homepage(char []);
void change_user(int);

struct bus_company
{
	char username[50];
	char pass[50];
	char name[50];
	int bus_number;
	char destinations[3][50];
	char unique_pin[10];
};

struct driver
{
	char username[50];
	char pass[50];
	char real_name[100];
	char license_number[20];
	int experience;
	char recruit_status;
	char unique_pin[10];
};

struct user
{
	char username[50];
	char pass[50];
	char real_name[100];
	char card[20];
	int age;
	char citizen_no[20];
	char unique_pin[10];
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
	char userName[50],Pass[50],choice;
	FILE *ptr;
	ptr = fopen("bus_company_login.bin","rb");
	if(ptr==NULL)
	{
		printf("\n\n\n\n\n\t\t\t\t\t  There is no bus company registered!");
		printf("\n\n\n\t\t\t\t\t     Redirecting to SignUp page");
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
		ask_forgot_pass:
		system("cls");
		printf("\n\n\t\t\t\t\t\t  Too many attempts!\n\n\t\t\t\t\t       Did you forgot your pass?:");
		printf("\n\n\t\t\t\t\t\t1.Yes [press \'y\' or \'Y\']");
		printf("\n\n\t\t\t\t\t\t 1.No [press \'n\' or \'N\']");
		printf("\n\n\n\t\t\t\t\t\t  Enter you choice: ");
		fflush(stdin);
		scanf("%c",&choice);
		if(choice == 'y' || choice == 'Y')
		{
			change_bus_company(0);
		}
		else if(choice == 'n' || choice == 'N')
		{
			printf("\n\n\t\t\t\t\t    Redirecting to homepage");
			for(i=5;i>=1;i--)
			{
				printf(".");
				Sleep(1000);
			}
			main();
		}
		else
		{
			printf("\n\n\t\t\t\t\t\t     Invalid Input\n\t\t\t\t\t\t    Redirecting");
			for(i=5;i>=1;i--)
			{
				printf(".");
				Sleep(1000);
			}
			goto ask_forgot_pass;
		}
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
	unique:
	fflush(stdin);
	printf("\n\n\t\t\tEnter unique pin[equal to 5 characters]: ");
	gets(b.unique_pin);
	if(strlen(b.unique_pin)!=5)
	{
		printf("\n\n\t\tunique pin must be equals to 5 characters! Try again");
		goto unique;
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
	printf("\n\n\n\t\t\t\t\t\t\t    Login Now!");
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

void change_bus_company(int n)
{
	system("cls");
	FILE *ptr;
	struct bus_company b,*all=NULL;
	int count=0,i;
	char userName[50],unique_code[6],new_pass[50],new_pass2[50];
	ptr = fopen("bus_company_login.bin","rb");
	while(fread(&b,sizeof(b),1,ptr))
	{
		count++;
	}
	all = (struct bus_company*)calloc(count,sizeof(struct bus_company));
	if(all == NULL)
	{
		printf("\n\n\n\n\t\t\t\t\tError in the server!Please Try again");
		for(i=5;i>=1;i--)
		{
			printf(".");
			Sleep(1000);
		}
		main();
	}
	rewind(ptr);
	fread(all,sizeof(struct bus_company),count,ptr);
	fclose(ptr);
	if(n  ==  0)
	{
		main_try_again:
		fflush(stdin);
		printf("\n\n\n\n\t\t\t\t\t\t  Enter your username: ");
		gets(userName);
		printf("\n\n\t\t\t\t\t\t  Enter your unique pin: ");
		gets(unique_code);
		for(i=0;i<count;i++)
		{
			if(strcmp(all[i].username,userName)==0&&strcmp(all[i].unique_pin,unique_code)==0)
			{
				try_again:
				fflush(stdin);
				printf("\n\n\t\t\t\t\t\tEnter your new pass: ");
				gets(new_pass);
				printf("\n\n\t\t\t\t\t   Enter your new pass again: ");
				gets(new_pass2);
				if(strcmp(new_pass,new_pass2)==0)
				{
					strcpy(all[i].pass,new_pass);
					ptr = fopen("bus_company_login.bin","wb");
					fwrite(all,sizeof(struct bus_company),count,ptr);
					fclose(ptr);
					printf("\n\n\n\t\t\t\t\tPassword changed successfully!");
					printf("\n\n\n\t\t\t\t\t\tRedirecting");
					for(i=5;i>=1;i--)
					{
						printf(".");
						Sleep(1000);
					}
					bus_company_login();
				}
				else
				{
					printf("\n\n\n\t\t\t\t    Password didnot match! Try again");
					goto try_again;
				}	
			}
		}
		printf("\n\n\t\t\t\t\tIncorrect username or code! Try again");
		goto main_try_again;
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
	char userName[50],Pass[50],choice;
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
		ask_forgot_pass:
		system("cls");
		printf("\n\n\t\t\t\t\t\t  Too many attempts!\n\n\t\t\t\t\t       Did you forgot your pass?:");
		printf("\n\n\t\t\t\t\t\t1.Yes [press \'y\' or \'Y\']");
		printf("\n\n\t\t\t\t\t\t 1.No [press \'n\' or \'N\']");
		printf("\n\n\n\t\t\t\t\t\t  Enter you choice: ");
		fflush(stdin);
		scanf("%c",&choice);
		if(choice == 'y' || choice == 'Y')
		{
			change_driver(0);
		}
		else if(choice == 'n' || choice == 'N')
		{
			printf("\n\n\t\t\t\t\t    Redirecting to homepage");
			for(i=5;i>=1;i--)
			{
				printf(".");
				Sleep(1000);
			}
			main();
		}
		else
		{
			printf("\n\n\t\t\t\t\t\t     Invalid Input\n\t\t\t\t\t\t    Redirecting");
			for(i=5;i>=1;i--)
			{
				printf(".");
				Sleep(1000);
			}
			goto ask_forgot_pass;
		}
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
	unique:
	fflush(stdin);
	printf("\n\n\t\t\tEnter unique pin[equal to 5 characters]: ");
	gets(d.unique_pin);
	if(strlen(d.unique_pin)!=5)
	{
		printf("\n\n\t\tunique pin must be equals to 5 characters! Try again");
		goto unique;
	}
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

void change_driver(int n)
{
	system("cls");
	FILE *ptr;
	struct driver d,*all=NULL;
	int count=0,i;
	char userName[50],unique_code[6],new_pass[50],new_pass2[50];
	ptr = fopen("driver_login.bin","rb");
	while(fread(&d,sizeof(d),1,ptr))
	{
		count++;
	}
	all = (struct driver*)calloc(count,sizeof(struct driver));
	if(all == NULL)
	{
		printf("\n\n\n\n\t\t\t\t\tError in the server!Please Try again");
		for(i=5;i>=1;i--)
		{
			printf(".");
			Sleep(1000);
		}
		main();
	}
	rewind(ptr);
	fread(all,sizeof(struct driver),count,ptr);
	fclose(ptr);
	if(n  ==  0)
	{
		main_try_again:
		fflush(stdin);
		printf("\n\n\n\n\t\t\t\t\t\t  Enter your username: ");
		gets(userName);
		printf("\n\n\t\t\t\t\t\t  Enter your unique pin: ");
		gets(unique_code);
		for(i=0;i<count;i++)
		{
			if(strcmp(all[i].username,userName)==0&&strcmp(all[i].unique_pin,unique_code)==0)
			{
				try_again:
				fflush(stdin);
				printf("\n\n\t\t\t\t\t\tEnter your new pass: ");
				gets(new_pass);
				printf("\n\n\t\t\t\t\t   Enter your new pass again: ");
				gets(new_pass2);
				if(strcmp(new_pass,new_pass2)==0)
				{
					strcpy(all[i].pass,new_pass);
					ptr = fopen("driver_login.bin","wb");
					fwrite(all,sizeof(struct driver),count,ptr);
					fclose(ptr);
					printf("\n\n\n\t\t\t\t\tPassword changed successfully!");
					printf("\n\n\n\t\t\t\t\t\tRedirecting");
					for(i=5;i>=1;i--)
					{
						printf(".");
						Sleep(1000);
					}
					driver_login();
				}
				else
				{
					printf("\n\n\n\t\t\t\t    Password didnot match! Try again");
					goto try_again;
				}	
			}
		}
		printf("\n\n\t\t\t\t\tIncorrect username or code! Try again");
		goto main_try_again;
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
	char userName[50],Pass[50],choice;
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
		ask_forgot_pass:
		system("cls");
		printf("\n\n\t\t\t\t\t\t  Too many attempts!\n\n\t\t\t\t\t       Did you forgot your pass?:");
		printf("\n\n\t\t\t\t\t\t1.Yes [press \'y\' or \'Y\']");
		printf("\n\n\t\t\t\t\t\t 1.No [press \'n\' or \'N\']");
		printf("\n\n\n\t\t\t\t\t\t  Enter you choice: ");
		fflush(stdin);
		scanf("%c",&choice);
		if(choice == 'y' || choice == 'Y')
		{
			change_user(0);
		}
		else if(choice == 'n' || choice == 'N')
		{
			printf("\n\n\t\t\t\t\t    Redirecting to homepage");
			for(i=5;i>=1;i--)
			{
				printf(".");
				Sleep(1000);
			}
			main();
		}
		else
		{
			printf("\n\n\t\t\t\t\t\t     Invalid Input\n\t\t\t\t\t\t    Redirecting");
			for(i=5;i>=1;i--)
			{
				printf(".");
				Sleep(1000);
			}
			goto ask_forgot_pass;
		}
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
	unique:
	fflush(stdin);
	printf("\n\n\t\t\tEnter unique pin[equal to 5 characters]: ");
	gets(u.unique_pin);
	if(strlen(u.unique_pin)!=5)
	{
		printf("\n\n\t\tunique pin must be equals to 5 characters! Try again");
		goto unique;
	}
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

void change_user(int n)
{
	system("cls");
	FILE *ptr;
	struct user u,*all=NULL;
	int count=0,i;
	char userName[50],unique_code[6],new_pass[50],new_pass2[50];
	ptr = fopen("user_login.bin","rb");
	while(fread(&u,sizeof(u),1,ptr))
	{
		count++;
	}
	all = (struct user*)calloc(count,sizeof(struct user));
	if(all == NULL)
	{
		printf("\n\n\n\n\t\t\t\t\tError in the server!Please Try again");
		for(i=5;i>=1;i--)
		{
			printf(".");
			Sleep(1000);
		}
		main();
	}
	rewind(ptr);
	fread(all,sizeof(struct user),count,ptr);
	fclose(ptr);
	if(n  ==  0)
	{
		main_try_again:
		fflush(stdin);
		printf("\n\n\n\n\t\t\t\t\t\t  Enter your username: ");
		gets(userName);
		printf("\n\n\t\t\t\t\t\t  Enter your unique pin: ");
		gets(unique_code);
		for(i=0;i<count;i++)
		{
			if(strcmp(all[i].username,userName)==0&&strcmp(all[i].unique_pin,unique_code)==0)
			{
				try_again:
				fflush(stdin);
				printf("\n\n\t\t\t\t\t\tEnter your new pass: ");
				gets(new_pass);
				printf("\n\n\t\t\t\t\t   Enter your new pass again: ");
				gets(new_pass2);
				if(strcmp(new_pass,new_pass2)==0)
				{
					strcpy(all[i].pass,new_pass);
					ptr = fopen("user_login.bin","wb");
					fwrite(all,sizeof(struct user),count,ptr);
					fclose(ptr);
					printf("\n\n\n\t\t\t\t\t      Password changed successfully!");
					printf("\n\n\n\t\t\t\t\t\t     Redirecting");
					for(i=5;i>=1;i--)
					{
						printf(".");
						Sleep(1000);
					}
					user_login();
				}
				else
				{
					printf("\n\n\n\t\t\t\t    Password didnot match! Try again");
					goto try_again;
				}	
			}
		}
		printf("\n\n\t\t\t\t\tIncorrect username or code! Try again");
		goto main_try_again;
	}
}
