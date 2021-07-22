#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x) //4,875
{
    float y = (x - (sin(x) * sin(x)) - 4);
    return y;
}

float bisection(float a, float b, float p)
{
    printf("a : %f\n", a);
    printf("b : %f\n", b);
    printf("a - b : %f\n", abs(a - b));
    printf("p: %0.9f\n", p);

    int k = 0;
    float x;

    while ((fabs(a - b)) > p)
    {
        k++;
        printf("k: %d\n", k);
        printf("a - b : %f\n", abs(a - b));

        x = (a + b) / 2;

        int calc = f(a) * f(x);

        if(calc > 0)
        {
            a = x;
        }
        else
        {
            b = x;
        }
    }
    printf("x: %f\n", x);
    printf("k: %d\n", k);
    return x;
}

/*float MIL(a , b, p)
{
    
}

float Newton_Raphson(a , b, p)
{
    
}*/

void main()
{
    float a, b, p, c;
    int choice, k;

    printf("Define the method for use: \n\n");
    printf("1 - Bisection;\n");
    printf("2 - MIL; \n");
    printf("3 - Newton Raphson.\n");
    scanf("%d", &choice);

    printf("Define the variables. \n\n");

    printf("a = ");
    scanf("%f", &a);

    printf("b = ");
    scanf("%f", &b);
    
    printf("p = ");
    scanf("%f", &p);

    switch(choice)
    {
        case 1:
            bisection(a, b, p);
            break;
        case 2:
            bisection(a, b, p);
            break;
        case 3:
            bisection(a, b, p);
            break;
        default:
            printf("Invalid. Choice the options 1, 2 or 3.\n");
    }

    c = bisection(a, b, p);
    printf("Approximate Root = %0.9f\n", c);
    //printf("Interactions = %d\n", k);
} 