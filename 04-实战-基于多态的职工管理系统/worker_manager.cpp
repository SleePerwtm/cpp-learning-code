#include <fstream>
#include <iostream>
using namespace std;

#include "worker_manager.h"

#include "boss.h"
#include "employee.h"
#include "manager.h"

#define FILE_NAME "worker_file.txt"

WorkerManager::WorkerManager() {
    ifstream ifs;
    ifs.open(FILE_NAME, ios::in);
    // 文件不存在时进行的初始化
    if (!ifs.is_open()) {
        // cout << "文件不存在！" << endl; // 测试输出
        file_is_empty_ = true;   // 初始文件不存在，等效为内容为空
        worker_num_ = 0;         // 初始职工数量为0
        worker_array_ = nullptr; // 初始职工数组为空
        ifs.close();             // 关闭文件
        return;
    }

    // 文件存在，但内容为空
    char c;
    ifs >> c;
    if (ifs.eof()) {
        // cout << "文件内容为空！" << endl; // 测试输出
        file_is_empty_ = true;   // 初始文件存在，但内容为空
        worker_num_ = 0;         // 初始职工数量为0
        worker_array_ = nullptr; // 初始职工数组为空
        ifs.close();             // 关闭文件
        return;
    }

    // 文件存在，且内容不为空
    worker_num_ = GetWorkerNumFromFile();                      // 读取职工数量
    worker_array_ = new Worker*[worker_num_];                  // 申请职工数组
    cout << "读取到" << worker_num_ << "位职工信息！" << endl; // 测试输出

    ifs.close(); // 关闭文件

    // 读取职工信息到数组中
    InitWorkerArray();
    file_is_empty_ = false; // 标记文件内容不为空

    Pause();
}

void WorkerManager::ShowMenu() {
    cout << "========================================" << endl;
    cout << "********  欢迎使用职工管理系统  ********" << endl;
    cout << "*********** 0. 退出管理系统  ***********" << endl;
    cout << "*********** 1. 新增职工信息  ***********" << endl;
    cout << "*********** 2. 显示职工信息  ***********" << endl;
    cout << "*********** 3. 删除离职职工  ***********" << endl;
    cout << "*********** 4. 修改职工信息  ***********" << endl;
    cout << "*********** 5. 查找职工信息  ***********" << endl;
    cout << "*********** 6. 按照编号排序  ***********" << endl;
    cout << "*********** 7. 清空所有职工  ***********" << endl;
    cout << "========================================" << endl;
    cout << endl;
}

void WorkerManager::ExitSystem() {
    cout << "欢迎下次使用！" << endl;
    Pause();
    exit(0);
}

void WorkerManager::AddWorker() {
    cout << "请输入添加职工的数量：" << endl;

    int add_num; // 保存输入的职工数量
    cin >> add_num;

    if (add_num <= 0) {
        cout << "输入的数量有误！" << endl;
        return;
    } else {
        int new_size = worker_num_ + add_num;       // 计算新数组的大小
        Worker** new_array = new Worker*[new_size]; // 申请新数组

        // 复制老数组中的数据到新数组中
        if (worker_array_ != nullptr) {
            for (int i = 0; i < worker_num_; i++)
                new_array[i] = worker_array_[i];
        }

        // 批量添加新数据
        int id;            // 职工编号
        string name;       // 职工姓名
        int department_id; // 部门编号
        for (int i = worker_num_, order = 1; i < new_size; i++, order++) {
            cout << "请输入第" << order << "位新职工的编号：" << endl;
            cin >> id;

            cout << "请输入第" << order << "位新职工的姓名：" << endl;
            cin >> name;

            cout << "请输入第" << order << "位新职工的岗位：" << endl;
            cout << "1. 职工" << endl;
            cout << "2. 经理" << endl;
            cout << "3. 老板" << endl;
            cin >> department_id;

            Worker* worker = nullptr;
            switch (department_id) {
            case 1:
                worker = new Employee(id, name, department_id);
                break;
            case 2:
                worker = new Manager(id, name, department_id);
                break;
            case 3:
                worker = new Boss(id, name, department_id);
                break;
            default:
                break;
            }

            // 将新职工添加到新数组中
            new_array[i] = worker;
        }

        delete[] worker_array_;    // 删除老数组
        worker_array_ = new_array; // 更新老数组
        worker_num_ = new_size;    // 更新职工数量

        // 成功添加后，保存到文件中
        SaveToFile();
        file_is_empty_ = false; // 标记文件内容不为空

        // 提示成功添加
        cout << "成功添加" << add_num << "位新职工！" << endl;
    }
}

