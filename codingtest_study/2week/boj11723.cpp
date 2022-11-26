#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0); // c의 stdio와 cpp 의 iostream을 동기화시켜주는데 이때
    cin.tie(0); // iostream 과 stdio의 버퍼를 둘다 사용하기 때문에 딜레이가 발생하기때문에
    string s;   // 이를 해제해주는것이다.
    int a[21] = {0,},m,b; // 알고리즘을 풀때는 싱글 쓰레드의 환경이기에 두 코드를 추가해주는 편이 좋다.
	cin >> m;
    while (m--)
    {
		cin >> s;
		if (s == "add")
        {
			cin >> b;
            a[b] = 1;
		}
		else if (s == "remove")
        {
			cin >> b;
            a[b] = 0;
		}
		else if (s == "check")
        {
			cin >> b;
            cout << a[b] << '\n';
		}
		else if (s == "toggle")
        {
			cin >> b;
            a[b] = 1 - a[b];
		}
		else if (s == "all") fill(a, a + 21, 1);
		else fill(a, a + 21, 0);
	}
}

///////////비트마스킹////////////////
// #include <iostream>
// #include <string>
// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);

//     int S=0;
//     int M; cin>>M;

//     while(M--){
//         int x;
//         string str; cin>>str;
//         if(str=="add"){
//             cin>>x;
//             S|=(1<<x);
//         }
//         else if(str=="remove"){
//             cin>>x;
//             S&=~(1<<x);
//         }
//         else if(str=="check"){
//             cin>>x;
//             cout<<(S&(1<<x)?1:0)<<'\n';
//         }
//         else if(str=="toggle"){
//             cin>>x;
//             S^=(1<<x);
//         }
//         else if(str=="all"){
//             S=(1<<21)-1;
//         }
//         else S=0;
//     }

//     return 0;
// }