#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Flight
{
    int id;
    char flight_name[50],source[50],destination[50];
};

void add_data();
void update_data();
void display();
void display_all();
char mygetch();
char fname[]="flight_DB.txt";

int main()
{
    int ch;
    while(1)
    {
        system("clear"); //clrscr();

        printf("==================Flight info System=============\n\n");

        printf("1. Add data\n\n");
        printf("2. Modify\n\n");
        printf("3. Display\n\n");
        printf("4. Display All\n\n");
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

            case 3: display();
            break;

            case 4: display_all();
            break;

            case 0: exit(0);

        }

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
    scanf("%s",f1.flight_name);
    printf("\nEnter Flight source:");
    scanf("%s",&f1.source);
    printf("\nEnter Flight destination:");
    scanf("%s",&f1.destination);
    fwrite(&f1,sizeof(f1),1,fp);

    fclose(fp);
}

void update_data()
{
    FILE *fp,*fp1;
    struct Flight t,t1;
    int id,found=0,count=0;

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
    scanf("%s",t.flight_name);
    printf("\nEnter Flight source:");
    scanf("%s",&t.source);
    printf("\nEnter Flight Destination:");
    scanf("%s",&t.destination);
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


void display()
{
    FILE *fp;
    struct Flight t;
    int id,found=0;

    fp=fopen(fname,"r");

    printf("\nEnter the Flight ID:");
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
    printf("\n========================================================\n\n");
    printf("\t\t Flight Details of %d\n\n",t.id);
    printf("========================================================\n\n");

    printf("Name\t\tSource\t\tDestination\n\n\n");

    printf("%s\t\t",t.flight_name);
    printf("%s\t\t",t.source);
    printf("%s\t\n\n",t.destination);

    printf("========================================================\n\n");
    }
    }
    if(found==0)
    {
    printf("\nSorry No Record Found");
    }
    fclose(fp);
}


void display_all()
{
FILE *fp;
struct Flight t;

fp=fopen(fname,"r");

printf("\n========================================================\n\n");
printf("\t\t All FLight Details\n\n");
printf("========================================================\n\n");

printf("ID\t\tName\t\tSource\t\tDestination\n\n\n");

while(1)
{
fread(&t,sizeof(t),1,fp);

if(feof(fp))
{
break;
}
printf("%d\t\t",t.id);
printf("%s\t\t",t.flight_name);
printf("%s\t\t",t.source);
printf("%s\n\n",t.destination);
}
printf("========================================================\n\n");

fclose(fp);
}

char mygetch()
{
char val;
char rel;

scanf("%c",&val);
scanf("%c",&rel);
return (val);
}
