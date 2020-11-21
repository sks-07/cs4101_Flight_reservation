#include "imports.h"

#ifndef _COLOR_CHANGE
#include "color_changer.c"
#endif

#ifndef _STRUCT_H
#include "structs.h"
#endif

struct passenger_info passenger[5];
//Function to calculate fare based on age and the distance dependent fare of the flight.
//The variable c takes the values 0 and 1, corresponding to whether student concession is applicable or not
//Total fare consists of four parts-base fare, flight's distance dependent fare, student concession and taxes (10%)
//Base fare is calculated based on age of the passenger

void booking(float total_payment)
{
	//color_change(3);
    char    greet_1[100] = "Welcome to the Payment Portal";
    char    greet_2[100] = "Please enter your method of payment";
    char    greet_3[100] = "\"0\" for card and \"1\" for net banking: ";
    int     choice, check_valid_choice=0;

	struct payment_details user_payment_details;
    char card_call_1[100] = "Please enter CARD type (Credit/Debit):";
    char card_call_2[100] = "Please enter CARD number :";
    char card_call_3[100] = "Please enter CARD cvv :";
    char card_call_4[100] = "Please enter CARD expiry date :";
    char card_call_5[100] = "Please enter CARD expiry month :";

    char bank_call_1[100] = "Please enter Bank Name :";
    char bank_call_2[100] = "Please enter Bank Id :";
    char bank_call_3[100] = "Please enter Bank Password :";

	color_change(3);
    printf("\n \t\t\t\t%s ", greet_1);
    do {
	color_change(3);
	printf("\n\n\t\t\t\t%s\n\t\t\t%s", greet_2, greet_3);color_change(7);
	scanf("%d", &choice);

    
    switch (choice) {
    case 0:
		check_valid_choice = 1;
        sscanf("Card", "%s", user_payment_details.payment_type);color_change(3);
        printf("\n\t\t\t\t%s\t",card_call_1);color_change(7);
        scanf("%s", user_payment_details.payment_card.card_type);color_change(3);
        printf("\n\t\t\t\t%s\t\t",card_call_2);color_change(7);
        scanf("%lu",&user_payment_details.payment_card.card_no);color_change(3);
        printf("\n\t\t\t\t%s\t\t\t",card_call_3);color_change(7);
        scanf("%d",&user_payment_details.payment_card.cvv);color_change(3);
        printf("\n\t\t\t\t%s\t\t",card_call_4);color_change(7);
        scanf("%d",&user_payment_details.payment_card.expiry_date);color_change(3);
        printf("\n\t\t\t\t%s\t",card_call_5);color_change(7);
        scanf("%d",&user_payment_details.payment_card.expiry_month);
        
        break;
    
    case 1:
		check_valid_choice = 1;
        sscanf("NetBanking", "%s", user_payment_details.payment_type);color_change(3);
        printf("\n\t\t\t\t%s\t",bank_call_1);color_change(7);
        scanf("%s", user_payment_details.payment_net.bank_id);color_change(3);
        printf("\n\t\t\t\t%s\t\t",bank_call_2);color_change(7);
        scanf("%s",user_payment_details.payment_net.bank_name);color_change(3);
        printf("\n\t\t\t\t%s\t",bank_call_3);color_change(7);
        scanf("%s",user_payment_details.payment_net.bank_pass);
        break;
    
    default:
		color_change(6);
        printf("Invalid choice selected... returning back");color_change(7);
        break;
    };} while (check_valid_choice==0);
	color_change(2);
	printf("\t\t\t\t%.2f has been paid through %s\n", total_payment ,user_payment_details.payment_type);color_change(7);
}







float fare_calculator(int age, float distance_fare, int c)	//Harshit Kumar 
{
	float base, student_concession, flight_fare, booking_charges, total;
	
	if(age<3)						base = 200;		//Base fare for infant
	else if(age>=3 && age <=5)		base = 600;		//Base fare for child
	else							base = 1000;	//Base fare for adult

	student_concession = -400.0;							//Student concession to be subtracted in case of a student passenger
	total = base + distance_fare + c*student_concession;	//Total fare without taxes
	total = total + 0.1*total;								//Total fare plus 10% taxes
	return total;
}

