#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#include<algorithm>

class Solution
{
public:
	void printVV(vector<vector<int>>v);

	int hammingWeight(uint32_t n);

	int hammingDistance(int x, int y);

	uint32_t reverseBits(uint32_t n);

	vector<vector<int>> generate(int numRows);

	bool isValid(string s);

	int missingNumber(vector<int>& nums);
};

