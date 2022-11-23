#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int a[21] = {0,},m,b;
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

///////////다른 풀이_비트마스크////////////////
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