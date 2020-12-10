#define _CRT_SECURE_NO_WARNINGS 1
//leetcode链表的中间节点---快慢指针法

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* middleNode(struct ListNode* head){
	//快慢指针法
	struct ListNode *fast = head;
	struct ListNode *slow = head;

	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}