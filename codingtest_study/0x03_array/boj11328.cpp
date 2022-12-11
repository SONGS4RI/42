/* Strfry */
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n;
	cin >> n;
	while(n--)
	{
		string s1,s2;
		int arr1[26] = {0,}, arr2[26] = {0,}, err=0;
		cin >> s1 >> s2;
		for(int i=0;i<s1.size();i++)
		{
			arr1[s1[i]-'a']++;
			arr2[s2[i]-'a']++;
		}
		for(int i=0;i<26;i++)
		{
			if(arr1[i] != arr2[i])
				err = 1;
		}
		if(err) cout << "Impossible\n";
		else cout << "Possible\n";
	}
}