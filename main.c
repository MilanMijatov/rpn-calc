#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"
#include "operations.h"

int rpn(int, char**);

int main(int argc, char *argv[])
{
        //char *s[] = {"15","4","+"};
        rpn(argc ,argv);
        return 0;
}

int rpn(int cnt, char *s[])
{
        int i;
        struct stack stck;
        double (*op) (double, double) = NULL, a, b;

        for(i = 0; i < cnt; i++)
        {
                switch(*s[i])
                {
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
                {
                        pop(&stck,&b);
                        pop(&stck,&a);
                        push(&stck, op(a, b));
                }
                else
                {
                        push(&stck, strtod(s[i], NULL));
                }
        }
        printf("%f\n", stck.nxt->a);
    return 0;
}