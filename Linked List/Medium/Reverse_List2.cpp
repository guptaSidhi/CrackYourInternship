class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr != NULL)
        {
            ListNode* fut = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = fut;
        }

        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head -> next == NULL || left == right) return head;

        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode* temp = dummy;
        ListNode* first = NULL;
        ListNode* temp2 = NULL;
        ListNode* second = NULL;

        int cnt = 0;
        while(temp != NULL)
        {
            if(cnt == left-1)
            {
                first = temp;
                temp2 = temp -> next;
            }
            if(cnt == right)
            {
                second = temp -> next;
                temp -> next = NULL;
                break;
            }
            cnt++;
            temp = temp -> next;
        }

        ListNode* newlist = reverse(temp2);
        first -> next = newlist;

        temp = newlist;
        while(temp -> next != NULL) temp = temp -> next;
        temp -> next = second;
 
        return dummy -> next;
    }
};