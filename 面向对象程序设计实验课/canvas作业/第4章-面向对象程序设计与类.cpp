#include <iostream>
#include <string>
using namespace std;

class Book;

class Student {
  public:
    Student(string name, int age) : name(name), age(age), book(nullptr) {}
    ~Student() = default;

    string getName() { return name; }
    int getAge() { return age; }
    Book* getBook() { return book; }

    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }

    void borrowBook(Book* b) { book = b; }

    void returnBook() { book = nullptr; }

  private:
    string name;
    int age;
    Book* book;
};

class Book {
  public:
    // 构造函数
    Book(string t, string id) : title(t), id(id) {
        cout << "Book 的构造函数被调用" << endl;
    }
    // 析构函数
    ~Book() { cout << "Book 的析构函数被调用" << endl; }

    string getTitle() { return title; }
    string getId() { return id; }

    void setTitle(string t) { title = t; }
    void setId(string i) { id = i; }

  private:
    string title; // 书名
    string id;    // 书籍id
};

struct Person {
    double height;
    double weight;
    int age;
};

union Data {
    double height;
    double weight;
    int age;
};

enum Weekday { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };
string weekdayName[7] = {"Monday", "Tuesday",  "Wednesday", "Thursday",
                         "Friday", "Saturday", "Sunday"};

void printWeekdays() {
    for (int i = Monday; i < 7; i++) {
        cout << weekdayName[i] << endl;
    }
}

int main() {
    // 创建书本对象
    Book book("C++ Primer", "123456");

    // 创建学生对象
    Student student("张三", 20);

    // 借书
    student.borrowBook(&book);
    cout << "学生" << student.getName() << "借了书籍《"
         << student.getBook()->getTitle() << "》" << endl;

    // 比较结构体与联合体占用内存大小
    cout << "Person 结构体大小为 " << sizeof(Person) << " 字节" << endl;
    cout << "Data 联合体大小为 " << sizeof(Data) << " 字节" << endl;

    // 输出一周七天的名称
    printWeekdays();
}