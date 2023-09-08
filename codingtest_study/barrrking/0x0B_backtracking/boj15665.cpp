/* N과 M(11) */
/* 15:21 ~ 15:34 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,ans[8];
vector<int> v;
bool vis[8];

bool func(int idx, int num) // 이전에 방문한 중복된 수인지 판별하는 함수
{
	while(--idx >= 0)
		if(v[idx]==num && !vis[idx]) return (false);
	return (true);
}

void dfs(int cnt)
{
	if(cnt == m)
	{
		for(int i=0;i<cnt;i++) cout << ans[i] << " ";
		cout << "\n";
		return ;
	}
	for(int i=0;i<n;i++) // 모든 중복된수의 조합이기때문에 인덱스는 따로 건들이지 않는다.
	{
		if(func(i,v[i]))
		{
			vis[i] = true;
			ans[cnt] = v[i];
			dfs(cnt+1);
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
	sort(v.begin(),v.end());
	dfs(0);
}