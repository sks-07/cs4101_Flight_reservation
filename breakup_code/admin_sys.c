//Including all files needed to run admin_sys.c 
#include "imports.h"  
#ifndef _STRUCT_H
#include "structs.h"
#endif
#include <stdio.h>

#ifndef _COLOR_CHANGE
    #include "color_changer.c"
#endif


char fname[]="flight.txt";//Declaring the main File in which all filght information is stored.
//Declaring all the modules for admin system 
void add_data();// add new flight data to the main txt file
void update_data();// To update any old flight record 
void display_all();//To display all the flight records
void display_all_date_wise();//To display all the flight records on a given date in 2020
void del();// To delete any old flight record 
void search();//To search for any Flight record
int day_of_week(int d,int m,int y);//It provides the day of the week on an given date of 2020(like0-sun,2-mon,...so on)
char mygetch();//Alternative of getch() for linux system/windows(if conio.h is not included).

void book_tickets(char *f1, float distance_fare);//to book ticket for a current user
void reg();//For resgistration of new user
struct flags login();//this structure is used to detect admin and user login
void logo();//to print logo

/* some line of code will repeadtedly occur like clrscr() and logo() For clear screen and to print logo	
   and color_change(number) its is used to change the color of the output in console window
*/
int admin_sys()
{	
    clrscr();
    logo();
    int user; int selection_flag=0;//intialize selection_flag
    while(selection_flag==0)
    {
        printf("\n\n\t\t\t\tWelcome to MakeMyTrip\n");
        //mygetch();
    color_change(5);printf("\n\t\t\t\t1");color_change(3);printf(" : Admin");color_change(5);printf(" \t\t2");color_change(3);printf(" : User");
    color_change(7);
    printf("\n\n\t\t\t\tPlease Enter your choice: ");
    scanf("%d",&user);
    struct flags f;
    if(user==1)
    {
        f = login();//login() function is called
        if(f.adminf==1)//if admin flag is 1 then only you can acess admin commands/operations. 
        {
            int ch;
            while(1)
            {
		//Admin is given a variety of choices/actions.
                clrscr();color_change(4);
                printf("\t\t\tLogin as Admin\n\n");
                printf("==========================");color_change(2);printf("Flight info System");color_change(4);printf("===========================\n\n");
                color_change(3);
                printf("1. Add data\n\n");
                printf("2. Modify\n\n");
                printf("3. Display Date wise\n\n");
                printf("4. Display All\n\n");
                printf("5. Delete\n\n");
                printf("6. Search\n\n");
                printf("0. Exit\n\n");
                color_change(4);
                printf("=========================================================================\n\n");color_change(6);

                printf("\nPlease enter your Choice:");color_change(7);
                scanf("%d",&ch);//taking input from the admin 
		//switch cas e is defined on the basis of admin choice folowing cases will wbe executed.	
                switch(ch)
                {
                    case 1: add_data();//if choice is 1 then add_data() function is called
                    break;

                    case 2: update_data();//if choice is 2 then update_data() function is called
                    break;

                    case 3: display_all_date_wise();//if choice is 3 then display_all_date_wise() function is called
                    break;

                    case 4: display_all();//if choice is 4 then display_all() function is called
                    break;

                    case 5: del();//if choice is 1 then del() function is called
                    break;

                    case 6: search();//if choice is 1 then search() function is called
                    break;

                    case 0: exit(0);//if choice is 0 then the program will terminate

                }
                color_change(2);
                printf("\nPress Enter to continue.....");
                color_change(7);
                mygetch();
                selection_flag=1;
            }
        }
        else //if admin flag is not 1 then you cannot access admin commands/operations
        {
            color_change(4);
            printf("\nInvalid Choice..!!!");
            color_change(2);
            printf("\n\nPress Enter to continue....");
            color_change(7);
            mygetch();    
	    }

    }
    else if(user==2)//now if the user input choice 2 then you will redirect to user portal
    {   
            int choice, user_login_flag;
            //system("clear");
            clrscr();
            logo();
            color_change(5);
            printf("\n\n\t\t\t\t1:");color_change(3);printf(" Registration");color_change(5);printf("\t\t2:");color_change(3);printf(" Login");color_change(7);
            printf("\n\n\t\t\t\tEnter your choice: ");//asking for choices from user
            scanf("%d",&choice);
	    //if choice is 1 then user is redirected to registration portal	
            if(choice==1)
            {
                reg();//registration function is called
            }
            else
            {
                struct flags f2;
                f2=login();
                if(f2.userf==1)//if user flag is 1 then you can access to the users command/operations
                {
		    //Declaring and intailizing some variable	
                    char flight_name[30],date1[10];
                    float distance_fare = 2000;
                    int ch;
                    while(1)//the loop will run infintely until user wants to exit 
                {
                    clrscr();
                    logo();
                    color_change(4);
                    printf("=================================================================================================================");
                    color_change(2);
                    printf("\n\t\t\t\tMakeMyTrip Booking Zone");
                    color_change(4);
                    printf("\n=================================================================================================================");
                    color_change(5);
                    printf("\n\n\t\t\t\t1:");color_change(3);printf("Booking");color_change(5);printf("\t\t0");color_change(3);printf(":exit");color_change(7);
                    printf("\n\n\t\t\t\tPlease enter your Choice: ");//asking for a valid choice from the users
                    scanf("%d",&ch);
                    switch(ch)
                    {
                        case 1://if choice is 1 then following lines of code will be executed
                                color_change(2);
                                printf("\n\t\t\t\tWelcome to booking counter");
                                color_change(4);
                                printf("\n-----------------------------------------------------------------------------------------------------------------");
                                printf("\n\t\t*** Due to covid19 pandemic we have restricted flight ");
                                printf("\n\t\tSource     :(KOL-Kolkata,MUM-Mumbai,DEL-Delhi,BBS-Bhubaneswar)");
                                printf("\n\t\tDestination:(KOl,MUM,DEL,BBS,GOA)");
                                printf("\n-----------------------------------------------------------------------------------------------------------------");
                                color_change(7);
                                printf("\n\n\t\t\t\tPress Enter to proceed... ");//waiting for user to press enter
                                mygetch();
                                color_change(3);
                                printf("\n\t\t\t\tEnter the date to see available Flight");//asking to enter the date from the user
                                display_all_date_wise();// calling the dasplay date wisefunction to display aall flight on a given date
				color_change(7);
                                printf("\n\n\t\t\t\tPress Enter to proceed..");
                                mygetch();color_change(3);
                                printf("\n\n\t\t\tEnter date to confirm date (Format: dd-mm):\t\t");color_change(7);//confirm the date
                                scanf("%s",date1);color_change(3);
                                printf("\n\n\t\t\tEnter the flight name from above availabe flights:\t");color_change(7);//enter the flight name from all the available flight
                                scanf("%s",flight_name);
                                strcat(flight_name,date1);
                                strcat(flight_name,".txt");//joining the name og the flight name and date to create a separate file for every flight on a given date
                                book_tickets(flight_name, distance_fare);//calling the booking function
                        break;

                        case 0:exit(0);
                    
                    }
                    printf("\n\t\t\t\tPress Enter to continue.....");
                    mygetch();
                    selection_flag=1;

                
                }
                } 
                else
                {
                    color_change(4);
                    printf("\t\t\t\tInvalid user....");color_change(7);
                    printf("\n\n\t\t\t\tPress Enter to continue....");
	                mygetch();
                }
                
            
            }
        
        
    }
    };
    
    return 0;
}

