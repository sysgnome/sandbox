#include <iostream>
using namespace std;

int main() {
  int m = 3, n = 49;
  int k[n - m + 1];

  for (int i = m; i <= n; i++) {
    k[i - m] = i;
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
