/* 단어 정렬 */
/* 14:57 ~ 15:12 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int compare(string a, string b)
{
	int alen = a.size();
	int blen = b.size();
	if (alen != blen) return (alen < blen); //  문자열 길이가 다르면 작은순 먼저
	return (a < b); // 같다면 사전순
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n;
	vector<string> v;
	string s;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(),v.end(),compare); // 먼저 정렬을 해준뒤
	v.erase(unique(v.begin(),v.end()),v.end()); // unique함수로 중복원소를 뒤로 미룬후 지워준다.
	for(auto c : v) cout << c << "\n";
}