#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "function.h"

int main()
{
    int choice;
    int inputValid = 0;


    while (1) {
        printf("\n*************  Welcome To Bank Management  ************\n");
        printf("Please select one number from these options:\n");
        printf("1: Create a new account\n");
        printf("2: Delete account\n");
        printf("3: Edit customer data\n");
        printf("4: Show CUSTOMER LIST\n");
        printf("5: Show ACCOUNT LIST\n");
        printf("6: Perform a transaction\n");
        printf("7: Exit\n");


        if (scanf("%d", &choice) != 1) {
            // If input is not an integer, clear the input buffer and show an error message
            printf("Invalid input. Please enter a valid integer.\n");
            fflush(stdin); // Clear the input buffer
        } else {
            inputValid = 1; // Set inputValid to 1 to exit the loop
        }
            printf("\n\n");

        switch (choice) {
            case 1:
                add_account();
                break;

            case 2:
                delete_account();
                break;

            case 3:
                edit_account();
                break;

            case 4:
                customers_list();
                break;

            case 5:
                account_list();
                break;

            case 6:
                transact();
                break;

            case 7:
                exit(0);
                break;

            default:
                printf("Wrong choice\n");
                break;
        }
    }

    return 0;
}
