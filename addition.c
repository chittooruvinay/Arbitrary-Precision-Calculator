#include "apc.h"

int addition(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR)
{
    /* Clear result list */
    delete_list(headR, tailR);

    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;
    int carry = 0;
    int data;

    while(temp1 != NULL || temp2 != NULL)
    {
        data = carry;

        if(temp1 != NULL)
        {
            data += temp1->data;
        }
        if(temp2 != NULL)
        {
            data += temp2->data;
        }
        insert_first(headR, tailR, data % 10);
        carry = data / 10;

        if(temp1 != NULL)
        {
            temp1 = temp1->prev;
        }
        if(temp2 != NULL)
        {
            temp2 = temp2->prev;
        }
    }

    if(carry)
    {
        insert_first(headR, tailR, carry);
    }
    return SUCCESS;
}
