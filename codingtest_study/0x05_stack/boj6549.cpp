/* 히스토리그램에서 가장 큰 직사각형 */
/* 15:34 ~  16:10(x) */
#include <iostream>
#include <stack>
using namespace std;
#define X first
#define Y second

int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	while (1)
	{
		int n;
		cin >> n;
		if (n == 0) break;
		stack<pair<int, int>> st;
		long long ans = 0;
		for (int i = 0; i < n; i++)
		{
			int h;
			cin >> h;
			int idx = i;
			while (!st.empty() && st.top().X >= h)//높이가 이전값보다 작은 값이 나오면 이전값까지의 최대 너비를 계산
			{
				ans = max(ans, 1LL * (i - st.top().Y) * st.top().X);
				idx = st.top().Y;//다시 오름차순으로 시작하는 새로운 인덱스 표시
				st.pop();
			}
			st.push({h, idx});
		}
		while (!st.empty())//오름차순으로 스택이 남아있을때 넓이의 최대값이 존재하는 경우 탐색
		{
			ans = max(ans, 1LL * (n - st.top().Y) * st.top().X);
			st.pop();
		}
		cout << ans << '\n';
	}
}