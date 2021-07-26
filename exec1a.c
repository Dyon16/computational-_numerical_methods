#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define e 2.718

void bisection(float a, float b, float p)
{
    int k = 0;
    float x, ya, yx, senoa, senox, cosa, cosx;

    while ((fabs(a - b)) > p)
    {
        k++;
        x = (a + b) / 2;

        /*printf("a: %f\n", a);
        printf("b: %f\n", b);*/

        //Questao 1A
        /*senoa = sin(a);
        ya = (a - (senoa * senoa) - 4);
        senox = sin(x);
        yx = (x - (senox * senox) - 4);*/

        //Questao 1B
        /*senoa = atan(a);
        ya = senoa + 2*sqrt(a) - 2;
        senox = atan(x);
        yx = senox + 2*sqrt(x) - 2;*/

        //Questão 2
        /*senoa = sin(a);
        cosa = cos(a);
        ya = (((senoa * senoa) - (cosa * cosa)) / (exp(-a) - 1));
        senox = sin(x);
        cosx = cos(x);
        yx = (((senox * senox) - (cosx * cosx)) / (exp(-x) - 1));*/

        //Questão 3
        /*ya = (pow(a,4)) + (2*(pow(a,3))) - (13*(pow(a,2))) - ((14)*a) + 24;
        yx = (pow(x,4)) + (2*(pow(x, 3))) - (13*(pow(x, 2))) - ((14)*x) + 24;*/

        //Questão 4a
        /*ya = ((2.2)*(a)) + (4.7) - ((0.4)*(pow(a, 2)));
        yx = ((2.2)*(x)) + (4.7) - ((0.4)*(pow(x, 2)));*/

        //Questão 4b
        /*ya = ((7*a) - ((5)*(pow(a, 2))) + ((6)*(pow(a, 3))) - (2));
        yx = ((7*x) - ((5)*(pow(x, 2))) + ((6)*(pow(x, 3))) - (2));*/

        //Questão 4c
        /*ya = ((0.9 - (0.4*a))/a);
        yx = ((0.9 - (0.4*x))/x);*/

        //Questão 4d
        senoa = cosh(a);
        ya = (senoa - ((2)*(pow(e, -0.3 * a))));
        senox = cosh(x);
        yx = (senox - ((2)*(pow(e, -0.3 * x))));

        if((ya * yx) > 0)
        {
            a = x;
        }
        else
        {
            b = x;
        }
    }
    
    printf("- Bisection -\n\n");
    printf("Approximate Root = %0.9f\n", x);
    printf("Interactions = %d\n\n", k);
}

void MIL(float x0, float p)
{
    int k;
    float x, seno, y;

    k = 1;

    seno = sin(x0);
    x = (x0 - (seno * seno) - 4);

    while((fabs(x - x0))  > p)
    {
        k++;
        x0 = x;
        
        seno = sin(x0);
        x = (x0 - (seno * seno) - 4);
    }

    printf("- MIL -\n\n");
    printf("Approximate Root = %0.9f\n", x);
    printf("Interactions = %d\n\n", k);
}

void newton_raphson(float x0 , float p)
{
    int k = 1; 
    float x, senoa, senob, ya, yb;

    //Questao 1B
    /*senoa = sin(x0);
    ya = (x0 - (senoa * senoa) - 4);

    float x0n = x0 * 2;
    senob = (sin(x0n));
    yb = (1 - (senob));*/

    /*senoa = atan(x0);
    ya = senoa + (2*sqrt(x0)) - 2;
    yb = (1 / (x0 + 1)) + (1/(sqrt(x0)));*/

    //Questão 4a
    /*ya = (2.2*x0) + (4.7) - ((0.4)*(pow(x0,2)));
    yb = (2.2) - (0.8*x);*/

    //Questão 4b
    /*ya = ((7*x0) - ((5)*(pow(x0, 2))) + ((6)*(pow(x0, 3))) - (2));
    yb = (((18)*(pow(x0, 2))) - (10*x0) + (7));*/

    //Questão 4c
    /*ya = ((0.9 - (0.4*x0))/x0);
    yb = (0 - ((0.9)/(pow(x0, 2))));*/

    //Questão 4d
    senoa = cosh(x0);
    ya = (senoa - ((2)*(pow(e, -0.3 * x0))));
    senob = sinh(x0);
    yb = (senob + (0.6*(pow(e, -0.3 * x0))));

    x = x0 - (ya/yb);

    while (fabs(x - x0) > p)
    {
        k++;
        x0 = x;

        /*senoa = atan(x0);
        ya = senoa + (2*sqrt(x0)) - 2;
        yb = (1 / (x0+1)) + (1/(sqrt(x0)));*/

        //Questão 4a
        /*ya = (2.2*x0) + (4.7) - ((0.4)*(pow(x0,2)));
        yb = (2.2) - (0.8*x);*/

        //Questão 4b
        /*ya = ((7*x0) - ((5)*(pow(x0, 2))) + ((6)*(pow(x0, 3))) - (2));
        yb = (((18)*(pow(x0, 2))) - (10*x0) + (7));*/

        //Questão 4c
        /*ya = ((0.9 - (0.4*x0))/x0);
        yb = (0 - ((0.9)/(pow(x0, 2))));*/

        //Questão 4d
        senoa = cosh(x0);
        ya = (senoa - ((2)*(pow(e, -0.3 * x0))));
        senob = sinh(x0);
        yb = (senob + (0.6*(pow(e, -0.3 * x0))));

        x = x0 - (ya/yb);
    }
    
    printf("- NEWTON RAPHSON -\n\n");
    printf("Approximate Root = %0.9f\n", x);
    printf("Interactions = %d\n", k);
}


void main()
{
    float a, b, p, c;
    int choice, k;

    /*printf("Define the method for use: \n\n");
    printf("1 - Bisection;\n");
    printf("2 - MIL; \n");
    printf("3 - Newton Raphson.\n");
    scanf("%d", &choice);*/

    printf("Define the variables. \n\n");

    printf("a = ");
    scanf("%f", &a);

    printf("b = ");
    scanf("%f", &b);

    printf("c = ");
    scanf("%f", &c);
    
    printf("p = ");
    scanf("%f", &p);

    /*a = 7;
    b = 8;
    c = 6;
    p = 1E-3;*/

    printf("\n");

    bisection(a, b, p);
    MIL(c, p);
    newton_raphson(c, p);
} 