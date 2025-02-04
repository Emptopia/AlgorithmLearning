#include "Solution.h"

void Solution::printVector(vector<int>nums)
{
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void Solution::merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	vector<int>res = vector<int>();
	int left = 0;
	int right = 0;
	while (left != m && right != n)
	{
		if (nums1[left] < nums2[right])
		{
			res.push_back(nums1[left]);
			left++;
		}
		else
		{
			res.push_back(nums2[right]);
			right++;
		}
	}
	if (left == m )
	{
		while (right != n )
		{
			res.push_back(nums2[right]);
			right++;
		}
	}
	else
	{
		while (left != m )
		{
			res.push_back(nums1[left]);
			left++;
		}
	}
	
	nums1 = res;
}

int Solution::firstBadVersion(int n)
{
	int left = 1, right = n;
	while (left < right)	// 循环直至区间左右端点相同
	{ 
		int mid = left + (right - left) / 2; // 防止计算时溢出
		if (isBadVersion(mid)) 
		{
			right = mid; // 答案在区间 [left, mid] 中
		}
		else 
		{
			left = mid + 1; // 答案在区间 [mid+1, right] 中
		}
	}
	// 此时有 left == right，区间缩为一个点，即为答案
	return left;

}

bool Solution::isBadVersion(int version)
{
	int bad = 4;
	if (version >= bad)
		return true;
	else
		return false;
}

int Solution::climbStairs(int n)
{
	/* 动态规划五部曲：
	   * 1.确定dp[i]的下标以及dp值的含义： 爬到第i层楼梯，有dp[i]种方法；
	   * 2.确定动态规划的递推公式：dp[i] = dp[i-1] + dp[i-2];
	   * 3.dp数组的初始化：因为提示中，1<=n<=45 所以初始化值，dp[1] = 1, dp[2] = 2;
	   * 4.确定遍历顺序：分析递推公式可知当前值依赖前两个值来确定，所以递推顺序应该是从前往后；
	   * 5.打印dp数组看自己写的对不对；
	  */
	if (n <= 1) return n;
	/* 定义dp数组 */
	vector<int> dp(n + 1);			//size是n+1,才可以循环到dp[n]			,dp[0]+dp[1] = dp[2] = 2
	/* 初始化dp数组 */
	dp[1] = 1;
	dp[2] = 2;
	/* 从前往后遍历 */
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];

}

int Solution::maxProfit(vector<int>& prices)
{
	int profit = 0;
	int min = prices[0];
	for (int i = 0; i < prices.size(); i++)
	{
		if (prices[i] < min)
			min = prices[i];
		if (prices[i] - min > profit)
			profit = prices[i] - min;
	}
	return profit;
}

int Solution::maxSubArray(vector<int>& nums)
{
	int pre = 0, maxAns = nums[0];
	for (int x = 0; x < nums.size(); x++)
	//for(const auto& x:nums)			//使用此迭代器循环时，nums[x]换为x
	{
		pre = max(pre + nums[x], nums[x]);			//等同于max(累加，左指针)
																							//累加 < x 时，舍弃先前累加，累加 = x			累加 > x 时，不舍弃累加，累加=累加+x
		maxAns = max(maxAns, pre);						//最大值 = 最大累加值
	}
	return maxAns;

}

int Solution::rob(vector<int>& nums)
{
	if (nums.empty())
		return 0;
	int size = nums.size();
	if (size == 1)
		return nums[0];
	vector<int>dp = vector<int>(size, 0);		//加入size个0
	dp[0] = nums[0];
	dp[1] = max(nums[0], nums[1]);
	for (int i = 2; i < size; i++)
	{
		dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);			//注意这里是（i-2的最高金额+i房间金额）对比（i-1的最高金额）
	}
	return dp[size - 1];
}





