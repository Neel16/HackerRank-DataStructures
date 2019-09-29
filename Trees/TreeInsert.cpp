   Node * insert(Node * root, int data) {

    Node * reference = root;
   Node *rs = nullptr; 
   Node *ls = nullptr;
   
   if(root == nullptr){
       root = new Node(data);
       //root->data = value;
       root->left = root->right = nullptr;
   }
   
   while(reference != nullptr){
       if(data < reference->data){
           if(reference->left == nullptr) 
              ls = reference;
           reference = reference->left;
       } else if(data > reference->data) {
           if(reference->right == nullptr) 
              rs = reference;
           reference = reference->right;
       }
   }
   
   reference = new Node(data);
   //r->data = data;
   reference->left = reference->right = nullptr;
   if(ls != nullptr) 
      ls->left = reference;
   if(rs != nullptr) 
      rs->right = reference;
   
   return root;
}