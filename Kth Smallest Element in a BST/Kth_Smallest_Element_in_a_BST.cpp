

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

int traversal(TreeNode* root, int k)
{

	int left_cnt = 0;
	int right_cnt = 0;
	if (root->left)
	{
		left_cnt = traversal(root->left, k);

		if (left_cnt <= 0)
			return left_cnt;
	}
	if (left_cnt + 1 == k)
		return root->val * -1;

	if (root->right)
	{
		right_cnt = traversal(root->right, k - left_cnt - 1);

		if (right_cnt <= 0)
			return right_cnt;
	}
	return left_cnt + 1 + right_cnt;
}

class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {

		// use inorder tree-traversal
		// meet target position, return minus value
		int result = traversal(root, k);

		if (result <= 0)
			return result * -1;

		return -1;
	}
};
