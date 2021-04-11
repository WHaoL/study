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

/* START: fig7_10.txt */
        /* Lpos = start of left half, Rpos = start of right half */

        void
        Merge( ElementType A[ ], ElementType TmpArray[ ],
                        int Lpos, int Rpos, int RightEnd )
        {
            int i, LeftEnd, NumElements, TmpPos;

            LeftEnd = Rpos - 1;
            TmpPos = Lpos;
            NumElements = RightEnd - Lpos + 1;

            /* main loop */
            while( Lpos <= LeftEnd && Rpos <= RightEnd )
                if( A[ Lpos ] <= A[ Rpos ] )
                    TmpArray[ TmpPos++ ] = A[ Lpos++ ];
                else
                    TmpArray[ TmpPos++ ] = A[ Rpos++ ];

            while( Lpos <= LeftEnd )  /* Copy rest of first half */
                TmpArray[ TmpPos++ ] = A[ Lpos++ ];
            while( Rpos <= RightEnd ) /* Copy rest of second half */
                TmpArray[ TmpPos++ ] = A[ Rpos++ ];

            /* Copy TmpArray back */
            for( i = 0; i < NumElements; i++, RightEnd-- )
                A[ RightEnd ] = TmpArray[ RightEnd ];
        }
/* END */

/* START: fig7_9.txt */
        void
        MSort( ElementType A[ ], ElementType TmpArray[ ],
                        int Left, int Right )
        {
            int Center;

            if( Left < Right )
            {
                Center = ( Left + Right ) / 2;
                MSort( A, TmpArray, Left, Center );
                MSort( A, TmpArray, Center + 1, Right );
                Merge( A, TmpArray, Left, Center + 1, Right );
            }
        }

        void
        Mergesort( ElementType A[ ], int N )
        {
            ElementType *TmpArray;

            TmpArray = (ElementType *)malloc( N * sizeof( ElementType ) );
            if( TmpArray != NULL )
            {
                MSort( A, TmpArray, 0, N - 1 );
                free( TmpArray );
            }
            else
                FatalError( "No space for tmp array!!!" );
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
                Mergesort( Arr1, MaxSize );
                Checksort( Arr1, MaxSize );
            }

            return 0;
        }