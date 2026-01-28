//
// Created by NandanRaj on 25-01-2026.
//
#include<iostream>

using namespace std;
int *dptr=nullptr;

float pow(float base, int exp)
{
    float result=1;
    for(int i=0;i<exp;i++)
    {
        result*=base;
    }
    return result;
}
// Function to calculate factorial
long long factorial(int n)
{
    if(dptr[n]!=0)//check if factorial already computed
    {
        return dptr[n];
    }
    if(n<=1)
        return 1;
    else
        return n*factorial(n-1);
}
// Function to calculate individual term in Taylor Series
float term(float x, int n)
{
    return pow(x,n)/factorial(n);
}
//  Function to calculate sum of Taylor Series up to n terms
float TaylorSeriesSum (float x, int n)
{
    float sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=term(x,i);
    }
    return sum;
}

int main()
{
    float x;
    int noOfTerms;
    cout<<"Enter the value of x (in radians): ";
    cin>>x;

    do//input validation for positive integer
    {
        cout<<"Enter the number of terms to consider in Taylor Series (positive integer): ";
        cin>>noOfTerms;
        if(noOfTerms<=0)
        {
            cout<<"Number of terms must be a positive integer. Please try again."<<endl;
        }
    } while (noOfTerms<=0);
    dptr = new int[noOfTerms+1]();//dynamic memory allocation for number of terms

    cout<<"Sum of Taylor Series: "<<TaylorSeriesSum(x,noOfTerms)<<endl;
    delete[] dptr; //free dynamically allocated memory
    return 0;
}