        /* This file contains a collection of sorting routines */

        #include <stdlib.h>
        #include "fatal.h"

        typedef int ElementType;

        void
        Swap( ElementType *Lhs, ElementType *Rhs )
        {
            ElementType Tmp = *Lhs;
            *Lhs = *Rhs;
            *Rhs = Tmp;
        }

/* START: fig7_4.txt */
        void
        Shellsort( ElementType A[ ], int N )
        {
            int i, j, Increment;
            ElementType Tmp;

/* 1*/      for( Increment = N / 2; Increment > 0; Increment /= 2 )
/* 2*/          for( i = Increment; i < N; i++ )
                {
/* 3*/              Tmp = A[ i ];
/* 4*/              for( j = i; j >= Increment; j -= Increment )
/* 5*/                  if( Tmp < A[ j - Increment ] )
/* 6*/                      A[ j ] = A[ j - Increment ];
                        else
/* 7*/                      break;
/* 8*/              A[ j ] = Tmp;
                }
        }
/* END */

        /* ROUTINES TO TEST THE SORTS */

        void
        Permute( ElementType A[ ], int N )
        {
            int i;

            for( i = 0; i < N; i++ )
                A[ i ] = i;
            for( i = 1; i < N; i++ )
                Swap( &A[ i ], &A[ rand( ) % ( i + 1 ) ] );
        }

        void
        Checksort( ElementType A[ ], int N )
        {
            int i;
            for( i = 0; i < N; i++ )
                if( A[ i ] != i )
                    printf( "Sort fails: %d %d\n", i, A[ i ] );
            printf( "Check completed\n" );
        }

        void
        Copy( ElementType Lhs[ ], const ElementType Rhs[ ], int N )
        {
            int i;
            for( i = 0; i < N; i++ )
                Lhs[ i ] = Rhs[ i ];
        }

        #define MaxSize 7000
        int Arr1[ MaxSize ];
        int Arr2[ MaxSize ];

        int main( )
        {
            int i;

            for( i = 0; i < 10; i++ )
            {
                Permute( Arr2, MaxSize );
                Copy( Arr1, Arr2, MaxSize );
                Shellsort( Arr1, MaxSize );
                Checksort( Arr1, MaxSize );
            }

            return 0;
        }