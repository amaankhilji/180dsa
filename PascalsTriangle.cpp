#include <bits/stdc++.h>
vector<vector<long long int>> printPascal(int n)
{
	vector<vector<long long int>> ans(n);             // initialize n rows
	for (int i = 0; i < n; i++) {
		ans[i] = vector<long long int>(i + 1, 1);     // ith row(0-indexed) has i+1 elements
		for (int j = 1; j < i; j++)         // 1st and last elements will be 1, rest will be sum of two elements from above row
			ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
	}
	return ans;
}


// Using previous rows to make new rows
// The idea is to use the definition of pascal’s triangle that its coefficients and are summation of adjacent elements in preceding rows. so in this way we can store the elements in a matrix and for further generation of values in it we can check the preceding elements and update the value.

// Declare an ArrayList of arraylist TRIANGLE to store the elements values.
// Run a loop from row R =0 till N-1.
// Now inside this loop run one more loop from value J=0 till J<=R.
// If the number is first or last one then just store 1 in the matrix i.e. TRIANGLE[R][J]=1.
// Else store the sum of adjacent elements in preceding rows i.e. TRIANGLE[R][J]=TRIANGLE[R-1][J-1] + TRIANGLE[R-1][J].
// Print this value i.e. the value in the current iteration TRIANGLE[R][J].
// Finally return the arrayList
// Time Complexity
// O(N^2), Where ‘N’ denotes the number of Rows.


// because we are using two nested loops.

// Space Complexity
// O(N^2),  Where ‘N’ denotes the number of Rows.


// We are using an ArrayList of ArrayList to store values.