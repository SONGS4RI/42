/* N과 M(12) */
/* 12:48 ~ 12:56 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,ans[8];
bool vis[8];
vector<int> v;

bool func(int idx, int num) // 중복되는 숫자일때 이전에 방문하지 않았다면 이전 선택에서 사용한 수라는 뜻
{
	while(--idx >= 0)
		if(v[idx] == num && !vis[idx]) return (false);
	return (true);
}

void dfs(int cnt, int idx)
{
	if(cnt == m)
	{
		for(int i=0;i<cnt;i++) cout << ans[i] << " ";
		cout << "\n";
		return ;
	}
	for(int i=idx;i<n;i++) // 중복되는 선택을 방지하기 위해 인덱스를 매개변수로 받아온다.
	{
		if(func(i,v[i]))
		{
			vis[i] = true;
			ans[cnt] = v[i];
			dfs(cnt+1,i);
			vis[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		cin >> ans[0];
		v.push_back(ans[0]);
	}
	sort(v.begin(), v.end());
	dfs(0,0);
}