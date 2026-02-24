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

// fix operator=
Worker Worker::operator=(const Worker &other) {
  m_position = other.m_position;
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

int operator+(const Worker &a) {
  return 0;
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

WorkerPlus::WorkerPlus(const WorkerPlus &other)
    : Worker(other) {
  m_n = other.m_n;
  m_bonus = new int[m_n];

  for (int i = 0; i < m_n; i++) {
    m_bonus[i] = other.m_bonus[i];
  }
}

WorkerPlus::~WorkerPlus() { delete[] m_bonus; }

void WorkerPlus::operator=(const WorkerPlus &other) {
  m_position = other.m_position;

  if (other.m_n != 0) {
    delete[] m_bonus;

    m_n = other.m_n;
    m_bonus = new int[m_n];

    for (int i = 0; i < m_n; i++) {
      m_bonus[i] = other.m_bonus[i];
    }
  }
}

bool WorkerPlus::operator==(const WorkerPlus &other) const {
  bool isEqual = 0;

  if (m_name == other.m_name && m_age == other.m_age &&
      m_position == other.m_position) {
    for (int i = 0; i < m_n; i++) {
      if (m_bonus[i] != other.m_bonus[i]) {
        return 0;
      }
    }
    isEqual = 1;
  }

  return isEqual;
}

int WorkerPlus::operator[](int i) const {
  for (int j = 0; j < m_n; j++) {
    if (j == i - 1) {
      return m_bonus[j];
    }
  }
  return 0;
}

void WorkerPlus::getData() const {
  Worker::getData();
  if (m_n != 0) {
    cout << "   Bonuses for the last " << m_n << " months: ";
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
