/* 곱셈 */
/* 13:20 ~ 13:52(x) */
#include <iostream>
using namespace std;

long long func(long long a,long long b,int c)
{
	long long ans;
	if(b==1) return (a % c); // b=1일때는 바로 리턴
	ans = func(a,b/2,c); // 절반으로 분할해서 나머지를 구해준다. ex) 2^10 == 2^5 * 2^5로 분할
						 // 2^11 == 2^5 * 2^5로 분할하고 마지막에 리턴할때 누락된 2를 추가해준다.
	ans = ans*ans%c; // 분할하여 나머지를 구한것 끼리 곱을 해준 후 나머지를 구해준다.
	if(b%2==0) return ans; // b가 짝수이면 바로 리턴(짝수이면 분할 할 때 딱 떨어지게 나누어지기 떄문이다.)
	return ans*a%c; // 홀수이면 func(a,b/2,c)를 할때 하나가 누락된 값의 나머지를 구한 것이므로 a를 한번더 곱하고 c로 나누어준다.
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int a,b,c;
	cin >> a >> b >> c;
	cout << func(a,b,c) << "\n";
}