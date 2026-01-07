Problem Link: https://www.codingninjas.com/codestudio/problems/remove-duplicates-from-sorted-array_8230811?challengeSlug=striver-sde-challenge&leftPanelTab=0

int removeDuplicates(vector<int> &arr, int n) {
	int unique = 0;
	for (int i=1; i<n; i++){
		if (arr[unique] != arr[i]) swap(arr[++unique], arr[i]);
	}

	return ++unique;
}
