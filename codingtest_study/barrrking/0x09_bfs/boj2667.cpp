/* 단지번호 붙이기 */
/* 17:58 ~ 18:20 */
#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};
	vector<int> v;
	queue<pair<int,int>> q;
	pair<int,int> cur;
	int n,nx,ny;
	cin >> n;
	string board[n];//연속되게 입력되어서 스트링으로 받는게 편하다
	bool visited[n][n]; memset(visited,false,sizeof(visited));
	for(int i=0;i<n;i++) cin >> board[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(board[i][j] == '1' && !visited[i][j])//단지이고 방문하지 않았다면
			{
				int cnt = 1;
				visited[i][j] = true;//방문 체크
				q.push({i,j});
				while(!q.empty())
				{
					cur = q.front();
					q.pop();
					for(int dir=0;dir<4;dir++)
					{
						nx = cur.first + dx[dir];
						ny = cur.second + dy[dir];
						if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
						if(board[nx][ny] == '0' || visited[nx][ny]) continue;
						visited[nx][ny] = true;
						q.push({nx,ny});
						cnt++;// 단지 넓이++
					}
				}
				v.push_back(cnt);//벡터에 추가
			}
		}
	}
	sort(v.begin(),v.end());//오름차수 정렬을 위해
	cout << v.size() << "\n";
	for(auto c : v) cout << c << "\n";
}