class Solution
{
    public:
    Node* reverse(Node* head)
    {
        Node* curr = head;
        Node* prev = NULL;
        while(curr != NULL){
            Node* fut = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = fut;
        }
        return prev;
    }
    
    Node *compute(Node *head)
    {
        // your code goes here
        if(head == NULL || head -> next == NULL) return head;
        head = reverse(head);
        int maxi = head -> data;
        Node* temp = head;
        while(temp -> next != NULL)
        {
            if(temp -> next -> data < maxi)
                temp -> next = temp -> next -> next;
            else
            {
                maxi = max(maxi,temp -> next -> data);
                temp = temp -> next;
            }
        }
        head = reverse(head);
        return head;
    }
    
};