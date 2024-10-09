#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to return the postOrder
// traversal of a binary tree using
// two stacks
vector<int> postOrder(Node* root) {
    // Vector to store
    // postorder traversal
    vector<int> postorder;

    // If the tree is empty,
    // return an empty traversal
    if(root == NULL){
        return postorder;
    }

    // Two stacks for
    // iterative traversal
    stack<Node*> st1, st2;

    // Push the root node
    // onto the first stack
    st1.push(root);

    // Iterative traversal to populate
    // st2 with nodes in postorder
    while(!st1.empty()){
        // Get the top node from st1
        root = st1.top();
        st1.pop();

        // Push the node onto st2
        st2.push(root);

        // Push left child onto st1 if exists
        if(root->left != NULL){
            st1.push(root->left);
        }

        // Push right child onto st1 if exists
        if(root->right != NULL){
            st1.push(root->right);
        }
    }

    // Populate the postorder traversal 
    // vector by popping st2
    while(!st2.empty()){
        postorder.push_back(st2.top()->data);
        st2.pop();
    }

    // Return the
    // postorder traversal
    return postorder;
}




// Function to print the
// elements of a vector
void printVector(const vector<int>& vec) {
    // Iterate through the vector
    // and print each element
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function
int main()
{
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Getting postorder traversal
    vector<int> result = postOrder(root);

    // Printing the postorder
    // traversal result
    cout << "Postorder traversal: ";
    printVector(result);

    return 0;
}
                            
                        