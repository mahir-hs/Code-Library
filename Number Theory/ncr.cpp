vector<int> f;
vector<int> invf;
const int M = 1e9 + 7;
void init(int n) {
  f.resize(n + 1);
  invf.resize(n + 1);
  f[0] = invf[0] = 1;
  for (int i = 1; i <= n; i++) f[i] = ((long long)f[i - 1] * (long long)i) % M;
  invf[n] = bigmod((long long)f[n], (long long)M - 2, (long long)M);
  for (int i = n - 1; i >= 0; i--) invf[i] = ((long long)invf[i + 1] * (long long)(i + 1)) % M;
}
int nCr(int n, int r) {
  if (r > n) return 0;
  int ans = ((long long)f[n] * (long long)invf[r]) % M;
  ans = ((long long)ans * (long long)invf[n - r]) % M;
  return ans;
}
void solve() {
  init(10);
  cout << nCr(5, 3) << endl;
}
