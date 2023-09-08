/* N과 M(2) */
/* 22:41 ~ 22:47 */
#include <iostream>
using namespace std;
int n,m,ans[9];
void	dfs(int cnt, int idx)
{
	if(cnt == m) // 조건을 만족한다면
	{
		for(int i=0;i<cnt;i++) cout << ans[i] << " "; // 카운트한 수들 출력
		cout << "\n";
		return ;
	}
	for(int i=idx;i<=n;i++)
	{
		ans[cnt] = i; // 카운트한 인덱스에 값 저장
		dfs(cnt+1, i+1); // cnt + 1, 그때의 인덱스+1(중복이 안되도록 하기위해 1,4 // 4,1 과같이)
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	dfs(0, 1);
}