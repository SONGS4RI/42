/* 역원소 정렬 */
/* 14:00 ~  14:30 */
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n;
	vector<long long> v;
	cin >> n;
	string s[n];
	for(int i=0;i<n;i++)
	{
		cin >> s[i];
		reverse(s[i].begin(), s[i].end()); // 문자열을 뒤집어주는 함수이다. algorithm 헤더에 들어있다.
		v.push_back(atoll(s[i].c_str())); // s[i].c_str() 은 string을 const char *로 반환시켜주는 메서드이다.
	}
	sort(v.begin(), v.end());
	for(auto c : v) cout << c << "\n";
}

/*
	atoi는 인트 반환이어서 범위 넘어가는 값들어오면 잘못된 값이 출력된다.
	long long 형으로 반환 받아야 할때는 atoll을 사용하면 된다.
*/