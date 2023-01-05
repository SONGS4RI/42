/* 나이트의 이동  */
/* 13:01 ~ */
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int dx[8] = {-2,-1,1,2,2,1,-1,-2}, dy[8] = {1,2,2,1,-1,-2,-2,-1};// 나이트 이동 경로
	int t,n,x,y;
	pair<int,int> cur;
	cin >> t;
	while(t--)
	{
		int ans = 1, nx, ny;
		queue<pair<int,int> > q;
		cin >> n >> x >> y;
		int arr[n][n];
		memset(arr,0,sizeof(arr));//arr 배열 초기화
		q.push(make_pair(x,y));//시작지점 큐에 넣어주기
		arr[x][y] = 1;// 시작지점 방문표시 및 이동횟수 표시
		cin >> x >> y;
		while(q.size() && ans)// 목표 경로에 도착하면 ans = 0이므로
		{
			cur = q.front();
			q.pop();
			for(int dir=0;dir<8;dir++)
			{
				nx = cur.first + dx[dir];
				ny = cur.second + dy[dir];
				if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
				if(arr[nx][ny]) continue;//한번이라도 방문하였다면
				arr[nx][ny] = arr[cur.first][cur.second] + 1;//이전값 + 1
				if(nx == x && ny == y)//목표지점이라면
				{
					cout << arr[nx][ny]-1 << "\n";
					ans = 0;
					break;
				}
				q.push(make_pair(nx,ny));
			}
		}
		if(ans) cout << "0\n";//시작지점 = 목표지점일 경우
	}
}