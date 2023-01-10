/* 하노이 탑 이동 순서 */
/* 13:44 ~  */
#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int go, int to, int n)
{
	if(n == 1)
	{
		cout << go << ' ' << to << '\n';
		return ;
	}
	hanoi(go, 6-go-to, n-1); // n-1 개의 하노이를 목적지 이외의 목표지점으로 이동
	cout << go << ' ' << to << '\n'; // 제일 밑의 판을 이동 => 1 3
	hanoi(6-go-to, to, n-1);// n-1 개의 판을 to으로 이동
}
int  main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	cout << int(pow(2,n) - 1) << '\n'; // pow는 double이므로 출력할때 int형으로 형변환을 해주어야한다.
	hanoi(1,3,n);
}