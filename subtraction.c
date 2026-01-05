#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR)
{
    /* Clear result list */
    delete_list(headR, tailR);

    /* Safety: equal numbers */
    if(compare_numbers(*head1, *head2) == 0)
    {
        insert_last(headR, tailR, 0);
        return SUCCESS;
    }

    /* Safety: ensure head1 >= head2 */
    if(compare_numbers(*head1, *head2) < 0)
    {
        return FAILURE;
    }
    Dlist *t1 = *tail1;
    Dlist *t2 = *tail2;
    int borrow = 0;

    while(t1 || t2)
    {
        int d1 = t1 ? t1->data : 0;
        int d2 = t2 ? t2->data : 0;

        d1 -= borrow;

        if(d1 < d2)
        {
            d1 += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        insert_first(headR, tailR, d1 - d2);

        if(t1)
        {
            t1 = t1->prev;
        }
        if(t2)
        {
            t2 = t2->prev;
        } 
        
    }

    /* Remove extra zeros */
    trim_leading_zeros(headR, tailR);

    return SUCCESS;
}
