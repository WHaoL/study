/* This code doesn't really do much */
/* Thus I haven't bothered testing it */

#include "fatal.h"

#define MaxDegree 100

static int
Max( int A, int B )
{
    return A > B ? A : B;
}

/* START: fig3_18.txt */ // 多项式
        typedef struct
        {
            int CoeffArray[ MaxDegree + 1 ]; //多项式各项的系数
            int HighPower;                   //多项式的最大的指数
        } *Polynomial;
/* END */

/* START: fig3_19.txt */ // 将多项式初始化为零的过程
        void
        ZeroPolynomial( Polynomial Poly )
        {
            int i;

            for( i = 0; i <= MaxDegree; i++ )
                Poly->CoeffArray[ i ] = 0;
            Poly->HighPower = 0;
        }
/* END */

/* START: fig3_20.txt */ // 两个多项式相加的过程
        void
        AddPolynomial( const Polynomial Poly1, const Polynomial Poly2,
                       Polynomial PolySum )
        {
            int i;

            ZeroPolynomial( PolySum );
            PolySum->HighPower = Max( Poly1->HighPower,
                                      Poly2->HighPower );

            for( i = PolySum->HighPower; i >= 0; i-- )
                PolySum->CoeffArray[ i ] = Poly1->CoeffArray[ i ]
                                               + Poly2->CoeffArray[ i ];
        }
/* END */

/* START: fig3_21.txt */ // 两个多项式相乘的过程
        void
        MultPolynomial( const Polynomial Poly1,
                        const Polynomial Poly2, Polynomial PolyProd )
        {
            int i, j;

            ZeroPolynomial( PolyProd );
            PolyProd->HighPower = Poly1->HighPower + Poly2->HighPower;

            if( PolyProd->HighPower > MaxDegree )
                Error( "Exceeded array size" );
            else
                for( i = 0; i <= Poly1->HighPower; i++ )
                    for( j = 0; j <= Poly2->HighPower; j++ )
                        PolyProd->CoeffArray[ i + j ] +=
                                Poly1->CoeffArray[ i ] *
                                Poly2->CoeffArray[ j ];
        }
/* END */

#if 0
/* START: fig3_23.txt */
        typedef struct Node *PtrToNode;

        struct Node
        {
            int Coefficient;
            int Exponent;
            PtrToNode Next;
        };

        typedef PtrToNode Polynomial;  /* Nodes sorted by exponent */
/* END */
#endif

void
PrintPoly( const Polynomial Q )
{
    int i;

    for( i = Q->HighPower; i > 0; i-- )
        printf( "%dx^%d + ", Q->CoeffArray[ i ], i );
    printf( "%d\n", Q->CoeffArray[ 0 ] );
}

int main( )
{
    Polynomial P, Q;

    P = malloc( sizeof( *P ) );
    Q = malloc( sizeof( *Q ) );

    P->HighPower = 1; P->CoeffArray[ 0 ] = 1; P->CoeffArray[ 1 ] = 1;
    PrintPoly(P);// 1x^1 + 1

    MultPolynomial(P, P, Q);
    PrintPoly(Q);//1x^2 + 2x^1 + 1

    MultPolynomial(Q, Q, P);
    PrintPoly(P);//1x^4 + 4x^3 + 6x^2 + 4x^1 + 1

    AddPolynomial(P, P, Q);
    PrintPoly(Q);//2x^4 + 8x^3 + 12x^2 + 8x^1 + 2

    return 0;
}
