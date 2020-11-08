#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Flight
{
    int id,date[3];
    char name[50],source[50],destination[50];
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


int main()
{
    int ch;
    while(1)
    {

        system("cls");
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
    return 0;
}


void add_data()
{
    FILE *fp;
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
    for(int i=0;i<3;i++)
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

        if(feof(fp))
        {
            break;
        }
        for(int i=0;i<3;i++)
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
printf("%s\t\t\t",t.destination);
for(int i=0;i<3;i++)
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
                printf("\n0-sun,1-mon,2-tue,3-wed,4-thur,5-fri,6-sat ");
                for(int i=0;i<3;i++)
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
            printf("%s\t\t",t.destination);
            for(int i=0;i<3;i++)
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