void WorkerManager::SaveToFile() {
    ofstream ofs;
    ofs.open(FILE_NAME, ios::out);

    for (int i = 0; i < worker_num_; i++) {
        ofs << worker_array_[i]->id_ << " " << worker_array_[i]->name_ << " "
            << worker_array_[i]->department_id_ << endl;
    }

    file_is_empty_ = true; // 标记文件存在

    ofs.close();
}

int WorkerManager::GetWorkerNumFromFile() {
    ifstream ifs;
    ifs.open(FILE_NAME, ios::in);

    int id;
    string name;
    int department_id;

    int num = 0;

    while (ifs >> id >> name >> department_id) {
        num++;
    }

    ifs.close();

    return num;
}

void WorkerManager::InitWorkerArray() {
    ifstream ifs;
    ifs.open(FILE_NAME, ios::in);

    int id;
    string name;
    int department_id;

    int index = 0;

    while (ifs >> id >> name >> department_id) {
        Worker* worker = nullptr;
        switch (department_id) {
        case 1:
            worker = new Employee(id, name, department_id);
            break;
        case 2:
            worker = new Manager(id, name, department_id);
            break;
        case 3:
            worker = new Boss(id, name, department_id);
            break;
        default:
            break;
        }

        worker_array_[index] = worker;
        index++;
        // cout << "编号：" << id << "\t姓名：" << name << "\t岗位："
        //      << department_id << endl; // 测试输出
    }
}

void WorkerManager::ShowWorkerInfo() {
    if (file_is_empty_) {
        cout << "文件不存在或内容为空！" << endl;
        return;
    }

    for (int i = 0; i < worker_num_; i++) {
        worker_array_[i]->DisplayInfo(); // 利用多态显示职工信息
    }
}

int WorkerManager::WorkerPosById(int id) {
    int index = -1;
    for (int i = 0; i < worker_num_; i++) {
        if (worker_array_[i]->id_ == id) {
            index = i;
            break;
        }
    }
    return index;
}

void WorkerManager::DelWorker() {
    if (file_is_empty_) {
        cout << "文件不存在或内容为空！" << endl;
        return;
    }

    cout << "请输入要删除的职工编号：" << endl;

    int del_id; // 保存输入的职工编号
    cin >> del_id;

    int pos = WorkerPosById(del_id);

    if (pos == -1) {
        cout << "没有找到该职工！" << endl;
        return;
    }

    cout << "查找到职工信息如下：" << endl;
    worker_array_[pos]->DisplayInfo(); // 利用多态显示职工信息

    cout << "是否确认删除该职工？y/n：" << endl;
    char confirm;
    cin >> confirm;
    while (true) {
        if (confirm == 'y' || confirm == 'Y') {
            break;
        } else if (confirm == 'n' || confirm == 'N') {
            cout << "取消删除！" << endl;
            return;
        } else {
            cout << "输入有误！请重新输入y/n：" << endl;
            cin >> confirm;
        }
    }

    // 数组元素向前移动
    for (int i = pos; i < worker_num_ - 1; i++) {
        worker_array_[i] = worker_array_[i + 1];
    }
    worker_num_--;

    // 保存到文件中
    SaveToFile();

    if (worker_num_ == 0) {
        file_is_empty_ = true; // 标记文件内容为空
    }

    cout << "成功删除职工！" << endl;
}

