/* 키로거 */
#include <iostream>
#include <list>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t;
	cin >> t;
	while(t--)
	{
		list <char> lst;
		string s;
		cin >> s;
		list <char>::iterator iter = lst.begin();
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='<' && iter != lst.begin() && lst.size()) iter--;
			else if(s[i]=='>' && iter != lst.end() && lst.size()) iter++;
			else if(s[i]=='-' && iter != lst.begin() && lst.size()) iter = lst.erase(--iter);
			else if(s[i]!='>' && s[i]!='<' && s[i]!= '-') lst.insert(iter,s[i]);
		}
		for(iter = lst.begin();iter!=lst.end();iter++) cout << *iter;
		cout << "\n";
	}
}