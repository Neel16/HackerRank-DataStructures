#include <bits/stdc++.h>	

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};
*/

    void levelOrder(Node * root) {

        queue<Node*> q;

        if(root == nullptr)
            return;
        
        q.push(root);

        while(!q.empty())
        {
            Node * temp = q.front();
            q.pop();

            cout<<temp->data<<" ";

            if(temp->left != nullptr)  
                q.push(temp->left);
            if(temp->right != nullptr)
                q.push(temp->right);
        }

        //Lets say the root has two children. In the first iteration of while loop temp = root(its in the queue)
        //, pop that node from queue and print. Now we push back left child and right child. Left child will be 
        //the front of queue. Next iteration of While loop, temp= left child(level 2). Pop it from queue and print.
        // add 3rd level left child and right child to queue. They will go after 2nd level right child. 
        //Hench, next while iteration will have temp = right child(level 2). pop and print. keep going.

    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.levelOrder(root);
    return 0;
}
