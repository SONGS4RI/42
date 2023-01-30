#include <stdio.h>
#include <stdlib.h>

void dfs(int x, int y, char **map)
{
	int dx[4] = {-1,0,1,0};
	int dy[4] = {0,1,0,-1};

	for(int dir=0;dir<4;dir++)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
		if(map[nx][ny] == '1') continue;
		map[nx][ny] = '1';
		dfs(nx,ny,map);
	}
}

int main()
{
	char **map;

	map = calloc(sizeof(char *), 6);
	for(int i=0;i<5;i++) map[i] = calloc(sizeof(char), 6);
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++) map[i][j] = '0';
	map[0][0] = '1';
	for(int i=0;i<5;i++) printf("%s\n",map[i]);
	dfs(0,0,map);
	for(int i=0;i<5;i++) printf("%s\n",map[i]);
}