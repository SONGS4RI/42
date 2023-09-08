/* 잃어버린 괄호 */
/* 12:53 ~ 13:45 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string s;
    vector<int> arr;
    vector<char> v;
    cin >> s;
    for(int i=0;i<s.size();i++) // 백터에 숫자와 연산자 따로 저장
    {
        int num = 0, offset=0;
        for(;i+offset<s.size();offset++)
        {
            if(s[i+offset] && s[i+offset]>='0' && s[i+offset]<='9')
                num = num*10 + s[i+offset] - '0';
            else
            {
                v.push_back(s[i+offset]);
                break;
            }
        }
        arr.push_back(num);
        i += offset;
    }
    int ans = 0;
    if (!v.empty()) // 연산이 있다면
    {
        for(int i=v.size();i>=0;i--) // 뒤에서 부터
        {
            if(v[i] == '+') arr[i] += arr[i+1]; // + 면 값 더해주기
            else ans -= arr[i+1]; // - 면 뺴주기
        }
    }
    /*
    ex)
    arr : 1 2 3 4
    v   : - + +   처럼 저장되는데
    +이면 arr[i] += arr[i+1], -면 arr[i+1]을 빼준다.
    */
    ans += arr[0]; // 처음에 들어오는값 더해준다.(이전에+였으면 쌓인값)
    cout << ans << "\n";
}