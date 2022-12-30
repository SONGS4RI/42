/* 괄호의 값 */
/* 18:03 ~  19:02*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	string s;
	stack<pair<char,int>> st;
	int ans[16]={0,};
	cin >> s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='(' || s[i] == '[') st.push({s[i],st.size()});
		else if(s[i] == ')')
		{
			if(st.empty() || st.top().first == '[')// 오류케이스
			{
				st.push({s[i],st.size()});
				break;
			}
			else
			{
				if(ans[st.top().second+1] == 0) ans[st.top().second]+=2;//낮은 깊이에 값이 없으면 더하기
				else
				{
					ans[st.top().second]+=2*ans[st.top().second+1];//낮은 깊이에 값이 있으면 곱하기
					ans[st.top().second+1] = 0;//곱해주었으니 초기화
				}
				st.pop();
			}
		}
		else if(s[i] == ']')//이하동문
		{
			if(st.empty() || st.top().first == '(')
			{
				st.push({s[i],st.size()});
				break;
			}
			else
			{
				if(ans[st.top().second+1] == 0) ans[st.top().second]+=3;
				else
				{
					ans[st.top().second]+=3*ans[st.top().second+1];
					ans[st.top().second+1] = 0;
				}
				st.pop();
			}
		}
	}
	if(st.empty()) cout << ans[0] << "\n";
	else cout << "0\n";
}