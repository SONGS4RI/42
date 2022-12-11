/* 에너그램 만들기 */
#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	string s1,s2;
	int arr[26]={0,},ans=0;
	cin >> s1 >> s2;
	for(int i=0;i<s1.size();i++)
		arr[s1[i]-'a']++;
	for(int i=0;i<s2.size();i++)
		arr[s2[i]-'a']--;
	for(int i=0;i<26;i++)
	{
		if(arr[i] != 0)
			ans += abs(arr[i]);
	}
	cout << ans << "\n";
}