/*
	    data is added to a text file using file pointer fp.
            file is open in mode "a"(Opens a text file for writing in appending mode.
             If it does not exist, then a new file is created. Here your program will 
             start appending content in the existing file content.) 
            with file open writing new flight information at the end of the file.
*/
void add_data()
{
    //declaring a file pointer which will run through the file
    FILE *fp;
    struct Flight f1;//declaring structure variable which will help to stored information in text file
    //opening a the file in appending mode which will write data and the end of the file	
    fp=fopen(fname,"a");color_change(3);
    //asking user to enter the flight information like id,source,destination,and day of operation of the flight	and stored everything in structure f1 
    printf("\nEnter ID:");color_change(7);
    scanf("%d",&f1.id);color_change(3);
    printf("\nEnter flight name/number :");color_change(7);
    scanf("%s",f1.name);color_change(3);
    printf("\nEnter Flight source:");color_change(7);
    scanf("%s",f1.source);color_change(3);
    printf("\nEnter Flight destination:");color_change(7);
    scanf("%s",f1.destination);color_change(7);
    printf("\nEnter the day of operation of the flight(1:mon,2:tue...so on)(max:3)");
    for(int i=0;i<3;i++)
        {color_change(3);
            printf("\nday of operation %d:",i+1);color_change(7);
            scanf("%d",&f1.date[i]);
        }
    fwrite(&f1,sizeof(f1),1,fp);//writing  the structure f1 to the file

    fclose(fp);//closing the file
}

