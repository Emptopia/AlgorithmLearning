#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<numeric>
#include<algorithm>
class Solution
{
public:
	void VVprint(vector<vector<int>>v);
	int pivotIndex(vector<int>& nums);
	int searchInsert(vector<int>& nums, int target);
	vector<vector<int>> merge(vector<vector<int>>& intervals);
	bool isMerge(vector<int>v1, vector<int>v2);
};

