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
        int i; /* counter */
        struct stack stck; /* Declare stack */
        double a, b; /* Declare two operands */
        double (*op) (double, double) = NULL; /* Initialize to null */
        
        for(i = 1; i < cnt; i++) /* start at 1 to avoid the first element */
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
                        case '^':
                                op = exponation;
                                break;
                        case 'r':
                                if(*(s[i] + 1) == 'o' && *(s[i] + 2) == 'o'
                                        && *(s[i] + 3) == 't' 
                                        && *(s[i] + 4) == '\0')
                                        op = root;
                                else if(*(s[i] + 1) == '\0')
                                        op = root;
                                else
                                        EXIT_FAILURE;                          
                                break;
                        default:
                                op = NULL; 
                }
                
                if(op)
                { /* If the function ptr is set perform an operation */
                        pop(&stck,&b);
                        pop(&stck,&a);
                        push(&stck, op(a, b));
                        op = NULL; 
                }
                else if(isdigit(*s[i]))
                { /* Add the opperand to the stack */
                        push(&stck, strtod(s[i], NULL));
                }
                else
                {
                        EXIT_FAILURE;
                }
                
        }
        printf("%f\n", stck.nxt->a); /* Send the result to STDOUT */
        return 0;                    /* TODO: change to fprinf() */
}