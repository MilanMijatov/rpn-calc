#include "../rpn/rpn.h"

__declspec(dllexport) char* rpn_export(int cnt ,char** s)
{
        //printf("%s\n",str[0]);
        char *str = malloc(1000*sizeof(char));
        double ret;
        if(cnt = rpn(cnt, s, &ret, 0) == 1)
                sprintf(str, "Invalid input,");
        else if(cnt == 2)
                sprintf(str, "Invalid input,");
        else sprintf(str, "%f", ret);
        return str;
}//cl /LD rpn.c /rpnc.dll