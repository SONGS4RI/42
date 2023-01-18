/* N과 M(8) */
/* 12:58 ~ 13:01 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,ans[8];
vector<int> v;
void	dfs(int cnt,int idx)
{
	if(cnt == m)
	{
		for(int i=0;i<cnt;i++) cout << ans[i] << " ";
		cout << "\n";
		return ;
	}
	for(int i=idx;i<n;i++) // 중복선택을 제외하는 조건이다.
	{
		ans[cnt] = v[i];
		dfs(cnt+1,i);
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