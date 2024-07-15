class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL && list2 != NULL) return list2;
        else if(list1 != NULL && list2 == NULL) return list1;
        else if(list1 == NULL && list2 == NULL) return NULL;

        ListNode* newhead = new ListNode(-1);
        ListNode* temp = newhead;
        while(list1 != NULL && list2 != NULL)
        {
            if(list1->val <= list2->val)
            {
                temp -> next = new ListNode(list1->val);
                temp = temp -> next;
                list1 = list1 -> next;
            }
            else
            {
                temp -> next = new ListNode(list2->val);
                temp = temp -> next;
                list2 = list2 -> next;
            }
        }

        while(list1 != NULL)
        {
            temp -> next = new ListNode(list1->val);
            temp = temp -> next;
            list1 = list1 -> next;
        }

        while(list2 != NULL)
        {
            temp -> next = new ListNode(list2->val);
            temp = temp -> next;
            list2 = list2 -> next;
        }

        return newhead -> next;
    }
};