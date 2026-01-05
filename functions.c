#include "apc.h"

/* Convert input strings to digit lists */
int digit_to_list(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,char *argv[],int *sign1, int *sign2)
{
    int i = 0;
    *sign1 = *sign2 = 1;

    /* ---------- Operand 1 ---------- */
    if(argv[1][0] == '-')
    {
        *sign1 = -1;
        i = 1;
    }

    if(argv[1][i] == '\0')
        return FAILURE;

    while(argv[1][i] == '0')
    {
        i++;
    }
    if(argv[1][i] == '\0')
    {
        insert_last(head1, tail1, 0);
        *sign1 = 1;   /* zero is always positive */
    }
    else
    {
        while(argv[1][i] != '\0')
        {
            if(argv[1][i] < '0' || argv[1][i] > '9')
                return FAILURE;

            insert_last(head1, tail1, argv[1][i] - '0');
            i++;
        }
    }

    /* ---------- Operand 2 ---------- */
    i = 0;
    if (argv[3][0] == '-')
    {
        *sign2 = -1;
        i = 1;
    }

    if(argv[3][i] == '\0')
    {
        return FAILURE;
    }
    while(argv[3][i] == '0')
    {
        i++;
    }
    if (argv[3][i] == '\0')
    {
        insert_last(head2, tail2, 0);
        *sign2 = 1;
    }
    else
    {
        while (argv[3][i] != '\0')
        {
            if (argv[3][i] < '0' || argv[3][i] > '9')
                return FAILURE;

            insert_last(head2, tail2, argv[3][i] - '0');
            i++;
        }
    }

    return SUCCESS;
}

/* Insert node at beginning */
int insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));
    if (new == NULL)
        return FAILURE;

    new->data = data;
    new->prev = NULL;
    new->next = *head;

    if (*head)
        (*head)->prev = new;
    else
        *tail = new;

    *head = new;
    return SUCCESS;
}

/* Insert node at end */
int insert_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));
    if(new == NULL)
    {
        return FAILURE;
    }
    new->data = data;
    new->next = NULL;
    new->prev = *tail;

    if(*tail)
        (*tail)->next = new;
    else
        *head = new;

    *tail = new;
    return SUCCESS;
}

/* Delete entire list */
void delete_list(Dlist **head, Dlist **tail)
{
    Dlist *temp = *head;
    while(temp)
    {
        Dlist *next = temp->next;
        free(temp);
        temp = next;
    }
    *head = *tail = NULL;
}

/* Remove extra leading zeros */
void trim_leading_zeros(Dlist **head, Dlist **tail)
{
    while(*head && (*head)->data == 0 && (*head)->next)
    {
        Dlist *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }
}

/* Print number */
void print_list(Dlist *head, int negative)
{
    if(head == NULL)
    {
        printf("0\n");
        return;
    }

    if(negative && !(head->data == 0 && head->next == NULL))
    {
        printf("-");
    }
    while (head)
    {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}

/* Count number of nodes */
int count_nodes(Dlist *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}

/* Compare two numbers */
int compare_numbers(Dlist *head1, Dlist *head2)
{
    int c1 = count_nodes(head1);
    int c2 = count_nodes(head2);

    if(c1 > c2) 
    {
        return 1;
    }
   
    if(c1 < c2) 
    {
        return -1;
    }
    while(head1 && head2)
    {
        if(head1->data > head2->data) 
        {
            return 1;
        }
        if(head1->data < head2->data) 
        {
            return -1;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return 0;
}
