/* 스타트링크 */
/* 12:42 ~  13:11*/
#include <iostream>
#include <queue>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int f,s,g,ud[2],cur,nx;
	cin >> f >> s >> g >> ud[0] >> ud[1];
	if(s==g)//바로 시작지점과 종료지점이 같은경우
	{
		cout << "0\n";
		exit(0);
	}
	ud[1] *= -1;//내려가는 것이기 때문에 -1을 곱해줬다
	queue<int> q;
	int startlink[f+1] = {0,};
	startlink[s] = 1;
	q.push(s);
	while(!q.empty())
	{
		cur = q.front();
		q.pop();
		for(int dir=0;dir<2;dir++)
		{
			nx = cur + ud[dir];
			if(nx<=0 || nx>f) continue;//1~f까지이므로 이외는 전부 통과
			if(startlink[nx]>0) continue;//방문했으면 통과
			startlink[nx] = startlink[cur] + 1;
			if(nx==g)//도착했다면 출력
			{
				cout << startlink[nx]-1 << "\n";
				exit(0);
			}
			q.push(nx);
		}
	}
	cout << "use the stairs\n";//도착하지 못했다면 계단 사용
}