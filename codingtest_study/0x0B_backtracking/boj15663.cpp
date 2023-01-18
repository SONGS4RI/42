/* N과 M(9) */
/* 13:02 ~ 13:54*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,ans[8];
bool vis[8];
vector<int> v;
/*
func이라는 조건식을 사용하여 만약 동일한 숫자인데 이전에 선택한 적이 없다면
이전의 재귀에서 방문체크를 해제했다는 의미이므로 중복된 선택이라는 것을 의미하여 0의 값을 리턴해준다.
*/
int func(int idx, int num) // 같은 숫자인데 이전에 방문한적이 없다면 중복선택이라는 의미이다!!!
{
	for(int i=idx-1;i>=0;i--)
		if(v[i]==num && !vis[i]) return (0);
	return (1);
}

void	dfs(int cnt)
{
	if(cnt == m)
	{
		for(int i=0;i<cnt;i++) cout << ans[i] << " ";
		cout << "\n";
		return ;
	}
	for(int i=0;i<n;i++)
	{
		if(!vis[i] && func(i,v[i])) // 선택한적이 있는 원소인지 && 같은 숫자인데 이전에 방문했는지의 유무
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