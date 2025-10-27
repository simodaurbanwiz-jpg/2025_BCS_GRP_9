#include "vending.h"
#include <stdio.h>
int ITEMS;
int denoSize;
int denominations[];
char *items[] = {"Soda", "Cake", "Juice", "Fries", "Water"};
    int price[] = {1000,2000,1500,2500,2000};
    int stock[] = {10,3,5,6,12};
    int denominations[] = {50000,20000,10000,5000,2000,1000,500,200,100,50};
    int denoSize = sizeof(denominations)/sizeof(denominations[0]);
bool isValidDenomination(int money){
for(int i = 0; i<denoSize; i++){
    if(money == denominations[i])return true;
    }
    return false;
}
void Display(){

    printf("*****VENDING MACHINE SIMULATOR*****");
    for(int i = 0; i < 5; i++){
        printf("\n%d  %-5s %-8d -> %-5d In Stock",i+1,items[i],price[i],stock[i]);
    }

}

void giveChange(int amount){


    if(amount <=0)return;
    printf("Your Change Is %d, Breakdown: \n",amount);
    for(int i = 0; i<denoSize; i++){
        int count = amount/denominations[i];
        if(count > 0){
            printf("%d x %d\n",count,denominations[i]);
        }
        amount %= denominations[i];
        //return 0;
    }
}

void buy(int *balance) {
    char input[20];
    int choice, quantity, inserted_money, inserted, change;

    Display();

    // --- Safe Item Choice ---
    while (1) {
        printf("\nEnter Your Item Choice: ");
        if (fgets(input, sizeof(input), stdin) == NULL) continue;
        if (sscanf(input, "%d", &choice) != 1 || choice < 1 || choice > 5) {
            printf("Invalid choice. Please enter a number between 1 and 5.\n");
            continue;
        }
        if (stock[choice - 1] == 0) {
            printf("%s is out of stock.\n", items[choice - 1]);
            return;
        }
        break;
    }

    // --- Safe Quantity Input ---
    while (1) {
        printf("\nEnter how many %s(s) you want: ", items[choice - 1]);
        if (fgets(input, sizeof(input), stdin) == NULL) continue;
        if (sscanf(input, "%d", &quantity) != 1 || quantity < 1 || quantity > stock[choice - 1]) {
            printf("Invalid quantity! Available stock: %d\n", stock[choice - 1]);
            continue;
        }
        break;
    }

    int cost = price[choice - 1] * quantity;
    printf("You are to pay %d UGX\n", cost);

    inserted = *balance; // start with existing balance
    printf("Your current balance: %d UGX\n", inserted);

    printf("Insert valid UGX denominations or 0 to cancel.\n");

    // --- Handle Money Insertion Safely ---
    while (inserted < cost) {
        printf("\nInsert: ");
        if (fgets(input, sizeof(input), stdin) == NULL) continue;
        if (sscanf(input, "%d", &inserted_money) != 1) {
            printf("Invalid input! Please insert a valid amount.\n");
            continue;
        }

        if (inserted_money == 0) {
            printf("\nTransaction cancelled! Returning %d UGX.\n", inserted);
            giveChange(inserted);
            *balance = 0;
            return;
        }

        if (!isValidDenomination(inserted_money)) {
            printf("Invalid denomination! Try again.\n");
            continue;
        }

        inserted += inserted_money;
        printf("Total inserted: %d UGX\n", inserted);
    }

    // --- Complete Transaction ---
    stock[choice - 1] -= quantity;
    change = inserted - cost;
    printf("\nYou are taking %d %s(s) for %d UGX\n", quantity, items[choice - 1], cost);

    if (change > 0) {
        printf("Remaining balance: %d UGX (kept for next purchase)\n", change);
    } else {
        printf("No change. Thank you!\n");
    }

    *balance = change; // store remaining money for next round
}
