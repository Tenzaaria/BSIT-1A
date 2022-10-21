// Point-of-Sales. System

#include <stdio.h>

//void = main function
void main(void) {

    int code, qty;
    float price, amt, totalAmt, change, cash;
	char addAnother;


//do-while -> post-test
//while loop -> pre-test
//for loop (almost similar with while loop) -> pre-test

do {
	system("cls");
    printf("\n==========================\n");
    printf("TENZ'S PIZZA OVERLOAD MENU\n");
    printf("==========================\n");
    printf("[1] Hawaiian Pizza Overload\tPhp350.00\n");
    printf("[2] Cheese Overload\t\tPhp320.00\n");
    printf("[3] All-Veggie Overload\t\tPhp350.00\n");
    printf("[4] All-Meat Overload\t\tPhp370.00\n");
    printf("[5] All-in-Overload\t\tPhp400.00\n");
// ang /t ay escape sequence pwede syang representation ng tab key
    printf("\nEnter Code\t: ");
    scanf("%d", &code);
//codes will be 1,2,3,4,5 therefore ang variable type ay integer. ang input ng user na code ay stored sa variable "code"
    printf("\nEnter Quantity\t: ");
    scanf("%d", &qty);

//gumamit ako ng switch-statement para sa prices ng code
    switch (code) {
//Float ang variable type ng price ko dito since may 2 decimal places ang currency
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
//example: 700.00 (amt)= 350.00(price) * 2(qty)
    printf("\nAmount: Php %.2f", amt);
//naglagay ako ng %.2f kasi 2 decimal place lang need ko sa currency    	
    totalAmt = totalAmt+amt;
	
	printf("\nTotal Amount:Php %.2f", totalAmt);    
    printf("\n\nAdd another order? (y/n)?");
    
	addAnother = getche(); //from getch to getche. I added e to echo the input data.
	} while(addAnother == 'y' || addAnother == 'Y');
	
	do {
		printf("\nCash Tendered\t: ");
		scanf("%f", &cash);
	}while(cash<totalAmt);
	
	change = cash-totalAmt;
	printf("\nChange\t\t: %.2f", change);
	printf("\nThank you for your patronage, Come again!");
    }
