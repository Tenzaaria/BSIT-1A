// Point-of-Sales. System

#include <stdio.h>

void main(void) {

    int code, qty;
    float price, amt;

    printf("==========================\n");
    printf("TENZ'S PIZZA OVERLOAD MENU\n");
    printf("==========================\n");
    printf("[1] Hawaiian Pizza Overload\tPhp350.00\n");
    printf("[2] Cheese Overload\t\tPhp320.00\n");
    printf("[3] All-Veggie Overload\t\tPhp350.00\n");
    printf("[4] All-Meat Overload\t\tPhp370.00\n");
    printf("[5] All-in-Overload\t\tPhp400.00\n");

    printf("\nEnter Code\t:");
    scanf("%d", &code);
    printf("\nEnter Quantity\t:");
    scanf("%d", &qty);


    switch (code) {

        case 1: price = 350.00;
            break;
        case 2: price = 320.00;
            break;
        case 3: price = 350.00;
            break;
        case 4: price = 370.00;
            break;
        case 5: price = 400.00;
            break;
    }

    amt = price*qty;
        //350.00 * 2(qty) = 700.00
    printf("\nAmount: %.2f", amt);
    }

