#include <stdio.h>
#include "AnnotationConvert.h"

int main()
{
    FILE *pR = fopen(InputFileName, "r");
    if (NULL == pR)
    {
        perror("fopen file for read!");
        exit(EXIT_FAILURE);
    }
    FILE *pW = fopen(OutputFileName, "w");
    if (NULL == pW)
    {
        fclose(pR);
        perror("fopen file for write!");
        exit(EXIT_FAILURE);
    }
    printf("Start conversion!\n");
    Convert(pR, pW);
    printf("End of conversion!\n");

    fclose(pR);
    fclose(pW);
    return 0;
}
