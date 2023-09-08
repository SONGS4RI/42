/* 로또 */
/* 13:01 ~ 13:13 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int k, ans[6];
vector<int> v;

void dfs(int cnt, int idx)
{
	if(cnt == 6) // 로또 숫자 6개를 고르면 종료
	{
		for(int i=0;i<cnt;i++) cout << ans[i] << " ";
		cout << "\n";
		return ;
	}
	for(int i=idx;i<k;i++) // 오름차순 정렬로 중복없이 출력하는 조건이다.
	{
		ans[cnt] = v[i];
		dfs(cnt+1, i+1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	while(1)
	{
		v.clear(); // 테스트 케이스마다 벡터를 비워준다.
		cin >> k;
		if(!k) return (0); // 종료 조건
		for(int i=0;i<k;i++)
		{
			cin >> ans[0];
			v.push_back(ans[0]);
		}
		sort(v.begin(),v.end());
		dfs(0, 0);
		cout << "\n";
	}
}