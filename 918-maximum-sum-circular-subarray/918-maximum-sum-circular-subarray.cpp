class Solution {
public:
   int MinSubArray(vector<int>& nums)
{
	int prefixSum = 0;
	int minSubarray = INT_MAX;
	int maxPrefixSoFar = INT_MIN;
	for (int i = 0; i < (int)nums.size(); i++)
	{
		prefixSum += nums[i];
		minSubarray = min(minSubarray, prefixSum);

		if (i)
			minSubarray = min(minSubarray, prefixSum - maxPrefixSoFar);


		maxPrefixSoFar = max(maxPrefixSoFar, prefixSum);

	}
	return minSubarray;
}

int MaxSubArray(vector<int>& nums)
{
	int prefixSum = 0;
	int maxSubarray = INT_MIN;
	int minPrefixSoFar = INT_MAX;
	for (int i = 0; i < (int)nums.size(); i++)
	{
		prefixSum += nums[i];
		maxSubarray = max(maxSubarray, prefixSum);

		if (i)
			maxSubarray = max(maxSubarray, prefixSum - minPrefixSoFar);


		minPrefixSoFar = min(minPrefixSoFar, prefixSum);

	}
	return maxSubarray;
}

int SumArray(vector<int>& nums)
{
	int sum = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		sum += nums[i];

	}
	return sum;
}
int maxSubarraySumCircular(vector<int>& nums) {
	
	int minSubArray = MinSubArray(nums);
	int maxSubArray = MaxSubArray(nums);
	int sum = SumArray(nums);

	if (minSubArray == sum)
		return maxSubArray;

	return max(maxSubArray, sum - minSubArray);

}


   
};