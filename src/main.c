/*  Copyright (c) 2019, MilanMijatov
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"
#include "operations.h"

int rpn(int, char**);

int main(int argc, char *argv[])
{
        //char *s[] = {"15","4","+"};
        rpn(argc, argv);
        return 0;
}

int rpn(int cnt, char *s[])
{
        int i;
        struct stack stck; /* Declare stack */
        double a, b; /* Declare two operands */
        double (*op) (double, double) = NULL; /* Initialize to null */
        
        for(i = 0; i < cnt; i++)
        {
                switch(*s[i])
                { /* Find the operator being used and set the function ptr */
                        case '+':
                                op = addition;
                                break;
                        case '-':
                                op = subtraction;
                                break;
                        case '*':
                                op = multiplication;
                                break;
                        case '/':
                                op = division;
                                break;
                        default:
                                op = NULL; 
                }

                if(op)
                { /* If the function ptr is set perform an operation */
                        pop(&stck,&b);
                        pop(&stck,&a);
                        push(&stck, op(a, b));
                }
                else
                { /* Add the opperand to the stack */
                        push(&stck, strtod(s[i], NULL));
                }
        }
        printf("%f\n", stck.nxt->a); /* Send the result to STDOUT */
        return 0;                    /* TODO: change to fprinf() */
}