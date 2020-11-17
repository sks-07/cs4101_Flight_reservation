#include<stdio.h>
#include<stdlib.h>

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

void booking()
{
    char    greet_1[100] = "Welcome to the Payment Portal";
    char    greet_2[100] = "Please enter your method of payment";
    char    greet_3[100] = "Please press \"0\" for card and \"1\" for cash";
    int     choice, check_valid_choice;

    printf("\n \t\t\t\t\t%s \n\n %s \n %s", greet_1,greet_2,greet_3);
    scanf("%d", &choice);

    struct payment_details user_payment_details;
    char card_call_1[100] = "Please enter CARD type :";
    char card_call_2[100] = "Please enter CARD number :";
    char card_call_3[100] = "Please enter CARD cvv :";
    char card_call_4[100] = "Please enter CARD expiry date :";
    char card_call_5[100] = "Please enter CARD expiry month :";

    char bank_call_1[100] = "Please enter Bank Name :";
    char bank_call_2[100] = "Please enter Bank Id :";
    char bank_call_3[100] = "Please enter Bank Password :";

    switch (choice) {
    case 0:
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
    };
}