int day_of_week(int d,int m,int y)
{
    /*	In  1990,  Michael  Keith  and  Tom  Craver  published  the  foregoing  expression  that  seeks  to  minimisethe number of keystrokes needed to 
	enter a self-contained function for converting a Gregorian date into anumerical day of the week.  
	It preserves neither y nor d, and returns 0 = Sunday, 1 = Monday, etc
    */
    // it is like direct formula to calculate the weekday from a given date		
    int weekday  = (d += m < 3 ? y-- : y - 2, 23*m/9 + d + 4 + y/4- y/100 + y/400)%7;
    return weekday;
}


//this function is used to display the flight records on a given date
/*          file is open in mode "r"(Reading mode)
            The file pointer will move through the entire file untill it reaches the EOF.
            at every iterartion we read a strurture from the file 
            and each strutured represent different flight information.
            and then we check that if date provided by user match with date of operation 
            of the flight then we display all such available filght on that specific date.
*/
void display_all_date_wise()
{
    int d,m,y=2020;//declaring day and month and intializing year =2020  
    color_change(3);
    //asking user to provide a date and ,month
    printf("\n\t\t\t\tEnter the date(dd):\t");color_change(7);
    scanf("%d",&d);color_change(3);
    printf("\n\t\t\t\tEnter the month(mm):\t");color_change(7);
    scanf("%d",&m);
    int n= day_of_week(d,m,y);//calling dayof the week function to know what is the day of the week on that date.

    //Declaring a file pointer	
    FILE *fp;
    struct Flight t;//declaring a flight structure which is used to read flight records from the text file

    fp=fopen(fname,"r");//opeining file in reading mode
    color_change(4);
    printf("\n\t\t\t========================================================\n\n");color_change(2);
    printf("\t\t\t\t\t All flights on %d-%d-%d\n\n",d,m,y);color_change(4);
    printf("\t\t\t========================================================\n\n");color_change(6);

    printf("\t\t\tID\t\tName\t\tSource\t\tDestination\n\n\n");color_change(3);
    //the llop will run untill it find the record on a given date and if we reach end of the file	
    while(1)
    {
        fread(&t,sizeof(t),1,fp);//reading one structure at every iteration
        if(feof(fp))
        {
            break;
        }
        for(int i=0;i<3;i++)
            {
		//if the date matches with date in flight records then print all such records
                if(t.date[i]==n)
                    {
                         printf("\t\t\t%d\t\t",t.id);
                         printf("%s\t\t",t.name);
                         printf("%s\t\t",t.source);
                         printf("%s\n\n",t.destination);
                    }

            }
    }color_change(4);
    printf("\t\t\t========================================================\n\n");color_change(7);

    fclose(fp);//closing the file
}


