/*
* @Author: zwyos
* @E-mail: so2os@mail.ustc.edu.cn
* @Date:   2017-04-02 20:57:29
* @Version: v1.0
* @Quesetion:  递归形式的数据翻转
* @Summary:  只需要考虑好一次是如何翻转的就好，剩下的是递归调用了
* @Last Modified by:   zwyos
* @Last Modified time: 2017-04-06 16:45:05
*/

#include <iostream>
#include <iterator>

using namespace std;

struct tnode
{
	int data;
	tnode * next;
};

tnode * reverse_recursive(tnode *head);

int main()
{
	tnode *head = NULL;
	for(int i = 0;i < 10;i++)
	{
		tnode *new_node = new tnode;
		new_node -> data = i * 10;
		new_node -> next = head;
		head = new_node;
	}

	head = reverse_recursive(head);
	tnode *iterator = head;
	while(iterator)
	{
	    cout << iterator -> data << '	';
	    iterator = iterator -> next;
	}
	
	return 0;
}

tnode * reverse_recursive(tnode *head)
{
	if(head == NULL || head->next == NULL)
		return head;
	tnode *second = head -> next;
	tnode *new_head = reverse_recursive(second);
	second -> next = head;
	head -> next = NULL;
	return new_head;
}
