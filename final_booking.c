#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>

struct passenger_info
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

struct passenger_info passenger[5];

float fare_calculator(int age, float distance_fare, int c)
{
	float base, student_concession, flight_fare, booking_charges, total;
	if(age<3)
	{
		base = 200;
	}
	else if(age>=3 && age <=5)
	{
		base = 600;
	}
	else
	{
		base = 1000;
	}
	student_concession = -400.0;
	flight_fare = distance_fare;
	total = base + flight_fare + c*student_concession;
	total = total + 0.1*total;
	return total;
}

int seat_info(char *flight_id)
{
	FILE *fp;
	fp = fopen(flight_id, "r");
	int n;
	if(fp == NULL)
	{
		fp = fopen(flight_id,"a");
		n = 100;
		fprintf(fp,"Available seats: %d\n", n);
		fclose(fp);
	}
	else
	{
		fseek(fp,-5,SEEK_END);
		fscanf(fp, "%d", &n);
	}
	fclose(fp);
	return n;
}

int disp_ticket(int n, float total_fare, int seat)
{
	printf("\n\nYour ticket has been booked!\n\nHere are the details:\n\n");	
	int k = 1;
	int pnr = ticket_pnr();
	printf("PNR: %d\n", pnr);
	printf("S.No.\t First Name \t Last Name \t Gender \t Student ID \t Age \t Fare \t Category\n");
	printf("======================================================================================\n");
	for(;k<=n;k++)
	{
		printf("%d \t %s \t %s \t %s \t %s \t %d \t %.2f \t %s\n", passenger[k].pass_serial, passenger[k].pass_fname, passenger[k].pass_lname, passenger[k].pass_gender, passenger[k].pass_StudentID, passenger[k].pass_age, passenger[k].pass_fare, passenger[k].pass_agecat);
	
	}
	printf("======================================================================================\n");
	printf("Total Fare: %.2f", total_fare);
	return pnr;
}

void ticket_info(char *flight_id, int n, int pnr, float total_fare, int seat)
{
	FILE *fptr;
	fptr = fopen(flight_id,"a");
	
    fprintf(fptr, "\nNumber of Passengers: %d\n",n);
    fprintf(fptr, "PNR: %d\n",pnr);
    int l = 1;
	for(;l<=n;l++)
	{
		fprintf(fptr, "%d %s %s %s %s %d %s\n", passenger[l].pass_serial, passenger[l].pass_fname, passenger[l].pass_lname, passenger[l].pass_gender, passenger[l].pass_StudentID, passenger[l].pass_age, passenger[l].pass_agecat);
	}
	fprintf(fptr, "Total Fare: %.2f\n", total_fare);
	fprintf(fptr, "\n");
	fprintf(fptr, "Available seats: %d\n", seat-n);
    fclose(fptr);
}

int ticket_pnr()
{ 
    srand(time(0)); 
    int pnr = (rand() % (999999 - 100000 + 1)) + 100000;
    return pnr;  
} 

float collect_info(int n, float distance_fare, int seat)
{
	float total_fare = 0.0;
	int c;
	
	int i;
	for(i=1;i<=n;i=i+1)
	{
		passenger[i].pass_serial = i;
		printf("Please provide the following details for passenger no. %d\n", i);
		printf("First Name:");
		scanf("%s",passenger[i].pass_fname);
		printf("Last Name:");
		scanf("%s",passenger[i].pass_lname);
		printf("Gender:");
		scanf("%s",passenger[i].pass_gender);
		printf("Are you a student? [Enter 1 for YES, 0 for NO]:");
		scanf("%d", &c);
		if(c==1)
		{
			printf("Please provide a valid ID number:");
			scanf("%s",passenger[i].pass_StudentID);
			printf("Please carry this ID card with you during the journey.\n");
		}
		else
		{
			strcpy(passenger[i].pass_StudentID,"NA");
		}
		printf("Age:");
		scanf("%d",&passenger[i].pass_age);
		if(passenger[i].pass_age < 3)
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
		
		passenger[i].pass_fare = fare_calculator(passenger[i].pass_age, distance_fare, c);
		total_fare = total_fare + passenger[i].pass_fare;
	}
	return total_fare;
}

book_tickets(char *f1, float distance_fare)
{
	FILE *filename;
	int n, i;
	int seat_num = seat_info(f1);
	
	printf("Available Seats: %d\n", seat_num);
	printf("Enter the number of passengers (You can only book for upto 5 passengers):\n");
	scanf("%d",&n);
	
	if(n>seat_num)
	{
		printf("Sorry! No seats available");
	}
	else if(n>5)
	{
		printf("Sorry, your entered number of passengers exceeds the maximun number of passengers you can add. Please try again.");
	}
	else
	{
		float total_fare = collect_info(n, distance_fare, seat_num);
		int pnr = disp_ticket(n, total_fare, seat_num);
		ticket_info(f1,n,pnr,total_fare, seat_num);
	}
}

void main()
{
	float distance_fare = 2000; //to be extracted from the flight database, value only to check
	char f1[] = "AIR"; //flight name to be retrieved from the user
	char date[] = "123";
	strcat(f1,date);
	strcat(f1,".txt");
	
	book_tickets(f1, distance_fare);
	
}
