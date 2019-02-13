#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"
#include "operations.h"

//__declspec(dllexport) char* rpn_export(int cnt,char** str);

int rpn(int cnt, char *s[], double *ret, int startat)
{
        int i; /* counter */
        struct stack stck; /* Declare stack */
        double a, b; /* Declare two operands */
        double (*op) (double, double) = NULL; /* Initialize to null */
        char *c;
        
        for(i = startat; i < cnt; i++) /* start at 1 to avoid the first element */
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
                                {
                                        fprintf(stderr, "Error: Invalid input on token: %s\n", s[i]);
                                        return(1);
                                }
                                break;
                        default:
                                op = NULL;
                }
                
                if(op)
                { /* If the function ptr is set perform an operation */
                        if(pop(&stck,&b))
                        {
                                fprintf(stderr, "Error: Invalid number of operator/opperands\n");
                                return(2);
                        }
                        if(pop(&stck,&a))
                        {
                                fprintf(stderr, "Error: Invalid number of operator/opperands\n");
                                return(2);
                        }
                        push(&stck, op(a, b));
                        op = NULL;
                }
                else if(isdigit(*s[i]))
                { /* Add the opperand to the stack */
                        push(&stck, strtod(s[i], &c));
                        if(*c)
                        {
                                fprintf(stderr, "Error: Invalid Token Element no.%d:\t%s\n", i, s[i]);
                                return(1);
                        }
                }
                else
                {
                        fprintf(stderr, "Error: Invalid Token Element no.%d:\t%s\n", i, s[i]);
                        return(1);
                }
                
        }
        
        if(pop(&stck,&a))
        {
                fprintf(stderr, "Error: Invalid number of operator/opperands\n");
                return(1);
        }
        fprintf(stdout,"%f\n", a); /* Send the result to STDOUT */
        *ret = a;
        return 0;
}