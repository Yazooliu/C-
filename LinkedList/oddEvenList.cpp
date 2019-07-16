/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Example1:
// Input: 2->1->3->5->6->4->7->NULL
// Output: 2->3->6->7->1->5->4->NULL
class Solution328 {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* odd  = head;
        ListNode* even = head->next;
        ListNode* evenstartnode = even; // evenstartnode 是第一个even节点
        while(odd->next&&even->next)
        {
            odd->next = even->next;
            odd       = odd->next;
            even->next= odd->next;
            even      = even->next;
        }
        
        odd->next = evenstartnode; // 把odd的最后一个节点连接上evenstartnode,形成整个完整链表
        return head;
    }
};