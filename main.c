#include <stdio.h>
#include <stdlib.h>
#include "vending.h"
#include "vending.c"

#include <stdbool.h>
//#define ITEMS 5
int main() {
    int cont;
    char input[20];
    int balance = 0; // keep leftover change here

    do {
        buy(&balance);

        while (1) {
            printf("\nDo you want to make another purchase [1 = Yes / 0 = No]: ");
            if (fgets(input, sizeof(input), stdin) == NULL) continue;
            if (sscanf(input, "%d", &cont) == 1 && (cont == 0 || cont == 1)) break;
            printf("Invalid input! Please enter 1 or 0.\n");
        }

    } while (cont == 1);

    if (balance > 0) {
        printf("\nReturning remaining balance of %d UGX. Thank you!\n", balance);
        giveChange(balance);
    }

    printf("Thanks :)\n");
    return 0;
}
