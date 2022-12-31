/* 미로 탐색 */
/* 20:05 ~ 20:33*/
#include <iostream>
#include <queue>
#include <string>
#include <string.h>//memset
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n,m;
	int dx[4] = {-1,0,1,0};
	int dy[4] = {0,1,0,-1};

	cin >> n >> m;
	string arr[n];
	int board[n][m]; memset(board,0,sizeof(board));
	queue<pair<int,int>> q;
	for(int i=0;i<n;i++) cin >> arr[i];
	q.push({0,0});
	board[0][0] = 1;//방문했는지를 표시 및 지금까지 얼마나 이동했는지
	while(q.size())
	{
		pair<int,int> p = q.front();
		q.pop();
		for(int dir=0;dir<4;dir++)
		{
			int nx = p.first + dx[dir];
			int ny = p.second + dy[dir];
			if(nx<0 || ny<0 || nx>= n || ny>=m) continue;
			if(board[nx][ny] || arr[nx][ny] != '1') continue;
			board[nx][ny] = board[p.first][p.second] + 1;// 이전배열값 +1
			q.push({nx,ny});
		}
	}
	cout << board[n-1][m-1] << "\n";
}