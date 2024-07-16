class Solution {
public:
    pair<ListNode*,ListNode*> middle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast != NULL && fast -> next != NULL)
        {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        return {prev,slow};
    }

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

    void reorderList(ListNode* head) {
        if(head == NULL || head -> next == NULL || head -> next -> next == NULL) return; 
        
        pair<ListNode*,ListNode*> nodes = middle(head);
        ListNode* bef = nodes.first;
        ListNode* middle = nodes.second;

        bef -> next = NULL;
        ListNode* head2 = reverse(middle);

        ListNode* fhead = head;

        while(head->next != NULL && head2->next != NULL)
        {
            ListNode* temp = head -> next;
            ListNode* temp2 = head2 -> next;
            head -> next = head2;
            head2 -> next = temp;
            head = temp;
            head2 = temp2;
        }

        if(head -> next == NULL)
        {
            while(head2 != NULL)
            {
                head -> next = head2;
                head2 = head2 -> next;
                head = head -> next;
            }
        }

        head = fhead;
    }
};