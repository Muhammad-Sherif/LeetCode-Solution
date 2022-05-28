class Solution {
public:
   vector<int> SuffixMax(vector<int>& height) {
	int n = (int)height.size();
	vector<int> suffixMax(n);
	for (int i = n - 1; i >= 0; i--)
	{
		if (i == n - 1)
			suffixMax[i] = height[i];
		else
			suffixMax[i] = max(height[i], suffixMax[i + 1]);
	}
	return suffixMax;

}


vector<int> PrefixMax(vector<int>& height) {
	int n = (int)height.size();
	vector<int> prefixMax(n);
	for (int i = 0; i < n; i++)
	{
		if (!i)
			prefixMax[i] = height[i];
		else
			prefixMax[i] = max(height[i], prefixMax[i - 1]);
	}
	return prefixMax;
}

int trap(vector<int>& height) {

	int n = height.size();
	int waterCount = 0;
	vector<int> prefixMax, suffixMax;
	prefixMax = PrefixMax(height);
	suffixMax = SuffixMax(height);
	for (int i = 1; i < n-1; i++)
	{
		if (prefixMax[i - 1] > height[i] && suffixMax[i + 1] > height[i])
			waterCount += min(prefixMax[i - 1], suffixMax[i + 1]) - height[i];

	}
	return waterCount;
}
};