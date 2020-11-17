#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<math.h>
#include<time.h>
#include<termios.h>
#include <unistd.h> 




struct Flight
{
    int id,date[3];
    char name[50],source[50],destination[50];
};


struct passenger_info	//Anmol Kumar
{
	int pass_serial;
	char pass_fname[50];
	char pass_lname[50];
	char pass_gender[10];
	char pass_StudentID[50];
	char pass_agecat[50];
	int pass_age;
	float pass_fare;
};

struct web
{
char name[30],pass[30];
}; 



char fname[]="flight.txt";
void add_data();
void update_data();
void display_all();
void display_all_date_wise();
void del();
void search();
int day_of_week(int d,int m,int y);
char mygetch();


float fare_calculator(int age, float distance_fare, int c);
int seat_info(char *flight_id);
int disp_ticket(int n, float total_fare, int seat);
void ticket_info(char *flight_id, int n, int pnr, float total_fare, int seat);
int ticket_pnr();
float collect_info(int n, float distance_fare, int seat);
void book_tickets(char *f1, float distance_fare);


int login(void);
void reg(void);


int main()
{
    int user;int flag;
    printf("=================================================================================================================");
    printf("\n\t\t\t\t\tMakeMyTrip");
    printf("\n=================================================================================================================");
    
    printf("\n 1 : Admin \t\t2 : User");
    printf("\n\nPlease Enter your choice:");
    scanf("%d",&user);
    if(user==1)
    {
        flag= login();
        if(flag==1)
        {
        int ch;
         while(1)
        {

           // system("cls");
            printf("\e[1;1H\e[2J");
            printf("\t\t\tLogin as Admin\n\n");
            printf("==================Flight info System=============\n\n");

            printf("1. Add data\n\n");
            printf("2. Modify\n\n");
            printf("3. Display Date wise\n\n");
            printf("4. Display All\n\n");
            printf("5. Delete\n\n");
            printf("6. Search\n\n");
            printf("0. Exit\n\n");

            printf("========================================================\n\n");

            printf("\nPlease enter your Choice:");
            scanf("%d",&ch);

            switch(ch)
            {
                case 1: add_data();
                break;

                case 2: update_data();
                break;

                case 3: display_all_date_wise();
                break;

                case 4: display_all();
                break;

                case 5: del();
                break;

                case 6: search();
                break;

                case 0: exit(0);

            }
            printf("\nPress Enter to continue.....");
            mygetch();
        }
        }
    }
    else
    {   
        int choice;
        A:
        printf("\n\n1: Registration\t\t2: Login");
        printf("\n\nEnter your choice:");
        scanf("%d",&choice);

        if(choice==1)
        {
            reg();
        }
        else
        {
            int c=login();
            char flight_name[30],date1[10];
            float distance_fare = 2000;
            int ch;
            while(1)
            {
                //system("cls");
                printf("\e[1;1H\e[2J");
                printf("=================================================================================================================");
                printf("\n\t\t\t\t\tMakeMyTrip");
                printf("\n=================================================================================================================");
                printf("\n\n1:Booking\t\t0:exit");
                printf("\n\nPlease enter your Choice:");
                scanf("%d",&ch);
                switch(ch)
                {
                    case 1:printf("\n\t\t\t\tWelcome to booking counter");
                            printf("\n-----------------------------------------------------------------------------------------------------------------");
                            printf("\n\n*** Due to covid19 pandemic we have restricted flight ");
                            printf("\n source :(KOL-Kolkata,MUM-Mumbai,DEL-Delhi,BBS-Bhubaneswar)");
                            printf("\n Destination:(KOl,MUM,DEL,BBS,GOA)");
                            printf("\n-----------------------------------------------------------------------------------------------------------------");
                            printf("\n\nPress Enter to proceed...");
                            mygetch();
                            printf("\nEnter the date to see available Flight..");
                            display_all_date_wise();
                            printf("\n\npress Enter to proceed..");
                            mygetch();
                            printf("\n\nEnter date to confirm dd-mm format:");
                            scanf("%s",date1);
                            printf("\n\nEnter the flight name from above availabe flights:");
                            scanf("%s",flight_name);
                            strcat(flight_name,date1);
                            strcat(flight_name,".txt");
                            book_tickets(flight_name, distance_fare);
                    break;

                    case 0:exit(0);
                
                }
                printf("\nPress Enter to continue.....");
                mygetch();

            
             }
        }
        goto A;
    }
    
    return 0;
}

