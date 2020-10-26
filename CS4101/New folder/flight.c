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

    }

    return 0;
}
