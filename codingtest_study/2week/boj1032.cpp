#include <bits/stdc++.h> 
using namespace std; 

int main() 
{                  
    int n, i;
    string s1,res;

    cin >> n;
    cin >> res;
    while(--n)
    {
        i = 0;
        cin >> s1;
        while(s1[i])
        {
            if(res[i] != s1[i])
                res[i] = '?';
            i++;
        }
    }
    cout << res << "\n";
    
}