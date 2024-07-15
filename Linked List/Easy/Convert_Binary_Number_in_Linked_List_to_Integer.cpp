class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
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

    int getDecimalValue(ListNode* head) {
        head = reverse(head);
        int index = 1;
        int ans = 0;
        while(head != NULL)
        {
            int value = head -> val;
            ans = ans + value*index;
            index = index*2;
            head = head -> next;
        }

        return ans;
    }
};