void add_data()
{
    FILE *fp;int i=0;
    struct Flight f1;
    fp=fopen(fname,"a");
    printf("\nEnter ID:");
    scanf("%d",&f1.id);
    printf("\nEnter flight name/number :");
    scanf("%s",f1.name);
    printf("\nEnter Flight source:");
    scanf("%s",&f1.source);
    printf("\nEnter Flight destination:");
    scanf("%s",&f1.destination);
    printf("\nEnter the day of operation of the flight(1:mon,2:tue...so on)(max:3)");
    for(i;i<3;i++)
        {
            printf("\nday of operation %d:",i+1);
            scanf("%d",&f1.date[i]);
        }
    fwrite(&f1,sizeof(f1),1,fp);

    fclose(fp);
}

int day_of_week(int d,int m,int y)
{
   //  d    = 6   ; //Day     1-31
    // m    = 11    ; //Month   1-12`
    // y    = 2020 ; //Year    2013`
    int weekday  = (d += m < 3 ? y-- : y - 2, 23*m/9 + d + 4 + y/4- y/100 + y/400)%7;
    return weekday;
}


void display_all_date_wise()
{
    int d,m,y=2020;
    printf("\nEnter the date(dd):");
    scanf("%d",&d);
    printf("\nEnter the month(mm):");
    scanf("%d",&m);
    int n= day_of_week(d,m,y);

    FILE *fp;
    struct Flight t;

    fp=fopen(fname,"r");

    printf("\n========================================================\n\n");
    printf("\t\t All flights on %d-%d-%d\n\n",d,m,y);
    printf("========================================================\n\n");

    printf("ID\t\tName\t\tSource\t\tDestination\n\n\n");

    while(1)
    {
        fread(&t,sizeof(t),1,fp);
		int i=0;
        if(feof(fp))
        {
            break;
        }
        for(i;i<3;i++)
            {
                if(t.date[i]==n)
                    {
                         printf("%d\t\t",t.id);
                         printf("%s\t\t",t.name);
                         printf("%s\t\t",t.source);
                         printf("%s\n\n",t.destination);
                    }

            }
    }
    printf("========================================================\n\n");

    fclose(fp);
}


void display_all()
{
FILE *fp;
struct Flight t;

fp=fopen(fname,"r");

printf("\n====================================================================================\n\n");
printf("\t\t All FLight Details\n\n");
printf("======================================================================================\n\n");

printf("ID\t\tName\t\tSource\t\tDestination\t\tDay of operation\n\n\n");

while(1)
{
fread(&t,sizeof(t),1,fp);

if(feof(fp))
{
break;
}
printf("%d\t\t",t.id);
printf("%s\t\t",t.name);
printf("%s\t\t",t.source);
printf("%s\t\t\t",t.destination);int i=0;
for(i;i<3;i++)
    printf("%d ",t.date[i]);
printf("\n\n");
}
printf("=======================================================================================\n\n");

fclose(fp);
}


void update_data()
{
    FILE *fp,*fp1;
    struct Flight t,t1;
    int id,found=0,count=0;
    char val[2];

    fp=fopen(fname,"r");
    fp1=fopen("temp.txt","w");

    printf("\nEnter the Flight ID you want to Modify:");
    scanf("%d",&id);

    while(1)
    {
        fread(&t,sizeof(t),1,fp);

        if(feof(fp))
        {
            break;
        }
        if(t.id==id)
        {
            found=1;
            printf("\nEnter Fligth ID:");
            scanf("%d",&t.id);

            fflush(stdin);
            printf("\nEnter flight name/number:");
            scanf("%s",t.name);
            printf("\nEnter Flight source:");
            scanf("%s",&t.source);
            printf("\nEnter Flight Destination:");
            scanf("%s",&t.destination);
            printf("\nDo yo want to change day of operation of flight [Y/N]:");
            scanf("%s",&val);
            if(strcmp(val,"Y")==0)
            {
                printf("\n0-sun,1-mon,2-tue,3-wed,4-thur,5-fri,6-sat ");int i=0;
                for(i;i<3;i++)
                {
                    printf("\nEnter the flight opertaion day:");
                    scanf("%d",&t.date[i]);
                }
            }
            fwrite(&t,sizeof(t),1,fp1);
        }
        else
        {
            fwrite(&t,sizeof(t),1,fp1);
        }
    }
    fclose(fp);
    fclose(fp1);

    if(found==0)
    {
    printf("Sorry No Record Found\n\n");
    }
    else
    {
    fp=fopen(fname,"w");
    fp1=fopen("temp.txt","r");

    while(1)
    {
    fread(&t,sizeof(t),1,fp1);

    if(feof(fp1))
    {
    break;
    }
    fwrite(&t,sizeof(t),1,fp);
    }

    }
    fclose(fp);
    fclose(fp1);
}

