class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        while(n--) ptr2 = ptr2 -> next;

        if(ptr2 == NULL) return ptr1 -> next;

        while(ptr2 -> next != NULL)
        {
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }

        ptr1 -> next = ptr1 -> next -> next;
        return head;
    }
};