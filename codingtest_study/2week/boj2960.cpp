#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=0, k, arr[1001]={0,};

    cin >> n >> k;
    for(int i=2;i<=n;i++)
        arr[i] = 1;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(!arr[i])
            continue;
        k--;
        for(int j=i*i;j<=n;j+=i)
        {
            arr[j] = 0;
            if(!--k)
            {
                cout << j << '\n';
                exit(0);
            }
        }
    }
    
}