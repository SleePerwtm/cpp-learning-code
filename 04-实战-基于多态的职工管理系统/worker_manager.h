#pragma once

#include "worker.h"

class WorkerManager {
  public:
    // 构造函数
    WorkerManager();

    // 显示菜单
    void ShowMenu();

    // 退出系统
    void ExitSystem();

    // 新增职工信息
    void AddWorker();

    // 显示职工信息
    void ShowWorkerInfo();

    // 按照编号删除职工信息
    void DelWorker();

    // 修改职工信息
    void EditWorker();

    // 查找职工信息
    void SearchWorker();

    // 按照编号排序
    void SortWorkerById();

    // 清空文件内容
    void ClearAllWorker();

    // 暂停函数
    void Pause();

    // 析构函数
    ~WorkerManager();

    int worker_num_;        // 职工数量
    Worker** worker_array_; // 职工数组指针
    bool file_is_empty_;    // 文件是否存在

  private:
    // 保存信息到文件
    void SaveToFile();

    // 从文件中读取人数信息
    int GetWorkerNumFromFile();

    // 初始化职工数组
    void InitWorkerArray();

    // 通过id编号查找职工位置
    int WorkerPosById(int id);

    // 交换两个职工信息
    void SwapWorker(Worker*&, Worker*&);

    static bool need_ignore; // 是否需要忽略换行符
};
