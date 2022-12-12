/* 에디터 */
#include <iostream>
#include <list>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	list <char>lst;
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++)
		lst.push_back(s[i]);
	int m;
	char c;
	list <char>::iterator iter = lst.end();
	cin >> m;
	while(m--)
	{
		cin >> c;
		if(c == 'L' && iter != lst.begin()) iter--;
		else if(c == 'D' && iter != lst.end()) iter++;
		else if(c == 'B' && iter != lst.begin()) iter = lst.erase(--iter);//erase는 해당 이터의 리스트값을 지우고 다음 이터를 반환한다
		else if(c == 'P')
		{
			cin >> c;
			lst.insert(iter, c);
		}
	}
	for(iter = lst.begin(); iter != lst.end();iter++)
		cout << *iter;
	cout << "\n";
}