char mygetch()
{
char val;
char rel;

scanf("%c",&val);
scanf("%c",&rel);
return (val);
}

void del()
{
    FILE *fp,*fp1;
    struct Flight t,t1;
    int id,found=0,count=0;

    fp=fopen(fname,"r");
    fp1=fopen("temp.txt","w");

    printf("\nEnter the Flight ID you want to Delete:");
    scanf("%d",&id);

    while(1)
    {
        fread(&t,sizeof(t),1,fp);
        if(feof(fp))
        {
                break;
        }
        if(t.id==id)
        {
            found=1;
        }
        else
        {
            fwrite(&t,sizeof(t),1,fp1);
        }
    }

    fclose(fp);
    fclose(fp1);

    if(found==0)
    {
        printf("Sorry No Record Found\n\n");
    }
    else
    {
        fp=fopen(fname,"w");
        fp1=fopen("temp.txt","r");

        while(1)
        {
            fread(&t,sizeof(t),1,fp1);
            if(feof(fp1))
            {
                break;
            }
            fwrite(&t,sizeof(t),1,fp);
        }
    }
    fclose(fp);
    fclose(fp1);
}


void search()
{
    FILE *fp;
    struct Flight t;
    int found=0;
    char name[20];

    fp=fopen(fname,"r");

    printf("\nEnter the Flight Name:");
    scanf("%s",&name);

    while(1)
    {
        fread(&t,sizeof(t),1,fp);

        if(feof(fp))
        {
            break;
        }
        if(strcmp(name,t.name)==0)
        {
            printf("\n=========================================================================\n\n");
            printf("\t\t Flight Details of id :%d\n\n",t.id);
            printf("===========================================================================\n\n");

            printf("Name\tSource\tDestination\tDay of opertaion\n\n");

            printf("%s\t",t.name);
            printf("%s\t",t.source);
            printf("%s\t\t",t.destination);int i=0;
            for(i;i<3;i++)
            printf("%d ",t.date[i]);

            printf("\n\n");

            printf("===========================================================================\n\n");
            found=1;
        }
    }
    if(found==0)
    {
    printf("\nSorry No Record Found");
    }
    fclose(fp);
}



struct passenger_info passenger[5];

//Function to calculate fare based on age and the distance dependent fare of the flight.
//The variable c takes the values 0 and 1, corresponding to whether student concession is applicable or not
//Total fare consists of four parts-base fare, flight's distance dependent fare, student concession and taxes (10%)
//Base fare is calculated based on age of the passenger
float fare_calculator(int age, float distance_fare, int c)	//Harshit Kumar 
{
	float base, student_concession, flight_fare, booking_charges, total;
	if(age<3)
	{
		base = 200;	//Base fare for infant
	}
	else if(age>=3 && age <=5)
	{
		base = 600;	//Base fare for child
	}
	else
	{
		base = 1000;	//Base fare for adult
	}
	student_concession = -400.0;	//Student concession to be subtracted in case of a student passenger
	flight_fare = distance_fare;
	total = base + flight_fare + c*student_concession;	//Total fare without taxes
	total = total + 0.1*total;	//Total fare plus 10% taxes
	return total;
}

