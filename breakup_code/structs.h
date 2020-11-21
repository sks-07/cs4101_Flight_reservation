#pragma once

#ifndef _STRUCT_H
#define _STRUCT_H
#endif

struct Flight
{
    int id,date[3];
    char name[50],source[50],destination[50];
};


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

struct web
{
char name[30],pass[30];
}; 

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

struct flags
{
    int adminf,userf,login_success;
};

