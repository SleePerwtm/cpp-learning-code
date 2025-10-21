#include <fstream>
using namespace std;

// 打开文件：
// ofs.open("文件名", 打开方式);
// 写入数据：
// ofs << "写入的数据";
// 关闭文件：
// ofs.close();

// 文件打开方式：
// ios::in  读入模式
// ios::out  写出模式
// ios::ate  打开文件时指针指向文件末尾
// ios::app  追加模式
// ios::trunc  截断模式，如果文件存在，则清空文件内容
// ios::binary  二进制模式

// 文件打开方式可以用 | 运算符连接，如：
// ofs.open("文件名", ios::in | ios::out | ios::ate);

void printLines(ofstream& ofs, string data) {
    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j <= i; j++) {
            ofs << data[j];
        }
        ofs << endl;
    }
}

int main() {
    ofstream ofs;
    ofs.open("61-test.txt", ios::binary | ios::out);
    printLines(ofs, "Hello, world!");
    ofs.close();
}