//Function to return the number of seats available for a given flight on a given date
//The file is named as Flight_numberDate.txt and is passed as a pointer type variable
int seat_info(char *flight_id)		//Anmol Kumar
{
	FILE *fp;
	fp = fopen(flight_id, "r");					//Opens the file to read its contents
	int n;
	if(fp == NULL)								//If the file does not exist, or in other words, no seat has been booked on that flight
	{
		fp = fopen(flight_id,"a");				//Opens the file to write on it
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

//Function to generate a PNR for the ticket
int ticket_pnr()	//Harshit Kumar
{ 
    srand(time(0));	//Generates a random number by taking time as a seed value
    int pnr = (rand() % (999999 - 100000 + 1)) + 100000;	//Scaling the random number to a 6 digit integer
    return pnr;  
} 

//Function to display the ticket details on the terminal
//Displays PNR, name, gender, fare, Student ID and age category from the passenger_info type array
//Returns the PNR to be kept for admin records
int disp_ticket(int n, float total_fare, int seat)	//Anmol Kumar
{	
	color_change(2);
	printf("\n\n\t\t\t\tYour ticket has been booked!\n\n\t\t\t\tHere are the details:\n\n");	
	int k = 1;
	int pnr = ticket_pnr();		//Calls the ticket_pnr function and stores the PNR in the interger type variable pnr
	color_change(5);
	printf("PNR: %d\n", pnr);color_change(6);
	printf("%-5s | %-20s | %-20s | %-7s | %-10s | %-3s | %-7s | %-7s\n","S.No.","First Name","Last Name","Gender","Student ID","Age","Fare","Category");color_change(2);
	printf("-----------------------------------------------------------------------------------------------------------------\n");color_change(3);
	for(;k<=n;k++)	//Displaying the ticket details recursively
	{
		printf("%-5d | %-20s | %-20s | %-7s | %-10s | %-3d | %-6.2f | %-7s\n", passenger[k].pass_serial, passenger[k].pass_fname, passenger[k].pass_lname, passenger[k].pass_gender, passenger[k].pass_StudentID, passenger[k].pass_age, passenger[k].pass_fare, passenger[k].pass_agecat);
	
	}color_change(2);
	printf("-----------------------------------------------------------------------------------------------------------------\n");color_change(1);
	printf("Total Fare: %.2f", total_fare);color_change(7);
	return pnr;
}

//Function to write to the same file from which seat availability is extracted: Flight_numberDate.txt
void ticket_info(char *flight_id, int n, int pnr, float total_fare, int seat)		//Anmol Kumar
{
	FILE *fptr;
	fptr = fopen(flight_id,"a");	//Open the file to append passenger information
	
    fprintf(fptr,"\n\n");
	fprintf(fptr, "\n%-25s %5d","Number of Passengers:",n);
    fprintf(fptr, "\n%-25s %5d\n","PNR:",pnr);
	fprintf(fptr,"%-5s | %-20s | %-20s | %-7s | %-10s | %-3s | %-7s\n","S.No.","First Name","Last Name","Gender","Student ID","Age","Category");
	fprintf(fptr,"-----------------------------------------------------------------------------------------------------------------\n");
	int l = 1;
	for(;l<=n;l++)	//Writing to the file recursively
	{
		fprintf(fptr, "%-5d | %-20s | %-20s | %-7s | %-10s | %-3d | %-7s\n", passenger[l].pass_serial, passenger[l].pass_fname, passenger[l].pass_lname, passenger[l].pass_gender, passenger[l].pass_StudentID, passenger[l].pass_age, passenger[l].pass_agecat);
	}
	fprintf(fptr,"-----------------------------------------------------------------------------------------------------------------\n");
	fprintf(fptr, "\n%-25s %8.2f","Total Fare", total_fare);
	fprintf(fptr, "\n%-25s %5d","Available seats:", seat-n);		//Updating the number of available seats by writing at the end of file
    fclose(fptr);
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
		passenger[i].pass_serial = i;color_change(3);
		printf("\n\t\t\t\tPlease provide the following details for passenger no. %d\n", i);color_change(5);
		printf("\t\t\t\t 1.");color_change(3);printf(" \t First Name\t:\t");color_change(7);
		scanf("%s",passenger[i].pass_fname);color_change(5);	//First Name
		printf("\t\t\t\t 2. \t");color_change(3);printf(" Last Name\t:\t");color_change(7);
		scanf("%s",passenger[i].pass_lname);	color_change(5);//Last Name
		printf("\t\t\t\t 3. \t");color_change(3); printf(" Gender\t\t:\t");color_change(7);
		scanf("%s",passenger[i].pass_gender);color_change(5);	//Gender
		printf("\t\t\t\t 4. "); color_change(3);printf(" Are you a student? \n\t\t\t     [Enter 1 for YES, 0 for NO]:\t");color_change(7);
		scanf("%d", &c);
		if(c==1)
		{
			color_change(3);
			printf("\t\t\tPlease provide a valid ID number:\t");color_change(7);	//If the passenger is a student (c=1), a student ID is asked and stored in the corresponding variable
			scanf("%s",passenger[i].pass_StudentID);color_change(3);
			printf("\t\t\t***Please carry this ID card with you during the journey.\n");color_change(7);
		}
		else
		{
			strcpy(passenger[i].pass_StudentID,"NA");	//If c=0, NA is stored in pass_StudentID
		}
		color_change(5);
		printf("\t\t\t\t 5.");color_change(3);printf(" \t Age\t\t:\t");	color_change(7);				//Age
		scanf("%d",&passenger[i].pass_age);
		if(passenger[i].pass_age < 3)					//Classification of passenger into infant, child and adult based on his/her age
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
		
		passenger[i].pass_fare = fare_calculator(passenger[i].pass_age, distance_fare, c);	//Calculation of fare for a single passenger using fare_calculator function
		total_fare = total_fare + passenger[i].pass_fare;									//Total fare for all the passengers, gets added recursively
	}
	return total_fare;
}

//Function to book tickets
//It takes the input parameters the file name pointer corresponding to the flight number and date, and the flight's distance dependent fare 
void book_tickets(char *f1, float distance_fare)	//Harshit Kumar
{
	clrscr();
	color_change(6);
	printf("\n-----------------------------------------------------------------------------------------------------------------\n");color_change(2);
	printf("\t\t\t\t\tADD PASSENGER DETAILS");color_change(6);
	printf("\n-----------------------------------------------------------------------------------------------------------------\n");color_change(3);
	int n, i;
	int seat_num = seat_info(f1);						//Extracts the number of seats available on the flight on that date
	
	printf("%48s\t\t%d\n","Available Seats:", seat_num);
	printf("%48s\n%48s\t\t","Enter the number of passengers ","(You can only book for upto 5 passengers):" );color_change(7);
	scanf("%d",&n);										//Takes the number of passengers the user can add for the journey
	
	if(n>seat_num)
	{	color_change(3);
		printf("\n\t\t\t\tSorry! No seats available");
		color_change(7);	//If the user tries to book more seats than there are available seats, this message would be displayed
	}
	else if(n>5)
	{
		color_change(4);
		printf("\n\t\t\t\tSorry. Your entered number of passengers exceeds the maximun number of passengers you can add. \n\t\tPlease try again.\n\n");	//Limiting the maximum number of passengers to add to 5
		book_tickets(f1,distance_fare);	color_change(7);				//Getting back to booking once again (This recursion does not break the program)
	
	}
	else
	{
		float total_fare = collect_info(n, distance_fare, seat_num);	//Collect passenger information and return the total fare
		booking(total_fare);
		int pnr = disp_ticket(n, total_fare, seat_num);					//Display the ticket to the user
		ticket_info(f1,n,pnr,total_fare, seat_num);						//Update the flight file with the added passengers and available seats

	}
}
