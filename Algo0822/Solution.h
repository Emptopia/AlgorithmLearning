#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<queue>

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	
};

class Solution
{
private:
	vector<int> vec;
	void traversal(TreeNode* root);
	bool check(TreeNode* u, TreeNode* v);

public:
	void printVector(vector<vector<int>>);
	void printLinkList(ListNode* list);

	ListNode* LinkList(vector<int> n);
	bool isPalindrome(ListNode* head);
	bool hasCycle(ListNode* head);
	int maxDepth(TreeNode* root);
	bool isValidBST(TreeNode* root);
	bool isSymmetric(TreeNode* root);
	vector<vector<int>> levelOrder(TreeNode* root);
	TreeNode* sortedArrayToBST(vector<int>& nums);
	TreeNode* helper(vector<int>& nums, int left, int right);

};


