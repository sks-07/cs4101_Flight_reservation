#include <stdio.h>
#include <string.h>

struct Flight
{
    char flight_no[50];
};

int main()
{
    char name[50],c[50];
    FILE *fp;int l=1,flag=1;
    fp = fopen("test.txt", "a+");

    printf("Enter the flight name:");
    scanf("%s",name);

    while(fgets(c, 50, fp) != NULL)
     {
            if((strstr(c, name) != NULL))
                {
                    printf("A match found at line: %d\n",l);
                    flag=0;
                }
                l++;

     }
    if (flag ==1)
        {fputs(name, fp);
        printf("Flight number registered sucessfully\n");}
    else
        printf("Filght already exist:\n");
}
