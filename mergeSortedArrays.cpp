/*
	Time complexity: O(M+N)
	Space complexity: O(1)

	Where M and N are the number of elements in ARR1 and ARR2 respectively.
*/

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {

	int i = m - 1;
	int j = n - 1;
	int lastIndex = m + n - 1;

	while (j >= 0) {

		if (i >= 0 && arr1[i] > arr2[j]) {
			arr1[lastIndex] = arr1[i];
			i--;
		} else {

			arr1[lastIndex] = arr2[j];
			j--;
		}

		lastIndex--;
	}
	return arr1;

}
