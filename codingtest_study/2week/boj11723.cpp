#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> arr;
    string s;
    int num,n;

    cin >> n;
    while(n--)
    {
        cin >> s;
        if (s == "add")
        {
            cin >> num;
            arr.insert(num);
        }
        else if(s == "remove")
        {
            cin >> num;
            arr.erase(num);
        }
        else if(s == "check")
        {
            cin >> num;
            cout << arr.count(num) << "\n";
        }
        else if(s == "toggle")
        {
            cin >> num;
            if(arr.count(num))
                arr.erase(num);
            else
                arr.insert(num);
        }
        else if(s == "all")
            for(int i=1;i<=20;i++)
                arr.insert(i);
        else if(s == "empty")
            arr.clear();
    }
}