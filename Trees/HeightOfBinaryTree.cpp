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
#include<queue>
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    int height(Node* root) {
        // Write your code here.

        Node *reference = root;
        int lcount=0, rcount = 0;

        if(reference== nullptr)
            return 0;
        
        queue<Node *> q;
        q.push(reference);
        int height = 0;
        while(1)
        {
            int nodes = q.size();
            if(nodes == 0)
                return height-1;
            
            height++;

            while(nodes >0)
            {
                Node *newnode = q.front();
                q.pop();
                if(newnode->left != nullptr)
                    q.push(newnode->left);
                if(newnode->right != nullptr)
                    q.push(newnode->right);
                
                nodes--;
            }
        }

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
  
    int height = myTree.height(root);
    
  	std::cout << height;

    return 0;
}
