//Task 2
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
Node* newNode(int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void zizagtraversal(struct Node* root)
{
    // if null then return
    if (!root)
    {
        return;
    }

    stack< Node*> currentlevel;
    stack< Node*> nextlevel;

    // push the root
    currentlevel.push(root);

    // check if stack is empty
    bool lefttoright = true;
    while (!currentlevel.empty())
    {
        // pop out of stack
        Node* temp = currentlevel.top();
        currentlevel.pop();

        // if not null
        if (temp)
        {
            cout << temp->data << " ";

            if (lefttoright) {
                if (temp->left)
                    nextlevel.push(temp->left);
                if (temp->right)
                    nextlevel.push(temp->right);
            }
            else {
                if (temp->right)
                    nextlevel.push(temp->right);
                if (temp->left)
                    nextlevel.push(temp->left);
            }
        }

        if (currentlevel.empty()) {
            lefttoright = !lefttoright;
            swap(currentlevel, nextlevel);
        }
    }
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    cout << "ZigZag traversal of binary tree is:-";
    zizagtraversal(root);
    return 0;
}
