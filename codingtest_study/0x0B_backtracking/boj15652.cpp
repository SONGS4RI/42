/* N과 M(4) */
/* 14:39 ~  14:46 */
#include <iostream>
using namespace std;
int n,m,ans[8];

void dfs(int cnt, int idx)
{
	if(cnt == m)
	{
		for(int i=0;i<cnt;i++) cout << ans[i] << " ";
		cout << "\n";
		return ;
	}
	for(int i=idx;i<=n;i++) // 매개변수로 전달받은 인덱스부터
	{
		ans[cnt] = i;
		dfs(cnt+1,i); // 카운트한 해당 인덱스를 전달
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	dfs(0, 1);
}
