#include <stdio.h> // P8 图1-3 无终止递归函数

/* START: fig1_3.txt */
        int
        Bad( unsigned int N )
        {
/* 1*/      if( N == 0 )
/* 2*/          return 0;
            else
/* 3*/          return Bad( N / 3 + 1 ) + N - 1;
        }
/* END */

main( )
{
    printf( "Bad is infinite recursion\n" );
    return 0;
}
