class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> qu;
        qu.push({beginWord,1});
        st.erase(beginWord);
        while(!qu.empty()){
            string word = qu.front().first;
            int count = qu.front().second;
            if(word == endWord) return count;
            qu.pop();
            for(int i = 0; i<word.size(); i++){
                char original = word[i];
                for(char j = 'a'; j<='z'; j++){
                    word[i] = j;
                    if(st.find(word)!=st.end()){
                        qu.push({word,count+1});
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};