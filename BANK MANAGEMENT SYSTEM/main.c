#include <stdio.h>
#include "header.h"
#include "function.h"

int main()
{
    int choice;


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

        scanf("%d", &choice);
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
