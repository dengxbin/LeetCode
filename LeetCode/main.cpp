#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

// Definition for binary tree
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> result;

    if (root != NULL) {
      result.push_back(root->val);

      vector<int> left = preorderTraversal(root->left);
      result.insert(result.end(), left.begin(), left.end());

      vector<int> right = preorderTraversal(root->right);
      result.insert(result.end(), right.begin(), right.end());
    }

    return result;
  }
};
int main() {
	struct TreeNode* root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	root->val = 1;
	struct TreeNode* node1_2 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	node1_2->val = 2;
	root->left = NULL;
	root->right = node1_2;
	struct TreeNode* node2_3 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	node2_3->val = 3;
	node1_2->left = node2_3;
	node1_2->right = NULL;
	struct TreeNode* node2_3 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	node2_3->left = NULL;
	node2_3->right = NULL;

	int returnSize = 0;
	Solution1 S1;
	vector<int> vals = S1.preorderTraversal(root);
		
	assert(vals[0] == 1);
	assert(vals[1] == 2);
	assert(vals[2] == 3);
	getchar();
  return 0;
}