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
	sort(v.begin(),v.end());//오름차순 정렬을 하는 이유는 작은 p_i분순서대로 합을 해야 최솟값이 되기 떄문
	for(int i=0;i<n;i++)
		res += (n - i) * v[i];//오름차순으로 정렬되었기때문에 순서대로 (n-i)만큼 곱해서 결과값에 더해주면 된다.
	cout << res;
}