//Function to return the number of seats available for a given flight on a given date
//The file is named as Flight_numberDate.txt and is passed as a pointer type variable
int seat_info(char *flight_id)		//Anmol Kumar
{
	FILE *fp;
	fp = fopen(flight_id, "r");	//Opens the file to read its contents
	int n;
	if(fp == NULL)	//If the file does not exist, or in other words, no seat has been booked on that flight
	{
		fp = fopen(flight_id,"a");	//Opens the file to write on it
		n = 100;
		fprintf(fp,"Available seats: %d\n", n);	//Sets the number of available seats to n (100), which is the capacity of the flight
		fclose(fp);
	}
	else
	{
		fseek(fp,-5,SEEK_END);	//If the file opens, the cursor goes to that point at the end of the file where the number of available seats is written 
		fscanf(fp, "%d", &n);	//Scans the last integer and stores in the variable n
	}
	fclose(fp);
	return n;
}

//Function to display the ticket details on the terminal
//Displays PNR, name, gender, fare, Student ID and age category from the passenger_info type array
//Returns the PNR to be kept for admin records
int disp_ticket(int n, float total_fare, int seat)	//Anmol Kumar
{
	printf("\n\nYour ticket has been booked!\n\nHere are the details:\n\n");	
	int k = 1;
	int pnr = ticket_pnr();		//Calls the ticket_pnr function and stores the PNR in the interger type variable pnr
	printf("PNR: %d\n", pnr);
	printf("%-5s | %-20s | %-20s | %-7s | %-10s | %-3s | %-7s | %-7s\n","S.No.","First Name","Last Name","Gender","Student ID","Age","Fare","Category");
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	for(;k<=n;k++)	//Displaying the ticket details recursively
	{
		printf("%-5d | %-20s | %-20s | %-7s | %-10s | %-3d | %-6.2f | %-7s\n", passenger[k].pass_serial, passenger[k].pass_fname, passenger[k].pass_lname, passenger[k].pass_gender, passenger[k].pass_StudentID, passenger[k].pass_age, passenger[k].pass_fare, passenger[k].pass_agecat);
	
	}
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("Total Fare: %.2f", total_fare);
	return pnr;
}

//Function to write to the same file from which seat availability is extracted: Flight_numberDate.txt
void ticket_info(char *flight_id, int n, int pnr, float total_fare, int seat)		//Anmol Kumar
{
	FILE *fptr;
	fptr = fopen(flight_id,"a");	//Open the file to append passenger information
	
    fprintf(fptr,"\n\n");
	fprintf(fptr, "\n%-25s %5d","Number of Passengers:",n);
    fprintf(fptr, "\n%-25s %5d\n","PNR:",pnr);
	fprintf(fptr,"%-5s | %-20s | %-20s | %-7s | %-10s | %-3s | %-7s\n","S.No.","First Name","Last Name","Gender","Student ID","Age","Category");
	fprintf(fptr,"-----------------------------------------------------------------------------------------------------------------\n");
	int l = 1;
	for(;l<=n;l++)	//Writing to the file recursively
	{
		fprintf(fptr, "%-5d | %-20s | %-20s | %-7s | %-10s | %-3d | %-7s\n", passenger[l].pass_serial, passenger[l].pass_fname, passenger[l].pass_lname, passenger[l].pass_gender, passenger[l].pass_StudentID, passenger[l].pass_age, passenger[l].pass_agecat);
	}
	fprintf(fptr,"-----------------------------------------------------------------------------------------------------------------\n");
	fprintf(fptr, "\n%-25s %8.2f","Total Fare", total_fare);
	fprintf(fptr, "\n%-25s %5d","Available seats:", seat-n);		//Updating the number of available seats by writing at the end of file
    fclose(fptr);
}


//Function to generate a PNR for the ticket
int ticket_pnr()	//Harshit Kumar
{ 
    srand(time(0));	//Generates a random number by taking time as a seed value
    int pnr = (rand() % (999999 - 100000 + 1)) + 100000;	//Scaling the random number to a 6 digit integer
    return pnr;  
} 

