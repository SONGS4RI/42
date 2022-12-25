/* 회전하는 큐 */
/* 15:49 ~ 16:13*/
#include <iostream>
#include <deque>
#include <cmath>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, m, num, ans=0;
	deque<int> dq;
	cin >> n >> m;
	for(int i=1;i<=n;i++) dq.push_back(i);
	for(int i=0;i<m;i++)
	{
		cin >> num;
		int tmp = 0;
		while(num!=dq.front())//탐색수와 순환큐의 front값이 같을때 까지 2번(왼쪽으로 돌리는 형식)적용
		{
			dq.push_back(dq.front());
			dq.pop_front();
			tmp++;
		}
		ans += min(tmp,(int)dq.size()-tmp);//왼쪽 오른쪽 돌리는 방식 중 작은것 선택
		dq.pop_front();					   //왼쪽 == tmp 오른쪽 dq.size()-tmp
	}
	cout << ans << "\n";
}