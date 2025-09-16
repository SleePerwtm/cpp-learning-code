#include <iostream>
using namespace std;

struct Student
{
    string name; // 姓名
    int age;     // 年龄
    float score; // 成绩
} s3;

int main()
{
    struct Student s1;
    s1.name = "SleePerwtm";
    s1.age = 18;
    s1.score = 0.f;
    cout << "姓名：" << s1.name << endl
         << "年龄：" << s1.age << endl
         << "成绩：" << s1.score << endl;

    struct Student s2 = {"Sleeper", 19, 1.0f};
    cout << "姓名：" << s2.name << endl
         << "年龄：" << s2.age << endl
         << "成绩：" << s2.score << endl;

    cout << "姓名：" << s3.name << endl
         << "年龄：" << s3.age << endl
         << "成绩：" << s3.score << endl;
}