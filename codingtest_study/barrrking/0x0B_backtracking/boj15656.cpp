/* N과 M(7) */
/* 12:51 ~ 12:56 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,ans[8];
vector<int> v;
void	dfs(int cnt)
{
	if(cnt == m)
	{
		for(int i=0;i<cnt;i++) cout << ans[i] << " ";
		cout << "\n";
		return ;
	}
	for(int i=0;i<n;i++) // 중복되는 조건들도 전부 출력
	{
		ans[cnt] = v[i];
		dfs(cnt+1);
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