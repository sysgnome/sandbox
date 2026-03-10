#include "worker.h"
#include <iostream>
using namespace std;

int main() {
  bool isEqual = 0;
  Worker max("Max", 37, "Bill Collector");
  Worker alex("Alex", 24);
  // use all costructors for Worker

  WorkerPlus barbara("Barbara", 28, "Risk Manager", 4);
  WorkerPlus debra("Debra");
  // use all constructors for WorkerPlus

  cout << "Worker:" << endl;

  max.getData();
  alex.getData();

  alex = max;
  alex.getData();

  // add if for ==
  isEqual = alex == max;
  cout << "Does alex is equal to max?" << endl;
  cout << "Answer: " << isEqual << endl;

  cout << "WorkerPlus:" << endl;

  barbara.setBonus();

  barbara.getData();
  debra.getData();

  debra = barbara;

  debra.getData();

  isEqual = debra == barbara;
  cout << "Does Debra is equal to Barbara?" << endl;
  cout << "Answer: " << isEqual << endl;

  cout << "Output Barbara's third bonus: " << barbara[3] << endl;

  return 0;
}
