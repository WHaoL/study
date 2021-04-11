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

        
/* START: fig7_2.txt */
        void
        InsertionSort( ElementType A[ ], int N )
        {
            int j, P;
            ElementType Tmp;

/* 1*/      for( P = 1; P < N; P++ )
            {
/* 2*/          Tmp = A[ P ];
/* 3*/          for( j = P; j > 0 && A[ j - 1 ] > Tmp; j-- )
/* 4*/              A[ j ] = A[ j - 1 ];
/* 5*/          A[ j ] = Tmp;
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
                InsertionSort( Arr1, MaxSize );
                Checksort( Arr1, MaxSize );
            }

            return 0;
        }