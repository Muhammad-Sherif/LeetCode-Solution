class Solution {
public:
    int lengthOfLongestSubstring(string s) {
   
        
   vector<pair<int , int >> wordFreqWithLastIndex(266);
	int start, end;
	start = end = 0;
	int maxSize = 0;
	string word = s;

	while (end < word.size())
	{
		int charIndex = word[end];
		if (wordFreqWithLastIndex[charIndex].first == 0)
		{
			wordFreqWithLastIndex[charIndex].first = 1;
			wordFreqWithLastIndex[charIndex].second = end;
			maxSize = max(maxSize,end-start+1);
			end++;
		}
		else
		{
			int charLastIndex = wordFreqWithLastIndex[charIndex].second + 1;
			for (int counter = start; counter <= wordFreqWithLastIndex[charIndex].second; counter++)
			{
				wordFreqWithLastIndex[word[counter]].first = 0;
				wordFreqWithLastIndex[word[counter]].second = 0;
			}
			start = charLastIndex;
		}


	}

	return maxSize;
        
    }
};