/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Example1:
// Input: 1->2->3->3->4->4->5
// Output: 1->2->5
// Leetcode 82
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode* preprehead = dummyhead;
        ListNode* cur = head;
        while(cur!= NULL && cur->next != NULL){
            if(cur->val!= cur->next->val){
                preprehead->next = cur;
                // preprehead and cur 整体向前移1步
                preprehead       = preprehead->next;
                cur              = cur->next;
                
            }
            else // cur->val== cur->next->val
            {
                while(cur!=NULL&&cur->next!=NULL&&cur->val == cur->next->val){
                    cur = cur->next; // 相同val中的最后一个val所在的位置
                }
                cur = cur->next;     // cur 向前移动1步，新的cur节点，继续进行下一轮比较: cur->val== cur->next->val?
            }
  
        }
        preprehead->next = cur;
        ListNode* resnode = dummyhead->next;
        return resnode;
        delete dummyhead;
    }
};