Node* merge(Node* root,Node* temp)
{
    Node* newlist = new Node(-1);
    Node* newhead = newlist;
    
    while(root != NULL && temp != NULL)
    {
        if(root->data <= temp->data)
        {
            newhead -> bottom = root;
            newhead = newhead -> bottom;
            root = root -> bottom;
        }
        else
        {
            newhead -> bottom = temp;
            newhead = newhead -> bottom;
            temp = temp -> bottom;
        }
    }
    
    while(root != NULL)
    {
        newhead -> bottom = root;
        root = root -> bottom;
        newhead = newhead -> bottom;
    }
    
    while(temp != NULL)
    {
        newhead -> bottom = temp;
        temp = temp -> bottom;
        newhead = newhead -> bottom;
    }
    
    return newlist -> bottom;
}

Node *flatten(Node *root) {
    // Your code here
    if(root == NULL || root->next == NULL) return root;
    Node* temp = flatten(root->next);
    root = merge(root,temp);
    return root;
}