void display_all()
{
	/*
	    file is open in mode "r"(Reading mode)
            The file pointer will move through the entire file untill it reaches the EOF.
            at every iterartion we read a strurture from the file and displayings all information of the flight.
	*/
//Declaring a file pointer
FILE *fp;
struct Flight t;//declaring a flight structure which is used to read flight records from the text file

fp=fopen(fname,"r");//opeining file in reading mode
color_change(4);
printf("\n====================================================================================\n\n");color_change(2);
printf("\t\t All FLight Details\n\n");color_change(4);
printf("======================================================================================\n\n");color_change(6);

printf("ID\t\tName\t\tSource\t\tDestination\t\tDay of operation\n\n\n");color_change(3);

while(1)//the loop will run until we reach end of the file
{
fread(&t,sizeof(t),1,fp);// reading one structure variable at every iteration and storing its value in strurture variable t

if(feof(fp))// if we reach end of the file then go out of the loop
{
break;
}
//printing all the flight  records stored in t	
printf("%d\t\t",t.id);
printf("%s\t\t",t.name);
printf("%s\t\t",t.source);
printf("%s\t\t\t",t.destination);
for(int i=0;i<3;i++)
    printf("%d ",t.date[i]);
printf("\n\n");
}color_change(4);
printf("=======================================================================================\n\n");color_change(7);

fclose(fp);//closing the file
}


