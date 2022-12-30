/* 그림 */
/* 01:28 ~  02:10*/
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};//동서남북
	queue<pair<int,int>> q;
	int n,m,ans=0,cnt=0;
	cin >> n >> m;
	int arr[n][m], visited[n][m];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin >> arr[i][j];//입력
			visited[i][j] = 0;//방문배열 초기화 => 애초에 bool로하면 해줄필요없긴함
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(arr[i][j] && !visited[i][j])//조건에 만족하며 방문하지않았다면
			{
				int ans_temp = 1;//현재그림의 범위
				visited[i][j] = 1;//방문표시
				q.push({i,j});
				while(q.size())//큐가 다 비어질때까지 == 더 탐색할것이 없을때 까지
				{
					pair<int,int> p = q.front();//현재 큐에 저장된값을 비워주어야 하기때문에 값을 담아주는 용도
					q.pop();
					for(int dir=0;dir<4;dir++)
					{
						int nx = p.first + dx[dir];
						int ny = p.second + dy[dir];
						if(nx<0 || ny<0 || nx>=n || ny>=m) continue;//범위 넘어갈때
						if(!arr[nx][ny] || visited[nx][ny]) continue;//조건만족x
						q.push({nx,ny});//조건에 만족하면 큐에 추가
						visited[nx][ny] = 1;//방문 표시
						ans_temp++;//현재 그림의 범위++
					}
				}
				ans = max(ans,ans_temp);
				cnt++;//그림의 개수++;
			}
		}
	cout << cnt << "\n" << ans << "\n";
}