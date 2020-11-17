#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

//Predefining some functions 
int ticket_pnr();

//Create a structure called passenger_info to store passenger information like name, gender, age, fare
//pass_StudentID contains the passenger's Student ID if he/she is a student
//pass_agecat contains the information whether the passenger is an infant, child or adult
struct passenger_info	//Anmol Kumar
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

//Create an array of type passenger_info of length 5, which is a global variable
struct passenger_info passenger[5];

//Create card and net_banking structs to store card and net banking detials
//Payment details are stored as a struct for easier referencing
struct card{
    char card_type[6];
    unsigned long int card_no;
    unsigned int cvv;
    unsigned int expiry_date, expiry_month;
};

struct net_banking{
    char    bank_name[50],
            bank_id[50],
            bank_pass[50];
};

struct payment_details{
    char payment_type[10];
    struct card payment_card;
    struct net_banking payment_net;
};


void booking(float total_payment)
{
    char    greet_1[100] = "Welcome to the Payment Portal";
    char    greet_2[100] = "Please enter your method of payment";
    char    greet_3[100] = "Please press \"0\" for card and \"1\" for cash";
    int     choice, check_valid_choice=0;

	struct payment_details user_payment_details;
    char card_call_1[100] = "Please enter CARD type :";
    char card_call_2[100] = "Please enter CARD number :";
    char card_call_3[100] = "Please enter CARD cvv :";
    char card_call_4[100] = "Please enter CARD expiry date :";
    char card_call_5[100] = "Please enter CARD expiry month :";

    char bank_call_1[100] = "Please enter Bank Name :";
    char bank_call_2[100] = "Please enter Bank Id :";
    char bank_call_3[100] = "Please enter Bank Password :";


    printf("\n \t\t\t\t\t%s \n\n %s \n %s", greet_1,greet_2,greet_3);
    do {
	scanf("%d", &choice);

    
    switch (choice) {
    case 0:
		check_valid_choice = 1;
        sscanf("Card", "%s", user_payment_details.payment_type);
        printf("\n%s",card_call_1);
        scanf("%s", user_payment_details.payment_card.card_type);
        printf("\n%s",card_call_2);
        scanf("%lu",&user_payment_details.payment_card.card_no);
        printf("\n%s",card_call_3);
        scanf("%d",&user_payment_details.payment_card.cvv);
        printf("\n%s",card_call_4);
        scanf("%d",&user_payment_details.payment_card.expiry_date);
        printf("\n%s",card_call_5);
        scanf("%d",&user_payment_details.payment_card.expiry_month);
        
        break;
    
    case 1:
		check_valid_choice = 1;
        sscanf("NetBanking", "%s", user_payment_details.payment_type);
        printf("\n%s",bank_call_1);
        scanf("%s", user_payment_details.payment_net.bank_id);
        printf("\n%s",bank_call_2);
        scanf("%s",user_payment_details.payment_net.bank_name);
        printf("\n%s",bank_call_3);
        scanf("%s",user_payment_details.payment_net.bank_pass);
        break;
    
    default:
        printf("Invalid choice selected... returning back");
        break;
    };} while (check_valid_choice==0);

	printf("%f has been paid through %s", total_payment ,user_payment_details.payment_type);
}

//Function to calculate fare based on age and the distance dependent fare of the flight.
//The variable c takes the values 0 and 1, corresponding to whether student concession is applicable or not
//Total fare consists of four parts-base fare, flight's distance dependent fare, student concession and taxes (10%)
//Base fare is calculated based on age of the passenger
float fare_calculator(int age, float distance_fare, int c)	//Harshit Kumar 
{
	float base, student_concession, booking_charges, total;
	if(age<3)
	{
		base = 200;	//Base fare for infant
	}
	else if(age>=3 && age <=5)
	{
		base = 600;	//Base fare for child
	}
	else
	{
		base = 1000;	//Base fare for adult
	}
	
	student_concession = -400.0;	//Student concession to be subtracted in case of a student passenger
	total = base + distance_fare + c*student_concession;	//Total fare without taxes
	float copy_total = total;
	total = total + 0.1*total;	//Total fare plus 10% taxes
	printf("Base: %f \n Student Concession: %f \n Distance_fare: %f \n Total(Before): %f \n Total(After): %f \n", base, student_concession, distance_fare, copy_total, total);
	return total;
}

