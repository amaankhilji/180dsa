#include <bits/stdc++.h>
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)

{

    // Write your code here.

    vector<vector<int> > mergeAns;

    sort(intervals.begin(), intervals.end());

    vector<int> pr = intervals[0];

    for (int i = 1; i < intervals.size(); i++)

    {

        if (intervals[i][0] <= pr[1])

        {

            pr[1] = max(pr[1], intervals[i][1]);

        }

        else

        {

            mergeAns.push_back(pr);

            pr = intervals[i];

        }

    }

    mergeAns.push_back(pr);



    return mergeAns;

}