void WorkerManager::EditWorker() {
    if (file_is_empty_) {
        cout << "文件不存在或内容为空！" << endl;
        return;
    }

    cout << "请输入要修改的职工编号：" << endl;

    int edit_id; // 保存输入的职工编号
    cin >> edit_id;

    int pos = WorkerPosById(edit_id);
    if (pos == -1) {
        cout << "没有找到该职工！" << endl;
        return;
    }

    cout << "原姓名如下：" << worker_array_[pos]->name_ << endl;
    cout << "请输入新的姓名：" << endl;
    string new_name;
    cin >> new_name;
    worker_array_[pos]->name_ = new_name;

    cout << "原岗位如下：" << worker_array_[pos]->department_id_ << endl;
    cout << "请输入新的岗位：" << endl;
    int new_department_id;
    cin >> new_department_id;
    worker_array_[pos]->department_id_ = new_department_id;

    // 保存到文件中
    SaveToFile();

    cout << "成功修改职工信息！" << endl;
}

void WorkerManager::SearchWorker() {
    if (file_is_empty_) {
        cout << "文件不存在或内容为空！" << endl;
        return;
    }

    cout << "输入要搜索的职工编号：" << endl;
    int search_id; // 保存输入的职工编号
    cin >> search_id;

    int pos = WorkerPosById(search_id);
    if (pos == -1) {
        cout << "没有找到该职工！" << endl;
        return;
    }

    cout << "查找到职工信息如下：" << endl;
    worker_array_[pos]->DisplayInfo(); // 利用多态显示职工信息
}

void WorkerManager::SortWorkerById() {
    if (file_is_empty_) {
        cout << "文件不存在或内容为空！" << endl;
        return;
    }

    cout << "选择排序方式：" << endl << "0. 升序" << endl << "1. 降序" << endl;
    int sort_type;
    cin >> sort_type;

    // 冒泡排序
    for (int i = 0; i < worker_num_; i++) {
        for (int j = 0; j < worker_num_ - i - 1;) {
            // 升序排序
            if (sort_type == 0) {
                if (worker_array_[j]->id_ > worker_array_[j + 1]->id_) {
                    SwapWorker(worker_array_[i], worker_array_[j + 1]);
                }
            } else if (sort_type == 1) {
                if (worker_array_[j]->id_ < worker_array_[j + 1]->id_) {
                    SwapWorker(worker_array_[i], worker_array_[j + 1]);
                }
            }
        }
    }

    // 逐个输出职工信息
    ShowWorkerInfo();
}

void WorkerManager::SwapWorker(Worker*& worker1, Worker*& worker2) {
    Worker* temp = worker1;
    worker1 = worker2;
    worker2 = temp;
}

bool WorkerManager::need_ignore = false;

void WorkerManager::Pause() {
    cout << "按下Enter键继续..." << flush;

    // 这里的条件判断是为了解决缓冲区中没有换行符时，现在输入的回车会被舍弃的问题
    if (need_ignore) {
        cin.ignore();
    } else {
        need_ignore = true;
    }
    cin.get();
}

void WorkerManager::ClearAllWorker() {
    if (file_is_empty_) {
        cout << "文件不存在或内容为空！" << endl;
        return;
    }

    cout << "是否确认清除所有职员信息？y/n：" << endl;
    char confirm;
    cin >> confirm;
    while (true) {
        if (confirm == 'y' || confirm == 'Y') {
            break;
        } else if (confirm == 'n' || confirm == 'N') {
            cout << "取消清除！" << endl;
            return;
        } else {
            cout << "输入有误！请重新输入y/n：" << endl;
            cin >> confirm;
        }
    }

    ofstream ofs;
    ofs.open(FILE_NAME, ios::trunc); // 清空文件内容
    ofs.close();

    file_is_empty_ = true; // 标记文件内容为空

    cout << "成功清除所有职员信息！" << endl;
}

WorkerManager::~WorkerManager() {
    if (worker_array_ != nullptr) {
        delete[] worker_array_;
        worker_array_ = nullptr;
    }
}
