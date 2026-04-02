#include "worker.h"
#include <iostream>
using namespace std;

int main() {
  // 5. додати обробку помилок
  // +теіоря до лаби 3 та 4

  WorkerPlus debra;
  WorkerPlus debian;
  WorkerPlus gentoo;

  cin >> debra >> debian;

  gentoo = debra + debian;

  cout << "=== Output Data ===" << endl;

  cout << debra;
  cout << debian;
  cout << gentoo;

  return 0;
}
