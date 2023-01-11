#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int	fd;
	char *s;
	struct s_list *next;
	struct s_list *back;
}t_list;

void del_list(t_list **target)
{
	printf("target가 가리키는 주소  : %p\n",target);
	printf("target가 가리키는 주소  : %p\n",t*arget);
	printf("*target가 가리키는 주소 : %p\n",**target->next);

}

void connect_list(t_list *first, t_list *second)
{
	printf("first가 가리키는 주소  : %p\n",first);
	printf("second가 가리키는 주소 : %p\n",second);
	first->next = second;
	second->back = first;
}

void func()
{
	static t_list *head;
	t_list *tmp1;
	t_list *tmp2;

	head = (t_list *)malloc(sizeof(t_list));
	head->s = (char *)malloc(sizeof(char)*10);
	tmp1 = (t_list *)malloc(sizeof(t_list));
	tmp1->s = (char *)malloc(sizeof(char)*10);
	tmp2 = (t_list *)malloc(sizeof(t_list));
	tmp2->s = (char *)malloc(sizeof(char)*10);

	printf("head가 가리키는 주소 : %p\n",head);
	printf("tmp1 가리키는 주소   : %p\n",tmp1);
	printf("tmp2 가리키는 주소   : %p\n",tmp2);
	printf("--------------------------------------------------------------\n");
	connect_list(head, tmp1);
	connect_list(tmp1, tmp2);
	printf("--------------------------------------------------------------\n");
	del_list(&tmp1);
}

int main()
{
	func();
}