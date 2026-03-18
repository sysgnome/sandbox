#include "worker.h"
#include <iostream>
using namespace std;

int main() {
  bool isEqual = 0;

  Worker joe;
  Worker alex("Alex", 24);
  Worker max("Max", 37, "Bill Collector");
  Worker bruno(max);

  WorkerPlus ali;
  WorkerPlus debra("Debra");
  WorkerPlus barbara("Barbara", 28, "Risk Manager", 4);
  WorkerPlus debian(barbara);

  cout << "Worker:" << endl;

  joe.getData();
  alex.getData();
  max.getData();
  bruno.getData();

  alex = max;
  alex.getData();

  isEqual = alex == max;
  cout << "Does alex is equal to max?" << endl;
  cout << "Answer: " << isEqual << endl;

  cout << "\nWorkerPlus:" << endl;

  barbara.setBonus();

  ali.getData();
  debra.getData();
  barbara.getData();
  debian.getData();

  debian.setBonus();

  debian.getData();

  debra = barbara;

  debra.getData();

  isEqual = debra == barbara;
  cout << "Does Debra is equal to Barbara?" << endl;
  cout << "Answer: " << isEqual << endl;

  cout << "Output Barbara's third bonus: " << barbara[3] << endl;

  return 0;
}
