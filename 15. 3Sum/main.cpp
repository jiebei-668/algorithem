#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ret;
		int first = 0;
		int second, third;
		sort(nums.begin(), nums.end());
		for(first = 0; first < nums.size()-2; first++)
		{
			if( first > 0 && nums[first] == nums[first-1]) continue;
			for(second = first+1, third = nums.size()-1; second < third; )
			{
				int sum = nums[first] + nums[second] + nums[third];
				if(sum == 0)
				{
					ret.push_back({nums[first], nums[second], nums[third]});
					while(second+1 < nums.size() && nums[second] == nums[++second]);
					while(third-1 > first && nums[third] == nums[--third]);
				}
				else if(sum < 0)
				{
					second++;
				}
				else
				{
					third--;
				}
			}
		}
		return ret;
        
    }
};
