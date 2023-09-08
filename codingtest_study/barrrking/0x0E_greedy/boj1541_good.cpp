/* 잃어버린 괄호 */
/* 13:48 ~ 12:11 */
#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string s;
    int num=0,ans=0,tmp=0,num_size=1;
    cin >> s;
    for(int i=s.size()-1;i>=0;i--) // 문자열 뒤에서 부터
    {
        if(isdigit(s[i])) // 숫자면
		{
			num += (s[i] - '0')*num_size; // num에 저장
			num_size *= 10; // 자리수
		}
        else if(s[i] == '+') // + 면
        {
            tmp += num; //  tmp에 값 추가
            num = 0;	// 초기화
			num_size = 1; // 초기화
        }
        else
        {
            ans -= tmp+num; // tmp에 쌓인값+현재num을 결과값에서 빼준다.
            tmp = 0; // 초기화
            num = 0; // 초기화
			num_size = 1; // 초기화
        }
    }
    cout << ans+num+tmp << "\n";
}