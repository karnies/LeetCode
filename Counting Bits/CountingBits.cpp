#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {

        // The number of 1s of 2^i ~ (2^(i+1))-1 is +1 to the number of 1s of 0~(2^i)-1.
        vector<int> answer(num+1);
        answer[0] = 0;
        for(int i = 1; i <=num; )
        {
            int cnt = i;
            for(int j = 0; j < cnt && i <=num; j++, i++)
            {
                answer[i] = answer[j] + 1;
            }
        }

        return answer;
    }
};
