/* N과 M(3) */
/* 23:17 ~ 23:21 */
#include <iostream>
using namespace std;

int n,m,ans[7];

void dfs(int cnt)
{
	if(cnt == m) // m개 만큼 카운트 하면
	{
		for(int i=0;i<cnt;i++) cout << ans[i] << " "; // 카운트 한 수 출력
		cout << "\n";
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		ans[cnt] = i; // i를 ans배열 cnt번째 인덱스에 저장
		dfs(cnt+1); // 카운트 하나 증가 시켜서
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	dfs(0);
}