//Function to collect passenger information from the user
//After a user has entered all the information, total fare is calculated and returned
//Input arguments are number of passengers n, the flight's distance dependent fare and number of available seats
float collect_info(int n, float distance_fare, int seat)	//Anmol Kumar
{
	float total_fare = 0.0;
	int c;
	
	int i;
	for(i=1;i<=n;i=i+1)
	{
		passenger[i].pass_serial = i;
		printf("\nPlease provide the following details for passenger no. %d\n", i);
		printf("\t 1. \t First Name\t:\t");
		scanf("%s",passenger[i].pass_fname);	//First Name
		printf("\t 2. \t Last Name\t:\t");
		scanf("%s",passenger[i].pass_lname);	//Last Name
		printf("\t 3. \t Gender\t\t:\t");
		scanf("%s",passenger[i].pass_gender);	//Gender
		printf("\t 4. \t Are you a student? [Enter 1 for YES, 0 for NO]\t:\t");
		scanf("%d", &c);
		if(c==1)
		{
			printf("\t \t Please provide a valid ID number\t\t:\t");	//If the passenger is a student (c=1), a student ID is asked and stored in the corresponding variable
			scanf("%s",passenger[i].pass_StudentID);
			printf("\t\t\t***Please carry this ID card with you during the journey.\n");
		}
		else
		{
			strcpy(passenger[i].pass_StudentID,"NA");	//If c=0, NA is stored in pass_StudentID
		}
		printf("\t 5. \t Age\t\t:\t");		//Age
		scanf("%d",&passenger[i].pass_age);
		if(passenger[i].pass_age < 3)	//Classification of passenger into infant, child and adult based on his/her age
		{
			strcpy(passenger[i].pass_agecat, "Infant");
		}
		else if(passenger[i].pass_age >= 3 && passenger[i].pass_age <= 5)
		{
			strcpy(passenger[i].pass_agecat, "Child");
		}
		else
		{
			strcpy(passenger[i].pass_agecat, "Adult");
		}
		
		passenger[i].pass_fare = fare_calculator(passenger[i].pass_age, distance_fare, c);	//Calculation of fare for a single passenger using fare_calculator function
		total_fare = total_fare + passenger[i].pass_fare;	//Total fare for all the passengers, gets added recursively
	}
	return total_fare;
}

//Function to book tickets
//It takes the input parameters the file name pointer corresponding to the flight number and date, and the flight's distance dependent fare 
void book_tickets(char *f1, float distance_fare)	//Harshit Kumar
{
	system("cls");
	printf("\n-----------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\tADD PASSENGER DETAILS");
	printf("\n-----------------------------------------------------------------------------------------------------------------\n");
	int n, i;
	int seat_num = seat_info(f1);	//Extracts the number of seats available on the flight on that date
	
	printf("\tAvailable Seats:\t\t %d\n", seat_num);
	printf("\tEnter the number of passengers (You can only book for upto 5 passengers):\t\t");
	scanf("%d",&n);		//Takes the number of passengers the user can add for the journey
	
	if(n>seat_num)
	{
		printf("\n\t\t\tSorry! No seats available");	//If the user tries to book more seats than there are available seats, this message would be displayed
	}
	else if(n>5)
	{
		printf("\n\t\tSorry. Your entered number of passengers exceeds the maximun number of passengers you can add. \n\t\tPlease try again.\n\n");	//Limiting the maximum number of passengers to add to 5
		book_tickets(f1,distance_fare);			//getting back to booking once again
	
	}
	else
	{
		float total_fare = collect_info(n, distance_fare, seat_num);	//Collect passenger information and return the total fare
		int pnr = disp_ticket(n, total_fare, seat_num);		//Display the ticket to the user
		ticket_info(f1,n,pnr,total_fare, seat_num);	//Update the flight file with the added passengers and available seats
	}
}

