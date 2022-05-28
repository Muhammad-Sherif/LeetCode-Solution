class Solution {
public:
    int maxSubArray(vector<int>& nums)
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

};