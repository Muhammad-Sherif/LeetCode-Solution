class Solution {
public:
    int lengthOfLongestSubstring(string s) {
   
   
    vector<int> lastVisitedIndex(266 , -1);
	int start, end;
	start = end = 0;
	int maxSize = 0;
	string word = s;
	while (end < word.size())
	{
		if (lastVisitedIndex[word[end]] != -1)
		{
			int nextStart = lastVisitedIndex[word[end]] + 1;
			for (; start < nextStart; start++)
			{
				lastVisitedIndex[word[start]] = -1;
			}
		}
		lastVisitedIndex[word[end]] = end;
		maxSize = max(maxSize, end - start + 1);
		end++;

	}
	return maxSize;
   
        
    }
};