#include <iostream>//틀렸음///
using namespace std;

int n,num,vote=0,vote_max,idx=1;
int student[101]= {0,},order[101]={0,};

int find_min(void)// 최소 추천수 탐색
{
	int student_min = 1001;
	for(int i=1;i<101;i++)
	{
		if(student[i])
			student_min = min(student_min,student[i]);
	}
	return (student_min);
}

int find_oldest(void)
{
	int idx_min=101,student_min;
	student_min = find_min();
	for(int i=1;i<101;i++)
	{
		if(student[i] == student_min)
			idx_min = min(idx_min,order[i]);
	}
	for(int i=1;i<101;i++)
	{
		if(student[i] == student_min && order[i] == idx_min)
			return (i);
	}
	return (0);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	cin >> vote_max;
	while (n>0 && vote < vote_max) // 꽉차기 전까지
	{
		cin >> num;
		if(!student[num])
		{
			n--;
			order[num] = idx++;
		}
		student[num]++;
		vote++;
	}
	while(vote < vote_max)
	{
		cin >> num;
		if(!student[num])// 최소투표자를 찾아서 갱신 해주어야 한다.
		{
			n = find_oldest();
			student[n] = 0;
			order[n] = 0;
			order[num] = idx++;
		}
		student[num]++;
		vote++;
	}
	for(int i=0;i<101;i++)
		if(student[i]!=0) cout << i << ' ';
}