#include <stdio.h>
// declaration
int number;
char name;
int price;
int quantity;
int choice;
char unitPrice;
int payment;
int deno_number;
int money;
int main () {
    int repeat = 1; 
    while(repeat == 1 ) {
    number=5;
    char *name[]={"Soda", "Water", "Juice", "Crisps", "Chocolate"};
    int price[]={1500, 1000, 2000, 1200, 2500};
    //performing displaying
    printf("=====WELCOME TO C VENDING MACHINE=====\n");
    printf("%-6s %-15s %-8s\n", "No.","Name","Price");
    printf("___    _________       ____________\n");
    for(int i=0 ; i<number;++i) {
    printf("%-6d %-15s %-8dUGX\n",i + 1,name[i], price[i]);
    }
    printf("==========================================\n");
    printf("\n");
    //ask for customer choice
    printf("Enter item number:");
    scanf("%d",& choice);
    if(choice<1||choice>number) {
    printf("Invalid selection.\n");
    return 0;
    }//printing the names and of the selected item number and their prices
       printf("Item detail: %s\n", name[choice-1]);
       printf("Unit price: %d UGX\n", price[choice-1]);
       //ask user to input item quantity
       printf("Enter item quantity: ");
       scanf("%d", &quantity);
       //performing calculation to findout totalPrice
       int totalprice=price[choice-1] * quantity;
       printf("Total Price: %d UGX\n", totalprice);
       //ask user to  input 
       printf("Enter amount to pay: ");
       scanf("%d", & payment);
       //calculation about change
       int change = payment - totalprice ;
       // setting conditions about payment
       if (payment >= totalprice) {
           printf("Your change is: %d UGX\n", change);
           printf("Purchase confirmed, dispense item\n");
       } else{
           printf("Insufficient funds, please add more money %d\n", -change);
               }
       //change break down
    int denom_number = 10;
    int denominations[] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
    char *denom_names[] = {"50,000", "20,000", "10,000", "5,000", "2,000", "1,000", "500", "200", "100", "50"};
    //displaying the breakdown
    printf("\n");
    printf("==================================================\n");

    printf("HERE'S YOUR CHANGE BREAK DOWN OF: %d UGX\n", change);
            printf("%-8s %-18s\n", "Main", "Denomination Name");
            printf("\n");
    for(int i=0; i<denom_number; i++){
        int main= change / denominations[i];
        if (main > 0) {
            printf("%-8d × %-18s UGX\n", main, denom_names[i]);
            change %= denominations[i];
        }
    }
            printf("Thanks dear clients, pleased to serve you\n" );
    printf("===================================================\n");
   printf("would you like to continue with the purchase? (yes=1,no=0)\n ");
   scanf("%d",&repeat);
}
  return 0;
}
