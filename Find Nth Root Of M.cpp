Problem Link: codingninjas.com/studio/problems/find-nth-root-of-m_8230799?challengeSlug=striver-sde-challenge

int f(int mid,int n, int m) {
  long long ans = 1;
  for (int i=1; i<=n; i++) {
    ans = ans*mid;
    if (ans>m) return 2;
  }

  if  (ans == m) return 1;
  return 0;

}

int NthRoot(int n, int m) {
  int l = 1, h = m;
  while (l<=h) {
    int mid = (l+h)/2;
    int midNth = f(mid, n, m);
    if (midNth == 1) return mid;
    else if (midNth == 0) l = mid+1;
    else h = mid-1;
  }
  return -1;
}
