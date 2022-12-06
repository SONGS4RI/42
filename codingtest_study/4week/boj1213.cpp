/*팰린드롬 만들기*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	string s;
	cin >> s;
	int alpha[26]={0,}, len = s.size();
	for(int i=0;i<len;i++)//알파벳별로 정리
		alpha[s[i]-'A']++;
	char res[len+1];
	for(int i=0;i<len/2;i++)
	{
		for(int j=0;j<26;j++)//사전순으로 대칭조건에 맞춰서 res배열에 넣어줌
		{
			if(alpha[j]>1)
			{
				res[i] = 'A' + j;
				res[len - 1 - i] = 'A' + j;
				alpha[j] -= 2;
				break;
			}
		}
	}
	for(int i=0;i<26;i++)//len이 홀수일경우 중앙부분 예외처리
	{
		if(len % 2 == 1 && alpha[i] >0)
				{
					res[len/2] = 'A'+ i;
					alpha[i]--;
					break;
				}
	}
	for(int i=0;i<26;i++)//조건에 맞춰 제대로 실행 되었다면 통과
		if(alpha[i]!=0)
		{
			cout << "I'm Sorry Hansoo\n";
			exit(0);
		}
	res[len] = '\0';//쓰레기값 방지
	cout << res << "\n";
}