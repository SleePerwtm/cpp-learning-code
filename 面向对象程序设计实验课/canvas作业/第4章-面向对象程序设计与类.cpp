#include <iostream>
using namespace std;

/* 1、定义一个 Book 类，编写构造函数和析构函数并在 main() 中创建与销毁对象。*/

const int kMaxBookNum = 100;

class Student;

class Book {
    friend class Student; // 声明 Student 类为友元类

  public:
    // 构造函数
    Book(const string& title, const string& id) : kTitle_(title), kId_(id) {
        cout << "Book 的构造函数被调用" << endl;
    }
    // 析构函数
    ~Book() { cout << "Book 的析构函数被调用" << endl; }

    // 取值函数
    string getTitle() const { return kTitle_; }
    string getId() const { return kId_; }

  private:
    const string kTitle_; // 书名
    const string kId_;    // 书籍id
    Student* borrower_;   // 借书人指针
};

/* 2、定义 Student 类并组合 Book 类，使用前向引用解决依赖问题并在 main()
 * 中演示借书。*/

class Student {
  public:
    // 构造函数
    Student(string name, int age) : name_(name), age_(age), book_num_(0) {}

    // 析构函数
    ~Student() = default;

    // 取值函数
    string getName() const { return name_; }
    int getAge() const { return age_; }
    Book** getBookList() const { return (Book**)book_list_; }

    // 设值函数
    void setName(string n) { name_ = n; }
    void setAge(int a) { age_ = a; }

    // 借书
    void borrowBook(Book* const b) {
        if (book_num_ >= kMaxBookNum) {
            cout << "书籍数量已满，无法借阅" << endl;
            return;
        }
        book_list_[book_num_] = b; // 借阅书籍
        b->borrower_ = this;       // 记录借书人
        book_num_++;               // 书籍数量加一
    }

    // 还书
    void returnBook(Book* const b) {
        int index = getIndex(b);
        if (index == -1) {
            cout << "该书籍未被借阅" << endl;
            return;
        }
        for (int i = index; i < book_num_ - 1; i++) {
            book_list_[i] = book_list_[i + 1];
        }
        book_list_[book_num_ - 1] = nullptr; // 置空最后一个元素
        b->borrower_ = nullptr;              // 记录借书人
        book_num_--;                         // 书籍数量减一
    }

    // 打印已借阅的书籍列表
    void printBorrowedBooks() const {
        for (int i = 0; i < book_num_; i++) {
            if (book_list_[i] != nullptr) {
                cout << "《" << book_list_[i]->getTitle() << "》" << endl;
            }
        }
    }

  private:
    string name_;                  // 学生姓名
    int age_;                      // 年龄
    Book* book_list_[kMaxBookNum]; // 书籍列表
    int book_num_;                 // 书籍数量

    // 获取书籍在列表中的索引，未找到返回-1
    int getIndex(Book* const b) const {
        for (int i = 0; i < book_num_; i++) {
            if (book_list_[i] == b) {
                return i;
            }
        }
        return -1; // 未找到书籍
    }
};

/* 3、定义 struct Person 和 union Data，用
 * sizeof比较结构体与联合体的内存占用。*/

// 结构体
struct Person {
    double height;
    double weight;
    int age;
};

// 联合体
union Data {
    double height;
    double weight;
    int age;
};

/* 4、定义 enum Weekday 并编写函数输出一周七天的名称。*/

enum Weekday { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };
string weekdayName[7] = {"Monday", "Tuesday",  "Wednesday", "Thursday",
                         "Friday", "Saturday", "Sunday"};

void printWeekdays() {
    for (int i = Monday; i < 7; i++) {
        cout << weekdayName[i] << endl;
    }
}

int main() {
    /* 1、定义一个 Book 类，编写构造函数和析构函数并在 main()
     * 中创建与销毁对象。*/
    /* 2、定义 Student 类并组合 Book 类，使用前向引用解决依赖问题并在 main()
     * 中演示借书。*/

    // 创建书本对象
    Book book("C++ Primer", "123456");
    Book book2("C++面向对象程序设计", "567890");

    // 创建学生对象
    Student student("张三", 20);

    // 借书
    student.borrowBook(&book);
    student.borrowBook(&book2);
    cout << "学生" << student.getName() << "已借阅的书籍列表如下：" << endl;
    student.printBorrowedBooks();

    // 还书
    student.returnBook(&book);
    cout << "学生" << student.getName() << "已借阅的书籍列表如下：" << endl;
    student.printBorrowedBooks();

    cout << endl;

    /* 3、定义 struct Person 和 union Data，用
     * sizeof比较结构体与联合体的内存占用。*/

    cout << "Person 结构体大小为 " << sizeof(Person) << " 字节" << endl;
    cout << "Data 联合体大小为 " << sizeof(Data) << " 字节" << endl;

    cout << endl;

    /* 4、定义 enum Weekday 并编写函数输出一周七天的名称。*/

    // 输出一周七天的名称
    printWeekdays();
}