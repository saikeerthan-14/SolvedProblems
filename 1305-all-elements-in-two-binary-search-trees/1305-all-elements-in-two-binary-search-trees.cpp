/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* morris(TreeNode* root)
    {
        if(!root)
            return NULL;
        TreeNode* temp;
        TreeNode* temp2;
        TreeNode* start=NULL;
        while(root)
        {
            if(root->left)
            {
                temp=root->left;
                while(temp->right)
                    temp=temp->right;
                temp->right=root;
                temp=root->left;
                root->left=NULL;
                root=temp;
                if(start!=NULL)
                    temp2->right=root;
            }
            else
            {
                if(start==NULL)
                    start=root;
                temp2=root;
                root=root->right;
            }
        }return start;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        TreeNode* list1=morris(root1);
        TreeNode* list2=morris(root2);
        vector<int>v;
        while(list1&&list2)
        {
            if(list1->val>list2->val)
            {
                v.push_back(list2->val);
                list2=list2->right;
            }
            else
            {
                v.push_back(list1->val);
                list1=list1->right;
            }
        }
        while(list1)
        {
            v.push_back(list1->val);
            list1=list1->right;
        }
        while(list2)
        {
            v.push_back(list2->val);
            list2=list2->right;
        }return v;
    }
};