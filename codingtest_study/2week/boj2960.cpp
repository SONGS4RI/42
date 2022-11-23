#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=0, cnt = 1, k, arr[1001]={0,};

    cin >> n >> k;
    for(int i=2;i<=n;i++)
        arr[i] = 1;
    for(int i=2;i<=n;i++)
    {
        if(!arr[i])
            continue;
        if(cnt++ == k)
        {
            cout << i << '\n';
            exit(0);
        }
        for(int j=i*i;j<=n;j+=i)
        {
            if(!arr[j])
                continue;
            arr[j] = 0;
            if(cnt++ == k)
            {
                cout << j << '\n';
                exit(0);
            }
        }
    }
    
}