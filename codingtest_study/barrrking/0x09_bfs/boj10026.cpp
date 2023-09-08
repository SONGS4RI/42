/* 적록색약 */
/* 14:00 ~ 14:25 */
#include <iostream>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

int n,ans_1=0,ans_2=0,nx,ny;//ans_1 : 정상, ans_2 : 적록생약
int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};
char board[100][100];//방문했는지용
string s[100];

void bfs(char c,int i,int j,int *ans)
{
    queue<pair<int,int> > q;
    q.push(make_pair(i,j));
    board[i][j] = c;
    while(q.size())
    {
        pair<int,int> cur = q.front();
        q.pop();
        for(int dir=0;dir<4;dir++)
        {
            nx = cur.first + dx[dir];
            ny = cur.second + dy[dir];
            if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
            if(board[nx][ny] != '0' || s[nx][ny] != c) continue;//방문했거나 다른 색이면
            board[nx][ny] = c;
            q.push(make_pair(nx,ny));
        }
    }
    (*ans)++;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    memset(board,'0',sizeof(board));//방문보드 초기화
    queue<pair<int,int> > q;
    for(int i=0;i<n;i++) cin >> s[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if((s[i][j]=='R' || s[i][j]=='G' || s[i][j]=='B') && board[i][j]=='0')
                bfs(s[i][j],i,j,&ans_1);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(s[i][j]=='G') s[i][j] = 'R';//G => R로 변경
    memset(board,'0',sizeof(board));//방문보드 초기화

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if((s[i][j]=='R' || s[i][j]=='B') && board[i][j]=='0')
                bfs(s[i][j],i,j,&ans_2);
    cout << ans_1 << " " << ans_2 << "\n";
}