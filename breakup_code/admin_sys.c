#include "imports.h"
#ifndef _STRUCT_H
#include "structs.h"
#endif
#include <stdio.h>

#ifndef _COLOR_CHANGE
    #include "color_changer.c"
#endif

char fname[]="flight.txt";
void add_data();
void update_data();
void display_all();
void display_all_date_wise();
void del();
void search();
int day_of_week(int d,int m,int y);
char mygetch();

void book_tickets(char *f1, float distance_fare);
void reg();
struct flags login();
void logo();


int admin_sys()
{
    clrscr();
    logo();
    int user; int selection_flag=0;
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
        f = login();
        if(f.adminf==1)
        {
            int ch;
            while(1)
            {

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
                color_change(2);
                printf("\nPress Enter to continue.....");
                color_change(7);
                mygetch();
                selection_flag=1;
            }
        }
        else 
        {
            color_change(4);
            printf("\nInvalid Choice..!!!");
            color_change(2);
            printf("\n\nPress Enter to continue....");
            color_change(7);
            mygetch();    
	    }

    }
    else if(user==2)
    {   
            int choice, user_login_flag;
            //system("clear");
            clrscr();
            logo();
            color_change(5);
            printf("\n\n\t\t\t\t1:");color_change(3);printf(" Registration");color_change(5);printf("\t\t2:");color_change(3);printf(" Login");color_change(7);
            printf("\n\n\t\t\t\tEnter your choice: ");
            scanf("%d",&choice);

            if(choice==1)
            {
                reg();
            }
            else
            {
                struct flags f2;
                f2=login();
                if(f2.userf==1)
                {
                    char flight_name[30],date1[10];
                    float distance_fare = 2000;
                    int ch;
                    while(1)
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
                    printf("\n\n\t\t\t\tPlease enter your Choice: ");
                    scanf("%d",&ch);
                    switch(ch)
                    {
                        case 1:
                                color_change(2);
                                printf("\n\t\t\t\tWelcome to booking counter");
                                color_change(4);
                                printf("\n-----------------------------------------------------------------------------------------------------------------");
                                printf("\n\t\t*** Due to covid19 pandemic we have restricted flight ");
                                printf("\n\t\tSource     :(KOL-Kolkata,MUM-Mumbai,DEL-Delhi,BBS-Bhubaneswar)");
                                printf("\n\t\tDestination:(KOl,MUM,DEL,BBS,GOA)");
                                printf("\n-----------------------------------------------------------------------------------------------------------------");
                                color_change(7);
                                printf("\n\n\t\t\t\tPress Enter to proceed... ");
                                mygetch();
                                color_change(3);
                                printf("\n\t\t\t\tEnter the date to see available Flight");
                                display_all_date_wise();color_change(7);
                                printf("\n\n\t\t\t\tPress Enter to proceed..");
                                mygetch();color_change(3);
                                printf("\n\n\t\t\tEnter date to confirm date (Format: dd-mm):\t\t");color_change(7);
                                scanf("%s",date1);color_change(3);
                                printf("\n\n\t\t\tEnter the flight name from above availabe flights:\t");color_change(7);
                                scanf("%s",flight_name);
                                strcat(flight_name,date1);
                                strcat(flight_name,".txt");
                                book_tickets(flight_name, distance_fare);
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

void add_data()
{
    FILE *fp;
    struct Flight f1;
    fp=fopen(fname,"a");color_change(3);
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
    int d,m,y=2020;color_change(3);
    printf("\n\t\t\t\tEnter the date(dd):\t");color_change(7);
    scanf("%d",&d);color_change(3);
    printf("\n\t\t\t\tEnter the month(mm):\t");color_change(7);
    scanf("%d",&m);
    int n= day_of_week(d,m,y);

    FILE *fp;
    struct Flight t;

    fp=fopen(fname,"r");
    color_change(4);
    printf("\n\t\t\t========================================================\n\n");color_change(2);
    printf("\t\t\t\t\t All flights on %d-%d-%d\n\n",d,m,y);color_change(4);
    printf("\t\t\t========================================================\n\n");color_change(6);

    printf("\t\t\tID\t\tName\t\tSource\t\tDestination\n\n\n");color_change(3);

    while(1)
    {
        fread(&t,sizeof(t),1,fp);
        if(feof(fp))
        {
            break;
        }
        for(int i=0;i<3;i++)
            {
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

    fclose(fp);
}


void display_all()
{
FILE *fp;
struct Flight t;

fp=fopen(fname,"r");
color_change(4);
printf("\n====================================================================================\n\n");color_change(2);
printf("\t\t All FLight Details\n\n");color_change(4);
printf("======================================================================================\n\n");color_change(6);

printf("ID\t\tName\t\tSource\t\tDestination\t\tDay of operation\n\n\n");color_change(3);

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
printf("%s\t\t\t",t.destination);
for(int i=0;i<3;i++)
    printf("%d ",t.date[i]);
printf("\n\n");
}color_change(4);
printf("=======================================================================================\n\n");color_change(7);

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
    color_change(3);
    printf("\nEnter the Flight ID you want to Modify:");color_change(7);
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
            found=1;color_change(3);
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
            printf("\nDo yo want to change day of operation of flight [Y/N]:");
            scanf("%s",val);color_change(7);
            if(strcmp(val,"Y")==0)
            {color_change(6);
                printf("\n0-sun,1-mon,2-tue,3-wed,4-thur,5-fri,6-sat ");
                for(int i=0;i<3;i++)
                {color_change(3);
                    printf("\nEnter the flight opertaion day:");color_change(7);
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
    {color_change(4);
    printf("Sorry No Record Found\n\n");color_change(7);
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
    color_change(3);
    printf("\nEnter the Flight ID you want to Delete:");color_change(7);
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
    {color_change(4);
        printf("Sorry No Record Found\n\n");
        color_change(7);
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
    scanf("%s",name);

    while(1)
    {
        fread(&t,sizeof(t),1,fp);

        if(feof(fp))
        {
            break;
        }
        if(strcmp(name,t.name)==0)
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
    printf("\nSorry No Record Found");color_change(7);
    }
    fclose(fp);
}


void reg()
  {
    FILE *fp;
    struct flags f3;
    struct web w,w2;int n;
    char c, checker[30]; int z=0, valid_username=1;char pass[30]; 
    fp=fopen("Web_user.txt","a+");
    color_change(2);
    printf("\n\n\t\t\t\tWELCOME TO REGISTRATION ZONE");
    color_change(4);
    printf("\n\t\t\t\t=============================");
    color_change(3);
    
    printf("\n\n\t\t\t\tENTER USERNAME: ");
    scanf("%s",checker);
      
     while (!feof(fp))
        {
          fread(&w,sizeof(w),1,fp);
          if(!strcmp(checker,w.name))
          {
            color_change(4); 
            printf("\n\n\t\t\t\tUSERNAME ALREDY EXISTS\n\n");color_change(7); 
            valid_username = 0;
            break;
          }
        }
    fclose(fp);

    if (valid_username==1)
        {
            strcpy(w.name,checker);
            fp=fopen("Web_user.txt","a+");
            char pw[100];color_change(3);
            printf("\t\t\t\tENTER PASSWORD: ");color_change(7);
            scanf("%s",pw);// get a password
            strcpy(w.pass,pw);
            //int l=strlen(w.pass);
            fwrite(&w,sizeof(w),1,fp);
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
      FILE *fp;
      FILE *fu;
      char c,name[30],pass[30]; int z=0;
      struct flags f,f1;
       f.adminf=0;
       f.userf=0;
   
      int checku=0;
      int checkp=0;
      fp=fopen("Web_user.txt","r");
      
    do
    {
        color_change(2);
        printf("\n\n\t\t\t\tWELCOME TO LOGIN ZONE");
        color_change(4);
        printf("\n\t\t\t\t======================");
        color_change(3);
        printf("\n\n\t\t\t\tENTER USERNAME: ");color_change(7);
        scanf("%s",name);
        char pw[100]; // password string pointer
        color_change(3);
        printf("\t\t\t\tENTER PASSWORD: ");color_change(7);
        scanf("%s",pw); // get a password
      
        char admin_pass[]   ="root";
        char admin_u[]      ="admin";
        if(strcmp(admin_u,name)==0 && strcmp(admin_pass,pw)==0)
          {
              f.adminf=1;color_change(2);
              printf("\n\t\t\tYOU HAVE LOGGED IN SUCCESSFULLY as admin\n");color_change(7);
          }
         
     while (!feof(fp))
        {
          struct web w1;int n;
          fread(&w1,sizeof(w1),1,fp);
          checku=strcmp(name,w1.name);
          checkp=strcmp(pw,w1.pass);
          
          
        if(checku==0&&checkp==0)
          {
            f.userf=1;clrscr();
            //printf("\e[1;1H\e[2J"); 
            color_change(6);
            printf("\n\n\n\t\t\tYOU HAVE LOGGED IN SUCCESSFULLY!!");
            printf("\n\n\n\t\t\t\tWELCOME, HAVE A NICE DAY\n");color_change(7);
            break;
          }
        else if(checku==0&&checkp!=0)
          {
              color_change(4);
            printf("\n\n\n\t\t\tWRONG PASSWORD!! Not %s??",name);color_change(6);
            printf("\n\n\t\t\t\t  (Press '1' to re-login)");color_change(7);
            scanf("%d",&n);
            break;
          }
        }
     
        if(checku!=0)
          {color_change(6);
           printf("\n\n\n\t\t\tYou are not a Registered User\n \t\t\t");color_change(7);
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
         } while (f.adminf==0 && f.userf==0); 	
      
        return f;
        
        
      }


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
