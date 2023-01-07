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
			for(int k=cur.first;k<nx;k++) board[j][k] = 1; // 겹치는 부분 상관없이 전부 1로 표기
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!board[i][j] && !visited[i][j]) // board가 0이고 방문한적 없다면
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
						w++; // 영역++
					}
				}
				v.push_back(w); // 벡터에 넣어주어서 나중에 답으로 출력
				ans++;
			}
		}
	}
	sort(v.begin(),v.end()); // 오름차순 정렬
	cout << ans << "\n";
	for(auto c : v) cout << c << " ";
}