/* Z */
/* 13:39 ~ 14:30 */
#include <iostream>
#include <cmath>
using namespace std;

void recur(int n, int r, int c, int cnt)
{
	long long len, quadrant;
	len = (int)pow(2,n); // 한변의 길이 이다.
	quadrant =len*len/4; // 나중에 몇사분면에 있는지에 따라 곱해주는 값
	if(n==1)
	{
		if(r==0 && c==1) cnt+=1; // 2사분면
		else if(r==1 && c==0) cnt+=2; // 3사분면
		else if(r==1 && c==1) cnt+=3; // 4사분면
		cout << cnt << "\n";
		return ;
	}
	if(r<len/2)
	{
		if(c<len/2) recur(n-1,r,c,cnt); // 1사분면 이면 그대로
		else recur(n-1,r,c-len/2,cnt+quadrant); // 2사분면 이면 1사분면까지의 칸수인 quadrant를 더해준다.
	}
	else
	{
		if(c<len/2) recur(n-1,r-len/2,c,cnt+quadrant*2); // 3사분면 이면 2사분면까지의 칸수인 quadrant*2를 더해준다.
		else recur(n-1,r-len/2,c-len/2,cnt+quadrant*3); // 4사분면 이면 3사분면까지의 칸수인 quadrant*3를 더해준다.
	}
	return ;
}

int main()
{
	int n,r,c;
	cin >> n >> r >> c;
	recur(n,r,c,0);
}