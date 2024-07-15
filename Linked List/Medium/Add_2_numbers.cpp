class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev =  NULL;
        ListNode* curr = head;
        while(curr != NULL)
        {
            ListNode* fut = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = fut;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode* temp = new ListNode(-1);
        ListNode* trav = temp;

        int carry = 0;
        while(l1 != NULL || l2 != NULL || carry != 0)
        {
            int sum = carry;
            if(l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            trav -> next = new ListNode(sum%10);
            trav = trav -> next;
            carry = sum/10;
        }

        return reverse(temp->next);
    }
};