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


/* START: fig7_8.txt */

        #define LeftChild( i )  ( 2 * ( i ) + 1 )

        void
        PercDown( ElementType A[ ], int i, int N )
        {
            int Child;
            ElementType Tmp;

/* 1*/      for( Tmp = A[ i ]; LeftChild( i ) < N; i = Child )
            {
/* 2*/          Child = LeftChild( i );
/* 3*/          if( Child != N - 1 && A[ Child + 1 ] > A[ Child ] )
/* 4*/              Child++;
/* 5*/          if( Tmp < A[ Child ] )
/* 6*/              A[ i ] = A[ Child ];
                else
/* 7*/              break;
            }
/* 8*/      A[ i ] =Tmp;
        }

        void
        Heapsort( ElementType A[ ], int N )
        {
            int i;

/* 1*/      for( i = N / 2; i >= 0; i-- )  /* BuildHeap */
/* 2*/          PercDown( A, i, N );
/* 3*/      for( i = N - 1; i > 0; i-- )
            {
/* 4*/          Swap( &A[ 0 ], &A[ i ] );  /* DeleteMax */
/* 5*/          PercDown( A, 0, i );
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
                Heapsort( Arr1, MaxSize );
                Checksort( Arr1, MaxSize );
            }

            return 0;
        }