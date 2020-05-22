class Solution {
public:
	int countSquares(vector<vector<int>>& matrix) {
		// use dynamic-programming
		// store the number of sqaure that (i,j) is right-down element 
		int M = matrix.size();
		int N = matrix[0].size();
		int i, j;
		int total_squares = 0;

		// count up-lines 1s
		for (i = 0; i < N; i++)
			total_squares += matrix[0][i];

		// count left-lines 1s
		for (i = 1; i < M; i++)
			total_squares += matrix[i][0];

		// store the number of sqaure that (i,j) is right-down element 
		// if left, up, left-up square is nxn and (i,j) is 1, then current square is (n+1)x(n+1)
		for (i = 1; i < M; i++)
		{
			for (j = 1; j < N; j++)
			{
				if (matrix[i][j])
				{
					matrix[i][j] = min(min(matrix[i - 1][j], matrix[i][j - 1]), matrix[i - 1][j - 1]) + 1;
				}

				total_squares += matrix[i][j];
			}
		}

		return total_squares;
	}
};
