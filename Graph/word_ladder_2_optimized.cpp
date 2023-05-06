#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
unordered_map<string,int>mp;
vector<vector<string>>ans;
string beg;

void dfs(string word , vector<string>&seq)
{
    if(word==beg)
    {
        reverse(seq.begin(),seq.end());
        ans.push_back(seq);
        reverse(seq.begin(),seq.end());
        return;
    }
    int steps = mp[word];
    int sz=word.size();
    for(int i=0;i<sz;i++)
    {
        char original = word[i];
        for(char ch='a';ch<='z';ch++)
        {
            word[i]=ch;
            if(mp.find(word)!=mp.end() && mp[word]+1==steps)
            {
                seq.push_back(word);
                dfs(word,seq);
                seq.pop_back();
            }
        }
        word[i]=original;
    }
    

} 

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<string>q;
        q.push({beginWord});

        mp[beginWord]=1;
        st.erase(beginWord);

        beg = beginWord;
        int sz= beginWord.size();
        while(!q.empty())
        {
            string word = q.front();
            int steps = mp[word];
            q.pop();

            if(word==endWord)break;

            for(int i=0;i<sz;i++)
            {
                char original = word[i];
                for(char ch='a';ch<='z';ch++)
                {
                    word[i]=ch;
                    if(st.count(word)>0)
                    {
                        q.push(word);
                        st.erase(word);
                        mp[word]=steps+1;
                    }
                }
                word[i]=original;
            }

           

        }
        if(mp.find(endWord)!=mp.end())
        {
            vector<string>seq;
            seq.push_back(endWord);
            dfs(endWord,seq);
        }
        return ans;
    }
};