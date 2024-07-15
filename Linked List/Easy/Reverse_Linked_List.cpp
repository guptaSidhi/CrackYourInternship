class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL){
            ListNode* fut = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = fut;
        }
        return prev;
    }
};