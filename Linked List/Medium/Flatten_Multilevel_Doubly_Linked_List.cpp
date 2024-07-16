class Solution {
public:
    Node* flatten(Node* head) {

        for(Node*temp = head;temp != NULL;temp=temp->next)
        {
            if(temp -> child)
            {
                Node* curr = temp -> next;
                temp -> next = temp -> child;
                temp -> next -> prev = temp;
                temp -> child = NULL;
                Node* fut = temp -> next;
                while(fut -> next) fut = fut -> next;
                fut -> next = curr;
                if(curr) curr -> prev = fut;
            }
        }
        
        return head;
    }
};