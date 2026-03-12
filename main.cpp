#include "worker.h"
#include <iostream>
using namespace std;

int main() {
  bool isEqual = 0;

  Worker max("Max", 37, "Bill Collector");
  Worker alex("Alex", 24);
  Worker debian("Debian");
  Worker bruno;

  WorkerPlus barbara("Barbara", 28, "Risk Manager", 4);
  WorkerPlus joe("Joe", 22, "Data Scientist");
  WorkerPlus ada("Ada", 23);
  WorkerPlus debra("Debra");
  WorkerPlus ali;

  cout << "Workers:" << endl;

  max.getData();
  alex.getData();
  debian.getData();
  bruno.getData();

  alex = max;
  alex.getData();

  isEqual = alex == max;
  cout << "Does alex is equal to max?" << endl;

  cout << "Answer: ";
  if (isEqual) {
    cout << "Yes!" << endl;
  } else {
    cout << "No!" << endl;
  }

  cout << "\nWorkers Plus:" << endl;
  barbara.setBonus();

  barbara.getData();
  joe.getData();
  ada.getData();
  debra.getData();
  ali.getData();

  debra = barbara;

  debra.getData();

  isEqual = debra == barbara;
  cout << "Does Debra is equal to Barbara?" << endl;

  cout << "Answer: ";
  if (isEqual) {
    cout << "Yes!" << endl;
  } else {
    cout << "No!" << endl;
  }

  cout << "Output Barbara's third bonus: " << barbara[3] << endl;

  return 0;
}
