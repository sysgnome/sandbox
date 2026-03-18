#include <string>

class Worker {
protected:
  std::string m_name;
  int m_age;
  std::string m_position;

public:
  Worker();
  Worker(std::string name);
  Worker(std::string name, int age);
  Worker(std::string name, int age, std::string position);
  Worker(const Worker &other);

  virtual void operator=(const Worker &other);
  virtual bool operator==(const Worker &other) const;

  void setName(std::string name);
  void setAge(int age);
  void setPosition(std::string position);
  virtual void getData() const;
};

class WorkerPlus : public Worker {
private:
  int m_n;
  int *m_bonus;

public:
  WorkerPlus();
  WorkerPlus(std::string name);
  WorkerPlus(std::string name, int age);
  WorkerPlus(std::string name, int age, std::string position);
  WorkerPlus(std::string name, int age, std::string position, int n);
  WorkerPlus(const WorkerPlus &other);

  ~WorkerPlus();

  void operator=(const WorkerPlus &other);
  bool operator==(const WorkerPlus &other) const;
  int operator[](int i) const;

  void getData() const;
  void setBonus();
};
