class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int right = 0;
		int left = 0;
		int cnt[255];
		memset(cnt, 0, sizeof(cnt));
		char repeating_char = ' ';
		int max_len = 0;
		while(right < s.size())
		{
			cnt[s[right]]++;
			right++;
			if(cnt[s[right-1]] == 1)
			{
				max_len = max(max_len, right-1-left+1);
				continue;
			}
			// cnt[s[right-1]-'a'] == 2
			repeating_char = s[right-1];
			while(s[left] != repeating_char)
			{
				cnt[s[left]] = max(0, cnt[s[left]]-1);
				left++;
			}
			cnt[s[left]]--;
			left++;
		}
		return max_len;
    }
};

