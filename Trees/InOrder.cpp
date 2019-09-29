void InOrder(Node *root) {
        Node *reference = root;

        if(reference == nullptr)
        {
            return;
        }

        postOrder(reference->left);
        cout<<reference->data<<" ";
        postOrder(reference->right);
        
    }