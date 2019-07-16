class Solution {
public:
    ListNode* deleteDuplicates83(ListNode* head) {
        
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode* cur = head;
        while(cur!=NULL && cur->next != NULL){
            while(cur->val == cur->next->val){
                ListNode*delnode = cur->next;
                cur->next = delnode->next;
                delete delnode;
                if(cur->next == NULL)
                    break;
            }
            cur = cur->next;
        }
        ListNode* resnode =  dummyhead->next;
        delete dummyhead;
        return resnode;
    }
};