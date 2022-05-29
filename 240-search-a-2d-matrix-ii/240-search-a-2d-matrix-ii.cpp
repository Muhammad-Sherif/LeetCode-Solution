class Solution {
public:
bool FindCell(vector<vector<int>>& matrix, int target,int  i, int j, int n, int m)
{
	if (i == n || j == -1)
		return false;

	if (matrix[i][j] == target)
		return true;
	if (target > matrix[i][j])
	{
		return FindCell(matrix, target, i + 1, j, n, m);

	}
	else
	{
		return FindCell(matrix, target, i, j - 1, n, m);
	}

	

}

bool searchMatrix(vector<vector<int>>& matrix, int target) {

	int n = matrix.size();
	int m = matrix[0].size();
	return FindCell(matrix , target , 0, m - 1, n, m);

}
};