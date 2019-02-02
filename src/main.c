/*  Copyright (c) 2019, MilanMijatov
*/
#include "stack.h"
#include "operations.h"
#include "rpn.h"

int main(int argc, char *argv[])
{
        //char *s[] = {"15","4","+"};
        if(rpn(argc, argv))
                exit(EXIT_FAILURE);
        return 0;
}