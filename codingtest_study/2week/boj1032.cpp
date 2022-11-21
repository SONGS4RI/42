#include <bits/stdc++.h> // 통합 헤더 (많이쓰는 헤더를 전부 포함하고있다)
using namespace std; // (std 클래스의 특정함수들을 사용하겠다는 의미)
                     // 만약 이렇게 쓰지않으면 std 함수들을 사용할때 
int main()           // 범위 지정 연산자 (::)을 사용해주어야함
{                    // ex) std::cout
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