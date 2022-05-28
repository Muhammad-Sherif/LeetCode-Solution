class Solution {
public:
    int trap(vector<int>& height) {
	int n = (int) height.size();
	vector<int> suffixMax(n);
	vector<int> prefixMax(n);
	int waterCount = 0;
	for (int i = 0; i < n; i++)
	{
		if (!i)
			prefixMax[i] = height[i];
		else
			prefixMax[i] = max(height[i] , prefixMax[i-1]);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		if(i == n-1)
			suffixMax[i] = height[i];
		else
			suffixMax[i] = max(height[i], suffixMax[i + 1]);
	}

	for (int i = 1; i < n-1; i++)
	{
		if (prefixMax[i - 1] > height[i] && suffixMax[i + 1] > height[i])
			waterCount += min(prefixMax[i - 1], suffixMax[i + 1]) - height[i];

	}
	return waterCount;
}
};