void update_data()//This function is used to update a particular flight record
{
	/*
	Main file is open in reading mode and a temperary file is open in 
            wirting mode.user is asked which Flight data you want to modify w.r.t flight id
            and that particular id is taken as input from the user.
            The file pointer will move through the entire file untill it reaches the EOF.
            and we maintain a variable "found" 
           *at every iterartion a condition is check i.e that flight id matches with id provided by the user
            if the condition is true then new information is asked from the user and then
            we write the strurture in the temperary file and found is equal to 1 ,otherwise if the conidtion is false we 
            simply write the strurture to the temperary file.

           *if found is equal to zero thendisplay the message that record with that id is not found 
           else again open main file in writing mode and temperary file in reading mode
           now copy everything from temperary and write it in main file.
           hence at the end we have updated main file;

	*/
   //Declaring two file pointer one for the main file and otther for the temporary file
    FILE *fp,*fp1;
    struct Flight t,t1;//declaring two structure valraible one for the main file and otther for the temporary file
    //maintaining some variable 	
    int id,found=0,count=0;
    char val[2];

    fp=fopen(fname,"r");//opening main file in reading mode 
    fp1=fopen("temp.txt","w");//opeining temporary file writing mode
    color_change(3);
    printf("\nEnter the Flight ID you want to Modify:");color_change(7);//asking user which flight record w.r.t to id he/she want to delete.
    scanf("%d",&id);

    while(1)//loop wil run until it reach end of the file
    {
        fread(&t,sizeof(t),1,fp);// At every iteration a flight record is read from the main file

        if(feof(fp))
        {
            break;//if it reach  end of the file then come out from the loop
        }
        if(t.id==id)//if the id provided by the user matches with the id in flight record
        {
		//make found =1 such that we know that we found the record
            found=1;color_change(3);
		//asking user to provide new information to upadte
            printf("\nEnter Fligth ID:");color_change(7);
            scanf("%d",&t.id);

            //fflush(stdin);
            color_change(3);
            printf("\nEnter flight name/number:");color_change(7);
            scanf("%s",t.name);color_change(3);
            printf("\nEnter Flight source:");color_change(7);
            scanf("%s",t.source);color_change(3);
            printf("\nEnter Flight Destination:");color_change(7);
            scanf("%s",t.destination);color_change(3);
            printf("\nDo yo want to change day of operation of flight [Y/N]:");//asking user whether they want to change day of opration of fligth or not.
            scanf("%s",val);color_change(7);
            if(strcmp(val,"Y")==0)//if yes then change the day of operation
            {color_change(6);
                printf("\n0-sun,1-mon,2-tue,3-wed,4-thur,5-fri,6-sat ");
                for(int i=0;i<3;i++)
                {color_change(3);
                    printf("\nEnter the flight opertaion day:");color_change(7);
                    scanf("%d",&t.date[i]);
                }
            }
            fwrite(&t,sizeof(t),1,fp1);//now write the strucutre variable in temporary file
        }
        else//if id is not matches with id in flight record then write that record to temporary file
        {
            fwrite(&t,sizeof(t),1,fp1);
        }
    }
	//close both the files
    fclose(fp);
    fclose(fp1);

    if(found==0)// if record doesnt found then print the message Sorry No Record Found
    {color_change(4);
    printf("Sorry No Record Found\n\n");color_change(7);
    }
    else
    {
    /* otherwise now again open main file in writing mode and temporary file in reading mode
       now copy everything from temperary and write it in main file.
       hence at the end we have updated main file;		
	   */    
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
    //close both the file
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
    /*      similar fashion like update_date function
            ask user which flight information he wants to delete from the file and taking coressponding id
            Main file is open in reading mode and a temperary file is open in 
            wirting mode.
            at every iteration write everything to the temperary file until we found the record then if found
            the matching id then found==1;(or do nothing)
            then close both the file
    */	
    FILE *fp,*fp1;//Declaring two file pointer one for the main file and otther for the temporary file
    struct Flight t,t1;//declaring two structure valraible one for the main file and otther for the temporary file
    int id,found=0,count=0;

    fp=fopen(fname,"r");//opening main file in reading mode
    fp1=fopen("temp.txt","w");//opeining file in writing mode
    color_change(3);
    printf("\nEnter the Flight ID you want to Delete:");//asking user which flight record w.r.t id he/she wants to delete.
    color_change(7);
    scanf("%d",&id);
    
    while(1)
    {
	 /* at every iteration write everything to the temperary file until we found the record then if found
            the matching id then found==1;(or do nothing)*/
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
    {color_change(4);
        printf("Sorry No Record Found\n\n");//if found = 0 then printing Sorry No Record Found
        color_change(7);
    }
    else
    {
	    /*otherwise if found is 0 then opein main file in writing mode and temp file in reading mode
	    and copy evry thing from temp file to main file
	    */
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
    }//close both the files
    fclose(fp);
    fclose(fp1);
}


void search()
{
	/* User is asked to input the Flight name he/she want to search.
           then file is open in reading mode and a variable found is maintain equal to zero
           then at every iteration if filght name and inputed flight name matches then 
           all information regarding the filght is displayed.
            and if found is equal to zero then a message is displayed that no record found.
	*/
   
    FILE *fp;//Declaring file pointer
    struct Flight t;//Declaring strucutre variable to read records from the file
    int found=0;
    char name[20];

    fp=fopen(fname,"r");//opeining file in reaading mode

    printf("\nEnter the Flight Name:");//asking flight record w.r.t to flight name to be searched
    scanf("%s",name);

    while(1)
    {
        fread(&t,sizeof(t),1,fp);//reading one flight record at every iteration

        if(feof(fp))
        {
            break;//if end of the file then come out of the loop
        }
        if(strcmp(name,t.name)==0)//if the flight name matches with filght name is record display all the information of that flight
        {
            color_change(4);
            printf("\n=========================================================================\n\n");
            color_change(2);
            printf("\t\t Flight Details of id :");color_change(3);printf("%d\n\n",t.id);color_change(4);
            printf("===========================================================================\n\n");
            color_change(6);

            printf("Name\tSource\tDestination\tDay of opertaion\n\n");color_change(3);

            printf("%s\t",t.name);
            printf("%s\t",t.source);
            printf("%s\t\t",t.destination);
            for(int i=0;i<3;i++)
                printf("%d ",t.date[i]);
            color_change(4);    
            printf("\n===========================================================================\n\n");color_change(7);
            found=1;
        }
    }
    if(found==0)
    {
        color_change(4);
    printf("\nSorry No Record Found");color_change(7);//if record is not found then print Sorry No Record Found
    }
    fclose(fp);//close the file
}


void reg()
  {
	/*
	User registration takes place. Once the user enters a username, it is checked with the existing database.
	If the username already exists, the user is asked to enter a new username. Once a unique username is input, 
	it is appended to the file, and the user inputs the password to complete the registration.
	*/
    FILE *fp;//Declaring file pointer
    struct flags f3;//Declaring strucutre flags to detect user and admin login
    struct web w;//Declaring structure variable which will help to stored information in text file
    char checker[30]; char pass[30]; //Declaring character variables to input username and password
    int valid_username=1; //Declaring integer variable to check for uniqueness of username
    int n;
    //opening a the file in appending mode which will write data and the end of the file	
    fp=fopen("Web_user.txt","a+");
    color_change(2);
	
    printf("\n\n\t\t\t\tWELCOME TO REGISTRATION ZONE");
    color_change(4);
    printf("\n====================================================================================");
    color_change(3);
    
    printf("\n\n\t\t\t\tENTER USERNAME: ");
    scanf("%s",checker);//Input username from user
      //The while loop is used to check for uniqueness of the username
     while (!feof(fp))
        {
          fread(&w,sizeof(w),1,fp); //Reads data from file, using structure variable
          if(!strcmp(checker,w.name)) //Username input compared with available database
          {
            color_change(4); 
            printf("\n\n\t\t\t\tUSERNAME ALREDY EXISTS\n\n");color_change(7); 
            valid_username = 0; //Username not unique, hence code does not go to the next part
            break;
          }
        }
    fclose(fp);//Closes file
     //Once username is unique, the following if-section is executed
    if (valid_username==1)
        {
            strcpy(w.name,checker);//New username appended to the file
            fp=fopen("Web_user.txt","a+");//opening a the file in appending mode which will write data and the end of the file
            char pw[100]; //Character to input password from user
	    color_change(3);
            printf("\t\t\t\tENTER PASSWORD: ");color_change(7);
            scanf("%s",pw);// get a password
            strcpy(w.pass,pw);//Password appended to file
            //int l=strlen(w.pass);
            fwrite(&w,sizeof(w),1,fp);//writes data to fp 
            //fseek( fp, -l, SEEK_CUR );
            //fread(&w2,sizeof(w2),1,fp);
            color_change(6);
            /*
            printf("\n\n\t\t\t\tDo you wanna recheck you password?\n\n");
            printf("\t\t\t\t\t> PRESS 1 FOR YES\n\n\t\t\t\t\t> PRESS 2 FOR NO\n\n\t\t\t\t");color_change(7);
            scanf("%d",&n);
            if (n==1)
            {
                printf("\n\n\t\t\t\t");
                printf("%s",w.pass);//printf("%s",password);
            }
            */
            fclose(fp);

                
            color_change(6);    
            printf("\n\n\t\t\t\tYou are successfully registered");
    };
    printf("\n\n\t\t\t\tGoing back to Login Portal"); color_change(7);  
	 printf("\n====================================================================================");
        /*
        printf("\n\n\t\tTry login to your account??\n\n\t\t  ");
        
        AB:
        printf("> PRESS 1 FOR YES\n\n\t\t  > PRESS 2 FOR NO\n\n\t\t\t\t");
        scanf("%d",&n);
        printf("\e[1;1H\e[2J"); 
        switch(n)
          {
              case 1: printf("\e[1;1H\e[2J");
                    f3=login();
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
        */

  
     
	
  }




struct flags login()
    {
	/*
	User and Admin Login takes place. Username and password entered is compared with available data obtained
	from registration. Admins have default username and password
	*/
      FILE *fp;//Declaring file pointer
      char name[30],pass[30]; //Declares character variables to input username and password
      struct flags f,f1;//Declaring structure flags 
       //Declaring flags in structure to control admin and user login, depending on whether condition is met
       f.adminf=0;
       f.userf=0;
       
      //Declaring interger type variable to compare username and password of user with available database
      int checku=0;
      int checkp=0;
     //This loop runs as long as either user or admin is not logged in, as the condition in 'while' explicitly mentions
    do
    {
	clrscr();//clears screen
        logo();//shows logo
	 //Opens file in reading mode
        fp=fopen("Web_user.txt","r");
        color_change(2);
        printf("\n\n\t\t\t\tWELCOME TO LOGIN ZONE");
        color_change(4);
         printf("\n====================================================================================");
        color_change(3);
        printf("\n\n\t\t\t\tENTER USERNAME: ");color_change(7);
        scanf("%s",name);//Input username
        char pw[100]; // password string pointer
        color_change(3);
        printf("\t\t\t\tENTER PASSWORD: ");color_change(7);
        scanf("%s",pw); // get a password
        
        char admin_pass[]   ="root"; //default admin password
        char admin_u[]      ="admin"; //default admin username
	 //compares input admin username and admin password with default admin username and admin password   
        if(strcmp(admin_u,name)==0 && strcmp(admin_pass,pw)==0) 
          {
              f.adminf=1;color_change(2);
              printf("\n\t\t\tYOU HAVE LOGGED IN SUCCESSFULLY as admin\n");color_change(7);
          }
         
     while (!feof(fp))
        {
          struct web w1; //Declaring structure variable which will help to access information from text file created in reg()
	  int n;
          fread(&w1,sizeof(w1),1,fp); //Reads data from file, using structure variable
          checku=strcmp(name,w1.name);//Compares input username with available database
          checkp=strcmp(pw,w1.pass);//Compares input password with available database
          
          
        if(checku==0&&checkp==0)//When both input username and password match with available data
          {
            f.userf=1;clrscr();
            //printf("\e[1;1H\e[2J"); 
            color_change(6);
            printf("\n\n\n\t\t\tYOU HAVE LOGGED IN SUCCESSFULLY!!");
            printf("\n\n\n\t\t\t\tWELCOME, HAVE A NICE DAY\n");color_change(7);
            break;
          }
        else if(checku==0&&checkp!=0)//When username matches with available data, but password does not. User is directed back to login
          {
              color_change(4);
            printf("\n\n\n\t\t\tWRONG PASSWORD!! Not %s??",name);color_change(6);
            printf("\n\n\t\t\t\t  (Press '1' to re-login)");color_change(7);
            scanf("%d",&n);
	    printf("\n====================================================================================");
            break;
          }
        }
        //When input username does not match with available data, user is supposed to register
        if(checku!=0)
          {color_change(6);
           printf("\n\n\n\t\t\tYou are not a Registered User\n \t\t\t");color_change(7);
	    printf("\n====================================================================================");
           /*printf("\n\n\n\t\t\tDo you want to register?\n \t\t\t");
           printf("\n\n\n\tPress 1 to register, Press 2 to try login again, Press anything else to skip\n");
           scanf("%d",&n);
           if(n==1)
           reg();
           else if(n==2)
           login();
           else
           printf("\n\n\t\t\tThank you for visiting our website. Have a good day\n");*/
           break;
          }
	   fclose(fp);//file is closed

         } while (f.adminf==0 && f.userf==0); 	
      
        return f;//Returns the flag
        
        
      }

//to print logo.
void logo()
	{
        color_change(4);
	    printf("\n=====================================================================================================================================\n\n");
	    color_change(10);
        printf("\n   ___  ___      _       ___ ___     _____    _   ");color_change(6);printf("              ______                                                    ");                      
	    color_change(10);
        printf("\n   | |_|  |     | |      | |_| |    |_   _|  (_)  ");color_change(6);printf("              _\\ _~-\\___                                                    ");
	    color_change(10);
        printf("\n   | .  . | __ _| | _____| .  . |_   _| |_ __ _ _ __");color_change(6);printf("     =  = ==(____AA____D");
	    color_change(10);
        printf("\n   | |--| |/ _` | |/ / _ | |--| | | | | | '__| | '_ \\ ");color_change(6);printf("           \\_____\\___________________,-~~~~~~~`-.._");
	    color_change(10);
        printf("\n   | |  | | (_| |   <  __/ |  | | |_| | | |  | | |_) |  ");color_change(6);printf("           /     o O o o o o O O o o o o o o O o  |\\_");
	    color_change(10);
        printf("\n   \\ |  |_|__,_ |_| |\\_| |_ | |___, | |_/_|  |_/ . _/ ");color_change(6);printf("            `~-.__        ___..----..                  )");
	    color_change(10);
        printf("\n                                  __/ |        | |       ");color_change(6);printf("             `---~~\\___________/------------`````");
	    color_change(10);
        printf("\n                                 |___/         |_|       ");color_change(6);printf("               =  ===(_________D\n");
	    color_change(4);
        printf("\n\n=====================================================================================================================================\n\n");
        color_change(7);
	}
