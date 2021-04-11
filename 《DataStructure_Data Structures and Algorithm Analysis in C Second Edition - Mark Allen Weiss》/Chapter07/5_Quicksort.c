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


/* START: fig7_13.txt */
        /* Return median of Left, Center, and Right */
        /* Order these and hide the pivot */

        ElementType
        Median3( ElementType A[ ], int Left, int Right )
        {
            int Center = ( Left + Right ) / 2;

            if( A[ Left ] > A[ Center ] )
                Swap( &A[ Left ], &A[ Center ] );
            if( A[ Left ] > A[ Right ] )
                Swap( &A[ Left ], &A[ Right ] );
            if( A[ Center ] > A[ Right ] )
                Swap( &A[ Center ], &A[ Right ] );

            /* Invariant: A[ Left ] <= A[ Center ] <= A[ Right ] */

            Swap( &A[ Center ], &A[ Right - 1 ] );  /* Hide pivot */
            return A[ Right - 1 ];                /* Return pivot */
        }
/* END */

/* START: fig7_14.txt */
        #define Cutoff ( 3 )

        void
        Qsort( ElementType A[ ], int Left, int Right )
        {
            int i, j;
            ElementType Pivot;

/* 1*/      if( Left + Cutoff <= Right )
            {
/* 2*/          Pivot = Median3( A, Left, Right );
/* 3*/          i = Left; j = Right - 1;
/* 4*/          for( ; ; )
                {
/* 5*/              while( A[ ++i ] < Pivot ){ }
/* 6*/              while( A[ --j ] > Pivot ){ }
/* 7*/              if( i < j )
/* 8*/                  Swap( &A[ i ], &A[ j ] );
                    else
/* 9*/                  break;
                }
/*10*/          Swap( &A[ i ], &A[ Right - 1 ] );  /* Restore pivot */

/*11*/          Qsort( A, Left, i - 1 );
/*12*/          Qsort( A, i + 1, Right );
            }
            else  /* Do an insertion sort on the subarray */
/*13*/          InsertionSort( A + Left, Right - Left + 1 );
        }
/* END */

        /* This code doesn't work; it's Figure 7.15. */
#if 0
/* START: fig7_15.txt */
/* 3*/          i = Left + 1; j = Right - 2;
/* 4*/          for( ; ; )
                {
/* 5*/              while( A[ i ] < Pivot ) i++;
/* 6*/              while( A[ j ] > Pivot ) j--;
/* 7*/              if( i < j )
/* 8*/                  Swap( &A[ i ], &A[ j ] );
                    else
/* 9*/                  break;
                }
/* END */
#endif

/* START: fig7_12.txt */
        void
        Quicksort( ElementType A[ ], int N )
        {
            Qsort( A, 0, N - 1 );
        }
/* END */

/* START: fig7_16.txt */
        /* Places the kth smallest element in the kth position */
        /* Because arrays start at 0, this will be index k-1 */
        void
        Qselect( ElementType A[ ], int k, int Left, int Right )
        {
            int i, j;
            ElementType Pivot;

/* 1*/      if( Left + Cutoff <= Right )
            {
/* 2*/          Pivot = Median3( A, Left, Right );
/* 3*/          i = Left; j = Right - 1;
/* 4*/          for( ; ; )
                {
/* 5*/              while( A[ ++i ] < Pivot ){ }
/* 6*/              while( A[ --j ] > Pivot ){ }
/* 7*/              if( i < j )
/* 8*/                  Swap( &A[ i ], &A[ j ] );
                    else
/* 9*/                  break;
                }
/*10*/          Swap( &A[ i ], &A[ Right - 1 ] );  /* Restore pivot */

/*11*/          if( k <= i )
/*12*/              Qselect( A, k, Left, i - 1 );
/*13*/          else if( k > i + 1 )
/*14*/              Qselect( A, k, i + 1, Right );
            }
            else  /* Do an insertion sort on the subarray */
/*15*/          InsertionSort( A + Left, Right - Left + 1 );
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
                Quicksort( Arr1, MaxSize );
                Checksort( Arr1, MaxSize );

                Copy( Arr1, Arr2, MaxSize );
                Qselect( Arr1, MaxSize / 2 + 1 + i, 0, MaxSize - 1 );
                if( Arr1[ MaxSize / 2 + i ] != MaxSize / 2 + i )
                    printf( "Select error: %d %d\n", MaxSize / 2 + i ,
                                            Arr1[ MaxSize / 2 + i ] );
                else
                    printf( "Select works\n" );
            }

            return 0;
        }