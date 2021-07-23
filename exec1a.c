#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void bisection(float a, float b, float p)
{
    int k = 0;
    float x, ya, yx, senoa, senox;

    while ((fabs(a - b)) > p)
    {
        k++;
        x = (a + b) / 2;

        senoa = sin(a);
        ya = (a - (senoa * senoa) - 4);
        senox = sin(x);
        yx = (x - (senox * senox) - 4);

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

    //printf("x0: %f\n", x0);

    senoa = sin(x0);
    ya = (x0 - (senoa * senoa) - 4);

    float x0n = x0 * 2;
    senob = (sin(x0n));
    yb = (1 - (senob));

    x = x0 - (ya/yb);

    while (fabs(x - x0) > p)
    {
        k++;
        x0 = x;

        senoa = sin(x0);
        ya = (x0 - (senoa * senoa) - 4);

        x0n = x0 * 2;
        senob = (sin(x0n));
        yb = (1 - (senob));

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