//Function to return the number of seats available for a given flight on a given date
//The file is named as Flight_numberDate.txt and is passed as a pointer type variable
int seat_info(char *flight_id)		//Anmol Kumar
{
	FILE *fp;
	fp = fopen(flight_id, "r");	//Opens the file to read its contents
	int n;
	if(fp == NULL)	//If the file does not exist, or in other words, no seat has been booked on that flight
	{
		fp = fopen(flight_id,"a");	//Opens the file to write on it
		n = 100;
		fprintf(fp,"Available seats: %d\n", n);	//Sets the number of available seats to n (100), which is the capacity of the flight
		fclose(fp);
	}
	else
	{
		fseek(fp,-5,SEEK_END);	//If the file opens, the cursor goes to that point at the end of the file where the number of available seats is written 
		fscanf(fp, "%d", &n);	//Scans the last integer and stores in the variable n
	}
	fclose(fp);
	return n;
}

//Function to display the ticket details on the terminal
//Displays PNR, name, gender, fare, Student ID and age category from the passenger_info type array
//Returns the PNR to be kept for admin records
int disp_ticket(int n, float total_fare, int seat)	//Anmol Kumar
{
	printf("\n\nYour ticket has been booked!\n\nHere are the details:\n\n");	
	int k = 1;
	int pnr; pnr = ticket_pnr();		//Calls the ticket_pnr function and stores the PNR in the interger type variable pnr
	printf("PNR: %d\n", pnr);
	printf("S.No.\t First Name \t Last Name \t Gender \t Student ID \t Age \t Fare \t Category\n");
	printf("======================================================================================\n");
	for(;k<=n;k++)	//Displaying the ticket details recursively
	{
		printf("%d \t %s \t %s \t %s \t %s \t %d \t %.2f \t %s\n", passenger[k].pass_serial, passenger[k].pass_fname, passenger[k].pass_lname, passenger[k].pass_gender, passenger[k].pass_StudentID, passenger[k].pass_age, passenger[k].pass_fare, passenger[k].pass_agecat);
	
	}
	printf("======================================================================================\n");
	printf("Total Fare: %.2f", total_fare);
	return pnr;
}

//Function to write to the same file from which seat availability is extracted: Flight_numberDate.txt
void ticket_info(char *flight_id, int n, int pnr, float total_fare, int seat)		//Anmol Kumar
{
	FILE *fptr;
	fptr = fopen(flight_id,"a");	//Open the file to append passenger information
	
    fprintf(fptr, "\nNumber of Passengers: %d\n",n);
    fprintf(fptr, "PNR: %d\n",pnr);
    int l = 1;
	for(;l<=n;l++)	//Writing to the file recursively
	{
		fprintf(fptr, "%d %s %s %s %s %d %s\n", passenger[l].pass_serial, passenger[l].pass_fname, passenger[l].pass_lname, passenger[l].pass_gender, passenger[l].pass_StudentID, passenger[l].pass_age, passenger[l].pass_agecat);
	}
	fprintf(fptr, "Total Fare: %.2f\n", total_fare);
	fprintf(fptr, "\n");
	fprintf(fptr, "Available seats: %d\n", seat-n);		//Updating the number of available seats by writing at the end of file
    fclose(fptr);
}


//Function to generate a PNR for the ticket
int ticket_pnr()	//Harshit Kumar
{ 
    srand(time(0));	//Generates a random number by taking time as a seed value
    int pnr = (rand() % (999999 - 100000 + 1)) + 100000;	//Scaling the random number to a 6 digit integer
    return pnr;  
} 

