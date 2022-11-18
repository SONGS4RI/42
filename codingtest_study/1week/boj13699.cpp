#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long arr[36] = {0,};
    cin >> n;
    arr[0] = 1;
    for(int i=1; i<=n ; i++)
    {
        for(int j=0;j<i;j++)
            arr[i] += arr[j]*arr[i-1-j];
    }
    cout << arr[n] << "\n";
}