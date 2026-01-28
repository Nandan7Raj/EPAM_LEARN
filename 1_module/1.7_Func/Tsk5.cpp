//
// Created by NandanRaj on 25-01-2026.
//
#include <cmath>
#include<iostream>
# define PI 3.14159265
using namespace std;
// Function to calculate power
float powr(float base, int exp)
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
    long long fact=1;
    for(int i=2;i<=n;i++)
    {
        fact*=i;
    }
    return fact;
}

// Function to calculate individual term in Taylor Series for sin(x)
float calculateTerm(float x, int n)
{
    return powr(-1,n+1)*powr(x,2*n-1)/factorial(2*n-1);
}
//  Function to calculate sin(x) using Taylor Series up to n terms
float sinx(float x, int n)
{
    float sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=calculateTerm(x,i);
    }
    return sum;
}
int main()
{
    // Input angle in degrees
    float angleInDegrees;
    cout << "Enter angle in degrees: ";
    cin >> angleInDegrees;

    angleInDegrees= fmod(360.0f + angleInDegrees,360.0f); // Normalize angle to [0, 360)

    float angleInRadians = angleInDegrees * (PI / 180.0);// Convert degrees to radians
    int noOfTerms;
    // Input validation for positive integer
    do
    {
        cout<<"Enter the number of terms to consider in Taylor Series (positive integer): ";
        cin>>noOfTerms;
        if(noOfTerms<=0)
        {
            cout<<"Number of terms must be a positive integer. Please try again."<<endl;
        }
    } while (noOfTerms<=0);
    // Calculate sin(x)
    float result=sinx(angleInRadians,noOfTerms);
    cout<<"sin("<<angleInDegrees<<" degrees) = "<<result<<endl;

    return 0;
}