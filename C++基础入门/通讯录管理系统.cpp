#include <iostream>
using namespace std;

const int MAX = 1000;

// 联系人结构体
struct Contact
{
    string name;    // 姓名
    int gender;     // 性别
    int age;        // 年龄
    string number;  // 联系电话
    string address; // 家庭住址
};

struct Book
{
    struct Contact contacts[MAX];
    int size;
};

void printMenu();
void addContact(Book *book);
void printAContact(Contact *contact);
void printContacts(Book *book);
int findIndex(Book *book, const string *name);
void deleteContact(Book *book);
void findContact(Book *book);
void modifyContact(Book *book);
void clearContacts(Book *book);

int main()
{
    /*初始化通讯录*/
    struct Book book;
    book.size = 3;
    book.contacts[0] = {"笋长椅", 1, 19, "13812345678", "北京市THU"};
    book.contacts[1] = {"真开吻", 1, 19, "13912345678", "香港特别行政区PolyU"};
    book.contacts[2] = {"胀痛象", 1, 19, "18612345678", "浙江省杭州市ZJU"};

    /*显示菜单、输入指令*/
    int order; // 指令
    printMenu();
    cin >> order;

    while (order != 0)
    {
        switch (order)
        {
        case 1:
            addContact(&book);
            break;
        case 2:
            printContacts(&book);
            break;
        case 3:
            deleteContact(&book);
            break;
        case 4:
            findContact(&book);
            break;
        case 5:
            modifyContact(&book);
            break;
        case 6:
            clearContacts(&book);
            break;
        }

        printMenu();
        cin >> order;
    }

    cout << "成功退出！\n";
    return 0;
}

// 显示菜单的函数
void printMenu()
{
    cout << "=========================\n";
    cout << "1. 添加联系人\n";
    cout << "2. 显示联系人\n";
    cout << "3. 删除联系人\n";
    cout << "4. 查找联系人\n";
    cout << "5. 修改联系人\n";
    cout << "6. 清空联系人\n";
    cout << "0. 退出通讯录\n";
    cout << "=========================\n";
    cout << "请输入操作指令：";
}

// 添加联系人的函数
void addContact(Book *book)
{
    cout << "\n";
    cout << "输入联系人姓名：";
    cin >> book->contacts[book->size].name;

    int gender;
    cout << "输入联系人性别(1为男,2为女)：";
    cin >> gender;
    while (true)
    {
        if (gender == 1 || gender == 2)
        {
            book->contacts[book->size].gender = gender;
            break;
        }
        else
        {
            cout << "输入有误，请重新输入：";
            cin >> gender;
        }
    }

    cout << "输入联系人年龄：";
    cin >> book->contacts[book->size].age;

    cout << "输入联系人电话号码：";
    cin >> book->contacts[book->size].number;

    cout << "输入联系人地址：";
    cin >> book->contacts[book->size].address;

    book->size++;

    cout << "联系人" << book->size << "-" << book->contacts[book->size - 1].name << "添加成功！\n";
    cout << "\n";
}

// 打印一个联系人的信息的函数
void printAContact(Contact *contact)
{
    string genderList[] = {"", "男", "女"};
    cout << "姓名：\t\t" << contact->name << endl;
    cout << "性别：\t\t" << genderList[contact->gender] << endl;
    cout << genderList[1];
    cout << "年龄：\t" << contact->age << endl;
    cout << "电话号码：\t" << contact->number << endl;
    cout << "家庭住址：\t" << contact->address << endl;
}

// 打印所有联系人的信息的函数
void printContacts(Book *book)
{
    cout << "\n";
    if (book->size == 0)
    {
        cout << "联系人列表为空\n";
        cout << "\n";
    }
    else
    {
        for (int i = 0; i < book->size; i++)
        {
            cout << "联系人" << i + 1 << "的信息为：\n";
            printAContact(&book->contacts[i]);
            cout << "\n";
        }
    }
}

// 查找联系人是否存在的函数
int findIndex(Book *book, const string *name)
{
    for (int i = 0; i < book->size; i++)
        if (book->contacts[i].name == *name)
            return i;
    return -1;
}

// 删除联系人的函数
void deleteContact(Book *book)
{
    cout << "\n";
    string name;
    cout << "请输入要删除的联系人姓名：";
    cin >> name;
    int idx = findIndex(book, &name);
    if (idx == -1)
    {
        cout << "该联系人不存在！\n";
        cout << "\n";
    }
    else
    {
        for (int i = idx; i < book->size; i++)
            book->contacts[i] = book->contacts[i + 1]; // 将后面的联系人往前移一位
        book->size--;
        cout << "联系人" << idx + 1 << "-" << name << "删除成功！\n";
        cout << "\n";
    }
}

// 查找联系人的函数
void findContact(Book *book)
{
    cout << "\n";
    string name;
    cout << "请输入要查找的联系人姓名：";
    cin >> name;
    int idx = findIndex(book, &name);
    if (idx == -1)
    {
        cout << "该联系人不存在！\n";
        cout << "\n";
    }
    else
    {
        cout << "联系人" << idx + 1 << "-" << name << "的信息为：\n";
        printAContact(&book->contacts[idx]);
        cout << "\n";
    }
}

// 修改联系人的函数
void modifyContact(Book *book)
{
    cout << "\n";
    string name;
    cout << "请输入要修改的联系人姓名：";
    cin >> name;
    int idx = findIndex(book, &name);
    if (idx == -1)
    {
        cout << "该联系人不存在！\n";
        cout << "\n";
    }
    else
    {
        cout << "输入新的联系人信息：\n";
        cout << "\n";
        cout << "输入联系人姓名：";
        cin >> book->contacts[book->size].name;

        int gender;
        cout << "输入联系人性别(1为男,2为女)：";
        cin >> gender;
        while (true)
        {
            if (gender == 1 || gender == 2)
            {
                book->contacts[book->size].gender = gender;
                break;
            }
            else
            {
                cout << "输入有误，请重新输入：";
                cin >> gender;
            }
        }

        cout << "输入联系人年龄：";
        cin >> book->contacts[book->size].age;

        cout << "输入联系人电话号码：";
        cin >> book->contacts[book->size].number;

        cout << "输入联系人地址：";
        cin >> book->contacts[book->size].address;

        cout << "联系人" << idx + 1 << "-" << name << "的信息已修改成功！\n";
        cout << "\n";
    }
}

// 清空联系人的函数
void clearContacts(Book *book)
{
    book->size = 0;
    cout << "联系人列表已清空！\n";
    cout << "\n";
}