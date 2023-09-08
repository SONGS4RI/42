/* N과 M(1) */
/* 13:56 ~ 14:31 */
#include <iostream>
#include <cstring>
#include <vector>
#include <deque>
using namespace std;

int n,m;
vector<pair<int,int> > v;
deque<int> dq; // 굳이 덱으로 안해도 되긴함
void bfs(int cnt)
{
	if(cnt == m)
	{
		for(int i=0;i<dq.size();i++) cout << dq[i] << " ";
		cout << "\n";
		return ;
	}
	for(int i=0;i<n;i++)
	{
		if(v[i].second == 0) // 방문 한적이 없다면
		{
			v[i].second = 1; // 방문 체크
			dq.push_back(v[i].first); // 덱에 넣어줌(나중에 순서대로 출력해주려고)
			bfs(cnt + 1); // 하나 카운트했으니 cnt+1해서 넣어준다.
			v[i].second = 0; //!!!!다시 나왔으니 방문체크 해제!!!!
			dq.pop_back(); // 넣어준거 그대로 빼주기
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	for(int i=1;i<=n;i++) v.push_back(make_pair(i,0));
	bfs(0);
}

/* 좀더 깔끔한 코드 */

int ans[9],n,m;
bool vis[9];

void bfs(int cnt)
{
	if(cnt == m)
	{
		for(int i=0;i<m;i++) cout << ans[i] << " ";
		cout << "\n";
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i] = true;
			ans[cnt] = i;
			bfs(cnt+1);
			vis[i] = false;
		}
	}
}

int main()
{
	cin >> n >> m;
	bfs(0);
}