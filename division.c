#include "apc.h"

int division(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR)
{
    /* Clear result list */
    delete_list(headR, tailR);

    /* Division by zero check */
    if(*head2 == NULL || ((*head2)->data == 0 && (*head2)->next == NULL))
    {
        return FAILURE;
    }
    /* Dividend < Divisor → Quotient = 0 */
    if(compare_numbers(*head1, *head2) < 0)
    {
        insert_last(headR, tailR, 0);
        return SUCCESS;
    }

    /* Quotient stored as linked list (not int) */
    Dlist *qH = NULL, *qT = NULL;
    Dlist *tempH = NULL, *tempT = NULL;

    while(compare_numbers(*head1, *head2) >= 0)
    {
        subtraction(head1, tail1, head2, tail2, &tempH, &tempT);

        delete_list(head1, tail1);
        *head1 = tempH;
        *tail1 = tempT;

        tempH = tempT = NULL;

        /* Increment quotient list by 1 */
        Dlist *oneH = NULL, *oneT = NULL;
        insert_last(&oneH, &oneT, 1);

        add_lists(&qH, &qT, &oneH, &oneT);
        delete_list(&oneH, &oneT);
    }

    trim_leading_zeros(&qH, &qT);

    *headR = qH;
    *tailR = qT;

    return SUCCESS;
}
