Problem Link: https://www.codingninjas.com/codestudio/problems/median-of-two-sorted-arrays_8230788?challengeSlug=striver-sde-challenge&leftPanelTab=0

double median(vector<int>& a, vector<int>& b) {
	// int n = a.size(), m = b.size();
	// int m1 = 0, m2 = 0;

	// int i=0, j = 0;
	
	// for (int k=0; k<=(n+m)/2; k++){
	// 	m2 = m1;
	// 	if (i<n && j<m) {
	// 		if (a[i] < b[j]) m1 = a[i++];
	// 		else m1 = b[j++];
	// 	}

	// 	else if (i<n) {
	// 		m1 = a[i++];
	// 	}

	// 	else {
	// 		m2 = b[j++];
	// 	}
	// }

	// if ((n+m)%2 == 0) return (double) (m1+m2)/2;
	// else return (double)m1;

	if (b.size() < a.size()) return median(b, a);

	int n = a.size();
	int m = b.size();

	int l = 0, h = n;

	while (l<=h){
		int cut1 = (l+h)/2;
		int cut2 = (n+m+1)/2 -cut1;

		int l1 = cut1==0? INT_MIN: a[cut1-1];
		int l2 = cut2==0? INT_MIN: b[cut2-1];

		int r1 = cut1==n? INT_MAX: a[cut1];
		int r2 = cut2==m? INT_MAX: b[cut2];


		if (l1<=r2 && l2<=r1) {
			if ((n+m)%2==0) return  (max(l1, l2) + min(r1, r2)) / 2.0;
			else return max(l1, l2);
		}

		else if (l1>r2) h = cut1-1;
		else l = cut1+1;
	}

	return 0.0;
}
