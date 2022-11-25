#include <bits/stdc++.h>
using namespace std;
    
int n, res=0;
string s[101];

char is_strike(string target, string ex) // 예측 숫자 스트라이크 갯수 세주기
{
	int strike = 0;
	for(int i=0;i<3;i++)
	{
		if(ex[i] == target[i])
			strike++;
	}
	return (strike + '0');
}

char is_ball(string target, string ex) // 예측 숫자 볼 갯수 세주기
{
	int ball = 0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
			if(ex[i] == target[j] && i!=j)
				ball++;
	}
	return (ball + '0');
}

void dfs(int cnt, string ex)
{
	if (cnt == 3)
	{
		for (int i=0;i<n;i++)
		{
			if ((is_strike(s[i],ex) != s[i][3]) || (is_ball(s[i],ex) != s[i][4])) // 입력받은 값이랑 스트라이크 볼이 다르면 종료
				return ;
		}
		res++;
		return ;
	}
	for(int i=1;i<=9;i++)
	{
		int err = 0;
		for(int j=0;j<cnt;j++)// 숫자의 중복을 없애기 위해 
		{
			if(ex[j] == i + '0')
				err = 1;
		}
		if(!err)
		{
			ex[cnt] = i + '0';
			dfs(cnt+1, ex);
		}
	}
	return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	string ex = "000";
	cin >> n;
	for(int i=0;i<n;i++) // 입력 받기
	{
		cin >> s[i];
		cin >> s[i][3];
		cin >> s[i][4];
	}
	dfs(0, ex);
	cout << res << "\n";
}