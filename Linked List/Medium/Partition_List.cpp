class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head -> next == NULL) return head;

        ListNode* less = new ListNode(-1);
        ListNode* more = new ListNode(-1);

        ListNode* lesshead = less;
        ListNode* morehead = more;

        while(head != NULL)
        {
            if(head->val < x)
            {
                less -> next = head;
                less = less -> next;
            }
            else
            {
                more -> next = head;
                more = more -> next;
            }
            head = head -> next;
        }

        more -> next = NULL;
        if(lesshead -> next != NULL)
        {
            less -> next = morehead -> next;
            return lesshead -> next;
        }
        return morehead -> next;
    }
};