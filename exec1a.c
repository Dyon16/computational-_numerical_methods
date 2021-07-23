#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float xf)
{
    //x = 4;
    printf ("xf: %f\n", xf);

    float seno, y;

    seno = sin(xf);
    y = (xf - (seno * seno) - 4);
    //printf("f: %f\n", y);

    return y;
}

float f1(float xf1)
{
    //x = 4;

    //printf ("xf1: %f\n", xf1);
    float sen, y;

    sen = (- sin(2*xf1));
    y = (1 - (sen));

    //printf("y = %f\n", y);

    return y;
}

/*float f2(float x)
{
    //printf ("x: %f", x);
    x = 3;

    float coss, y;

    coss = cos(2*x);
    y = (-2 * coss);

    printf("y = %f", y);

    return y;
}*/

void bisection(float a, float b, float p)
{
    /*printf("a : %0.10f\n", a);
    printf("b : %0.10f\n", b);
    printf("a - b : %.10f\n", fabs(a - b));
    printf("p: %0.10f\n", p);*/

    int k = 0;
    float xb, calcf, calcabs;

    while ((fabs(a - b)) > p)
    {
        k++;

        /*printf("k: %d\n", k);
        printf("a - b : %.10f\n", fabs(a - b));*/

        xb = (a + b) / 2;

        calcf = f(a) * f(xb);

        if(calcf > 0)
        {
            a = xb;
        }
        else
        {
            b = xb;
        }
    }
    
    printf("- Bisection -\n\n");
    printf("Approximate Root = %0.9f\n", xb);
    printf("Interactions = %d\n\n", k);
}

void MIL(float x0, float p)
{
    int k;
    float xm;

    xm = f(x0);
    k = 1;

    /*printf("x0: %f\n", x0);
    printf("k: %d\n", k);
    printf("x: %f\n", x);*/

    while((fabs(xm - x0))  > p)
    {
        k++;
        x0 = xm;
        xm = f(x0);
    }

    printf("- MIL -\n\n");
    printf("Approximate Root = %0.9f\n", xm);
    printf("Interactions = %d\n", k);
}

void newton_raphson(float x0 , float p)
{
    int k = 1;

    //printf("x0: %f\n", x0);

    float xn = x0 - (f(x0) / f1(x0));
    /*printf("x: %f\n", xn);
    printf("x0: %f\n", x0);*/

    while (fabs(xn - x0) > p)
    {
        k++;
        //printf("k: %d\n", k);
        x0 = xn;
        //printf("x0: %f\n", x0);
        xn = x0 - (f(x0)/f1(x0));
        //printf("x: %f\n", x);
        /*if (k < 100)
        {
            printf("x%d: %f\n", k, xn);
            printf("x0%d: %f\n", k, x0);
        }*/
    }
    
    printf("- NEWTON RAPHSON -\n\n");
    printf("Approximate Root = %0.9f\n", xn);
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

    /*printf("a = ");
    scanf("%f", &a);

    printf("b = ");
    scanf("%f", &b);

    printf("c = ");
    scanf("%f", &c);
    
    printf("p = ");
    scanf("%f", &p);*/

    a = 4;
    b = 5;
    c = 4;
    p = 1E-6;

    printf("\n");

    bisection(a, b, p);
    MIL(c, p);
    newton_raphson(c, p);
} 