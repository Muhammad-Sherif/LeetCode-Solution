class Solution {
public:
int maxSubArray(vector<int>& nums)
{
	int max_so_far = INT_MIN, max_ending_here = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		max_ending_here = max_ending_here + nums[i];
		if (max_so_far < max_ending_here)
			max_so_far = max_ending_here;

		if (max_ending_here < 0)
			max_ending_here = 0;
	}
	return max_so_far;
}
int maxAbsoluteSum(vector<int>& nums) {

	vector<int> numsWithReverseSign(nums.size());
	for (int i = 0; i < nums.size(); i++)
	{
		numsWithReverseSign[i] = nums[i] * -1;

	}
	return max(maxSubArray(nums), maxSubArray(numsWithReverseSign));

}
};