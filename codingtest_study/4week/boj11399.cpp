/* ATM */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n,num,res=0;
	vector<int> v;

	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(),v.end());//������������ ����
	for(int i=0;i<n;i++)
		res += (n - i) * v[i];
	cout << res;
}