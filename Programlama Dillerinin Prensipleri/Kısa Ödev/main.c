#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *Lines;
int SumOfDigits(int value);
void LuhnFunc(char *number);
void ReadFile(char *file_name);
char *UnnecessaryCleaner(char *array, int arrayLenght);
int CalculateNumbers(char *justNumbers, int justNumbersLenght);
int main(void)
{

    ReadFile("inputs.txt");
    
    int count = 0;
}
void ReadFile(char *file_name)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(file_name, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    int lineCount = 1;
    while ((read = getline(&line, &len, fp)) != -1)
    {
        LuhnFunc(line);
    }

    fclose(fp);
    if (line)
        free(line);

    exit(EXIT_SUCCESS);
}
void LuhnFunc(char *numbers)
{

    if (numbers[strlen(numbers) - 1] == '\n')
    {
        numbers[strlen(numbers) - 1] = '\0';
    }

    int arrayLenght = strlen(numbers);
    char *justNumbers = UnnecessaryCleaner(numbers, arrayLenght);
    int justNumbersLenght = strlen(justNumbers);
    int totalValue = CalculateNumbers(justNumbers, justNumbersLenght);
    int result = totalValue % 10;
    printf("%s", numbers);
    printf(" - ");
    if (result % 10 == 0)
    {
        printf("Gecerli\n");
    }
    else
    {
        printf("Gecersiz\n");
    }
}
int CalculateNumbers(char *justNumbers, int justNumbersLenght)
{
    int total = 0;
    for (int i = 1; i < justNumbersLenght - 1; i += 2)
    {

        int value = (justNumbers[i] - 48) * 2;
        if (value > 9)
        {
            value = SumOfDigits(value);
            ;
        }
        total += value;
        // printf("Val: %d\t\tDef: %d\t\tIndex: %d\t\tLenght %d\n",value, (justNumbers[i] - 48),i,justNumbersLenght);
    }

    for (int i = 0; i < justNumbersLenght - 1; i += 2)
    {
        total += justNumbers[i] - 48;
        // printf("Def: %d\t\tIndex: %d\t\tLenght: %d\n",(justNumbers[i] - 48),i,justNumbersLenght);
    }

    return total;
}
int SumOfDigits(int value)
{
    int bigStep = value / 10;
    int smallStep = value % 10;
    return bigStep + smallStep;
}
char *UnnecessaryCleaner(char *array, int arrayLenght)
{

    char justNumbers[arrayLenght];

    int m = 0;
    for (int i = arrayLenght - 1; i >= 0; i--)
    {
        int value = array[i] - 48;
        if (value > -1 && value < 10)
        {
            justNumbers[m] = array[i];
            m++;
        }
    }
    char *str = strcpy(str, justNumbers);
    return str;
}
