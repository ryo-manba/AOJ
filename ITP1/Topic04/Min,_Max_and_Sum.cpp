#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long a[n];
    long long mini = 1000000000;
    long long maxi = -100000000;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (mini > a[i]) mini = a[i];
        if (maxi < a[i]) maxi = a[i];
        sum += a[i];
    }

    printf("%lld %lld %lld\n", mini, maxi, sum);
    return 0;
}