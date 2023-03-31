#include<stdio.h>
#include<windows.h>//gotoxy()
#include<conio.h>//use for delay(),getch()etc.
#include<ctype.h>//use for toupper(), tolower(),etc.
#include<string.h>//use for strcmp(),strcpy(),strlen(),etc.
#include<stdlib.h>
char ans=0;
int ok;
int b, valid=0;
//FUNCTION DECLERATION
void WelcomeScreen(void);//WelcomeScreen function decleration
void Title(void);//Title function decleration 
void MainMenu(void);//MainMenu function declaration
void LoginScreen(void);//LoginScreen function decleration
void Add_rec(void);//Add_rec function decleration
void func_list();//function to list the patient details
void Search_rec(void);//Search_rec function decleration
void Edit_rec(void);//Edit_rec function decleration
void Dlt_rec(void);//Dlt_rec function decleration
void ex_it(void);//exit function declarection
void gotoxy(short x, short y)
{
	COORD pos = {x, y};//sets co-ordinates in (x,y)#include<stdio.h>
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//list of global variable

struct patient
{
	int age;
	char Gender;
	char First_Name[20];
	char Last_Name[20];
	char Contact_no[15];
	char Address[30];
	char Email[30];
	char Doctor[20];
	char problem[20];
};
struct patient p,temp_c;
main(void)
{
	WelcomeScreen();//Use to call WelcomeScreen function
	Title();//Use to call Title function
	LoginScreen();//Use to call Menu function
}
/* ************************************************ Welcome Screen ******************************************* */
void WelcomeScreen(void)//function for welcome screen
{
	printf("\n\n\n\n\n\n\n\t\t\t############################################");
	printf("\n\t\t\t\t#\t\tWELCOME TO\t\t#");
	printf("\n\t\t\t#     AURBINDO HOSPITAL MANAGEMENT SYSTEM    #");
	printf("\n\t\t\t############################################");
	printf("\n\n\n\n\n Press any key to continue.....\n");
	getch();
	system("cls");//Use to clear screen
}
/* ************************************************ Title Screen ********************************************** */
void Title(void)//function for title screen
{
	printf("\n\n\t\t-------------------------------------------------------------------------------------------");
	printf("\n\t\t\t             AURBINDO HOSPITAL           ");
	printf("\n\t\t---------------------------------------------------------------------------------------------");
}
/* ************************************************ Main Menu  ********************************************** */
void MainMenu(void)//function decleration
{
	system("cls");
	int choose;
	Title();//call Title function
	printf("\n\t\t\t\t1. Add Patient Record\n");
	printf("\n\t\t\t\t2. List Patient Record\n");
	printf("\n\t\t\t\t3. Search Patient Record\n");
	printf("\n\t\t\t\t4. Edit Patient Record\n");
	printf("\n\t\t\t\t5. Delete Patient Record\n");
	printf("\n\t\t\t\t6. Exit\n");
	printf("\n\n\n \n\t\t\t\tchoose from 1 to 6:");
	scanf("%i", &choose);
	switch(choose)//Add_rec function is called
	{
		case 1:
			Add_rec();
			break;
		case 2:
		     func_list();
			 break;
		case 3:
		     Search_rec();//View _rec function is call
			break;
		case 4:
		     Edit_rec();//Edit_rec function is call
		     break;
		case 5:
		     Dlt_rec();//Dlt_rec functiomn is call
		     break;
		case 6:
		     ex_it();//ex_it function is call
		     break;
		default:
		     printf("\t\t\tInvalid entry. please enter right option :)");
			 getch();
    }
}
/* ************************************************ Exit Screen  ********************************************** */
void ex_it(void)//function to exit
{
	system("cls");
	Title();
	printf("\n\n\n\n\n\t\t\tTHANK YOU FOR VISITING :)");
	getch();
}
/* ************************************************ Login Screen ********************************************** */
void LoginScreen(void)//function for login screen
{
	//List of variables
	int e=0 ;
	char Username[15];
	char Password[15];
	char original_Username[25]="chanchal";
	char original_Password[15]="5626";
	do
	{
		printf("\n\n\n\n\t\t\tEnter your Username and Password :)");
		printf("\n\n\n\t\t\t\tUsername:");
		scanf("%s", &Username);
		printf("\n\n\t\t\t\tPassword:");
		scanf("%s", &Password);
		if (strcmp(Username,original_Username)==0 && strcmp(Password,original_Password)==0)
		{
			printf("\n\n\n\t\t\t\t\t...Login Successful...");
			getch();
			MainMenu();//call MainMenu function
			break;
		}
		else
		{
			printf("\n\t\t\tPassword in incorrect:( Try Again :)");
			e++;
			getch();
		}
	}while(e<=2);
	if(e>2)
	{
		printf("You have cross the limit. You cannot login. :( :(");
		getch();
		ex_it();
	}
	system("cls");
}
/* ************************************************ ADD RECORD ********************************************** */
void Add_rec(void)
{
	system("cls");
	Title();// call Title function
	//list of variables
	char ans;
	FILE*ek;//file pointer
	ek=fopen("Record2.dat","a");//open file in write mode
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Add Patient Record  !!!!!!!!!!!!!!!!!\n");
	/* ***********************First Name ********************************** */
	A:
	printf("\n\t\t\tFirst Name: ");
	scanf("%s",p.First_Name);
	p.First_Name[0]=toupper(p.First_Name[0]);
	if(strlen(p.First_Name)>20||strlen(p.First_Name)<2)	
	{
		printf("\n\t Invalid :( \t The max range for first name is 20 and min range is 2)");
		goto A;
    }
     else
     {
     	for (b=0;b<strlen(p.First_Name);b++)
     	{
     		if(isalpha(p.First_Name[b]))
     		{
     			valid=1;
			}
			else
			{
			 	valid=0;
			 	break;
		    }
		}
		if(!valid)
		{
			printf("\n\t\t First name contain Invalid character :( Enter again :)");
			goto A;
		}
	}
	/* ***********************Last Name ********************************** */
	B:
	printf("\n\t\t\tLast Name: ");
	scanf("%s",p.Last_Name[0]);
	p.Last_Name[0]=toupper(p.Last_Name[0]);
	if(strlen(p.Last_Name)>20||strlen(p.Last_Name)<2)	
	{
		printf("\n\t Invalid :( \t The max range for last name is 20 and min range is 2 :)");
		goto B;
	}
	else
	{
		for (b=0;b<strlen(p.Last_Name);b++)
		{
			if (isalpha(p.Last_Name[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Last name contain Invalid character :( Enter again :)");
			goto B;
		}
	}
    /* ******************************************  Gender ******************************************* */
    do
    {
    	printf("\n\t\tGender[F/M]: ");
    	scanf(" %c",&p.Gender);
    	if(toupper(p.Gender)=='M'|| toupper(p.Gender)=='F')
    	{
    		ok =1;
		}
		else
		{
			ok =0;
		}
		if(!ok)
		{
			printf("\n\t\t Gender Invalid character :( Enter either F or M :)");
		}
	}while(!ok);
	/* ******************************  Age  ************************************ */
	printf("\n\t\t\tAge:");
	scanf(" %i",&p.age);
	/* ***************************   Address  ********************************** */
	do
	{
		C:
		printf("\n\t\t\tAddress: ");
		scanf("%s",p.Address);
		p.Address[0]=toupper(p.Address[0]);
		if(strlen(p.Address)>20||strlen(p.Address)<4)
		{
			printf("\n\t Invalid :( \t The max range for address is 20 and min range is 4)");
			goto C;
		}
	}while(!valid);
	/* *****************************  Contact no. ********************************** */
	do
	{
		D:
		printf("\n\t\tContact no: ");
		scanf("%s",p.Contact_no);
		if(strlen(p.Contact_no)>10||strlen(p.Contact_no)!=10)
		{
			printf("\n\t Sorry :( Invalid Contact no. must contain 10 numbers . Enter again)");
			goto D;
     	}
		 else
		{
		 	for (b=0;b<strlen(p.Contact_no);b++)
		 	{
		 		if (!isalpha(p.Contact_no[b]))
		 		{
		 			valid=1;
				}
				else
				{
					valid=0;
					break;
				}
			}
			if(!valid)
			{
				printf("\n\t\t Contact no. contain Invalid character :( Enter again :)");
				goto D;
			}
		}	
	}while(!valid);
	/* **********************************  Email  ********************************** */
	do
	{
		printf("\n\t\tEmail: ");
		scanf("%s",p.Email);
		if(strlen(p.Email)>30||strlen(p.Email)<8)
		{
			printf("\n\t Invalid :( \t The max range for email is 30 and min range is 8 :)");
		}
	}while(strlen(p.Email)>30||strlen(p.Email)<8);
	/* ***************************  Problem  ********************************** */
	E:
	printf("\n\t\tProblem:  ");
	scanf("%s",p.problem);
	p.problem[0]=toupper(p.problem[0]);
	if(strlen(p.problem)>15||strlen(p.problem)<3)
	{
		printf("\n\t Invalid :( \t The max range for first name is 15 and min range is 3)");
		goto E;
	}
	else
	{
		for (b=0;b<strlen(p.problem);b++)
		{
			if (isalpha(p.problem[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Problem contain Invalid character :( Enter again :)");
			goto E;
		}
	}
	/* ***************************  Prescribed Doctor ********************************** */
	F:
	printf("\n\t\tPrescribed Doctor:  ");
	scanf("%s",p.Doctor);
	p.Doctor[0]=toupper(p.Doctor[0]);
	if(strlen(p.Doctor)>30||strlen(p.Doctor)<3)
	{
		printf("\n\t Invalid :( \t The max range for first name is 30 and min range is 3)");
		goto F;
	}
	else
	{
		for (b=0;b<strlen(p.Doctor);b++)
		{
			if (isalpha(p.Doctor[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Doctor name contain Invalid character :( Enter again :)");
			goto F;
		}
	}
	fprintf(ek," %s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.problem);
	printf("\n\n\t\t\t... Information Record Successful...");
	fclose(ek);//ek file closed
	sd:
	getch();
	printf("\n\n\t\t\tDo you want to add more[Y/N]?? ");
	scanf(" %c , &ans");
	if (toupper(ans)=='Y')
	{
		Add_rec();
	}
	else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you :) :");
		getch();
		MainMenu();
	}
	else
	{
		printf("\n\t\tInvalid Input\n");
		goto D;
	}
}
 /* ********************************************VIEW RECORD*************************************** */
 void func_list()
 {
 	int row;
 	system("cls");
 	Title();
 	FILE *ek;
 	ek=fopen("Record2.dat","r");
 	printf("\n\n\t\t\t!!!!!!!!!!!!!! List Patients Record !!!!!!!!!!!!!!!!!!!\n");
 	     gotoxy(1,15);
 	     printf("Full Name");
 	     gotoxy(20,15);
 	     printf("Gender");
 	     gotoxy(32,15);
 	     printf("Age");
 	     gotoxy(37,15);
 	     printf("Address");
 	     gotoxy(49,15);
		 printf("Contact No");
		 gotoxy(64,15);
		 printf("Email");
		 gotoxy(88,15);
		 printf("problem");
		 gotoxy(98,15);
		 printf("Prescribed Doctor\n");
		 printf("-------------------------------------------------------------------------------------");
		 row=17;
		 while(fscanf(ek, "%s %s %c %i %s %s %s %s %s\n",p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.problem))  	
         {
         	gotoxy(1,row);
         	printf("%s %s",p.First_Name, p.Last_Name);
         	gotoxy(20,row);
         	printf("%c",p.Gender);
         	gotoxy(32,row);
         	printf("%i",p.age);
         	gotoxy(37,row);
         	printf("%s",p.Address);
         	gotoxy(49,row);
         	printf("%s",p.Contact_no);
         	gotoxy(64,row);
         	printf("%S",p.Email);
         	gotoxy(88,row);
         	printf("%s",p.problem);
         	gotoxy(98,row);
         	printf("%s",p.Doctor);
         	row++;
		 }
		 fclose(ek);
		 getch();
		 MainMenu();
}
void Search_rec(void)
{
	char name[20];
	system("cls");
	Title();//call Title function
	FILE *ek;
	ek=fopen("Record2.dat","r");
	printf("\n\n\t\t!!!!!!!!!!!!!!! Search Patient Record !!!!!!!!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("\n Enter patient Name to be viewed:");
	scanf("%s",name);
	fflush(stdin);
	name[0]=toupper(name[0]);
	while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", p.First_Name,p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.problem))
 {
 	    if(strcmp(p.First_Name,name)==0)
 	    {
 	     gotoxy(1,15);
 	     printf("Full Name");
 	     gotoxy(25,15);
 	     printf("Gender");
 	     gotoxy(32,15);
 	     printf("Age");
 	     gotoxy(37,15);
 	     printf("Address");
 	     gotoxy(52,15);
		 printf("Contact No");
		 gotoxy(64,15);
		 printf("Email");
		 gotoxy(80,15);
		 printf("problem");
		 gotoxy(95,15);
		 printf("Prescribed Doctor\n");
		 printf("---------------------------------------------------------------------------------------------------------------------------------------------");
		 gotoxy(1,18);
		 printf("%s %s",p.First_Name, p.Last_Name);
         gotoxy(20,18);
         printf("%c",p.Gender);
         gotoxy(32,18);
         printf("%i",p.age);
         gotoxy(37,18);
         printf("%s",p.Address);
         gotoxy(52,18);
         printf("%s",p.Contact_no);
         gotoxy(64,18);
         printf("%S",p.Email);
         gotoxy(80,18);
         printf("%s",p.problem);
         gotoxy(95,18);
         printf("%s",p.Doctor);
         printf("\n");
         break;
	    }
 	}
 	if(strcmp(p.First_Name,name)!=0)
 	{
 		gotoxy(5,10);
 		printf("Record not found!");
 		getch();
	}
	fclose(ek);
	L:
	getch();
    printf("\n\n\t\t\tDo you want to view more[Y/N]??");
	scanf("%c",&ans);
	if(toupper(ans)=='Y')
	{
		Search_rec();
	}
	else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you :) :)");
		getch();
		MainMenu();
	}
	else
	{
		printf("\n\tInvalid Input.\n");
		goto L;
	}
}
void Edit_rec(void)
{
	FILE *ek, *ft;
	int i,b, valid=0;
	char ch;
	char name[20];
	system("cls");
	Title();
	ft=fopen("temp2.dat","w+");
	ek=fopen("Record2.dat","r");
	if(ek==NULL)
	{
		printf("\n\t Can not open file!! ");
		getch();
		MainMenu();
	}
	printf("\n\n\t\t!!!!!!!!!!!!!!!!!!!!!!!! Edit Patient Record  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	gotoxy(12,13);
	printf("Enter the First Name of the Patient : ");
	scanf("%s", name);
	fflush(stdin);
	name[0]=toupper(name[0]);
	gotoxy(12,15);
	if(ft==NULL)
	{
		printf("\n Can not open file");
		getch();
		MainMenu();
	}
	while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.problem))		
    {
    	if(strcmp(p.First_Name, name)==0)
    	{
    		valid=1;
    		gotoxy(25,17);
    		printf("*** Existing Record ***");
    		gotoxy(10,19);
    		printf("%s \t%s \t%c \t%i \t%s \t%s \t%s \t%s \t%s\n",p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.problem);
		    gotoxy(12,22);
		    printf("Enter New First_Name: ");
		    scanf("%s",p.Last_Name);
		    gotoxy(12,24);
		    printf("Enter Last_Name: ");
		    scanf("%s",p.Last_Name);
		    gotoxy(12,26);
		    printf("Enter Gender: ");
		    scanf("%c",p.Gender);
		    p.Gender=toupper(p.Gender);
		    gotoxy(12,28);
		    printf("Enter Age: ");
		    scanf("%i",p.age);
		    gotoxy(12,30);
		    printf("Enter Address: ");
		    scanf("%s",p.Address);
		    p.Address[0]=toupper(p.Address[0]);
		    gotoxy(12,32);
		    printf("Enter Contact_no: ");
		    scanf("%s",p.Contact_no);
		    gotoxy(12,34);
		    printf("Enter New Email: ");
		    scanf("%s",p.Email);
		    gotoxy(12,36);
		    printf("Enter Problem: ");
		    scanf("%s",p.problem);
		    p.problem[0]=toupper(p.problem[0]);
		    gotoxy(12,38);
		    printf("Enter Doctor: ");
		    scanf("%s",p.Doctor);
		    p.Doctor[0]=toupper(p.Doctor[0]);
		    printf("\nPress U charecter for the Updating operation :");
		    ch=getch();
		    if(ch=='u' || ch=='U')
		    {
		    	fprintf(ft, "%s %s %c %i %s %s %s %s %s\n",p.First_Name,p.Last_Name,p.Gender,p.age,p.Contact_no,p.Email,p.problem);
		    	printf("\n\n\t\t\tPatient record updated successfully... ");
			}
	    }
	    else
	    {
	    	fprintf(ft, "%s %s %c %i %s %s %s %s %s\n",p.First_Name,p.Last_Name,p.Gender,p.age,p.Contact_no,p.Email,p.problem);
	    }
	}
	if(!valid)
	{
		printf("\n\t\tNO RECORD FOUND...");
	}
	fclose(ft);
	fclose(ek);
	remove("Record2.dat");
	rename("temp2.dat","Record2.dat");
	getch();
	MainMenu();
}
void Dlt_rec()
{
	char name[20];
	int found=0;
	system("cls");
	Title();//call Title function
	FILE *ek, *ft;
	ft=fopen("temp_file2.dat","w+");
	ek=fopen("Record2.dat","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!!  Delete Patient Record  !!!!!!!!!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("\n Enter Patient Name To Delete: ");
	fflush(stdin);
	gets(name);
	name[0]=toupper(name[0]);
	while(fscanf(ek, "%s %s %c %i %s %s %s %s %s\n",p.First_Name,p.Last_Name,p.Gender,p.age,p.Contact_no,p.Email,p.problem))
	{
	
	 	if (strcmp(p.First_Name,name)!=0)
	 	fprintf(ft, "%s %s %c %i %s %s %s %s %s\n",p.First_Name,p.Last_Name,p.Gender,p.age,p.Contact_no,p.Email,p.problem);
	 	else
	   {
	 			printf("%s %s %c %i %s %s %s %s %s\n",p.First_Name,p.Last_Name,p.Gender,p.age,p.Contact_no,p.Email,p.problem);
	 			found=1;
	    }
    }//while loop ends
     if(found==0)
   {
	 	printf("\n\n\t\t\t Record not found...");
	 	getch();
	 	MainMenu();
	}
	 else
	{
	 	fclose(ek);
	 	fclose(ft);
	 	remove("Record2.dat");
	 	rename("temp_file2.dat","Record2.dat");
	 	printf("\n\n\t\t\t Record deleted successfully :) ");
	 	getch();
	 	
	}
}
	
	
	
		
		
	


	
	
    
	















