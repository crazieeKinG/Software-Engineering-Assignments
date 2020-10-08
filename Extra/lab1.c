#include<stdio.h>

int SumOfEven(int listOfNumber[],int evenList[])
{
    int sum = 0;
    for(int i = 0; i < 10; i++)
    {
        if(listOfNumber[i] % 2 != 0)
        {
            sum += listOfNumber[i];
            evenList[i] = listOfNumber[i];
        }
        else
            evenList[i] = 0;
    }
    return sum;
}

int SumOfOdd(int listOfNumber[],int oddList[])
{
    int sum = 0;
    for(int i = 0; i < 10; i++)
    {
        if(listOfNumber[i] % 2 != 0)
        {
            sum += listOfNumber[i];
            oddList[i] = listOfNumber[i];
        }
        else
            oddList[i] = 0;
    }
    return sum;
}

void ValidateEvenSum(int sumedValue, int expectedValueList[])
{
    int sum = SumOfArray(expectedValueList);
    if(sumedValue == sum)
        printf("\nSum of even number is valid");
    else
        printf("\nSum of even number is not valid");
}

void ValidateOddSum(int sumedValue, int expectedValueList[])
{
    int sum = SumOfArray(expectedValueList);
    if(sumedValue == sum)
        printf("\nSum of odd number is valid");
    else
        printf("\nSum of odd number is not valid");
}

int SumOfArray(int numberList[])
{
    int sum = 0;
    for(int i = 0; i < 10; i++)
        sum += numberList[i];
    return sum;
}

void main()
{
    int numberList[10]={10,9,8,7,6,5,4,3,2,1},evenList[10],oddList[10];
    int evenSum = SumOfEven(numberList,evenList);
    int oddSum = SumOfOdd(numberList,oddList);
    printf("Sum of even number = %d",evenSum);
    printf("\nSum of odd number = %d",oddSum);
    ValidateEvenSum(evenSum,evenList);
    ValidateOddSum(oddSum,oddList);
}
