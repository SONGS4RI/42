#include <bits/stdc++>
using namespace std;

int is_strike(string target, string res)
{
	int strike = 0;
	for(int i=0;i<3;i++)
	{
		if(res[i] == target[i])
			strike++;
	}
	return (strike);
}

int is_ball(string target, string res)
{
	int ball = 0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
			if(res[i] == target[j] && i!=j)
				ball++;
	}
	return (ball);
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int n;
	string s[101];

	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> s[i];
		for(int j=0;j<2;j++)
			cin >> s[i][3 + j];
	}
	

}