#include "worker.h"
#include <iostream>
using namespace std;

Worker::Worker() {
  m_name = "Unknown";
  m_age = -1;
  m_position = "Unknown";
}

Worker::Worker(string name) {
  m_name = name;
  m_age = -1;
  m_position = "Unknown";
}

Worker::Worker(string name, int age) {
  m_name = name;
  m_age = age;
  m_position = "Unknown";
}

Worker::Worker(string name, int age, string position) {
  m_name = name;
  m_age = age;
  m_position = position;
}

Worker::Worker(const Worker &other) {
  m_name = other.m_name;
  m_age = other.m_age;
  m_position = other.m_position;
}

Worker &Worker::operator=(const Worker &other) {
  m_position = other.m_position;
  m_name = other.m_name;
  m_age = other.m_age;
  return *this;
}

bool Worker::operator==(const Worker &other) const {
  bool isEqual = 0;

  if (m_name == other.m_name && m_age == other.m_age &&
      m_position == other.m_position) {
    isEqual = 1;
  }

  return isEqual;
}

std::ostream &operator<<(std::ostream &os, const Worker &obj) {
  os << " - name: " << obj.m_name << endl;
  os << "   age: " << obj.m_age << endl;
  os << "   position: " << obj.m_position << endl;
  return os;
}

std::istream &operator>>(std::istream &is, Worker &obj) {
  cout << "Enter name: ";
  is >> obj.m_name;

  cout << "Enter age: ";
  is >> obj.m_age;

  cout << "Enter position: ";
  is >> obj.m_position;

  return is;
}

void Worker::setName(string name) { m_name = name; }
void Worker::setAge(int age) { m_age = age; }
void Worker::setPosition(string position) { m_position = position; }

void Worker::getData() const {
  if (m_name != "Unknown") {
    cout << " - name: " << m_name << "." << endl;
  } else {
    cout << " - Worker indefinite." << endl;
  }

  if (m_age != -1) {
    cout << "   age: " << m_age << "." << endl;
  }

  if (m_position != "Unknown") {
    cout << "   position: " << m_position << "." << endl;
  }
}

WorkerPlus::WorkerPlus() {
  m_n = 0;
  m_bonus = nullptr;
}

WorkerPlus::WorkerPlus(string name) : Worker(name) {
  m_n = 0;
  m_bonus = nullptr;
}

WorkerPlus::WorkerPlus(string name, int age) : Worker(name, age) {
  m_n = 0;
  m_bonus = nullptr;
}

WorkerPlus::WorkerPlus(string name, int age, string position)
    : Worker(name, age, position) {
  m_n = 0;
  m_bonus = nullptr;
}

WorkerPlus::WorkerPlus(string name, int age, string position, int n)
    : Worker(name, age, position) {
  m_n = n;
  m_bonus = new int[m_n];

  for (int i = 0; i < m_n; i++) {
    m_bonus[i] = 0;
  }
}

WorkerPlus::WorkerPlus(const WorkerPlus &other) : Worker(other) {
  m_n = other.m_n;
  m_bonus = new int[m_n];

  for (int i = 0; i < m_n; i++) {
    m_bonus[i] = other.m_bonus[i];
  }
}

WorkerPlus::~WorkerPlus() { delete[] m_bonus; }

WorkerPlus &WorkerPlus::operator=(const WorkerPlus &other) {
  if (this == &other) {
    return *this;
  }

  Worker::operator=(other);

  delete[] m_bonus;

  m_n = other.m_n;
  if (m_n > 0) {
    m_bonus = new int[m_n];

    for (int i = 0; i < m_n; i++) {
      m_bonus[i] = other.m_bonus[i];
    }
  } else {
    m_bonus = nullptr;
  }

  return *this;
}

bool WorkerPlus::operator==(const WorkerPlus &other) const {
  if (!Worker::operator==(other)) {
    return false;
  }

  if (m_n != other.m_n) {
    return false;
  }

  for (int i = 0; i < m_n; i++) {
    if (m_bonus[i] != other.m_bonus[i]) {
      return false;
    }
  }

  return true;
}

int WorkerPlus::operator[](int i) const {
  for (int j = 0; j < m_n; j++) {
    if (j == i - 1) {
      return m_bonus[j];
    }
  }
  return 0;
}

WorkerPlus operator+(const WorkerPlus &a, const WorkerPlus &b) {
  WorkerPlus tmp(a);

  if (b.m_n < a.m_n) {
    tmp.m_n = b.m_n;
    delete[] tmp.m_bonus;
    tmp.m_bonus = new int[tmp.m_n];
  }

  for (int i = 0; i < tmp.m_n; i++) {
    tmp.m_bonus[i] = a.m_bonus[i] + b.m_bonus[i];
  }

  return tmp;
}

std::ostream &operator<<(std::ostream &os, const WorkerPlus &obj) {
  os << (const Worker&)obj;

  if (obj.m_n != 0) {
    cout << "   bonuses for the last " << obj.m_n << " months: ";
    for (int i = 0; i < obj.m_n; i++) {
      cout << obj.m_bonus[i] << " ";
    }
    os << endl;
  }
  return os;
}


std::istream &operator>>(std::istream &is, WorkerPlus &obj) {
  is >> (Worker&)obj;

  cout << "Enter the number of bonuses: ";
  is >> obj.m_n;

  obj.m_bonus = new int[obj.m_n];

  obj.setBonus();

  return is;
}

void WorkerPlus::getData() const {
  Worker::getData();
  if (m_n != 0) {
    cout << "   bonuses for the last " << m_n << " months: ";
    for (int i = 0; i < m_n; i++) {
      cout << m_bonus[i] << " ";
    }
    cout << endl;
  }
}

void WorkerPlus::setBonus() {
  cout << "Enter " << m_n << " bonuses for " << m_name << ": ";
  for (int i = 0; i < m_n; i++) {
    cin >> m_bonus[i];
  }
}
