#include <stdio.h>
#include <string.h>

struct Flight
{
    char flight_no[50],from[50],to[50];

};

main() {
   FILE *fp;


   /*
   fprintf(fp, "hello world\n");
   fputs("hi there fuck you\n", fp);
   fclose(fp);



   FILE *fp;
   char buff[255];

   fp = fopen("test.txt", "r");
   fscanf(fp, "%s", buff);
   printf("1 : %s\n", buff );

   fgets(buff, 255, (FILE*)fp);
   printf("2: %s\n", buff );

   fgets(buff, 255, (FILE*)fp);
   printf("3: %s\n", buff );*/

    struct Flight f1;
    fp = fopen("test1.txt", "a+");
    fscanf(fp, "%s", &f1.flight_no);
    fscanf(fp, "%s", &f1.from);
    fscanf(fp, "%s/n", &f1.to);




   fclose(fp);




}
