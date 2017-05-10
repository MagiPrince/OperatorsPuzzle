#include <stdlib.h>
#include <stdio.h>
#define NB_RESEARCHED 6
#define NB_START 2
#define NB_END 6
#define ARRAY_SIZE 5
#define NB_OPERATORS 4

void instantiateArray(int nbArray[])
{
    int counter = NB_START;

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        nbArray[i] = counter;
        counter++;
    }
}

int add(int a, int b)
{
    return a + b;
}

int substract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    if(b == 0)
    {
        return -1;
    }

    return a / b;
}


int main(int argc, char *argv[])
{
    int nbArray[ARRAY_SIZE] = {0};
    int (*operatorsArray[NB_OPERATORS])(int a, int b) = {NULL};
    int operatorsPriority[NB_OPERATORS] = {0};
    char operatorList[NB_OPERATORS] = {'+','-','*','/'};

    //Define each operator for each place in the array
    operatorsArray[0] = &add;
    operatorsArray[1] = &substract;
    operatorsArray[2] = &multiply;
    operatorsArray[3] = &divide;

    //Define the priority of the operation
    operatorsPriority[0] = 0;
    operatorsPriority[1] = 0;
    operatorsPriority[2] = 1;
    operatorsPriority[3] = 1;

    instantiateArray(nbArray);

    //Do the calculs to find the researched number

     for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        for (int j = 0; j < NB_OPERATORS; ++j)
        {
            for (int k = 0; k < NB_OPERATORS; ++k)
            {
                int result = 0;

                if(operatorsPriority[j] > operatorsPriority[k])
                {
                    result = operatorsArray[j](nbArray[i],nbArray[i]);
                    result = operatorsArray[k](result, nbArray[i]);

                    if(result == NB_RESEARCHED)
                    {
                        printf("%d %c %d %c %d = %d\n", nbArray[i], operatorList[j], nbArray[i], operatorList[k], nbArray[i], NB_RESEARCHED);
                    }
                }
                else if(operatorsPriority[j] < operatorsPriority[k])
                {
                    result = operatorsArray[k](nbArray[i],nbArray[i]);
                    result = operatorsArray[j](nbArray[i], result);

                    if(result == NB_RESEARCHED)
                    {
                        printf("%d %c %d %c %d = %d\n", nbArray[i], operatorList[j], nbArray[i], operatorList[k], nbArray[i], NB_RESEARCHED);
                    }
                }
                else
                {
                    result = operatorsArray[j](nbArray[i],nbArray[i]);
                    result = operatorsArray[k](result, nbArray[i]);

                    if(result == NB_RESEARCHED)
                    {
                        printf("%d %c %d %c %d = %d\n", nbArray[i], operatorList[j], nbArray[i], operatorList[k], nbArray[i], NB_RESEARCHED);
                    }
                }
            }
        }
    }    


    return 0;
}