#include <stdio.h>
#include <string.h>

struct Flight
{
    char flight_no[50],from[50],to[50];

};
 void function(struct Flight f1)
{
   FILE *fp;
   fp = fopen("test1.txt", "a+");
   fputs(f1.flight_no, fp);fputs(" ", fp);
   fputs(f1.from, fp);fputs(" ", fp);
   fputs(f1.to, fp);fputs(" \n", fp);
   fclose(fp);
}

struct Flight retrieve(n)
{
    struct Flight f1;int i=1;
    FILE *fp;
    fp = fopen("test1.txt", "a+");
    while(n>0)
    {
        printf("\n    Flight record number:%d\n",i);
        fscanf(fp, "%s", f1.flight_no);
        fscanf(fp, "%s", f1.from);
        fscanf(fp, "%s/n", f1.to);
        printf("\nFilght number:%s",f1.flight_no);
        printf("\nFilght source: %s",f1.from);
        printf("\nFilght destination: %s\n",f1.to);
        n--;i++;
    }


    fclose(fp);
    return f1;
}


int main()
{
    int n,i=1;char c[10];

    printf("Do you want to add data to flight info [y/n]:");
    gets(c);
     if(strcmp(c,"y")==0)
     {
         printf("Number of flight regestration:");
         scanf("%d",&n);
         while(n>0)
            {
                struct Flight f;
                printf("           Record number: %d",i);
                printf("\nEnter the filght number like 4R888:");
                scanf("%s",&f.flight_no);
                printf("\nEnter the filght source:");
                scanf("%s",&f.from);
                printf("\nEnter the filght destination:");
                scanf("%s",&f.to);
                function(f);
                n--;i++;
            }

     }else
      printf("Gaand marao\n");


    printf("Do you want to retrieve flight info [y/n]:");
    gets(c);
    if(strcmp(c,"y")==0)
    {
        printf("\nHow many records you wants to retrieve(max 4):");
        scanf("%d",&n);
        struct Flight f;
        f=retrieve(n);



    }
    else
        printf("Gaand marao\n");

     return 0;
}
