#include <stdio.h>
#define CubicAlgorithm 
//gcc -DCubicAlgorithm fig2_5_MaxSubsequenceSum.c -o execute


#ifdef CubicAlgorithm

/* START: fig2_5.txt P21 */
        int
        MaxSubsequenceSum( const int A[ ], int N )
        {
            int ThisSum, MaxSum, i, j, k;

/* 1*/      MaxSum = 0;
/* 2*/      for( i = 0; i < N; i++ )
/* 3*/          for( j = i; j < N; j++ )
                {
/* 4*/              ThisSum = 0;
/* 5*/              for( k = i; k <= j; k++ )
/* 6*/                  ThisSum += A[ k ];

/* 7*/              if( ThisSum > MaxSum )
/* 8*/                  MaxSum = ThisSum;
                }
/* 9*/      return MaxSum;
        }
/* END */

#endif

main( )
{
    static int A[ ] = { 4, -3, 5, -2, -1, 2, 6, -2 };

    printf( "Maxsum = %d\n",
            MaxSubsequenceSum( A, sizeof( A ) / sizeof( A[ 0 ] ) ) );
    return 0;
}
