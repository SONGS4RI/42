/* 숫자의 개수 */
#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int a,b,c,arr[10]={0,};
	cin >> a >> b >> c;
	a *= b*c;
	while(a>0)
	{
		arr[a%10]++;
		a/=10;
	}
	for(int i=0;i<10;i++)
		cout << arr[i] << "\n";
}