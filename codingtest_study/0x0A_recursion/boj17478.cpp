/* 재귀함수가 뭔가요? */
/* 13:26 ~ 13:57 */
#include <iostream>
#include <string>
using namespace std;

string s[7] = {"어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n","\"재귀함수가 뭔가요?\"\n","\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n","마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n","그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n","\"재귀함수는 자기 자신을 호출하는 함수라네\"\n","라고 답변하였지.\n"};

void print_string(int cnt, int idx)
{
	for(int i=0;i<cnt;i++) cout << "____"; // 들어온 깊이 만큼 "____" 출력
	cout << s[idx];	//	idx의 문장 출력
}

void recur(int n, int cnt)// cnt는 재귀로 들어간 깊이를 의미한다.
{
	if (cnt==n) // 목표 깊이에 도달하면
	{
		print_string(cnt,1);
		print_string(cnt,5);
		print_string(cnt,6);
		return ;
	}
	for(int i=1;i<=4;i++) print_string(cnt,i);
	recur(n, cnt+1);
	print_string(cnt,6);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n;
	cin >> n;
	cout << s[0];
	recur(n,0);
}