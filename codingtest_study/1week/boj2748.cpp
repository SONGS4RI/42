#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long arr[91];
    int n; 

    arr[0] = 0; arr[1] = 1;
    cin >> n;
    for(int i=2; i<= n; i++)
    {
        arr[i] = arr[i-1] + arr[i-2];
    }
    cout << arr[n] << "\n";
}