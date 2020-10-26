#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>

float fare_calculator(int age, float distance_fare)
{
	float base, flight_fare, booking_charges, total;
	if(age<5)
	{
		base = 500;
	}
	else
	{
		base = 1000;
	}
	flight_fare = distance_fare;
	total = base + flight_fare;
	total = total + 0.1*total;
	return total;
}

struct passenger_info
{
	int pass_serial;
	char pass_fname[50];
	char pass_lname[50];
	char pass_gender[1];
	int pass_age;
	float pass_fare;
};

/*void disp_ticket(int n, struct passenger_info ticket[5], float total_fare)
{
	struct passenger_info tick[5];
	tick[5] = ticket[5];
	int k = 1;
		printf("S.No.\t First Name \t Last Name \t Gender \t Age \t Fare\n");
		printf("======================================================================================\n");
		for(;k<=n;k++)
		{
			printf("%d \t %s \t %s \t %s \t %d \t %.2f\n", tick[k].pass_serial, tick[k].pass_fname, tick[k].pass_lname, tick[k].pass_gender, tick[k].pass_age, tick[k].pass_fare);
		}
		printf("======================================================================================\n");
		printf("Total Fare: %.2f", total_fare);
	
}*/

void ticket_info(struct passenger_info passenger[5], char flight_id[], char date[], int n, int pnr, float total_fare)
{
	strcat(flight_id,date);
	strcat(flight_id,".txt");
	
	FILE *fptr;
	fptr = fopen(flight_id,"a");
	
	if (fptr == NULL)
    {
        printf("File does not exist.\n");
        return;
    }
    
    fprintf(fptr, "Number of Passengers: %d\n",n);
    fprintf(fptr, "PNR: %d\n",pnr);
    int l = 1;
	for(;l<=n;l++)
	{
		fprintf(fptr, "%d %s %s %s %d\n", passenger[l].pass_serial, passenger[l].pass_fname, passenger[l].pass_lname, passenger[l].pass_gender, passenger[l].pass_age);
	}
	fprintf(fptr, "Total Fare: %.2f\n", total_fare);
	fprintf(fptr, "\n");
    fclose(fptr);
}

int ticket_pnr()
{ 
    srand(time(0)); 
    int pnr = (rand() % (999999 - 100000 + 1)) + 100000;
    return pnr;  
} 

void collect_info(int n, float distance_fare, char f1[], char date[])
{
	float total_fare = 0.0;
	
	struct passenger_info passenger[5];
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
		printf("Age:");
		scanf("%d",&passenger[i].pass_age);
		passenger[i].pass_fare = fare_calculator(passenger[i].pass_age, distance_fare);
		total_fare = total_fare + passenger[i].pass_fare;
	}
		
	int k = 1;
	printf("S.No.\t First Name \t Last Name \t Gender \t Age \t Fare\n");
	printf("======================================================================================\n");
	for(;k<=n;k++)
	{
		printf("%d \t %s \t %s \t %s \t %d \t %.2f\n", passenger[k].pass_serial, passenger[k].pass_fname, passenger[k].pass_lname, passenger[k].pass_gender, passenger[k].pass_age, passenger[k].pass_fare);
	
	}
	printf("======================================================================================\n");
	printf("Total Fare: %.2f", total_fare);
	
	int pnr = ticket_pnr();
	ticket_info(passenger,f1,date,n,pnr,total_fare);
}

void main()
{
	int n, i;
	float total_fare = 0.0;
	
	float distance_fare = 2000; //to be extracted from the flight database, value only to check
	char f1[] = "AI101"; //flight name to be retrieved from the user
	char date[] = "26102020.txt"; //Date in ddmmyyy format
	
	printf("Enter the number of passengers (You can only book for upto 5 passengers):\n");
	scanf("%d",&n);
	
	struct passenger_info passenger[5];
	if(n>5)
	{
		printf("Sorry, your entered number of passengers exceeds the maximun number of passengers you can add. Please try again.");
	}
	else
	{
		collect_info(n, distance_fare, f1, date);
	}
	
}