//Function to collect passenger information from the user
//After a user has entered all the information, total fare is calculated and returned
//Input arguments are number of passengers n, the flight's distance dependent fare and number of available seats
float collect_info(int n, float distance_fare, int seat)	//Anmol Kumar
{
	float total_fare = 0.0;
	int c;
	
	int i;
	for(i=1;i<=n;i=i+1)
	{
		passenger[i].pass_serial = i;
		printf("Please provide the following details for passenger no. %d\n", i);
		printf("First Name:");
		scanf("%s",passenger[i].pass_fname);	//First Name
		printf("Last Name:");
		scanf("%s",passenger[i].pass_lname);	//Last Name
		printf("Gender:");
		scanf("%s",passenger[i].pass_gender);	//Gender
		printf("Are you a student? [Enter 1 for YES, 0 for NO]:");
		scanf("%d", &c);
		if(c==1)
		{
			printf("Please provide a valid ID number:");	//If the passenger is a student (c=1), a student ID is asked and stored in the corresponding variable
			scanf("%s",passenger[i].pass_StudentID);
			printf("Please carry this ID card with you during the journey.\n");
		}
		else
		{
			strcpy(passenger[i].pass_StudentID,"NA");	//If c=0, NA is stored in pass_StudentID
		}
		printf("Age:");		//Age
		scanf("%d",&passenger[i].pass_age);
		if(passenger[i].pass_age < 3)	//Classification of passenger into infant, child and adult based on his/her age
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
		//
		printf("passenger[i].pass_age: %d, distance_fare: %f, c: %d\n", passenger[i].pass_age, distance_fare, c);

		passenger[i].pass_fare = fare_calculator(passenger[i].pass_age, distance_fare, c);	//Calculation of fare for a single passenger using fare_calculator function
		//
		printf("Before total fare: %f\n", total_fare);
		
		total_fare = total_fare + passenger[i].pass_fare;	//Total fare for all the passengers, gets added recursively
		//
		printf("After total fare: %f\n", total_fare);
	}
	return total_fare;
}

//Function to book tickets
//It takes the input parameters the file name pointer corresponding to the flight number and date, and the flight's distance dependent fare 
void book_tickets(char *f1, float distance_fare)	//Harshit Kumar
{
	int n, i;
	int seat_num = seat_info(f1);	//Extracts the number of seats available on the flight on that date
	
	printf("Available Seats: %d\n", seat_num);
	printf("Enter the number of passengers (You can only book for upto 5 passengers):\n");
	scanf("%d",&n);		//Takes the number of passengers the user can add for the journey
	
	if(n>seat_num)
	{
		printf("Sorry! No seats available");	//If the user tries to book more seats than there are available seats, this message would be displayed
	}
	else if(n>5)
	{
		printf("Sorry, your entered number of passengers exceeds the maximun number of passengers you can add. Please try again.");	//Limiting the maximum number of passengers to add to 5
	}
	else
	{
		printf("(book_tickets_function) distance_fare: %f", distance_fare);
		float total_fare = collect_info(n, distance_fare, seat_num);	//Collect passenger information and return the total fare
		int pnr = disp_ticket(n, total_fare, seat_num);		//Display the ticket to the user
		booking(total_fare);						// Transports to the booking portal
		ticket_info(f1,n,pnr,total_fare, seat_num);	//Update the flight file with the added passengers and available seats
	}
}

int main()
{
	float distance_fare = 2000.0;
	char f1[] = "AIR";	//Flight Number selected by the user
	char date[] = "123";	//Date of journey selected by the user
	strcat(f1,date);	//Catenate two strings flight number and date of flight and store it in f1 variable
	strcat(f1,".txt");	//Add the .txt file extension to file name string
	printf("distance");
	book_tickets(f1, distance_fare);	//Function called to book tickets
	return 0;
}
