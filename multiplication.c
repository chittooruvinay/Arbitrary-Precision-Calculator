#include "apc.h"

int add_lists(Dlist **headR, Dlist **tailR,Dlist **tempH, Dlist **tempT)
{
    /* If result is empty, TRANSFER ownership */
    if(*headR == NULL)
    {
        *headR = *tempH;
        *tailR = *tempT;

        /* Prevent caller from freeing it */
        *tempH = NULL;
        *tempT = NULL;

        return SUCCESS;
    }

    Dlist *p1 = *tailR;
    Dlist *p2 = *tempT;
    Dlist *resH = NULL, *resT = NULL;
    int carry = 0;

    while (p1 || p2 || carry)
    {
        int sum = carry;

        if(p1)
        {
            sum += p1->data;
            p1 = p1->prev;
        }

        if(p2)
        {
            sum += p2->data;
            p2 = p2->prev;
        }

        insert_first(&resH, &resT, sum % 10);
        carry = sum / 10;
    }

    delete_list(headR, tailR);

    *headR = resH;
    *tailR = resT;

    return SUCCESS;
}

int multiplication(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR)
{
    delete_list(headR, tailR);

    /* Multiplication by zero */
    if((*head1)->data == 0 || (*head2)->data == 0)
    {
        insert_last(headR, tailR, 0);
        return SUCCESS;
    }

    Dlist *p2 = *tail2;
    int zeros = 0;

    while(p2)
    {
        Dlist *tempH = NULL, *tempT = NULL;
        Dlist *p1 = *tail1;
        int carry = 0;

        while(p1)
        {
            int mul = p1->data * p2->data + carry;
            insert_first(&tempH, &tempT, mul % 10);
            carry = mul / 10;
            p1 = p1->prev;
        }

        if(carry)
        {
            insert_first(&tempH, &tempT, carry);
        }
        /* Append zeros (shift) */
        for(int i = 0; i < zeros; i++)
        {
            insert_last(&tempH, &tempT, 0);
        }

        add_lists(headR, tailR, &tempH, &tempT);
        delete_list(&tempH, &tempT);

        zeros++;
        p2 = p2->prev;
    }

    trim_leading_zeros(headR, tailR);
    return SUCCESS;
}

