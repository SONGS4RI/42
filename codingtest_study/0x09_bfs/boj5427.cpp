/* 불 */
/* 14:44 ~ 16:28(x) */
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);


    int t,w,h,dist_sang[1001][1001],dist_fire[1001][1001],nx,ny;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    string s[1001];

    cin >> t;
    while(t--){
        queue<pair<int,int>> q_sang,q_fire;
        int escape = 0;
        cin >> w >> h;
        for(int i=0;i<h;i++)
		{
            cin >> s[i];
            fill(dist_sang[i],dist_sang[i]+w,-1);
            fill(dist_fire[i],dist_fire[i]+w,-1);
            for(int j=0;j<w;j++)//불과 사람 위치 찍어주기
			{
                if(s[i][j]=='@')
				{
                    q_sang.push({i,j});
                    dist_sang[i][j] = 0;
            	}
				else if(s[i][j]=='*')
				{
					q_fire.push({i,j});
					dist_fire[i][j] = 0;
				}
            }
        }

        while(!q_fire.empty())
		{
            auto cur = q_fire.front();
            q_fire.pop();
            for(int i=0;i<4;i++)
			{
                nx = cur.first + dx[i];
                ny = cur.second + dy[i];
                if(nx<0 || ny <0 || nx >= h || ny >= w) continue;
                if(dist_fire[nx][ny]>=0 || s[nx][ny] =='#') continue;//방문했거나 벽이면 통과
                dist_fire[nx][ny] = dist_fire[cur.first][cur.second] +1;
                q_fire.push({nx,ny});
            }
        }
        while(!q_sang.empty() && !escape)
		{
            auto cur = q_sang.front();//c++몇이상인가 부터 사용됨 auto, 자동으로 형 맞춰줌
            q_sang.pop();
            for(int i=0;i<4;i++)
			{
                nx = cur.first + dx[i];
                ny = cur.second + dy[i];
                if(nx<0 || ny <0 || nx >= h || ny >= w)//밖에 나갔으면
				{
                    cout << dist_sang[cur.first][cur.second] +1 << "\n";//현재값 + 1 출력
                    escape = 1;//탈출 플래그
                    break;
                }
                if(dist_sang[nx][ny]>=0 || s[nx][ny] !='.') continue;//방문 했거나 이동할수있는 경로가 아닌 경우 통과
                if(dist_fire[nx][ny]!=-1 && dist_fire[nx][ny]<=dist_sang[cur.first][cur.second]+1) continue;
                /* 불이 붙은곳 && 불붙은곳 값이 이전위치 (사람값+1)보다 작거나 같으면 통과*/
                dist_sang[nx][ny] = dist_sang[cur.first][cur.second] +1;
                q_sang.push({nx,ny});
            }
        }
        if(!escape) cout << "IMPOSSIBLE" << "\n";// 탈출 하지 못했다면
    }
}