#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to build the tree recursively
node* buildTree() {
    int data;
    cout << "Enter node value (-1 for NULL): ";
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    node* root = new node(data);
    
    cout << "Enter left child of " << data << ": " << endl;
    root->left = buildTree();  // Recursively build left subtree

    cout << "Enter right child of " << data << ": " << endl;
    root->right = buildTree();  // Recursively build right subtree

    return root;
}

// Function to perform level order traversal
void levelOrderTraversal(node* root) {
    if (root == NULL) {
        cout << "Tree is empty." << endl;
        return;
    }

    queue<node*> q;
    q.push(root);
    q.push(NULL);  // Push NULL after the root to indicate the end of the first level

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;  // Separator for each level

            // If the queue is not empty, push NULL to mark the end of the next level
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";

            // Push left and right children of the node
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

void reverseLevelOrderTraversal(node* root) {
    if (root == NULL) {
        cout << "Tree is empty." << endl;
        return;
    }

    queue<node*> q;
    stack<vector<int>> s;  // Stack to store each level as a vector of nodes
    q.push(root);
    q.push(NULL);  // Push NULL after the root to mark the end of the first level

    vector<int> currentLevel;

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            // Store the current level in the stack
            s.push(currentLevel);

            // If the queue is not empty, push NULL to mark the end of the next level
            if (!q.empty()) {
                q.push(NULL);
            }

            // Clear current level for the next level's nodes
            currentLevel.clear();
        } else {
            // Add node to current level
            currentLevel.push_back(temp->data);

            // Push left and right children of the node in reverse order (right child first)
            if (temp->right) {
                q.push(temp->right);
            }
            if (temp->left) {
                q.push(temp->left);
            }
        }
    }

    // Print the levels in reverse order
    while (!s.empty()) {
        vector<int> level = s.top();
        s.pop();

        // Print the current level's nodes
        for (int i = 0; i < level.size(); i++) {
            cout << level[i] << " ";
        }

        cout << endl;
    }
}

void inorder(node* root){
    if(root == NULL){
        return ;
    }

    inorder(root->left);
    cout << root -> data << " ";
    inorder(root->right);
}

void preorder(node* root){
    if(root == NULL){
        return ;
    }

    cout << root -> data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root == NULL){
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root -> data << " ";
}
int main() {
    node* root = buildTree();  // Build the tree

    cout << "Level order traversal: "<< endl;
    levelOrderTraversal(root);  // Perform level order traversal

    cout << endl; 
    cout << "Reverse Level order traversal: "<< endl;
    reverseLevelOrderTraversal(root);
    
    cout << endl;
    cout << "Inorder traversal: "<< endl;
    inorder(root); 

    cout << endl;
    cout << "preorder traversal: "<< endl;
    preorder(root);

    cout << endl;
    cout << "postorder traversal: "<< endl;
    postorder(root);
}

