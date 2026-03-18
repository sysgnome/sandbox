#include "worker.h"
#include <iostream>
using namespace std;

int main() {
  // 1. ввести декілька обʼєктів
  // 2. додати їх
  // 3. присвоїти
  // 4. вивести
  // 5. додати обробку помилок
  // +теіоря до лаби 3 та 4

  WorkerPlus max;
  WorkerPlus debian;

  cin >> max >> debian;

  WorkerPlus gentoo = max + debian;

  cout << max;
  cout << debian;
  cout << gentoo;

  return 0;
}
