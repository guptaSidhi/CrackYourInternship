class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL)
        {
            slow = slow -> next;
            if(fast -> next != NULL) fast = fast -> next -> next;
            else break;
            if(slow == fast) return true;
        }
        return false;
    }
};