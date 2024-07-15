class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        if(head == NULL || head -> next == NULL) return head;
        
        Node* zero = new Node(-1);
        Node* one = new Node(-1);
        Node* two = new Node(-1);
        
        Node* zerohead = zero;
        Node* onehead = one;
        Node* twohead = two;
        
        while(head != NULL)
        {
            if(head -> data == 0)
            {
                zero -> next = head;
                zero = zero -> next;
            }
            else if(head -> data == 1)
            {
                one -> next = head;
                one = one -> next;
            }
            else
            {
                two -> next = head;
                two = two -> next;
            }
            head = head -> next;
        }
        
        two -> next = NULL;
        
        if(onehead -> next == NULL) 
        {
            zero -> next = twohead -> next;
        }
        else
        {
            zero -> next = onehead -> next;
            one -> next = twohead -> next;
        }
        return zerohead -> next;
    }
};