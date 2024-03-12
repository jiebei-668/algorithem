class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
		int scores_a = 0;
		int scores_b = 0;
		// first: aliceValues[i] + bobValues[i]
		// second: idx in aliceValues (and also in bobValues)
		vector<pair<int, int>> a_add_b;
		a_add_b.resize(aliceValues.size());
		for(int ii = 0; ii < aliceValues.size(); ii++)
		{
			a_add_b[ii].first = aliceValues[ii] + bobValues[ii];
			a_add_b[ii].second = ii;
		}
		sort(a_add_b.begin(), a_add_b.end(), [&](const pair<int, int> &a, const pair<int, int> &b){
			return a.first > b.first;
		});
		for(int i = 0; i < a_add_b.size(); i++)
		{
			if((i%2))
			{
				scores_b += bobValues[a_add_b[i].second];
			}
			else
			{
				scores_a += aliceValues[a_add_b[i].second];
			}
		}
		if(scores_a < scores_b)
		{
			return -1;
		}
		else if(scores_a > scores_b)
		{
			return 1;
		}
		return 0;
    }
};
