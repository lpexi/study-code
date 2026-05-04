#include <stdio.h>

int main()
    {
        float num1, num2, result = 0;
        char operation;

        printf("Start Clacukator \n");
        printf("This clalculator can do '+' '-' '*' '/' operations with two diget numbers \n");

        //Get and verify number 1 
        printf("Please enter the first number: ");
            if (scanf("%f", &num1) != 1);
            {
                printf("Invalide input \n");
                return(1);
            }

        //Get and verify number 2 
        printf("Please enter the first number: ");
            if (scanf("%f", &num2) != 1);
            {
                printf("Invalide input \n");
                return(1);
            }
             
    }