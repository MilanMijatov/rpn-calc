/*  Copyright (c) 2019, MilanMijatov
*/
#include "../rpn/rpn.h"

int main(int argc, char *argv[])
{
        char *err[] = {"Error: Invalid input on token: %s\n", 
                        "Error: Invalid number of operator/opperands\n"};
        //char *s[] = {"15","4","+"};
        double ret = 0;
        if(argc == 1)
                fprintf(stdout, "%s", "Standard input is in the form of ascii tokens delimited by spaces. For example:\nrpn-calc 15 5 +\n");
        else if(argc = rpn(argc, argv, &ret, 1))
        {
                fprintf(stderr, "%s", err[argc - 1]);
                exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
}