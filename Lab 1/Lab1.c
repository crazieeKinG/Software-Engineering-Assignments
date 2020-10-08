#include<stdio.h>
#include<assert.h>
#include<math.h>
float CalculateMean(int dataSet[], int frequency)
{
    float sum = 0;
    for(int i = 0; i < frequency; i++)
        sum += dataSet[i];
    return sum / frequency;
}

float CalculateSD(int dataSet[], int frequency, float mean)
{
    float sum = 0;
    for(int i = 0; i < frequency; i++)
        sum += pow((dataSet[i] - mean),2);
    return sqrt(sum/frequency);
}
void CalculateData(int dataSet[], int dataSetLength, float expectedMean, float expectedSD)
{
    float mean = CalculateMean(dataSet,dataSetLength);
    float sd = CalculateSD(dataSet,dataSetLength,mean);
    printf("\nMean: %f",mean);
    printf("\nStandard Deviation: %f",sd);
    assert(mean == expectedMean);
    printf("\nMean Function is working properly");
    assert(sd == expectedSD);
    printf("\nStandard Deviation Function is working properly");
}
void main()
{
    int dataSet1[10]={1,3,5,7,9,11,13,15,17,19},dataSet2[5]={1,3,5,4,9},dataSet3[8]={5,1,6,7,3,7,8,9},dataSetLength;
    float expectedMean,expectedSD;
    printf("For dataSet 1");
    dataSetLength = 10;
    expectedMean = 10;
    expectedSD = sqrt(33);
    CalculateData(dataSet1,dataSetLength,expectedMean,expectedSD);
    printf("\nFor dataSet 2");
    dataSetLength = 5;
    expectedMean = 4.4;
    expectedSD = sqrt(7.04);
    CalculateData(dataSet2,dataSetLength,expectedMean,expectedSD);
    printf("\nFor dataSet 3");
    dataSetLength = 8;
    expectedMean = 5.75;
    expectedSD = sqrt(6.1875);
    CalculateData(dataSet3,dataSetLength,expectedMean,expectedSD);
}
