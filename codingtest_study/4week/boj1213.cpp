/*�Ӹ���� �����*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	string s;
	cin >> s;
	int alpha[26]={0,}, len = s.size();
	for(int i=0;i<len;i++)//���ĺ����� ����
		alpha[s[i]-'A']++;
	char res[len+1];
	for(int i=0;i<len/2;i++)
	{
		for(int j=0;j<26;j++)//���������� ��Ī���ǿ� ���缭 res�迭�� �־���
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
	for(int i=0;i<26;i++)//len�� Ȧ���ϰ�� �߾Ӻκ� ����ó��
	{
		if(len % 2 == 1 && alpha[i] >0)
				{
					res[len/2] = 'A'+ i;
					alpha[i]--;
					break;
				}
	}
	for(int i=0;i<26;i++)//���ǿ� ���� ����� ���� �Ǿ��ٸ� ���
		if(alpha[i]!=0)
		{
			cout << "I'm Sorry Hansoo\n";
			exit(0);
		}
	res[len] = '\0';//�����Ⱚ ����
	cout << res << "\n";
}