//给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回新的头节点 。
#include<stdio.h>
#include<stdlib.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//	struct ListNode* cur;
//	struct ListNode* curprv;
//	if(head==NULL)
//	{
//		return head;
//	}
//	else
//	{
//	while(head->val==val)
//	{
//		head=head->next;
//	}
//	cur=head->next;
//	curprv=head;
//	while(cur)
//	{
//		if(cur->val==val)
//		{
//			curprv->next=cur->next;
//			cur=cur->next;
//		}
//		else
//		{
//			curprv=cur;
//			cur=cur->next;
//		}
//	}
//	return head;
//	}
//}
struct ListNode* removeElements(struct ListNode* head, int val){
	struct ListNode* cur=head;
	struct ListNode* curprv=NULL;
    if(head==NULL)
    {
        return head;
    }
    else{
while(head!=NULL&&head->val==val)
	{
		head=head->next;
        free(cur);
		cur=head;
	}
	curprv=head;
	while(cur)
	{
		if(cur->val==val)
		{
			curprv->next=cur->next;
            free(cur);
			cur=curprv->next;
		}
		else
		{
			curprv=cur;
			cur=cur->next;
		}
	}
	return head;
    }
}
void ListNodePrint(struct ListNode* head)
{
	while(head)
	{
		printf("%d",head->val);
		head=head->next;
	}
	printf("\n");
}
int main()
{
	struct ListNode* n1=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n2=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n3=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n4=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* tmp;
	n1->val=7;
	n2->val=7;
	n3->val=7;
	n4->val=7;
	n1->next=n2;
	n2->next=n3;
	n3->next=n4;
	n4->next=NULL;
	ListNodePrint(n1);
	tmp=removeElements(n1,7);
	ListNodePrint(tmp);
}