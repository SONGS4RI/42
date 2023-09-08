/* 괄호 */
/* 21:35 ~ 21:40 */
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t;
	string s;
	cin >> t;
	while(t--)
	{
		stack<char> st;
		cin >> s;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='(') st.push('(');
			else
			{
				if(st.empty() || st.top() == ')') st.push(')');
				else st.pop();
			}
		}
		if(st.empty()) cout << "YES\n";
		else cout << "NO\n";
	}
}