void postOrder(Node *root) {
        Node *reference = root;

        if(reference == nullptr)
        {
            return;
        }

        postOrder(reference->left);
        postOrder(reference->right);
        cout<<reference->data<<" ";
    }