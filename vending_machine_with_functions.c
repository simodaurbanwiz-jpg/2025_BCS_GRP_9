#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#define ITEMS 5

char *items[] = {"Soda", "Cake", "Juice", "Flies", "Water"};
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
    for(int i = 0; i < ITEMS; i++){
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
    }
}

void buy(){
    int choice, quantity, inserted_money, inserted, change;
    Display();
    printf("\nEnter Your Item Choice: ");
    scanf("%d",&choice);
    if (choice <= 0 || choice > 5 ){
        printf("Invalid Choice");
        return;
    }
    if(stock[choice - 1] == 0){
        printf("%s is out of stock", items[choice-1]);
        return;
    }
    printf("\nEnter How many %s (s) You Want To Take: ",items[choice-1]);
    scanf("%d",&quantity);
    if(quantity < 0 || quantity > stock[choice-1]){
        printf("Aren't you seeing the number of %s (s) in stock",items[choice-1]);
        return;
    }
    int cost = price[choice - 1]*quantity;
    printf("You are To pay %d UGX\n",cost);
    inserted = 0;
    printf("Insert Valid UGX Dominations or 0 to cancel");

    while(inserted < cost){
        printf("\nInsert: ");
        scanf("%d",&inserted_money);
        if(inserted_money == 0){
            printf("\nTransaction Cancelled!!");
            if (inserted > 0){
                giveChange(inserted_money);
                return;
            }
        }
        if(!isValidDenomination(inserted_money)){
        printf("Invalid Domination");
        continue;
        }
        inserted += inserted_money;
        printf("\nTotal Inserted %d",inserted);


    }
    stock[choice-1] -= quantity;
    change = inserted - cost;
    printf("\nYou are taking %d %s(s) at UGX %d \n", quantity,items[choice-1],cost);
    if (change > 0)giveChange(change);
    else printf("No Change :) Thank you");


}

int main()
{
    int cont;
    do{
        buy();
        printf("\nDo You Want To Make Another Perchase[1 = Yes/0 = No]");
        scanf("%d",&cont);
    }while(cont == 1);
    printf("Thanks:)");
    return 0;
}
