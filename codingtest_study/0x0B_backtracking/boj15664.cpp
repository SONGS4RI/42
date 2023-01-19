/* N과 M(10) */
/* 13:53 ~ 14:09 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,ans[8];
vector<int> v;
bool vis[8];
int func(int idx, int num)
{
	for(int i=idx-1;i>=0;i--)
	{
		if(v[i] == num && !vis[i])
			return (0);
	}
	return (1);
}

void dfs(int cnt, int idx)
{
	if(cnt == m)
	{
		for(int i=0;i<cnt;i++) cout << ans[i] << " ";
		cout << "\n";
		return ;
	}
	for(int i=idx;i<n;i++) // 중복조건을 없애기 위해
	{
		if(!vis[i] && func(i,v[i])) // 중복된 숫자이고 이전에 방문하지 않았다는 것은 곧 이전에 선택하고 선택을 취소했다는 의미이다.
		{
			vis[i] = true;
			ans[cnt] = v[i];
			dfs(cnt+1, i+1);
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
	dfs(0,0);
}