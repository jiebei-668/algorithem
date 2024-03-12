#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int half_cnt = (nums1.size() + nums2.size())/2;
		int first1 = 0;
		int first2 = 0;
		int mid1, mid2;
		int processed_cnt = 0;
		double smaller = 0.0;
		while(processed_cnt < half_cnt)
		{
			mid1 = (first1 + nums1.size()-1)/2;
			mid2 = (first2 + nums2.size()-1)/2;
			if(nums1[mid1] < nums2[mid2])
			{
				if(half_cnt - processed_cnt < mid1-first1+1)
				{
					first1 += half_cnt - processed_cnt;
					smaller = nums1[first1-1];
					processed_cnt = half_cnt;
					break;
				}
				else
				{
					processed_cnt += (mid1-first1+1);
					first1 = mid1+1;
					smaller = nums1[first1-1];
				}
			}
			else
			{
				if(half_cnt - processed_cnt < mid2-first2+1)
				{
					first2 += half_cnt - processed_cnt;
					smaller = nums2[first2-1];
					processed_cnt = half_cnt;
					break;
				}
				else
				{
					processed_cnt += (mid2-first2+1);
					first2 = mid2+1;
					smaller = nums2[first2-1];
				}
			}
		}
		if((nums1.size()+nums2.size())%2 == 1)
		{
			if(first1 < nums1.size() && first2 < nums2.size())
			{
				return min(nums1[first1], nums2[first2]);
			}
			else if(first1 < nums1.size())
			{
				return nums1[first1];
			}
			else
			{
				return nums2[first2];
			}
		}
		//return (smaller + min(nums1[first1], nums2[first2]))/2;
		if(first1 < nums1.size() && first2 < nums2.size())
		{
			return (smaller + min(nums1[first1], nums2[first2]))/2;
		}
		else if(first1 < nums1.size())
		{
			return (smaller + nums1[first1])/2;
		}
		else
		{
			return (smaller + nums2[first2])/2;
		}

    }
};
int main(int argc, char* argv[])
{
	Solution s;
	vector<int> v1 = {1, 2};
	vector<int> v2 = {3, 4};
	s.findMedianSortedArrays(v1, v2);
	return 0;
}
