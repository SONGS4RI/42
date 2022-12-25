/* 회전하는 큐 */
/* 15:49 ~ 16:13*/
#include <iostream>
#include <deque>
#include <cmath>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, m, num, ans=0;;
	deque<int> dq, arr;
	cin >> n >> m;
	for(int i=1;i<=n;i++) dq.push_back(i);
	for(int i=0;i<m;i++)
	{
		cin >> num;
		arr.push_back(num);
	}
	while(arr.size())//탐색수가 다 떨어질때 까지
	{
		num = 0;
		while(arr.front()!=dq.front())//탐색수와 순환큐의 front값이 같을때 까지 2번(왼쪽으로 돌리는 형식)적용
		{
			dq.push_back(dq.front());
			dq.pop_front();
			num++;
		}
		ans += min(num,(int)dq.size()-num);//오른쪽 왼쪽 중 작은것 선택
		dq.pop_front();
		arr.pop_front();
	}
	cout << ans << "\n";
}