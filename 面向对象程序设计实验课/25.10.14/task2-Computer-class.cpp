#include <iostream>

enum CPU_Rank { P1 = 1, P2, P3, P4, P5, P6, P7 };

class CPU {
  public:
    void run() { std::cout << "CPU开始运行" << std::endl; }
    void stop() { std::cout << "CPU停止运行" << std::endl; }
    CPU(enum CPU_Rank r, int f, double v) : rank(r), frequency(f), voltage(v) {
        std::cout << "CPU的构造函数调用" << std::endl;
    }
    ~CPU() { std::cout << "CPU的析构函数调用" << std::endl; }

    enum CPU_Rank getRank() { return rank; }
    int getFreq() { return frequency; }
    double getVoltage() { return voltage; }

    void setRank(enum CPU_Rank r) { rank = r; }
    void setFreq(int f) { frequency = f; }
    void setVoltage(double v) { voltage = v; }

  private:
    enum CPU_Rank rank;
    int frequency;
    double voltage;
};

class RAM {};

class CDROM {};

class Computer {
  public:
    void run() { std::cout << "电脑开始运行" << std::endl; }
    void stop() { std::cout << "电脑停止运行" << std::endl; }

  private:
    CPU cpu;
    RAM ram;
    CDROM cdrom;
};