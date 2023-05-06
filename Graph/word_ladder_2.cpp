#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList){
        unordered_set<string>st(wordList.begin(),wordList.end());
        vector<vector<string>>ans;//storing the sequence

        queue<vector<string>>q;//queue of vector to store the intermediates sequences
        q.push({beginWord});

        vector<string>used_strings_on_level;
        used_strings_on_level.push_back(beginWord);

        int level= 0;

        while(q.empty()==false)
        {
            vector<string>v=q.front();
            q.pop();

            if(v.size()>level)//another string pushed ,means one level completed
            {
                level++;

                for(auto i:used_strings_on_level)
                {
                    st.erase(i);
                }
                used_strings_on_level.clear();//clearing the previous words..to reduce complexity
            }

            string word = v.back();//last word of the stored vector
            if(word==endWord)
            {
                ans.push_back(v);
            }

            for(int i=0;i<word.size();i++)
            {
                char original = word[i];
                for(char ch = 'a';ch<='z';ch++)
                {
                    word[i] = ch;
                    if(st.find(word)!=st.end())//if in set push in queue
                    {
                        v.push_back(word);
                        q.push(v);
                        used_strings_on_level.push_back(word);
                        v.pop_back();
                    }
                }
                word[i]=original;
            }

        }
        return ans;

    }
};