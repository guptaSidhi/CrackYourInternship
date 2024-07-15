class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        dummy -> next = head;

        while(temp->next != NULL && temp->next->next != NULL)
        {
            if(temp->next->val == temp->next->next->val)
            {
                int value = temp -> next -> val;
                ListNode* curr = temp -> next;
                while(curr != NULL && curr -> val == value) curr = curr -> next;
                if(curr != NULL) temp -> next = curr;
                else temp -> next = NULL;
            }
            else temp = temp -> next;
        }

        return dummy -> next;
    }
};