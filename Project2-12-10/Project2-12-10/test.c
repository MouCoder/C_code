#define _CRT_SECURE_NO_WARNINGS 1
//leetcode������м�ڵ�---����ָ�뷨

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* middleNode(struct ListNode* head){
	//����ָ�뷨
	struct ListNode *fast = head;
	struct ListNode *slow = head;

	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}