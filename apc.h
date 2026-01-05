#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>

/* Macros */
#define SUCCESS 0
#define FAILURE -1

/* Doubly Linked List Node */
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} Dlist;

/* List utilities */
int insert_first(Dlist **head, Dlist **tail, int data);

int insert_last(Dlist **head, Dlist **tail, int data);

void delete_list(Dlist **head, Dlist **tail);

void trim_leading_zeros(Dlist **head, Dlist **tail);

void print_list(Dlist *head, int negative);

/* Number utilities */
int count_nodes(Dlist *head);

int compare_numbers(Dlist *head1, Dlist *head2);

/* Core operations */
int addition(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR);

int subtraction(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR);

int multiplication(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR);

int division(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR);

/* Helpers */
int add_lists(Dlist **headR, Dlist **tailR,Dlist **tempH, Dlist **tempT);

int digit_to_list(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,char *argv[],int *sign1, int *sign2);

#endif
