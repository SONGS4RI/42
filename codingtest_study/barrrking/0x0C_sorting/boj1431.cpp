/* 시리얼 번호 */
/* 14:50 ~  15:39 */
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int compare(string a, string b) // 스트링을 매개변수로 받을때는 다른 자료형들과 달리 포인터로 안받아도 된다.
{
	int a_len = a.size(), b_len = b.size();
	int a_sum = 0, b_sum = 0;
	if(a_len != b_len) return (a_len < b_len); // 길이가 다르다면 작은길이가 앞에가도록 정렬
	else
	{
		for(int i=0;i<a_len;i++)
			if(isdigit(a[i])) a_sum += a[i] - '0';
		for(int i=0;i<b_len;i++)
			if(isdigit(b[i])) b_sum += b[i] - '0';
		if(a_sum != b_sum) return (a_sum < b_sum); // 수의 합이 같지 않다면 작은수가 앞으로
		return a < b; // 사전순으로 정렬
	}
}

int main()
{
	int n;
	cin >> n;
	string s[n];
	for(int i=0;i<n;i++) cin >> s[i];
	sort(s, s+n, compare);
	for(auto c : s) cout << c << "\n";
}