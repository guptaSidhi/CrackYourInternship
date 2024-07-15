class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        long long ans = 0;
        long long mod = 1e9 + 7;
        
        long long first_data = 0;
        long long second_data = 0;
        while(first != NULL || second != NULL)
        {
            if(first != NULL) 
            {
                first_data = first_data*10 + first->data;
                first_data = first_data % mod;
                first = first -> next;
            }
            if(second != NULL)
            {
                second_data = second_data*10 + second->data;
                second_data = second_data % mod;
                second = second -> next;
            }
        }
        
        ans = (first_data * second_data) % mod;
        return ans;
    }
};