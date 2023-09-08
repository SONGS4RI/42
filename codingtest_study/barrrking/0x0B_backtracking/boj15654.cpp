/* N과 M(5) */
/* 14:47 ~  14:59 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,ans[8];
bool vis[8];
vector<int> v;

void dfs(int cnt)
{
	if(cnt == m) // 카운트 개수가 m이 된다면.
	{
		for(int i=0;i<cnt;i++) cout << ans[i] << " ";
		cout << "\n";
		return ;
	}
	for(int i=0;i<n;i++)
	{
		if(!vis[i]) // 방문 체크
		{
			vis[i] = true; // 방문 체크
			ans[cnt] = v[i]; // ans배열 cnt번째인덱스에 v[i]값을 넣어준다.
			dfs(cnt+1);
			vis[i] = false; // 방문 해제
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
	sort(v.begin(), v.end()); // 오름차순 정렬
	dfs(0);
}