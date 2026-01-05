/*
Name 			: chittooru vinay
Date 			: 18-12-2025
Project name 	: Arbitrary Precision Calculator (APC)

Project Description:

This project implements an Arbitrary Precision Calculator (APC) in C to perform arithmetic operations on integers of unlimited size. 
Since C has fixed-size data types, numbers are represented using a doubly linked list, with each node storing a single digit. 
The program accepts input as strings, manually validates them, and converts them into linked lists. 
It supports addition, subtraction, multiplication, and division, including negative numbers.
Arithmetic operations are performed digit by digit with proper handling of carry, borrow, sign management, and leading zeros. 
The project uses modular programming and dynamic memory allocation to ensure correctness and memory safety.

Addition:
Addition is performed by adding corresponding digits from the least significant side along with carry. 
The result is built by inserting digits at the front of the result list, and any remaining carry is added at the end.

Subtraction:
Subtraction is done by subtracting digits from right to left while handling borrow. 
Leading zeros are removed after the operation, and sign handling is managed separately.

Multiplication:
Multiplication is implemented using the grade-school method by generating partial products, 
shifting them using zeros, and adding them to obtain the final result.

Division:
Division is performed using repeated subtraction until the dividend becomes smaller than the divisor. 
The quotient is stored as a linked list, and division-by-zero cases are handled safely.

*/

#include "apc.h"

int main(int argc, char *argv[])
{
    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *headR = NULL, *tailR = NULL;

    int sign1, sign2, result_sign = 1;

    /* Argument validation */
    if(argc != 4)
    {
        printf("Usage: ./a.out <operand1> <operator> <operand2>\n");
        return FAILURE;
    }

    /* Convert input strings to linked lists */
    digit_to_list(&head1, &tail1, &head2, &tail2, argv, &sign1, &sign2);

    switch(argv[2][0])
    {
        case '+':
            if(sign1 == sign2)
            {
                /* Same sign → addition */
                addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                result_sign = sign1;
            }
            else
            {
                /* Different sign → subtraction */
                if (compare_numbers(head1, head2) >= 0)
                {
                    subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                    result_sign = sign1;
                }
                else
                {
                    subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR);
                    result_sign = sign2;
                }
            }
            break;

        case '-':
            if(sign1 != sign2)
            {
                /* A - (-B) or (-A) - B → addition */
                addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                result_sign = sign1;
            }
            else
            {
                /* Same sign → subtraction */
                if(compare_numbers(head1, head2) >= 0)
                {
                    subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                    result_sign = sign1;
                }
                else
                {
                    subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR);
                    result_sign = -sign1;
                }
            }
            break;
        case 'x':
			/* multiplication */
            multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
            result_sign = sign1 * sign2;
            break;

        case '/':
            /* Division by zero check */
            if(head2 == NULL || (head2->data == 0 && head2->next == NULL))
            {
                printf("Division by zero error\n");
                delete_list(&head1, &tail1);
                delete_list(&head2, &tail2);
                return FAILURE;
            }

            division(&head1, &tail1, &head2, &tail2, &headR, &tailR);
            result_sign = sign1 * sign2;
            break;

        default:
            printf("Invalid operator\n");
            delete_list(&head1, &tail1);
            delete_list(&head2, &tail2);
            return FAILURE;
    }

    /* Normalize zero (avoid -0) */
    if(headR && headR->data == 0 && headR->next == NULL)
	{
        result_sign = 1;
	}
    /* Print result */
    print_list(headR, result_sign == -1);

    /* Free memory */
    delete_list(&head1, &tail1);
    delete_list(&head2, &tail2);
    delete_list(&headR, &tailR);

    return SUCCESS;
}