void reg()
  {
    FILE *fp;
    struct web w,w2;int n;
    char c, checker[30]; int z=0;char pass[30]; 
    fp=fopen("Web_user.txt","a+");
    printf("\n\n\t\t\t\tWELCOME TO REGISTER ZONE");
    printf("\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^");
    
    printf("\n\n\t\t\t\t  ENTER USERNAME: ");
    scanf("%s",checker);
      
     while (!feof(fp))
        {
          fread(&w,sizeof(w),1,fp);
          if(!strcmp(checker,w.name))
            {
            printf("\n\n\t\t\tUSERNAME ALREDY EXISTS");
            printf("\e[1;1H\e[2J"); //clrscr();
            reg();
            
            }
          else
          {
            strcpy(w.name,checker);
            break;
          }
        }
        
      
    
    char *password; // password string pointer
    password = getpass("\n\n\t\t\t\tEnter password : "); // get a password
    strcpy(w.pass,password);
    fwrite(&w,sizeof(w),1,fp);
    fread(&w2,sizeof(w2),1,fp);
    printf("\n\n\t\t\tDo you wanna recheck you password?\n\n\t\t\t\t ");
    printf("> PRESS 1 FOR YES\n\n\t\t\t\t  > PRESS 2 FOR NO\n\n\t\t\t\t");
     scanf("%d",&n);
    if (n==1)
    {
    printf("\n\n\t\t\t\t");
    printf("%s",w2.pass);//printf("%s",password);
    }
    
    
    
       
        
        printf("\n\n\t\tYou are successfully registered");
        printf("\n\n\t\tTry login to your account??\n\n\t\t  ");
        AB:
        printf("> PRESS 1 FOR YES\n\n\t\t  > PRESS 2 FOR NO\n\n\t\t\t\t");
        scanf("%d",&n);
        printf("\e[1;1H\e[2J"); 
        switch(n)
          {
              case 1: printf("\e[1;1H\e[2J");
                    login();
                    break;
              case 2: printf("\e[1;1H\e[2J"); 
                    printf("\n\n\n\t\tTHANK YOU FOR REGISTERING\n");
                    break;
              default: printf("\n\n\t\t\t\tNO MATCH FOUND");
        	printf("\n\n\t\t\tPress Enter to re-Enter the choice\n\n\t\t");
        	if(gets()==13)
        	printf("\e[1;1H\e[2J");
        	goto AB;
          }

  
     
	
  }



int login()
    {
      FILE *fp;
      FILE *fu;
      char c,name[30],pass[30]; int z=0;
      int admin=0;int d;
   
      int checku=0;
      int checkp=0;
      fp=fopen("Web_user.txt","r");
      
      printf("\n\n\t\t\t\tWELCOME TO LOGIN ZONE");
      printf("\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^");
      printf("\n\n\t\t\t\t  ENTER USERNAME: ");
       scanf("%s",name);
       char *pw; // password string pointer
    pw = getpass("\n\n\t\t\t\tEnter password : "); // get a password
      
        
         
     while (!feof(fp))
        {
          struct web w1;int n;
          fread(&w1,sizeof(w1),1,fp);
          checku=strcmp(name,w1.name);
          checkp=strcmp(pw,w1.pass);
          char admin_pass[]="root";
          char admin_u[]="admin";
          if(strcmp(admin_u,w1.name)==0 && strcmp(admin_pass,w1.pass)==0)
          {
              admin=1;
              printf("\nYOU HAVE LOGGED IN SUCCESSFULLY as admin\n");
          }
          if(checku==0&&checkp==0)
          {
            printf("\e[1;1H\e[2J"); 
            printf("\n\n\n\t\t\tYOU HAVE LOGGED IN SUCCESSFULLY!!");
            printf("\n\n\n\t\t\t\tWELCOME, HAVE A NICE DAY\n");
            break;
          }
       else if(checku==0&&checkp!=0)
          {
            printf("\n\n\n\t\t\tWRONG PASSWORD!! Not %s??",name);
            printf("\n\n\t\t\t\t  (Press '1' to re-login)");
            scanf("%d",&n);
          if(n==1)
            d=login();
          else
          break;
          }
    /*  else if(checku!=0)
          {
           printf("\n\n\n\t\t\tYou are not a Registered User\n \t\t\t");
           printf("\n\n\n\t\t\tDo you want to register?\n \t\t\t");
           printf("\n\n\n\tPress 1 to register, Press 2 to try login again, Press anything else to skip\n");
           scanf("%d",&n);
           if(n==1)
           reg();
           else if(n==2)
           login();
           else
           printf("\n\n\t\t\tThank you for visiting our website. Have a good day\n");
           break;
          } */
         } 	
      
        return admin;
        
        
      }