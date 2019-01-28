/*  Copyright (c) 2019, MilanMijatov
*/
#include <stdlib.h>

struct stack {
        struct node *nxt;
};
struct node {
        double a;
        struct node *nxt;
};

int push(struct stack *stck, double a)
{
        struct node *nxt = malloc(sizeof(struct node));
        nxt->a = a;
        nxt->nxt = stck->nxt;
        stck->nxt = nxt;
        return 0;
}

int pop(struct stack *stck, double *a)
{
        if(stck->nxt)
        {
                struct node *nde = stck->nxt;
                stck->nxt = stck->nxt->nxt;
                *a = nde->a;
                free(nde);
                return 0;
        }
        return 1;
}