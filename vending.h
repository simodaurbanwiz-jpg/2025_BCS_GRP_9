#include <stdbool.h>
#ifndef VENDING_H
#define VENDING_H

//#define ITEMS 5
// VENDOR_H
void Display();
bool isValidDenomination(int money);
void giveChange(int amount);
void buy();
int price[];
char *items[];
int stock[];

#endif
