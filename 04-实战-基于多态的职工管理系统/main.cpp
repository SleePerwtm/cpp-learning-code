#include <iostream>
using namespace std;

#include "worker_manager.h"

// #include "boss.h"
// #include "employee.h"
// #include "manager.h"
// #include "worker.h"

// void test() {
//     Worker* worker = nullptr;

//     worker = new Employee(1, "张三", 1);
//     worker->DisplayInfo();
//     delete worker;

//     worker = new Manager(2, "李四", 2);
//     worker->DisplayInfo();
//     delete worker;

//     worker = new Boss(3, "王五", 3);
//     worker->DisplayInfo();
//     delete worker;
// }

int main() {
    // test();
    WorkerManager wm;
    int choice = 0;
    while (true) {
        wm.ShowMenu();
        cout << "请输入您的选择：" << endl;
        cin >> choice;

        switch (choice) {
        case 0:
            wm.ExitSystem();
            break;
        case 1:
            wm.AddWorker();
            wm.Pause();
            break;
        case 2:
            wm.ShowWorkerInfo();
            wm.Pause();
            break;
        case 3:
            wm.DelWorker();
            wm.Pause();
            break;
        case 4:
            wm.EditWorker();
            wm.Pause();
            break;
        case 5:
            wm.SearchWorker();
            wm.Pause();
            break;
        case 6:
            wm.SortWorkerById();
            wm.Pause();
            break;
        case 7:
            wm.ClearAllWorker();
            wm.Pause();
            break;
        }
    }
}
