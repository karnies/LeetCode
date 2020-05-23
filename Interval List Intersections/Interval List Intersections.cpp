class Solution {
public:
	vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
		int sizeA = A.size();
		int sizeB = B.size();
		int i, j;

		if (sizeA == 0 || sizeB == 0)
			return {};

		vector<vector<int>> ret;
		ret.reserve(max(sizeA, sizeB));
		i = j = 0;
		while (i < sizeA && j < sizeB)
		{

			// check not intersect
			if (B[j][0] > A[i][1])
			{
				i++;
				continue;
			}
			// check not intersect
			if (B[j][1] < A[i][0])
			{
				j++;
				continue;
			}

			// max start and min end is intersect
			vector<int> a({ max(A[i][0], B[j][0]), min(A[i][1], B[j][1]) });
			ret.emplace_back(a);

			// Change the block in front of the end point 
			if (A[i][1] < B[j][1])
				i++;
			else if (A[i][1] > B[j][1])
				j++;
			else
			{
				i++;
				j++;
			}
		}

		return ret;
	}
};
