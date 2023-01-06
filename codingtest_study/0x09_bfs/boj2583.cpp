/* 영역 구하기 */
/* 16:37 ~ 17:17 */
#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int m,n,k,nx,ny,ans=0;
	vector<int> v;
	int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};
	pair<int,int> cur;
	cin >> n >> m >> k;
	int board[n][m]; memset(board,0,sizeof(board));
	bool visited[n][m]; memset(visited,false,sizeof(visited));
	queue<pair<int,int>> q;
	for(int i=0;i<k;i++)
	{
		cin >> cur.first >> cur.second;
		cin >> nx >> ny;
		for(int j=cur.second;j<ny;j++)
			for(int k=cur.first;k<nx;k++) board[j][k] = 1;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!board[i][j] && !visited[i][j])
			{
				int w=1;
				q.push({i,j});
				visited[i][j] = true;
				while(!q.empty())
				{
					cur = q.front();
					q.pop();
					for(int dir=0;dir<4;dir++)
					{
						nx = cur.first +dx[dir];
						ny = cur.second +dy[dir];
						if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
						if(board[nx][ny]|| visited[nx][ny]) continue;
						visited[nx][ny] = true;
						q.push({nx,ny});
						w++;
					}
				}
				v.push_back(w);
				ans++;
			}
		}
	}
	sort(v.begin(),v.end());
	cout << ans << "\n";
	for(auto c : v) cout << c << " ";
}