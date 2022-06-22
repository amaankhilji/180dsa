/*

    Time Complexity: O(N * (2 ^ (N - 1)))
    Space Complexity: O(N* (2 ^ (N - 1)))
    
    Where N is the length of the string S.

*/

#include <unordered_map>
#include <unordered_set>

vector<string> wordBreakHelper(string &s, int idx, unordered_set<string> &dictSet, unordered_map<int, vector<string>> &dp, int size)
{
    // Base Condition
    if (idx == size)
    {
        return {""};
    }

    // Already has a solution for the current sentence, simply return the solution.
    if (dp.find(idx) != dp.end())
    {
        return dp[idx];
    }

    vector<string> subPart, completePart;
    string word = "";

    /*
        Start exploring the sentence from the index until we wouldn't find 'j' such that substring [index,j] exists in the dictionary as a word.
    */
    for (int j = idx; j < size; j++)
    {

        word.push_back(s[j]);
        if (dictSet.count(word) == 0)
        {
            continue;
        }

        // Get the answer for rest of sentence from 'j' to s.size().
        subPart = wordBreakHelper(s, j + 1, dictSet, dp, size);

        // Append "word" with all the answer that we got.
        for (int i = 0; i < subPart.size(); i++)
        {
            if (subPart[i].size() != 0)
            {
                string temp = word;
                temp.append(" ");
                temp.append(subPart[i]);
                subPart[i] = temp;
            }
            else
            {
                subPart[i] = word;
            }
        }

        for (int i = 0; i < subPart.size(); i++)
        {
            completePart.push_back(subPart[i]);
        }
    }

    // Store all the answer for the current index in the map
    dp[idx] = completePart;

    return dp[idx];
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // dp[idx] will store the all possible sentence which have been formed from the current index 'idx' to end of the given s.
    unordered_map<int, vector<string>> dp;

    //  Set to check whether any word exists in the dictionary or not.
    unordered_set<string> dictSet;

    for (int i = 0; i < dictionary.size(); i++)
    {
        dictSet.insert(dictionary[i]);
    }
    return wordBreakHelper(s, 0, dictSet, dp, s.size());
}
