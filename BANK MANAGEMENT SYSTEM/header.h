#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a macro to compare strings
#define EQ(a, b) (!strcmp((a), (b)))

// Define the structure for a transaction
typedef struct transaction {
    char date[11];
    char type[11];
    float amount;
    float blance;
} Transaction;

// Define the structure for a transaction node
typedef struct transaction_node {
    Transaction transaction_info;
    struct transaction_node* next;
} Transaction_Node;

// Define the structure for a customer
typedef struct customer {
    int id_key;
    char customer_name[50];
    char customer_address[50];
    char account_type[8];
    char gender[8];
    char national_id[15];
    char phone_number[12];
    char birth_date[11];
    float deposit;
    float blance;
    Transaction_Node* transaction_head;
} Customer;

// Define the structure for a linked list node
typedef struct node {
    Customer customer_info;
    struct node* next;
} Node;

// Declare a global variable to point to the head of the linked list
extern Node* head;

#endif // HEADER_H_INCLUDED
