#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<math.h>

void bus_company_f();
void driver_f();
void user_f();
void bus_company_login();
void bus_company_signup();
void bus_company_homepage(char []);
void change_bus_company(int);
void bus_company_setting(char []);
void driver_login();
void driver_signup();
void driver_homepage(char []);
void change_driver(int);
void driver_setting(char []);
void user_login();
void user_signup();
void user_homepage(char []);
void change_user(int);
void user_setting(char []);
void bus_list(char []);
void travelling_fare(char []);
void user_report(char []);
void check_report(char []);
void increase_bus(char []);
void job_apply(char []);
void recruit_driver(char []);

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
	char affiliated_company[50];
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

struct report
{
	char name[100];
	char bus[100];
	char reprt[300];
};

struct job_application
{
	char company_name[50];
	char employee_name[50];
};

int main()
{
	int i;
	char user_choice;
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
	fflush(stdin);
	scanf("%c",&user_choice);
	switch (user_choice)
	{
		case '1':
			bus_company_f();
		break;
		case '2':
			driver_f();
		break;
		case '3':
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
	char userName[50],Pass[50],choice,ch;
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
	i=0;
	while(1)
	{
		if(_kbhit())
		{
			ch = _getch();
			if(ch == '\r')
			{
				Pass[i] = '\0';
				break;
			}
			else if(ch == '\b' && i>0)
			{
				printf("\b \b");
                i--;
			}
			else if(i<100)
			{
				Pass[i] = ch;
				printf("*");
				i++;
			}
		}
	}
	rewind(ptr);
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
	printf("\n\n\t\t\t\t\t  incorrect id or password! enter again");
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
	char ch;
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
	i=0;
	while(1)
	{
		if(_kbhit())
		{
			ch = _getch();
			if(ch == '\r')
			{
				b.pass[i] = '\0';
				break;
			}
			else if(ch == '\b' && i>0)
			{
				printf("\b \b");
                i--;
			}
			else if(i<100)
			{
				b.pass[i] = ch;
				printf("*");
				i++;
			}
		}
	}
	if(strlen(b.pass)<8&&strlen(b.pass)>50)
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
	printf("\t\t\t   3.See Report");
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
			recruit_driver(username);
		break;
		case 2:
			increase_bus(username);
		break;
		case 3:
			check_report(username);
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
			bus_company_setting(username);
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
	int count=0,i,flag=0,error_count=0,j,file_count;
	char userName[50],unique_code[6],new_pass[50],new_pass2[50],ch,Pass[50],new_username[50],new_companyname[50];
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
		for(file_count=0;file_count<count;file_count++)
		{
			if(strcmp(all[file_count].username,userName)==0&&strcmp(all[file_count].unique_pin,unique_code)==0)
			{
				try_again:
				fflush(stdin);
				printf("\n\n\t\t\t\t\t\tEnter your new pass: ");
				i=0;
				while(1)
				{
					if(_kbhit())
					{
						ch = _getch();
						if(ch == '\r')
						{
							new_pass[i] = '\0';
							break;
						}
						else if(ch == '\b' && i>0)
						{
							printf("\b \b");
                			i--;
						}
						else if(i<100)
						{
							new_pass[i] = ch;
							printf("*");
							i++;
						}
					}
				}
				printf("\n\n\t\t\t\t\t   Enter your new pass again: ");
				i=0;
				while(1)
				{
					if(_kbhit())
					{
						ch = _getch();
						if(ch == '\r')
						{
							new_pass2[i] = '\0';
							break;
						}
						else if(ch == '\b' && i>0)
						{
							printf("\b \b");
                			i--;
						}
						else if(i<100)
						{
							new_pass2[i] = ch;
							printf("*");
							i++;
						}
					}
				}
				if(strcmp(new_pass,new_pass2)==0)
				{
					strcpy(all[file_count].pass,new_pass);
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
		error_count++;
		if(error_count >=2)
		{
			printf("\n\n\t\t\t\t\t\t  Too many attempts!");
			printf("\n\n\t\t\t\t\t    Redirecting to homepage");	
			for(j=5;j>=1;j--)
			{
				printf(".");
				Sleep(1000);
			}
			main();
		}
		goto main_try_again;
	}
	else if(n == 1)
	{
		username_try_again:
		fflush(stdin);
		printf("\n\n\n\n\t\t\t\t\t\t  Enter your username: ");
		gets(userName);
		printf("\n\n\t\t\t\t\t\t  Enter your password: ");
		gets(Pass);
		for(i=0;i<count;i++)
		{
			if(strcmp(all[i].username,userName)==0&&strcmp(all[i].pass,Pass)==0)
			{
				fflush(stdin);
				printf("\n\n\t\t\t\t\t\tEnter your new username: ");
				gets(new_username);
				strcpy(all[i].username,new_username);
				ptr = fopen("bus_company_login.bin","wb");
				fwrite(all,sizeof(struct bus_company),count,ptr);
				fclose(ptr);
				printf("\n\n\n\t\t\t\t\tUsername changed successfully!");
				printf("\n\n\n\t\t\t\t\t\tRedirecting");
				for(i=5;i>=1;i--)
				{
					printf(".");
					Sleep(1000);
				}
				bus_company_login();
			}
		}
		printf("\n\n\t\t\t\t\tIncorrect username or password! Try again");
		goto username_try_again;
	}
	else if(n == 2)
	{
		pass_try_again:
		fflush(stdin);
		printf("\n\n\n\n\t\t\t\t\t\t  Enter your username: ");
		gets(userName);
		printf("\n\n\t\t\t\t\t    Enter your current password: ");
		gets(Pass);
		for(i=0;i<count;i++)
		{
			if(strcmp(all[i].username,userName)==0&&strcmp(all[i].pass,Pass)==0)
			{
				p_try_again:
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
					printf("\n\n\n\t\t\t\t\t    Password changed successfully!");
					printf("\n\n\n\t\t\t\t\t\t   Redirecting");
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
					goto p_try_again;
				}	
			}
		}
		printf("\n\n\t\t\t\t\tIncorrect username or pass! Try again");
		goto pass_try_again;
	}
	else if(n == 3)
	{
		name_try_again:
		fflush(stdin);
		printf("\n\n\n\n\t\t\t\t\t\t  Enter your username: ");
		gets(userName);
		printf("\n\n\t\t\t\t\t\t  Enter your password: ");
		gets(Pass);
		for(i=0;i<count;i++)
		{
			if(strcmp(all[i].username,userName)==0&&strcmp(all[i].pass,Pass)==0)
			{
				fflush(stdin);
				printf("\n\n\t\t\t\t\t    Enter your new Company Name: ");
				gets(new_companyname);
				strcpy(all[i].name,new_companyname);
				ptr = fopen("bus_company_login.bin","wb");
				fwrite(all,sizeof(struct bus_company),count,ptr);
				fclose(ptr);
				printf("\n\n\n\t\t\t\t\tComapny Name changed successfully!");
				printf("\n\n\n\t\t\t\t\t\tRedirecting");
				for(i=5;i>=1;i--)
				{
					printf(".");
					Sleep(1000);
				}
				bus_company_login();
			}
		}
		printf("\n\n\t\t\t\t\tIncorrect username or password! Try again");
		goto name_try_again;
	}
	else if(n == 4)
	{
		delete_try_again:
		fflush(stdin);
		printf("\n\n\n\n\t\t\t\t\t\t  Enter your username: ");
		gets(userName);
		printf("\n\n\t\t\t\t\t\t  Enter your password: ");
		gets(Pass);
		ptr = fopen("bus_company_login.bin","wb");
		for(i=0;i<count;i++)
		{
			if(strcmp(all[i].username,userName)==0&&strcmp(all[i].pass,Pass)==0)
			{
				flag = 1;
				continue;
			}
			else
			{
				fwrite(&all[i],sizeof(struct bus_company),1,ptr);
			}
		}
		fclose(ptr);
		if(flag == 0)
		{
			printf("\n\n\t\t\t\t\tIncorrect username or password! Try again");
			goto name_try_again;	
		}
		else
		{
			printf("\n\n\t\t\t\t\t    ID deletd successfully!");
			printf("\n\n\t\t\t\t\t\t    Redirecting");
			for(i=5;i>=1;i--)
			{
				printf(".");
				Sleep(1000);
			}
			main();
		}
	}
}

void bus_company_setting(char username[])
{
	system("cls");
	char user_choice;
	int i;
	retry:
	printf("\n\n\n\t\t\t\t\t\t    Bus Company Settings");
	printf("\n\n\t\t\t\t\t\t     User %s!",username);
	printf("\n\n+----------------------------------------------------------------------------------------------------------------------+");
	printf("\n\n\t\t\t\t\t\t\t  Features");
	printf("\n\n\n\t  1.Change username");
	printf("\t\t\t\t2.Change password");
	printf("\t\t\t3.Change Company Name");
	printf("\n\t     [Press 1]");
	printf("\t\t\t\t\t  [Press 2]");
	printf("\t\t\t\t     [Press 3]");
	printf("\n\n\n\t        4.<-- Back");
	printf("\t\t\t\t\t\t\t\t5.Delete Account");
	printf("\n\t         [Press 4]");
	printf("\t\t\t\t\t\t\t\t  [Press 5]");
	printf("\n\n\n\n+----------------------------------------------------------------------------------------------------------------------+");
	printf("\n\n\n\t\t\t\t\t\t  Enter you choice: ");
	fflush(stdin);
	scanf("%c",&user_choice);
	switch (user_choice)
	{
		case '1':
			change_bus_company(1);
		break;
		case '2':
			change_bus_company(2);
		break;
		case '3':
			change_bus_company(3);
		break;
		case '4':
			system("cls");
			printf("\n\n\n\n\t\t\t\t\t\t\tExiting");
			for(i=5;i>=1;i--)
			{
				printf(".");
				Sleep(1000);
			}
			bus_company_homepage(username);
		break;
		case '5':
			change_bus_company(4);
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

void check_report(char username[])
{
	int i,count=0,counter=0,choice,j,quit;
	struct bus_company b;
	struct report r;
	struct user u;
	FILE *ptr_report,*ptr_bus,*ptr_user,*ptr_temp;
	ptr_user = fopen("user_login.bin","rb");
	if(ptr_user == NULL)
	{
		printf("\n\n\n\n\t\t\t\t\tError in the server!Please Try again");
		for(i=5;i>=1;i--)
		{
			printf(".");
			Sleep(1000);
		}
		main();
	}
	ptr_temp = fopen("temp_report.bin","wb+");
	if(ptr_temp == NULL)
	{
		printf("\n\n\n\n\t\t\t\t\tError in the server!Please Try again");
		for(i=5;i>=1;i--)
		{
			printf(".");
			Sleep(1000);
		}
		main();
	}
	ptr_bus = fopen("bus_company_login.bin","rb");
	if(ptr_bus == NULL)
	{
		printf("\n\n\n\n\t\t\t\t\tError in the server!Please Try again");
		for(i=5;i>=1;i--)
		{
			printf(".");
			Sleep(1000);
		}
		main();
	}
	ptr_report = fopen("user_report.bin","rb");
	if(ptr_report == NULL)
	{
		printf("\n\n\n\n\t\t\t\t\tError in the server!Please Try again");
		for(i=5;i>=1;i--)
		{
			printf(".");
			Sleep(1000);
		}
		main();
	}
	system("cls");
	printf("\n\n\n\t\t\t\t\t\t\tBus Company");
	printf("\n\n\t\t\t\t\t\t     User %s!",username);
	printf("\n\n+----------------------------------------------------------------------------------------------------------------------+");
	printf("\n\n\n\t\t\t\t\t\tList of Reports are:");
	while(fread(&r,sizeof(r),1,ptr_report))
	{
		count++;
		if(strcmp(username,r.bus)==0)
		{
			counter++;
			fwrite(&r,sizeof(r),1,ptr_temp);
			printf("\n\n\t\t\t\t%d %s",counter,r.reprt);
			printf("\n\t\t\t\t[By : %s]",r.name);
		}
	}
	printf("\n\n\t\t\t\t%d  <-- back",counter+1,r.reprt);
	printf("\n\n\n\t\t\t\t\tSelect user to view their details: ");
	fflush(stdin);
	scanf("%d",&choice);
	if(choice == counter+1)
	{
		bus_company_homepage(username);
	}
	else if(choice<0||choice>counter)
	{
		printf("\n\n\t\t\t\t\t Incorrect option! Try Again");
		for(j=3;j>=1;j--)
		{
			printf(".");
			Sleep(1000);
		}
		check_report(username);
	}
	rewind(ptr_report);
	rewind(ptr_temp);
	for(i=0;i<counter;i++)
	{
		fread(&r,sizeof(r),1,ptr_temp);
		if(i+1==choice)
		{
			while(fread(&u,sizeof(u),1,ptr_user))
			{
				if(strcmp(u.real_name,r.name)==0)
				{
					system("cls");
					printf("\n\n\n\t\t\t\t\t   Details of reporter are: ");
					printf("\n\n\t\t\t\t\t\tName: %s",u.real_name);
					printf("\n\n\t\t\t\t\t\tUser name: %s",u.username);
					printf("\n\n\t\t\t\t\t\tAge: %d",u.age);
					break;
				}
			}
		}
	}
	printf("\n\n+----------------------------------------------------------------------------------------------------------------------+");
	printf("\n\n\t\t\t\t\t   Enter any thing to go back: ");
	fflush(stdin);
	scanf("%c",&quit);
	check_report(username);
}

void increase_bus(char username[])
{
	int i,change,choice,bus_number,original_bus_number,quit,count=0;;
	struct bus_company b;
	FILE *ptr;
	ptr = fopen("bus_company_login.bin","rb");
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
	system("cls");
	printf("\n\n\n\t\t\t\t\t\t\tBus Company");
	printf("\n\n\t\t\t\t\t\t     User %s!",username);
	printf("\n\n+----------------------------------------------------------------------------------------------------------------------+");
	while(fread(&b,sizeof(b),1,ptr))
	{
		count++;
		if(strcmp(b.username,username)==0)
		{
			printf("\n\n\t\t\t\t\t\tTotal number of buses is: %d",b.bus_number);
			original_bus_number = b.bus_number;
		}
	}
	retry:
	printf("\n\n\t\t\t\t\t\t\tOptions:");
	printf("\n\n\t\t\t\t\t\t\t1. Increase");
	printf("\n\n\t\t\t\t\t\t\t2. Decrease");
	printf("\n\n\t\t\t\t\t\t\t3. <-- Back");
	printf("\n\n\t\t\t\t\t\t  Enter your choice: ");
	fflush(stdin);
	scanf("%d",&choice);
	if(choice == 1)
	{
		printf("\n\n\t\t\t\t     Enter the number of bus you want to increase: ");
		scanf("%d",&bus_number);
		if(bus_number>20||bus_number<1)
		{
			printf("\n\n\t\t\t\t\tError! Upto 20 buses can be increase at a time");
			increase_bus(username);
		}
		bus_number += original_bus_number;
		
	}
	else if(choice == 2)
	{
		printf("\n\n\t\t\t\t     Enter the number of bus you want to desrease: ");
		scanf("%d",&bus_number);
		if(bus_number>20||bus_number<1)
		{
			printf("\n\n\t\t\t\t\tError! Upto 20 buses can be desrease at a time");
			goto retry;
		}
		if(original_bus_number - bus_number < 0)
		{
			printf("\n\n\t\t\t\t\tError! Bus number cannot be less than zero!");
			goto retry;
		}
		bus_number = original_bus_number - bus_number;
	}
	else if(choice == 3)
	{
		bus_company_homepage(username);
	}
	else
	{
		printf("\n\n\t\t\t\t\tError! Incorrect Option. Try again");
		for(i=5;i>=1;i--)
		{
			printf(".");
			Sleep(1000);
		}
		goto retry;
	}
	struct bus_company all[count];
	rewind(ptr);
	fread(&all,sizeof(struct bus_company),count,ptr);
	ptr = fopen("bus_company_login.bin","wb");
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
	for(i=0;i<count;i++)
	{
		if(strcmp(all[i].username,username)==0)
		{
			all[i].bus_number = bus_number;
			printf("\n\n\t\t\t\t\tChanged total number of buses is: %d",all[i].bus_number);
		}
	}
	fwrite(&all,sizeof(struct bus_company),count,ptr);
	fclose(ptr);
	printf("\n\n+----------------------------------------------------------------------------------------------------------------------+");
	printf("\n\n\t\t\t\t\t   Enter any thing to go back: ");
	fflush(stdin);
	scanf("%c",&quit);
	bus_company_homepage(username);
}

void recruit_driver(char username[])
{
	int i,count=0,count_2=0;
	FILE *ptr_job,*ptr_driver;
	struct job_application j;
	struct driver d;
	ptr_job = fopen("job_application.bin","ab+");
	if(ptr_job == NULL)
	{
		printf("\n\n\n\n\t\t\t\t\tError in the server!Please Try again");
		for(i=5;i>=1;i--)
		{
			printf(".");
			Sleep(1000);
		}
		main();
	}
	ptr_driver = fopen("driver_login.bin","rb");
	if(ptr_driver == NULL)
	{
		printf("\n\n\n\n\t\t\t\t\tError in the server!Please Try again");
		for(i=5;i>=1;i--)
		{
			printf(".");
			Sleep(1000);
		}
		main();
	}
	system("cls");
	printf("\n\n\n\t\t\t\t\t\t\tBus Company");
	printf("\n\n\t\t\t\t\t\t     User %s!",username);
	printf("\n\n+----------------------------------------------------------------------------------------------------------------------+");
	printf("\n\n\t\t\t\t\t\tList of Job Applications are:");
	while(fread(&j,sizeof(j),1,ptr_job))
	{
		count++;
		if(strcmp(j.company_name,username)==0)
		{
			count_2++;
			printf("\n\n\t\t\t\t\t\t%d %s",count_2,j.employee_name);
		}
	}
	for(i=5;i>=1;i--)
		{
			printf(".");
			Sleep(1000);
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
	char userName[50],Pass[50],choice,ch;
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
	i=0;
	while(1)
	{
		if(_kbhit())
		{
			fflush(stdin);
			ch = _getch();
			if(ch == '\r')
			{
				Pass[i] = '\0';
				break;
			}
			else if(ch == '\b' && i>0)
			{
				printf("\b \b");
                i--;
			}
			else if(i<100)
			{
				Pass[i] = ch;
				printf("*");
				i++;
			}
		}
	}
	rewind(ptr);
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
	printf("\n\n\t\t\t\t\t  incorrect id or password! enter again");
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
	char ch;
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
	i=0;
	while(1)
	{
		if(_kbhit())
		{
			ch = _getch();
			if(ch == '\r')
			{
				d.pass[i] = '\0';
				break;
			}
			else if(ch == '\b' && i>0)
			{
				printf("\b \b");
                i--;
			}
			else if(i<100)
			{
				d.pass[i] = ch;
				printf("*");
				i++;
			}
		}
	}
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
	strcpy(d.affiliated_company,"n");
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
			job_apply(username);
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
			driver_setting(username);
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
	int count=0,i,flag=0,error_count=0,j,file_count;
	char userName[50],unique_code[6],new_pass[50],new_pass2[50],ch,Pass[50],new_username[50],new_name[50];;
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
		for(file_count=0;file_count<count;file_count++)
		{
			if(strcmp(all[file_count].username,userName)==0&&strcmp(all[file_count].unique_pin,unique_code)==0)
			{
				try_again:
				fflush(stdin);
				printf("\n\n\t\t\t\t\t\tEnter your new pass: ");
				i=0;
				while(1)
				{
					if(_kbhit())
					{
						ch = _getch();
						if(ch == '\r')
						{
							new_pass[i] = '\0';
							break;
						}
						else if(ch == '\b' && i>0)
						{
							printf("\b \b");
                			i--;
						}
						else if(i<100)
						{
							new_pass[i] = ch;
							printf("*");
							i++;
						}
					}
				}
				printf("\n\n\t\t\t\t\t   Enter your new pass again: ");
				i=0;
				while(1)
				{
					if(_kbhit())
					{
						ch = _getch();
						if(ch == '\r')
						{
							new_pass2[i] = '\0';
							break;
						}
						else if(ch == '\b' && i>0)
						{
							printf("\b \b");
                			i--;
						}
						else if(i<100)
						{
							new_pass2[i] = ch;
							printf("*");
							i++;
						}
					}
				}
				if(strcmp(new_pass,new_pass2)==0)
				{
					strcpy(all[file_count].pass,new_pass);
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
		error_count++;
		if(error_count >=2)
		{
			printf("\n\n\t\t\t\t\t\t  Too many attempts!");
			printf("\n\n\t\t\t\t\t    Redirecting to homepage");	
			for(j=5;j>=1;j--)
			{
				printf(".");
				Sleep(1000);
			}
			main();
		}
		goto main_try_again;
	}
	else if(n == 1)
	{
		username_try_again:
		fflush(stdin);
		printf("\n\n\n\n\t\t\t\t\t\t  Enter your username: ");
		gets(userName);
		printf("\n\n\t\t\t\t\t\t  Enter your password: ");
		gets(Pass);
		for(i=0;i<count;i++)
		{
			if(strcmp(all[i].username,userName)==0&&strcmp(all[i].pass,Pass)==0)
			{
				fflush(stdin);
				printf("\n\n\t\t\t\t\t\tEnter your new username: ");
				gets(new_username);
				strcpy(all[i].username,new_username);
				ptr = fopen("driver_login.bin","wb");
				fwrite(all,sizeof(struct driver),count,ptr);
				fclose(ptr);
				printf("\n\n\n\t\t\t\t\tUsername changed successfully!");
				printf("\n\n\n\t\t\t\t\t\tRedirecting");
				for(i=5;i>=1;i--)
				{
					printf(".");
					Sleep(1000);
				}
				driver_login();
			}
		}
		printf("\n\n\t\t\t\t\tIncorrect username or password! Try again");
		goto username_try_again;
	}
	else if(n == 2)
	{
		pass_try_again:
		fflush(stdin);
		printf("\n\n\n\n\t\t\t\t\t\t  Enter your username: ");
		gets(userName);
		printf("\n\n\t\t\t\t\t    Enter your current password: ");
		gets(Pass);
		for(i=0;i<count;i++)
		{
			if(strcmp(all[i].username,userName)==0&&strcmp(all[i].pass,Pass)==0)
			{
				p_try_again:
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
					printf("\n\n\n\t\t\t\t\t    Password changed successfully!");
					printf("\n\n\n\t\t\t\t\t\t   Redirecting");
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
					goto p_try_again;
				}	
			}
		}
		printf("\n\n\t\t\t\t\tIncorrect username or pass! Try again");
		goto pass_try_again;
	}
	else if(n == 3)
	{
		name_try_again:
		fflush(stdin);
		printf("\n\n\n\n\t\t\t\t\t\t  Enter your username: ");
		gets(userName);
		printf("\n\n\t\t\t\t\t\t  Enter your password: ");
		gets(Pass);
		for(i=0;i<count;i++)
		{
			if(strcmp(all[i].username,userName)==0&&strcmp(all[i].pass,Pass)==0)
			{
				fflush(stdin);
				printf("\n\n\t\t\t\t\t Enter your new Real Name: ");
				gets(new_name);
				strcpy(all[i].real_name,new_name);
				ptr = fopen("driver_login.bin","wb");
				fwrite(all,sizeof(struct driver),count,ptr);
				fclose(ptr);
				printf("\n\n\n\t\t\t\t\tReal Name changed successfully!");
				printf("\n\n\n\t\t\t\t\t\tRedirecting");
				for(i=5;i>=1;i--)
				{
					printf(".");
					Sleep(1000);
				}
				driver_login();
			}
		}
		printf("\n\n\t\t\t\t\tIncorrect username or password! Try again");
		goto name_try_again;
	}
	else if(n == 4)
	{
		delete_try_again:
		fflush(stdin);
		printf("\n\n\n\n\t\t\t\t\t\t  Enter your username: ");
		gets(userName);
		printf("\n\n\t\t\t\t\t\t  Enter your password: ");
		gets(Pass);
		ptr = fopen("driver_login.bin","wb");
		for(i=0;i<count;i++)
		{
			if(strcmp(all[i].username,userName)==0&&strcmp(all[i].pass,Pass)==0)
			{
				flag = 1;
				continue;
			}
			else
			{
				fwrite(&all[i],sizeof(struct driver),1,ptr);
			}
		}
		fclose(ptr);
		if(flag == 0)
		{
			printf("\n\n\t\t\t\t\tIncorrect username or password! Try again");
			goto name_try_again;	
		}
		else
		{
			printf("\n\n\t\t\t\t\t    ID deletd successfully!");
			printf("\n\n\t\t\t\t\t\t    Redirecting");
			for(i=5;i>=1;i--)
			{
				printf(".");
				Sleep(1000);
			}
			main();
		}
	}
}

void driver_setting(char username[])
{
	system("cls");
	char user_choice;
	int i;
	retry:
	printf("\n\n\n\t\t\t\t\t\t      Driver Settings");
	printf("\n\n\t\t\t\t\t\t     User %s!",username);
	printf("\n\n+----------------------------------------------------------------------------------------------------------------------+");
	printf("\n\n\t\t\t\t\t\t\t  Features");
	printf("\n\n\n\t  1.Change username");
	printf("\t\t\t\t2.Change password");
	printf("\t\t\t   3.Change Real Name");
	printf("\n\t     [Press 1]");
	printf("\t\t\t\t\t  [Press 2]");
	printf("\t\t\t\t     [Press 3]");
	printf("\n\n\n\t        4.<-- Back");
	printf("\t\t\t\t\t\t\t\t5.Delete Account");
	printf("\n\t         [Press 4]");
	printf("\t\t\t\t\t\t\t\t  [Press 5]");
	printf("\n\n\n\n+----------------------------------------------------------------------------------------------------------------------+");
	printf("\n\n\n\t\t\t\t\t\t  Enter you choice: ");
	fflush(stdin);
	scanf("%c",&user_choice);
	switch (user_choice)
	{
		case '1':
			change_driver(1);
		break;
		case '2':
			change_driver(2);
		break;
		case '3':
			change_driver(3);
		break;
		case '4':
			system("cls");
			printf("\n\n\n\n\t\t\t\t\t\t\tExiting");
			for(i=5;i>=1;i--)
			{
				printf(".");
				Sleep(1000);
			}
			driver_homepage(username);
		break;
		case '5':
			change_driver(4);
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

void job_apply(char username[])
{
	int i,k,recruit_choice,count=0,choice,user_choice,count_driver=0;
	char quit;
	struct bus_company b;
	struct driver d,d2;
	struct job_application j;
	FILE *ptr_driver,*ptr_company,*ptr_job;
	ptr_driver = fopen("driver_login.bin","rb");
	if(ptr_driver == NULL)
	{
		printf("\n\n\n\n\t\t\t\t\tError in the server!Please Try again");
		for(i=5;i>=1;i--)
		{
			printf(".");
			Sleep(1000);
		}
		main();
	}
	ptr_company = fopen("bus_company_login.bin","rb");
	if(ptr_company == NULL)
	{
		printf("\n\n\n\n\t\t\t\t\tError in the server!Please Try again");
		for(i=5;i>=1;i--)
		{
			printf(".");
			Sleep(1000);
		}
		main();
	}
	ptr_job = fopen("job_application.bin","ab+");
	if(ptr_job == NULL)
	{
		printf("\n\n\n\n\t\t\t\t\tError in the server!Please Try again");
		for(i=5;i>=1;i--)
		{
			printf(".");
			Sleep(1000);
		}
		main();
	}
	system("cls");
	printf("\n\n\n\t\t\t\t\t\t\tDriver\'s Hub");
	printf("\n\n\t\t\t\t\t\t  Welcome User %s!",username);
	printf("\n\n+----------------------------------------------------------------------------------------------------------------------+");
	while(!feof(ptr_driver))
	{
		fread(&d,sizeof(d),1,ptr_driver);
		if(strcmp(d.username,username)==0)
		{
			if(d.recruit_status=='y')
			{
				printf("\n\n\t\t\t\t\t\tYou are already hired by %s.",d.affiliated_company);
				printf("\n\n\t\t\t\t\t\tOptions:");
				printf("\n\n\t\t\t\t\t     1. Leave Job");
				printf("\n\n\t\t\t\t\t     2. <-- Back");
				printf("\n\n\t\t\t\t\tEnter your choice: ");
				scanf("%d",&recruit_choice);
				if(recruit_choice == 1)
				{
					printf("\n\n\t\t\t\t\t\tList of company to apply for job:");
					while(fread(&b,sizeof(b),1,ptr_company))
					{
						count++;
						printf("\n\n\t\t\t\t\t\t%d %s",count,b.name);
					}
					rewind(ptr_driver);
					while(!feof(ptr_driver))
					{
						fread(&d2,sizeof(d2),1,ptr_driver);
						count_driver++;
					}
					struct driver all[count_driver];
					rewind(ptr_company);
					rewind(ptr_driver);
					fread(&all,sizeof(struct driver),count,ptr_driver);
					fclose(ptr_driver);
					printf("\n\n\t\t\t\t\t\tEnter your choice:");
					scanf("%d",&choice);
					if(choice<0||choice>count)
					{
						printf("\n\n\t\t\t\t\t\tInvalid Input! Try again");
						for(i=5;i>=1;i--)
						{
							printf(".");
							Sleep(1000);
						}
						job_apply(username);
					}
					for(i=0;i<count;i++)
					{
						fread(&b,sizeof(b),1,ptr_company);
						if(i+1==choice)
						{
							system("cls");
							printf("\n\n\n\t\t\t\t\t\t\tDriver\'s Hub");
							printf("\n\n\t\t\t\t\t\t  Welcome User %s!",username);
							printf("\n\n+----------------------------------------------------------------------------------------------------------------------+");
							printf("\n\n\t\t\t\t\t      Details of %s",b.name);
							printf("\n\n\t\t\t\t\t\t Bus number = %d",b.bus_number);
							printf("\n\n\t\t\t\t\t\t Destination 1: %s",b.destinations[0]);
							printf("\n\n\t\t\t\t\t\t Destination 2: %s",b.destinations[1]);
							printf("\n\n\t\t\t\t\t\t Destination 3: %s",b.destinations[2]);
							printf("\n\n+----------------------------------------------------------------------------------------------------------------------+");
							printf("\n\n\t\t\t\t\t\t\tOptions:");
							printf("\n\n\t1. Apply for Job \t\t\t\t\t\t\t\t\t2.Exit");
							printf("\n\n\t\t\t\t\t\tEnter your choice:");
							fflush(stdin);
							scanf("%d",&user_choice);
							if(user_choice == 1)
							{
								strcpy(j.employee_name,username);
								strcpy(j.company_name,b.username);
								fwrite(&j,sizeof(j),1,ptr_job);
								fclose(ptr_job);
								for(k=0;k<count_driver;k++)
								{
									if(strcmp(all[k].username,username)==0)
									{
										all[k].recruit_status = 'e';
									}
								}
								ptr_driver = fopen("driver_login.bin","wb");
								fwrite(&all,sizeof(struct driver),count,ptr_driver);
								fclose(ptr_driver);
								system("cls");
								printf("\n\n\t\t\t\t\t\tApplied Successfully!");
								printf("\n\n\t\t\t\t\t\t\tRedirecting");
								for(i=5;i>=1;i--)
								{
									printf(".");
									Sleep(1000);
								}
								driver_homepage(username);
								break;
							}
						}
					}
					break;
				}
				else if(recruit_choice == 2)
				{
					driver_homepage(username);
				}
				else
				{
					printf("\n\n\t\t\t\t\t\tInvalid Input! Try again");
					for(i=5;i>=1;i--)
					{
						printf(".");
						Sleep(1000);
					}
					job_apply(username);
				}
			}
			else if(d.recruit_status=='e')
			{
				system("cls");
				printf("\n\n\n\t\t\t\t\tYou are in process of hiring. Please wait!");
				printf("\n\n\t\t\t\t\tEnter any thing to go to homepage: ");
				fflush(stdin);
				scanf("%c",&quit);
				driver_homepage(username);
			}
			else if(d.recruit_status=='n')
			{
				printf("\n\n\t\t\t\t\t\tList of company to apply for job:");
				while(fread(&b,sizeof(b),1,ptr_company))
				{
					count++;
					printf("\n\n\t\t\t\t\t\t%d %s",count,b.name);
				}
				rewind(ptr_driver);
				while(!feof(ptr_driver))
				{
					fread(&d2,sizeof(d2),1,ptr_driver);
					count_driver++;
				}
				struct driver all[count_driver];
				rewind(ptr_company);
				rewind(ptr_driver);
				fread(&all,sizeof(struct driver),count,ptr_driver);
				fclose(ptr_driver);
				printf("\n\n\t\t\t\t\t\tEnter your choice:");
				scanf("%d",&choice);
				if(choice<0||choice>count)
				{
					printf("\n\n\t\t\t\t\t\tInvalid Input! Try again");
					for(i=5;i>=1;i--)
					{
						printf(".");
						Sleep(1000);
					}
					job_apply(username);	
				}
				for(i=0;i<count;i++)
				{
					fread(&b,sizeof(b),1,ptr_company);
					if(i+1==choice)
					{
						system("cls");
						printf("\n\n\n\t\t\t\t\t\t\tDriver\'s Hub");
						printf("\n\n\t\t\t\t\t\t  Welcome User %s!",username);
						printf("\n\n+----------------------------------------------------------------------------------------------------------------------+");
						printf("\n\n\t\t\t\t\t      Details of %s",b.name);
						printf("\n\n\t\t\t\t\t\t Bus number = %d",b.bus_number);
						printf("\n\n\t\t\t\t\t\t Destination 1: %s",b.destinations[0]);
						printf("\n\n\t\t\t\t\t\t Destination 2: %s",b.destinations[1]);
						printf("\n\n\t\t\t\t\t\t Destination 3: %s",b.destinations[2]);
						printf("\n\n+----------------------------------------------------------------------------------------------------------------------+");
						printf("\n\n\t\t\t\t\t\t\tOptions:");
						printf("\n\n\t1. Apply for Job \t\t\t\t\t\t\t\t\t2.Exit");
						printf("\n\n\t\t\t\t\t\tEnter your choice:");
						fflush(stdin);
						scanf("%d",&user_choice);
						if(user_choice == 1)
						{
							strcpy(j.employee_name,username);
							strcpy(j.company_name,b.username);
							fwrite(&j,sizeof(j),1,ptr_job);
							fclose(ptr_job);
							for(k=0;k<count_driver;k++)
							{
								if(strcmp(all[k].username,username)==0)
								{
									all[k].recruit_status = 'e';
									break;
								}
							}
							printf("%c",all[k].recruit_status);
							ptr_driver = fopen("driver_login.bin","wb");
							fwrite(&all,sizeof(struct driver),count,ptr_driver);
							fclose(ptr_driver);
							system("cls");
							printf("\n\n\t\t\t\t\t\tApplied Successfully!");
							printf("\n\n\t\t\t\t\t\t\tRedirecting");
							for(i=5;i>=1;i--)
							{
								printf(".");
								Sleep(1000);
							}
							driver_homepage(username);
							break;
						}
						else if(user_choice == 2)
						{
							driver_homepage(username);
						}
						else
						{
							printf("\n\n\t\t\t\t\t\tInvalid input! Try Again");
							for(i=5;i>=1;i--)
							{
								printf(".");
								Sleep(1000);
							}
							job_apply(username);
						}
					}
				}
				break;
			}
		}
	}
	for(i=5;i>=1;i--)
		{
			printf(".");
			Sleep(1000);
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
	char userName[50],Pass[50],choice,ch;
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
	i=0;
	while(1)
	{
		if(_kbhit())
		{
			ch = _getch();
			if(ch == '\r')
			{
				Pass[i] = '\0';
				break;
			}
			else if(ch == '\b' && i>0)
			{
				printf("\b \b");
                i--;
			}
			else if(i<100)
			{
				Pass[i] = ch;
				printf("*");
				i++;
			}
		}
	}
	rewind(ptr);
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
	printf("\n\n\t\t\t\t\t  incorrect id or password! enter again");
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
	char card_choice,ch;
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
	i=0;
	while(1)
	{
		if(_kbhit())
		{
			ch = _getch();
			if(ch == '\r')
			{
				u.pass[i] = '\0';
				break;
			}
			else if(ch == '\b' && i>0)
			{
				printf("\b \b");
                i--;
			}
			else if(i<100)
			{
				u.pass[i] = ch;
				printf("*");
				i++;
			}
		}
	}
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
			bus_list(username);
		break;
		case 2:
			travelling_fare(username);
		break;
		case 3:
			user_report(username);
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
			user_setting(username);
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
	int count=0,i,flag=0,error_count=0,j,file_count;
	char userName[50],unique_code[6],new_pass[50],new_pass2[50],ch,Pass[50],new_username[50],new_name[50];;
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
		for(file_count=0;file_count<count;file_count++)
		{
			if(strcmp(all[file_count].username,userName)==0&&strcmp(all[file_count].unique_pin,unique_code)==0)
			{
				try_again:
				fflush(stdin);
				printf("\n\n\t\t\t\t\t\tEnter your new pass: ");
				i=0;
				while(1)
				{
					if(_kbhit())
					{
						ch = _getch();
						if(ch == '\r')
						{
							new_pass[i] = '\0';
							break;
						}
						else if(ch == '\b' && i>0)
						{
							printf("\b \b");
                			i--;
						}
						else if(i<100)
						{
							new_pass[i] = ch;
							printf("*");
							i++;
						}
					}
				}
				printf("\n\n\t\t\t\t\t   Enter your new pass again: ");
				i=0;
				while(1)
				{
					if(_kbhit())
					{
						ch = _getch();
						if(ch == '\r')
						{
							new_pass2[i] = '\0';
							break;
						}
						else if(ch == '\b' && i>0)
						{
							printf("\b \b");
                			i--;
						}
						else if(i<100)
						{
							new_pass2[i] = ch;
							printf("*");
							i++;
						}
					}
				}
				if(strcmp(new_pass,new_pass2)==0)
				{
					strcpy(all[file_count].pass,new_pass);
					ptr = fopen("user_login.bin","wb");
					fwrite(all,sizeof(struct user),count,ptr);
					fclose(ptr);
					printf("\n\n\n\t\t\t\t\tPassword changed successfully!");
					printf("\n\n\n\t\t\t\t\t\tRedirecting");
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
		error_count++;
		if(error_count >=2)
		{
			printf("\n\n\t\t\t\t\t\t  Too many attempts!");
			printf("\n\n\t\t\t\t\t    Redirecting to homepage");	
			for(j=5;j>=1;j--)
			{
				printf(".");
				Sleep(1000);
			}
			main();
		}
		goto main_try_again;
	}
	else if(n == 1)
	{
		username_try_again:
		fflush(stdin);
		printf("\n\n\n\n\t\t\t\t\t\t  Enter your username: ");
		gets(userName);
		printf("\n\n\t\t\t\t\t\t  Enter your password: ");
		gets(Pass);
		for(i=0;i<count;i++)
		{
			if(strcmp(all[i].username,userName)==0&&strcmp(all[i].pass,Pass)==0)
			{
				fflush(stdin);
				printf("\n\n\t\t\t\t\t\tEnter your new username: ");
				gets(new_username);
				strcpy(all[i].username,new_username);
				ptr = fopen("user_login.bin","wb");
				fwrite(all,sizeof(struct user),count,ptr);
				fclose(ptr);
				printf("\n\n\n\t\t\t\t\tUsername changed successfully!");
				printf("\n\n\n\t\t\t\t\t\tRedirecting");
				for(i=5;i>=1;i--)
				{
					printf(".");
					Sleep(1000);
				}
				user_login();
			}
		}
		printf("\n\n\t\t\t\t\tIncorrect username or password! Try again");
		goto username_try_again;
	}
	else if(n == 2)
	{
		pass_try_again:
		fflush(stdin);
		printf("\n\n\n\n\t\t\t\t\t\t  Enter your username: ");
		gets(userName);
		printf("\n\n\t\t\t\t\t    Enter your current password: ");
		gets(Pass);
		for(i=0;i<count;i++)
		{
			if(strcmp(all[i].username,userName)==0&&strcmp(all[i].pass,Pass)==0)
			{
				p_try_again:
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
					printf("\n\n\n\t\t\t\t\t    Password changed successfully!");
					printf("\n\n\n\t\t\t\t\t\t   Redirecting");
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
					goto p_try_again;
				}	
			}
		}
		printf("\n\n\t\t\t\t\tIncorrect username or pass! Try again");
		goto pass_try_again;
	}
	else if(n == 3)
	{
		name_try_again:
		fflush(stdin);
		printf("\n\n\n\n\t\t\t\t\t\t  Enter your username: ");
		gets(userName);
		printf("\n\n\t\t\t\t\t\t  Enter your password: ");
		gets(Pass);
		for(i=0;i<count;i++)
		{
			if(strcmp(all[i].username,userName)==0&&strcmp(all[i].pass,Pass)==0)
			{
				fflush(stdin);
				printf("\n\n\t\t\t\t\t Enter your new Real Name: ");
				gets(new_name);
				strcpy(all[i].real_name,new_name);
				ptr = fopen("user_login.bin","wb");
				fwrite(all,sizeof(struct user),count,ptr);
				fclose(ptr);
				printf("\n\n\n\t\t\t\t\tReal Name changed successfully!");
				printf("\n\n\n\t\t\t\t\t\tRedirecting");
				for(i=5;i>=1;i--)
				{
					printf(".");
					Sleep(1000);
				}
				user_login();
			}
		}
		printf("\n\n\t\t\t\t\tIncorrect username or password! Try again");
		goto name_try_again;
	}
	else if(n == 4)
	{
		delete_try_again:
		fflush(stdin);
		printf("\n\n\n\n\t\t\t\t\t\t  Enter your username: ");
		gets(userName);
		printf("\n\n\t\t\t\t\t\t  Enter your password: ");
		gets(Pass);
		ptr = fopen("user_login.bin","wb");
		for(i=0;i<count;i++)
		{
			if(strcmp(all[i].username,userName)==0&&strcmp(all[i].pass,Pass)==0)
			{
				flag = 1;
				continue;
			}
			else
			{
				fwrite(&all[i],sizeof(struct user),1,ptr);
			}
		}
		fclose(ptr);
		if(flag == 0)
		{
			printf("\n\n\t\t\t\t\tIncorrect username or password! Try again");
			goto name_try_again;	
		}
		else
		{
			printf("\n\n\t\t\t\t\t    ID deletd successfully!");
			printf("\n\n\t\t\t\t\t\t    Redirecting");
			for(i=5;i>=1;i--)
			{
				printf(".");
				Sleep(1000);
			}
			main();
		}
	}
}

void user_setting(char username[])
{
	system("cls");
	char user_choice;
	int i;
	retry:
	printf("\n\n\n\t\t\t\t\t\t      User\'s Settings");
	printf("\n\n\t\t\t\t\t\t     User %s!",username);
	printf("\n\n+----------------------------------------------------------------------------------------------------------------------+");
	printf("\n\n\t\t\t\t\t\t\t  Features");
	printf("\n\n\n\t  1.Change username");
	printf("\t\t\t\t2.Change password");
	printf("\t\t\t   3.Change Real Name");
	printf("\n\t     [Press 1]");
	printf("\t\t\t\t\t  [Press 2]");
	printf("\t\t\t\t     [Press 3]");
	printf("\n\n\n\t        4.<-- Back");
	printf("\t\t\t\t\t\t\t\t5.Delete Account");
	printf("\n\t         [Press 4]");
	printf("\t\t\t\t\t\t\t\t  [Press 5]");
	printf("\n\n\n\n+----------------------------------------------------------------------------------------------------------------------+");
	printf("\n\n\n\t\t\t\t\t\t  Enter you choice: ");
	fflush(stdin);
	scanf("%c",&user_choice);
	switch (user_choice)
	{
		case '1':
			change_user(1);
		break;
		case '2':
			change_user(2);
		break;
		case '3':
			change_user(3);
		break;
		case '4':
			system("cls");
			printf("\n\n\n\n\t\t\t\t\t\t\tExiting");
			for(i=5;i>=1;i--)
			{
				printf(".");
				Sleep(1000);
			}
			user_homepage(username);
		break;
		case '5':
			change_user(4);
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

void bus_list(char username[])
{
	system("cls");
	int count=0,i,choice,j,one_choice;
	FILE *ptr;
	struct bus_company b,*all = NULL;
	ptr = fopen("bus_company_login.bin","rb");
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
	printf("\n\n\t\t\t\t\t\tWelcome User %s!",username);
	printf("\n\n+----------------------------------------------------------------------------------------------------------------------+");
	printf("\n\n\t\t\t\t\t       List of active bus company");
	while(fread(&b,sizeof(b),1,ptr))
	{
		printf("\n\n\t\t\t\t\t    %d %s [%d buses]",count+1,b.name,b.bus_number);
		count++;
	}
	printf("\n\n\t\t\t\t\t    %d <--back",count+1);
	rewind(ptr);
	all = (struct bus_company*)calloc(count,sizeof(struct bus_company));
	fread(all,sizeof(struct bus_company),count,ptr);
	printf("\n\n\n\t\t\t\t   Enter number above to see the route: ");
	fflush(stdin);
	scanf("%d",&choice);
	if(choice == count+1)
	{
		user_homepage(username);
	}
	for(i=0;i<count;i++)
	{
		if(i+1==choice)
		{
			system("cls");
			printf("\n\n\t\t\t\t\t    The route of %s are:",all[i].name);
			for(j=0;j<3;j++)
			{
				printf("\n\n\t\t\t\t\t\t\t%d %s",j+1,all[i].destinations[j]);
			}
			printf("\n\n+----------------------------------------------------------------------------------------------------------------------+");
			printf("\n\n\t\t\t\t\t\t\tOptions:");
			printf("\n\n\t\t\t\t\t\t  1. Bus Fair Calculate");
			printf("\n\n\t\t\t\t\t\t     2. <--Back");
			printf("\n\n\n\t\t\t\t\tEnter your choice: ");
			fflush(stdin);
			scanf("%d",&one_choice);
			if(one_choice == 1)
			{ 
				travelling_fare(username);
			}
			else if(one_choice == 2)
			{
				bus_list(username);
			}
			else
			{
				printf("\n\n\t\t\t\t\t\t    Incorrect Input!");
				printf("\n\n\t\t\t\t\t\t     Redirecting");
				for(j=5;j>=1;j--)
				{
					printf(".");
					Sleep(1000);
				}
				bus_list(username);
			}
		}	
	}
	printf("\n\n\t\t\t\t\t    Incorrect option! Try Again");
	for(j=3;j>=1;j--)
	{
		printf(".");
		Sleep(1000);
	}
	bus_list(username);
}

void travelling_fare(char username[])
{
	system("cls");
	int i,j,count=0,choice,p_location,d_location;
	float fare,discount;
	char exit_choice,quit;
	struct bus_company b, *all_bus = NULL;
	struct user u, *all_user = NULL;
	FILE *bus_ptr,*user_ptr;
	bus_ptr = fopen("bus_company_login.bin","rb");
	if(bus_ptr == NULL)
	{
		printf("\n\n\n\n\t\t\t\t\tError in the server!Please Try again");
		for(i=5;i>=1;i--)
		{
			printf(".");
			Sleep(1000);
		}
		main();
	}
	user_ptr = fopen("user_login.bin","rb");
	if(user_ptr == NULL)
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
	printf("\n\n\t\t\t\t\t\tWelcome User %s!",username);
	printf("\n\n+----------------------------------------------------------------------------------------------------------------------+");
	printf("\n\n\t\t\t\t\t\tTravelling Fare Calculator");
	printf("\n\n\t\t\t\t\t       List of active bus company");
	while(fread(&b,sizeof(b),1,bus_ptr))
	{
		printf("\n\n\t\t\t\t\t    %d %s [%d buses]",count+1,b.name,b.bus_number);
		count++;
	}
	printf("\n\n\t\t\t\t\t    %d <--back",count+1);
	rewind(bus_ptr);
	all_bus = (struct bus_company*)calloc(count,sizeof(struct bus_company));
	fread(all_bus,sizeof(struct bus_company),count,bus_ptr);
	printf("\n\n\t\t\t\t    Note: Bus fare can only be calculated for the same bus!");
	printf("\n\n\n\t\t\t\t   Enter number above to calculate fare: ");
	fflush(stdin);
	scanf("%d",&choice);
	if(choice == count+1)
	{
		user_homepage(username);
	}
	for(i=0;i<count;i++)
	{
		if(i+1 == choice)
		{
			system("cls");
			printf("\n\n\t\t\t\t\t    The route of %s are:",all_bus[i].name);
			for(j=0;j<3;j++)
			{
				printf("\n\n\t\t\t\t\t\t\t%d %s",j+1,all_bus[i].destinations[j]);
			}
			printf("\n\n+----------------------------------------------------------------------------------------------------------------------+");
			retry:
			printf("\n\n\n\t\t\t     Choose your pickup location[in number]: ");
			scanf("%d",&p_location);
			printf("\n\n\n\t\t\t     Choose your destination[in number]: ");
			scanf("%d",&d_location);
			if(p_location == d_location)
			{
				printf("\n\n\t\t\t\t    Error! You cannot have same pickup and destination.");
				goto retry;
			}
			else if((p_location<1||p_location>3)||(d_location<1||d_location>3))
			{
				try_again:
				system("cls");
				printf("\n\n\t\t\t\t\t    Incorrect option! Do you want to exit?");
				printf("\n\n\n\t\t\t\t\t\t\t    Yes\n\t\t\t\t\t\t    [Press 'y' or 'Y']");
				printf("\n\n\n\t\t\t\t\t\t\t     No\n\t\t\t\t\t\t    [Press 'n' or 'N']");
				printf("\n\n\n\t\t\t\t\tEnter your choice: ");
				fflush(stdin);
				scanf("%c",&exit_choice);
				if(exit_choice == 'y' || exit_choice == 'Y')
				{
					user_homepage(username);
				}
				else if(exit_choice == 'n' || exit_choice == 'N')
				{
					travelling_fare(username);
				}
				else
				{
					printf("\n\n\t\t\t\t\t    Incorrect option! Try Again");
					for(j=3;j>=1;j--)
					{
						printf(".");
						Sleep(1000);
					}
					goto try_again;
				}
			}
			if(abs(p_location-d_location)==1)
			{
				fare = 20.0;
			}
			else if(abs(p_location-d_location)==2)
			{
				fare = 30.0;
			}
			while(fread(&u,sizeof(u),1,user_ptr))
			{
				if(strcmp(u.username,username)==0)
				{
					if(u.age<=22||u.age>=65)
					{
						discount = (45.0/100)*fare;
						fare = fare - discount;
						break;
					}
				}
			}
			system("cls");
			printf("\n\n\n\t\t\t\t\t\t\tUser\'s Hub");
			printf("\n\n\t\t\t\t\t\tWelcome User %s!",username);
			printf("\n\n+----------------------------------------------------------------------------------------------------------------------+");
			printf("\n\n\t\t\t\t\t\tTravelling Fare Calculator");
			printf("\n\n\n\n\t\t\t\t\t      Your total Fare is: %.2f",fare);
			if(discount > 0)
			{
				printf("\n\n\t\t\t\t\t     Your total discount is: %.2f",discount);
			}
			printf("\n\n\t\t\t\t\t\t Enter any thing to go to homepage: ");
			fflush(stdin);
			scanf("%c",&quit);
			user_homepage(username);
		}
	}
	printf("\n\n\t\t\t\t\t    Incorrect option! Try Again");
	for(j=3;j>=1;j--)
	{
		printf(".");
		Sleep(1000);
	}
	travelling_fare(username);
}

void user_report(char username[])
{
	struct report r;
	struct user u;
	struct bus_company b,*all=NULL;
	int count=0,user_detect,i,bus_no,j,quit;
	FILE *ptr_report,*ptr_user,*ptr_bus;
	ptr_user = fopen("user_login.bin","rb");
	if(ptr_user == NULL)
	{
		printf("\n\n\n\n\t\t\t\t\tError in the server!Please Try again");
		for(i=5;i>=1;i--)
		{
			printf(".");
			Sleep(1000);
		}
		main();
	}
	ptr_bus = fopen("bus_company_login.bin","rb");
	if(ptr_bus == NULL)
	{
		printf("\n\n\n\n\t\t\t\t\tError in the server!Please Try again");
		for(i=5;i>=1;i--)
		{
			printf(".");
			Sleep(1000);
		}
		main();
	}
	ptr_report = fopen("user_report.bin","ab+");
	if(ptr_report == NULL)
	{
		printf("\n\n\n\n\t\t\t\t\tError in the server!Please Try again");
		for(i=5;i>=1;i--)
		{
			printf(".");
			Sleep(1000);
		}
		main();
	}
	system("cls");
	printf("\n\n\n\t\t\t\t\t\t\tUser\'s Hub");
	printf("\n\n\t\t\t\t\t\tWelcome User %s!",username);
	printf("\n\n+----------------------------------------------------------------------------------------------------------------------+");
	printf("\n\n\t\t\t\t\t\t    Report Section");
	printf("\n\n\n\t\t\t\t\tChoose the company to want to report to!");
	while(fread(&b,sizeof(b),1,ptr_bus))
	{
		printf("\n\n\t\t\t\t\t    %d %s [%d buses]",count+1,b.name,b.bus_number);
		count++;
	}
	printf("\n\n\n\t\t\t\t      Enter number above to report: ");
	scanf("%d",&bus_no);
	if(bus_no<1||bus_no>count)
	{
		printf("\n\n\t\t\t\t\t Incorrect option! Try Again");
		for(j=3;j>=1;j--)
		{
			printf(".");
			Sleep(1000);
		}
		user_report(username);
	}
	rewind(ptr_bus);
	for(i=0;i<count;i++)
	{
		fread(&b,sizeof(b),1,ptr_bus);
		if(i+1==bus_no)
		{
			strcpy(r.bus,b.username);
			break;
		}
	}
	printf("\n\n\t\t\t\t\t     Enter your report here:\n\n\t\t");
	fflush(stdin);
	gets(r.reprt);
	while(fread(&u,sizeof(u),1,ptr_user))
	{
		if(strcmp(u.username,username)==0)
		{
			strcpy(r.name,u.real_name);
		}
	}
	fwrite(&r,sizeof(r),1,ptr_report);
	fclose(ptr_user);
	fclose(ptr_report);
	fclose(ptr_bus);
	printf("\n\n\t\t\t\t\t\tReported Successfully!");
	printf("\n\n\t\t\t\t\tEnter any thing to go to homepage: ");
	fflush(stdin);
	scanf("%c",&quit);
	user_homepage(username);
}
