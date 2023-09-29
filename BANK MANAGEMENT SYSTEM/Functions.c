#include "header.h"
#include "function.h"
#include <string.h>



Node* head = NULL; // Definition of the global variable 'head'


void add_account() {
    // Prompt the user to enter customer information
    Customer new_customer;
    printf("\nEnter the customer's name: ");
    fflush(stdin);
    gets(new_customer.customer_name);
    printf("Enter the customer's address: ");
    fflush(stdin);
    gets(new_customer.customer_address);
    printf("Enter the customer's national ID: ");
    fflush(stdin);
    gets(new_customer.national_id);
    printf("Enter the customer's phone number: ");
    fflush(stdin);
    gets(new_customer.phone_number);
    printf("Enter the customer's birthdate (dd/mm/yy): ");
    fflush(stdin);
    gets(new_customer.birth_date);
    printf("Enter the customer's account key: ");   // used to find account in system
    fflush(stdin);
    scanf("%d", &new_customer.id_key);
    printf("Enter the customer's initial deposit: ");
    fflush(stdin);
    scanf("%f", &new_customer.deposit);
    new_customer.blance = 0;

    // Create a new node and add it to the linked list
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->customer_info = new_customer;
    new_node->next = head;
    head = new_node;
}

void delete_account() {
    int account_key;
    printf("\nEnter the account key of the customer to be deleted: ");
    scanf("%d", &account_key);

    Node *current_node = head;
    Node *previous_node = NULL;

    while (current_node != NULL) {
        if (current_node->customer_info.id_key == account_key) {
            if (previous_node == NULL) {
                head = current_node->next;
            } else {
                previous_node->next = current_node->next;
            }
            free(current_node);
            printf("Customer with account key %d has been deleted.\n", account_key);
            return; // Exit the function after deletion
        }

        previous_node = current_node;
        current_node = current_node->next;
    }

    printf("Customer with account key %d not found.\n", account_key);
}

void edit_account() {
    int account_key;
    printf("\nEnter the account key of the customer to be edited: ");
    scanf("%d", &account_key);

    Node *current_node = head;

    while (current_node != NULL) {
        if (current_node->customer_info.id_key == account_key) {
            printf("Enter the customer's name: ");
            fflush(stdin);
            gets(current_node->customer_info.customer_name);
            printf("Enter the customer's address: ");
            fflush(stdin);
            gets(current_node->customer_info.customer_address);
            printf("Enter the customer's ID: ");
            fflush(stdin);
            gets(current_node->customer_info.national_id);
            printf("Enter the customer's phone number: ");
            fflush(stdin);
            gets(current_node->customer_info.phone_number);
            printf("Enter the customer's birthdate (dd/mm/yy): ");
            fflush(stdin);
            gets(current_node->customer_info.birth_date);
            printf("Enter the customer's account number: ");
            scanf("%d", &current_node->customer_info.id_key);

            printf("Customer information has been updated.\n");
            return; // Exit the function after updating
        }

        current_node = current_node->next;
    }

    printf("Customer with account key %d not found.\n", account_key);
}

void customers_list() {
    Node *current_node = head;

    printf("\nCustomer List\n");
    printf("-------------\n");
    printf("%-5s %-20s %-20s %-15s %-10s %-30s %-10s %-10s\n", "ID", "Name", "Birth Date", "Phone Number", "ID", "Address", "Balance", "Account Number");
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    while (current_node != NULL) {
        Customer customer = current_node->customer_info;
        printf("%-5d %-20s %-20s %-15s %-10s %-30s %-10.2f %-10d\n", customer.id_key, customer.customer_name, customer.birth_date, customer.phone_number, customer.national_id, customer.customer_address, customer.blance, customer.id_key);
        current_node = current_node->next;
    }
}

void transact() {
    int account_number;
    printf("\nEnter the account number of the customer to perform a transaction: ");
    scanf("%d", &account_number);

    Node *current_node = head;

    while (current_node != NULL) {
        if (current_node->customer_info.id_key == account_number) {
            Transaction new_transaction;
            printf("Enter the Date of the Transaction (dd/mm/yy): ");
            fflush(stdin);
            fgets(new_transaction.date, sizeof(new_transaction.date), stdin);
            printf("Enter the Type of the Transaction (Deposit or Withdrawal): ");
            fflush(stdin);
            fgets(new_transaction.type, sizeof(new_transaction.type), stdin);
            printf("Enter the Amount of the Transaction: ");
            fflush(stdin);
            scanf("%f", &new_transaction.amount);

            Transaction_Node *new_transaction_node = (Transaction_Node *)malloc(sizeof(Transaction_Node));
            new_transaction_node->transaction_info = new_transaction;
            new_transaction_node->next = current_node->customer_info.transaction_head;
            current_node->customer_info.transaction_head = new_transaction_node;

            if (EQ(new_transaction.type, "Withdrawal")) {
                current_node->customer_info.blance -= new_transaction.amount;
            } else if (EQ(new_transaction.type, "Deposit")) {
                current_node->customer_info.blance += new_transaction.amount;
            } else {
                printf("Invalid transaction type.\n");
            }

            new_transaction_node->transaction_info.blance = current_node->customer_info.blance;
            printf("\nTransaction successful!\n");

            return;
        }

        current_node = current_node->next;
    }

    printf("Customer with account number %d not found.\n", account_number);
}

void account_list() {
    int account_number;
    printf("\nEnter the account number of the customer: ");
    scanf("%d", &account_number);

    Node *current_node = head;

    while (current_node != NULL) {
        if (current_node->customer_info.id_key == account_number) {
            printf("\nTransaction List for Customer %d\n", account_number);
            printf("--------------------------------\n");
            printf("%-20s %-30s %-10s %-10s\n", "Transaction Type", "Date of Transaction", "Amount", "Balance");

            Transaction_Node *current_transaction_node = current_node->customer_info.transaction_head;

            while (current_transaction_node != NULL) {
                printf("%-20s %-30s %-10.2f %-10.2f\n", current_transaction_node->transaction_info.type, current_transaction_node->transaction_info.date, current_transaction_node->transaction_info.amount, current_transaction_node->transaction_info.blance);
                current_transaction_node = current_transaction_node->next;
            }

            return;
        }

        current_node = current_node->next;
    }

    printf("Customer with account number %d not found.\n", account_number);
}
