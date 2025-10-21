#include <fstream>
#include <iostream>
using namespace std;

// 四种读的方式

ifstream openFile() {
    ifstream ifs;
    ifs.open("61-test.txt", ios::in);
    return ifs;
}

// 这种方式空白字符会影响读取结果格式
void readFile1() {
    cout << "readFile1" << endl;

    ifstream ifs = openFile();

    char buffer[1024];
    while (ifs >> buffer) {
        cout << buffer << endl;
    }

    cout << endl;
    ifs.close();
}

void readFile2() {
    cout << "readFile2" << endl;

    ifstream ifs = openFile();

    char buffer[1024];
    while (ifs.getline(buffer, sizeof(buffer))) {
        cout << buffer << endl;
    }

    cout << endl;
    ifs.close();
}

void readFile3() {
    cout << "readFile3" << endl;

    ifstream ifs = openFile();

    string line;
    while (getline(ifs, line)) {
        cout << line << endl;
    }

    cout << endl;
    ifs.close();
}

void readFile4() {
    cout << "readFile4" << endl;

    ifstream ifs = openFile();

    char c;
    while ((c = ifs.get()) != EOF) {
        cout << c;
    }

    cout << endl;
    ifs.close();
}

int main() {
    readFile1();
    readFile2();
    readFile3();
    readFile4();
}