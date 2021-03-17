#include<iostream>
#include<stdio.h>
using namespace std;

const double PI=3.14159265358979323846;
int main()
{
    double r;
    cin >> r;
    double a = r * r * PI;
    double b = r * 2 * PI;
    printf("%.6f %.6f\n", a, b);
    return 0;
}