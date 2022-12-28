/* 균형잡힌 세상 */
/* 18:39 ~  20:03*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
	string s;
	getline(cin,s,'.');
	while(s!="")
	{
		stack<char> st;
		int err = 0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='[') st.push('[');
			else if(s[i]=='(') st.push('(');
			else if(s[i]==']')
			{
				if(st.empty() || st.top()!='[')
				{
					st.push('[');
					break;
				}
				else if(st.top()=='[') st.pop();
			}
			else if(s[i]==')')
			{
				if(st.empty() || st.top()!='(')
				{
					st.push('(');
					break;
				}
				else if(st.top()=='(') st.pop();
			}
		}
		if(st.size()) cout << "no\n";
		else cout << "yes\n";
		cin.ignore();
		getline(cin,s,'.');
	}
}
