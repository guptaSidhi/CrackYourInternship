class Solution{
public:
    Node* divide(int N, Node *head){
        if(head == NULL || head -> next == NULL) return head;
        Node* even = new Node(-1);
        Node* odd = new Node(-1);
        
        Node* evenhead = even;
        Node* oddhead = odd;
        
        while(head != NULL)
        {
            if(head->data % 2 == 0) 
            {
                even -> next = head;
                even = even -> next;
            }
            else
            {
                odd -> next = head;
                odd = odd -> next;
            }
            head = head -> next;
        } 
        
        odd -> next = NULL;
        
        if(evenhead -> next == NULL) return oddhead -> next;
        even -> next = oddhead -> next;
        return evenhead -> next;

    }
};