/*
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

*/
#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    void preOrderTraversal(TreeNode *node){
    if(node == NULL)
        return;
    preOrderTraversal(node->left);
    cout<<" "<<node->val;
    preOrderTraversal(node->right);
    }
};

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
      TreeNode *common = commonAncestor(root , x ,y);
      int depth_x = findLevel(common, x)-1;
      int depth_y = findLevel(common,y)-1;
      #ifdef DEBUG
      cout<<"depth_x= "<<depth_x<<"depth_y= "<<depth_y<<endl;
      if(common != NULL){
            cout<<"\n"<<common->val<<endl;
        }
      #endif
        if(depth_x ==1 && depth_y ==1)
            return false;
      if(depth_x == depth_y)
        return true;


      return false;
    }
private:
    TreeNode* commonAncestor(TreeNode *node , int x , int y){
        if(node != NULL){
                if((node->val == x) || (node->val ==y))
                return node;
            TreeNode* left =commonAncestor(node->left,x,y);
            TreeNode* right =commonAncestor(node->right,x,y);
            if(left != NULL && right != NULL)
                return node;
            if(left)
                return left;
            if(right)
                return right;
        }
        return NULL;
    }

    int findLevel(TreeNode *node , int x )
    {
        if(node == NULL)
            return 0;
        int level = 0;
        if ((node->val == x) || (level = findLevel(node->left, x)) > 0
        || (level = findLevel(node->right, x)) > 0)
        {
            return level + 1;
        }
        return 0;

    }
};

int main(){
   TreeNode *root = new TreeNode(1);
   root->left = new TreeNode(2);
   root->right = new TreeNode(3);
   root->left->right = new TreeNode(4);
   root->right->right = new TreeNode(5);
   #ifdef DEBUG
    root->preOrderTraversal(root);
   #endif
   Solution s;
   std::cout << std::boolalpha;  // set the boolalpha var in std stream to print the string form of booleans
   cout<<s.isCousins(root,2,3)<<endl;
   cout<<s.isCousins(root,4,5);
   return 0;
}
