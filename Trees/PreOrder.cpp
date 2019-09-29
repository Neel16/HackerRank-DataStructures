//NON- RECURSIVE
void preOrder(Node *root) {
        Node *reference = new Node(3);
        Node *curr = root;

        if(root == nullptr)
            return;
        while(curr != nullptr)
        {
            cout<<curr->data<<" ";
            if(curr->left != nullptr && curr->right != nullptr)
            {
                   Node *pred = curr->left;
                   while(pred->right != nullptr)
                   {
                       pred=pred->right;
                   }
                   pred->right = curr->right;
            }
            if(curr->left != nullptr)
            {
                curr=curr->left;
            }
            else{
                curr=curr->right;
            }
         
        }
    }

    // RECURSIVE

    void preOrder(Node *root) {
        Node *reference = root;
        
        if(reference == nullptr)
            return;
        cout<<reference->data<<" ";
        preOrder(reference->left);
        preOrder(reference->right);
    }