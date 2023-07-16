class Solution {
public:
    int n,m;
    int target_mask;
    vector<int>ans;
    void helper(int i,int mask,vector<int>&ds,vector<int>&peopleSkills,vector<vector<int>>&dp)
    {
        if(i>=m)
        {
            if(mask==target_mask)
            {
                if(ans.size()==0 || ans.size()>ds.size())
                {
                    ans=ds;
                }
            }
            return;
        }
        if(ans.size()!=0 && ds.size()>=ans.size())
        return;
        //if result is not updated first time and current size of hired people becomes greater we return the function , bcoz we only need minimum ans
        if(dp[i][mask]!=-1)
        {
            if(dp[i][mask]<=ds.size())
            return;
        }

        helper(i+1,mask,ds,peopleSkills,dp);

        if(peopleSkills[i]==0)//no skill but will not change mask so can be added to ans later so we skip this
        return;

        ds.push_back(i);
        helper(i+1,mask|peopleSkills[i],ds,peopleSkills,dp);
        ds.pop_back();

        if(ds.size()>0)
        dp[i][mask]=ds.size();

        
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        n = req_skills.size();
        m = people.size();

        map<string,int>mp;//skills-->index...for bitmasking
        for(int i=0;i<n;i++)
        {
            mp[req_skills[i]]=i;//java-->0,nodejs-->1,reactjs-->2
        }
        vector<int>peopleSkills;

        for(int i=0;i<m;i++)
        {
            int skill_mask=0;
            for(int j=0;j<people[i].size();j++)
            {
                skill_mask = skill_mask | (1<<mp[people[i][j]]);
            }
            peopleSkills.push_back(skill_mask);
        }

        target_mask = pow(2,n)-1;//we need all skills in req_skills;
        vector<int>ds;
        vector<vector<int>>dp(m,vector<int>(1<<16,-1));
        helper(0,0,ds,peopleSkills,dp);
        return ans;

    }
};