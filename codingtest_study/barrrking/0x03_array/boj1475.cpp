/* 방 번호 */
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n,arr[9]={0,},ans=0;
	cin >> n;
	while(n>0)
	{
		if(n%10==6 || n%10==9) arr[6]++;
		else arr[n%10]++;
		n/=10;
	}
	if(arr[6]%2==1) arr[6] = arr[6]/2 + 1;
	else arr[6] /= 2;
	for(int i=0;i<9;i++) ans = max(ans,arr[i]);
	cout << ans << "\n";
}