class Solution {
public:
	static bool comp(vector<int>& a,vector<int>& b){
		if(a[0]==b[0]) return a[1]>b[1];
		return a[0]<b[0];
	}

	int maxEnvelopes(vector<vector<int>>& env) {
		int n=env.size();
		sort(env.begin(),env.end(),comp);   
		vector<int> temp;
		temp.push_back(env[0][1]); //height daali phle ki
		for(int i=1;i<n;i++){
			if(temp.back()<env[i][1]) temp.push_back(env[i][1]); //last element aage wala
			else{
				int ind=lower_bound(temp.begin(),temp.end(),env[i][1])-temp.begin(); // lower bound that is not less than height of the 2nd envelope then by -begin, index is calculated
				temp[ind]=env[i][1];
			}
		}
		return temp.size();
	}
};