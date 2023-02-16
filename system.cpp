#include <iostream>
#include <string.h>
#include <fstream>
#include <conio.h>
#include <regex>
#include <stdlib.h>
#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

// 欢迎界面
void ShowWelcome()
{
    cout << "\t######################################" << endl;
    cout << "\t#       欢迎使用新冠管理系统         #" << endl;
    cout << "\t######################################" << endl;
    system("pause");
    system("cls");
}

// 顶部信息
void TopInfo()
{
    cout << "\t--------------------------------------------" << endl;
    cout << "\t               新冠管理系统                 " << endl;
    cout << "\t--------------------------------------------" << endl;
}

// 菜单选择
void MenuSelect()
{
    cout << "\t\t1.新增患者记录" << endl;
    cout << "\t\t2.统计患者信息" << endl;
    cout << "\t\t3.查询患者信息" << endl;
    cout << "\t\t4.新增疫苗接种记录" << endl;
    cout << "\t\t5.退出系统" << endl;
    cout << "\n";
}

// 登录界面
void LoginIn()
{
    TopInfo();
    string username;
    string pwd;

    while (true)
    {
        cout << "\t\t输入用户名及密码：" << endl;
        cout << "\t\t用户名：";
        cin >> username;
        cout << "\t\t密码：";
        char c;
        int count = 0;
        char password[MAX] = {};
        while ((c = getch()) != '\r')
        {
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            {                 // 密码只可包含数字和字母
                putchar('*'); // 接收到一个字符后, 打印一个*
                password[count] = c;
                count++;
            }
        }
        pwd = password;
        cout << endl;
        if (username != "admin" || pwd != "1234")
        {
            cout << "\t\t用户名或密码错误，请重新输入" << endl;
        }
        else
        {
            cout << "\t\t登录成功，";
            break;
        }
    }
    system("pause");
    system("cls");
}

// 患者信息
struct Patient
{
    string name;
    string sex;
    int age;
    string address;
    string phone;
    string email;
    string symptom;
    string doctorname;
};

// 接种疫苗信息
struct VacInfo
{
    string name;
    string sex;
    int age;
    string date;
    string phone;
    string vac;
};

// 疫苗信息数组
struct VacInfoList
{
    struct VacInfo vacinfo[MAX];
    int V_size;
};

// 患者数组
struct PatientList
{
    struct Patient patient[MAX];
    int P_size;
};

// 字数统计
int GetStringWords(string strWord)
{
    int nWords(0);
    int nLen = strWord.length();
    int i(0);
    while (i < nLen)
    {
        // 如果是汉字则移到下一个
        if (strWord[i] & 0x80)
        {
            i++;
        }
        nWords++;
        i++;
    }
    return nWords;
}

// 判断手机号是否正确
bool JudgePhone(string strWord)
{
    int number(0);
    int nLen = strWord.length();
    int i(0);
    while (i < nLen)
    {
        if (int(strWord[i]) >= 48 && int(strWord[i]) <= 57)
        {
            number++;
        }
        i++;
    }
    if (i == number && number == 11 && i == 11)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 判断邮箱是否正确
bool JudgeEmail(string strWord)
{
    bool res = regex_match(strWord, regex("^[A-Za-z0-9]+@[a-zA-Z0-9][-a-zA-Z0-9]{0,62}(?:\\.com)+$"));
    return res;
}

// 判断日期格式是否正确
bool JudgeDate(string strWord)
{
    bool res = regex_match(strWord, regex("^(?:0?[1-9]|[1-2]\\d|30|31)\\/(?:1[0-2]|0?[1-9])\\/\\d{2}$"));
    return res;
}

// 新增患者记录
void AddPatient(bool sign)
{
    PatientList patientlist;
    patientlist.patient[MAX];
    patientlist.P_size = 0;
    char flag;
    if (sign == false)
    {
        fstream fout("Record1.txt", ios::out);
        fout.close();
    }
    do
    {
        system("cls");
        TopInfo();
        int i = patientlist.P_size;
        cout << "\t！！！！！！！新增一条患者记录！！！！！！！" << endl;
        do
        {
            cout << "\t\t姓名：";
            cin >> patientlist.patient[i].name;
            if (GetStringWords(patientlist.patient[i].name) < 2 || GetStringWords(patientlist.patient[i].name) > 6)
            {
                cout << "\t输入无效，姓名只能由2-6个字符组成。请重新输入！" << endl;
            }
        } while (GetStringWords(patientlist.patient[i].name) < 2 || GetStringWords(patientlist.patient[i].name) > 6);
        do
        {
            cout << "\t\t性别[男/女]：";
            cin >> patientlist.patient[i].sex;
            if (patientlist.patient[i].sex != "男" && patientlist.patient[i].sex != "女")
            {
                cout << "\t输入无效，性别只能为男或女。请重新输入！" << endl;
            }
        } while (patientlist.patient[i].sex != "男" && patientlist.patient[i].sex != "女");
        do
        {
            cout << "\t\t年龄：";
            cin >> patientlist.patient[i].age;
            if (patientlist.patient[i].age < 1 || patientlist.patient[i].age > 120)
            {
                cout << "\t输入无效，年龄只能为1-120岁。请重新输入！" << endl;
            }
        } while (patientlist.patient[i].age < 1 || patientlist.patient[i].age > 120);
        do
        {
            cout << "\t\t住址：";
            cin >> patientlist.patient[i].address;
            if (GetStringWords(patientlist.patient[i].address) < 2 || GetStringWords(patientlist.patient[i].address) > 10)
            {
                cout << "\t输入无效，住址只能由2-10个字符组成。请重新输入！" << endl;
            }
        } while (GetStringWords(patientlist.patient[i].address) < 2 || GetStringWords(patientlist.patient[i].address) > 10);
        do
        {
            cout << "\t\t手机：";
            cin >> patientlist.patient[i].phone;
            if (!JudgePhone(patientlist.patient[i].phone))
            {
                cout << "\t输入无效，手机号码只能由11位数字组成。请重新输入！" << endl;
            }
        } while (!JudgePhone(patientlist.patient[i].phone));
        do
        {
            cout << "\t\t邮箱：";
            cin >> patientlist.patient[i].email;
            if (!JudgeEmail(patientlist.patient[i].email))
            {
                cout << "\t输入无效，不符合电子邮箱格式。请重新输入！" << endl;
            }
        } while (!JudgeEmail(patientlist.patient[i].email));
        do
        {
            cout << "\t\t症状：";
            cin >> patientlist.patient[i].symptom;
            if (GetStringWords(patientlist.patient[i].symptom) < 2 || GetStringWords(patientlist.patient[i].symptom) > 15)
            {
                cout << "\t输入无效，症状只能由2-15个字符组成。请重新输入！" << endl;
            }
        } while (GetStringWords(patientlist.patient[i].symptom) < 2 || GetStringWords(patientlist.patient[i].symptom) > 15);
        do
        {
            cout << "\t\t主治医生：";
            cin >> patientlist.patient[i].doctorname;
            if (GetStringWords(patientlist.patient[i].doctorname) < 2 || GetStringWords(patientlist.patient[i].doctorname) > 6)
            {
                cout << "\t输入无效，主治医生只能由2-6个字符组成。请重新输入！" << endl;
            }
        } while (GetStringWords(patientlist.patient[i].doctorname) < 2 || GetStringWords(patientlist.patient[i].doctorname) > 6);
        patientlist.P_size++;
        ofstream ofs;
        ofs.open("Record1.txt", ios::out | ios::app);
        ofs << patientlist.patient[i].name << "\n"
            << patientlist.patient[i].sex << "\n"
            << patientlist.patient[i].age
            << "\n"
            << patientlist.patient[i].address << "\n"
            << patientlist.patient[i].phone << "\n"
            << patientlist.patient[i].email
            << "\n"
            << patientlist.patient[i].symptom << "\n"
            << patientlist.patient[i].doctorname << "\n";

        cout << "\t\t……………患者信息录入成功……………" << endl;
        cout << "\t\t是否继续录用[Y/N]：";
        cin >> flag;
        if (flag == 'Y' || flag == 'y')
        {
            ofs << "end" << endl;
            ofs.close();
        }
    } while (flag == 'Y' || flag == 'y');
    cout << "\t\t感谢使用！";
    system("pause");
    system("cls");
}

// 排序输出信息
void SortPatient()
{
    system("cls");
    PatientList patientlist;
    patientlist.patient[MAX];
    patientlist.P_size = 0;
    ifstream ifs;
    ifs.open("Record1.txt", ios::in);
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    string buf_s;
    // int buf_i;
    bool flag = false;
    // int count = 0;
    do
    {
        getline(ifs, buf_s);
        patientlist.patient[patientlist.P_size].name = buf_s;
        getline(ifs, buf_s);
        patientlist.patient[patientlist.P_size].sex = buf_s;
        getline(ifs, buf_s);
        patientlist.patient[patientlist.P_size].age = atoi(buf_s.c_str());
        getline(ifs, buf_s);
        patientlist.patient[patientlist.P_size].address = buf_s;
        getline(ifs, buf_s);
        patientlist.patient[patientlist.P_size].phone = buf_s;
        getline(ifs, buf_s);
        patientlist.patient[patientlist.P_size].email = buf_s;
        getline(ifs, buf_s);
        patientlist.patient[patientlist.P_size].symptom = buf_s;
        getline(ifs, buf_s);
        patientlist.patient[patientlist.P_size].doctorname = buf_s;
        patientlist.P_size++;
    } while (getline(ifs, buf_s));
    ifs.close();
    cout << "\t！！！！！！！患者信息统计！！！！！！！" << endl;
    cout << "姓名\t性别\t年龄\t住址\t\t手机\t\t邮箱\t\t症状\t主治医生" << endl;
    cout << "============================================================================================" << endl;
    // 一共n-1个阶段，在第i个阶段，未排序序列长度从n-i+1到n-i。
    Patient temp = {};
    for (int i = 0; i < patientlist.P_size; ++i)
    {
        // 将序列从1到n-i+1的最大值，移到n-i+1的位置
        for (int j = 0; j < patientlist.P_size - i; ++j)
            // 其中j枚举的是前后交换元素的前一个元素序号
            if (patientlist.patient[j].age < patientlist.patient[j + 1].age)
            {
                temp = patientlist.patient[j];
                patientlist.patient[j] = patientlist.patient[j + 1];
                patientlist.patient[j + 1] = temp;
            }
        // swap(patientlist.patient[j], patientlist.patient[j + 1]);
    }
    // 输出

    for (int i = 0; i < patientlist.P_size; i++)
    {

        cout << patientlist.patient[i].name << "\t" << patientlist.patient[i].sex << "\t"
             << patientlist.patient[i].age << "\t" << patientlist.patient[i].address << "\t"
             << patientlist.patient[i].phone << "\t" << patientlist.patient[i].email << "\t"
             << patientlist.patient[i].symptom << "\t" << patientlist.patient[i].doctorname << endl;
    }
    cout << "\t\t感谢使用！";
    system("pause");
    system("cls");
}

// 查询患者信息
void SearchPatient()
{
    char retry;
    do
    {
        system("cls");
        PatientList patientlist;
        patientlist.patient[MAX];
        patientlist.P_size = 0;
        ifstream ifs;
        ifs.open("Record1.txt", ios::in);
        if (!ifs.is_open())
        {
            cout << "文件打开失败" << endl;
            return;
        }
        string buf_s;
        // int buf_i;
        bool flag = false;
        // int count = 0;
        do
        {
            getline(ifs, buf_s);
            patientlist.patient[patientlist.P_size].name = buf_s;
            getline(ifs, buf_s);
            patientlist.patient[patientlist.P_size].sex = buf_s;
            getline(ifs, buf_s);
            patientlist.patient[patientlist.P_size].age = atoi(buf_s.c_str());
            getline(ifs, buf_s);
            patientlist.patient[patientlist.P_size].address = buf_s;
            getline(ifs, buf_s);
            patientlist.patient[patientlist.P_size].phone = buf_s;
            getline(ifs, buf_s);
            patientlist.patient[patientlist.P_size].email = buf_s;
            getline(ifs, buf_s);
            patientlist.patient[patientlist.P_size].symptom = buf_s;
            getline(ifs, buf_s);
            patientlist.patient[patientlist.P_size].doctorname = buf_s;
            patientlist.P_size++;
        } while (getline(ifs, buf_s));
        ifs.close();

        TopInfo();
        cout << "\t！！！！！！！患者信息查询！！！！！！！" << endl;
        string pname;
        bool flag1 = 0;
        cout << "\t\t输入患者姓名：";
        cin >> pname;
        for (int i = 0; i < patientlist.P_size; i++)
        {
            if (pname == patientlist.patient[i].name)
            {
                flag1 = 1;
                cout << "姓名\t性别\t年龄\t住址\t\t手机\t\t邮箱\t\t\t症状\t主治医生" << endl;
                cout << "============================================================================================" << endl;
                cout << patientlist.patient[i].name << "\t" << patientlist.patient[i].sex << "\t"
                     << patientlist.patient[i].age << "\t" << patientlist.patient[i].address << "\t"
                     << patientlist.patient[i].phone << "\t" << patientlist.patient[i].email << "\t"
                     << patientlist.patient[i].symptom << "\t" << patientlist.patient[i].doctorname << endl;
            }
        }
        if (flag1 == 0)
        {
            cout << "\t\t未查询到该患者信息！" << endl;
        }
        cout << "\t\t是否继续查询[Y/N]：";
        cin >> retry;
    } while (retry == 'Y' || retry == 'y');
    cout << "\t\t感谢使用！";
    system("pause");
    system("cls");
}

// 添加疫苗信息
void AddVacInfo()
{
    VacInfoList vacinfolist;
    vacinfolist.vacinfo[MAX];
    vacinfolist.V_size = 0;
    // char flag;
    // do
    // {
    system("cls");
    TopInfo();
    int i = vacinfolist.V_size;
    cout << "\t！！！！！！！疫苗接种系统！！！！！！！" << endl;
    do
    {
        cout << "\t\t接种者姓名：";
        cin >> vacinfolist.vacinfo[i].name;
        if (GetStringWords(vacinfolist.vacinfo[i].name) < 2 || GetStringWords(vacinfolist.vacinfo[i].name) > 6)
        {
            cout << "\t输入无效，姓名只能由2-6个字符组成。请重新输入！" << endl;
        }
    } while (GetStringWords(vacinfolist.vacinfo[i].name) < 2 || GetStringWords(vacinfolist.vacinfo[i].name) > 6);
    do
    {
        cout << "\t\t性别[男/女]：";
        cin >> vacinfolist.vacinfo[i].sex;
        if (vacinfolist.vacinfo[i].sex != "男" && vacinfolist.vacinfo[i].sex != "女")
        {
            cout << "\t输入无效，性别只能为男或女。请重新输入！" << endl;
        }
    } while (vacinfolist.vacinfo[i].sex != "男" && vacinfolist.vacinfo[i].sex != "女");
    do
    {
        cout << "\t\t年龄：";
        cin >> vacinfolist.vacinfo[i].age;
        if (vacinfolist.vacinfo[i].age < 1 || vacinfolist.vacinfo[i].age > 120)
        {
            cout << "\t输入无效，年龄只能为1-120岁。请重新输入！" << endl;
        }
    } while (vacinfolist.vacinfo[i].age < 1 || vacinfolist.vacinfo[i].age > 120);
    do
    {
        cout << "\t\t接种日期（dd/mm/yy）：";
        cin >> vacinfolist.vacinfo[i].date;
        if (!JudgeDate(vacinfolist.vacinfo[i].date))
        {
            cout << "\t输入无效，不符合日期格式。请重新输入！" << endl;
        }
    } while (!JudgeDate(vacinfolist.vacinfo[i].date));
    do
    {
        cout << "\t\t手机：";
        cin >> vacinfolist.vacinfo[i].phone;
        if (!JudgePhone(vacinfolist.vacinfo[i].phone))
        {
            cout << "\t输入无效，手机号码只能由11位数字组成。请重新输入！" << endl;
        }
    } while (!JudgePhone(vacinfolist.vacinfo[i].phone));
    int vac = 0;
    do
    {
        cout << "\t\t选择疫苗：" << endl;
        cout << "\t\t\t1.国药中生北京" << endl;
        cout << "\t\t\t2.国药中生武汉" << endl;
        cout << "\t\t\t3.北京科兴中维" << endl;
        cout << "\t\t请选择（1-3）：";
        cin >> vac;
        switch (vac)
        {
        case 1:
        {
            vacinfolist.vacinfo[i].vac = "国药中生北京";
            cout << "\t……国药中生北京疫苗接种信息录入成功……" << endl;
        }
        break;
        case 2:
        {
            vacinfolist.vacinfo[i].vac = "国药中生武汉";
            cout << "\t……国药中生武汉疫苗接种信息录入成功……" << endl;
        }
        break;
        case 3:
        {
            vacinfolist.vacinfo[i].vac = "北京科兴中维";
            cout << "\t……北京科兴中维疫苗接种信息录入成功……" << endl;
        }
        break;
        default:
            cout << "输入有误，请重新输入" << endl;
            break;
        }
    } while (vac < 1 || vac > 3);
    vacinfolist.V_size++;
    ofstream ofs;
    ofs.open("Record2.txt", ios::out | ios::app);
    ofs << vacinfolist.vacinfo[i].name << "\t"
        << vacinfolist.vacinfo[i].sex << "\t"
        << vacinfolist.vacinfo[i].age << "\t"
        << vacinfolist.vacinfo[i].date << "\t"
        << vacinfolist.vacinfo[i].phone << "\t"
        << vacinfolist.vacinfo[i].vac << "\n";
    // cout << "\t\t……………患者信息录入成功……………" << endl;
    // cout << "\t\t是否继续录用[Y/N]：";
    // cin >> flag;
    // if (flag == 'Y' || flag == 'y')
    // {
    // ofs << "end" << endl;
    ofs.close();
    //     }
    // } while (flag == 'Y' || flag == 'y');
    cout << "\t\t感谢使用！";
    system("pause");
    system("cls");
}
int main()
{
    char meun;
    bool sign = false;
    // PatientList patientlist;
    // patientlist.patient[MAX];
    // patientlist.P_size = 0;
    ShowWelcome();
    LoginIn();
    do
    {
        TopInfo();
        MenuSelect();
        do
        {
            cout << "\t\t请选择相应的功能（1-5）：";
            cin >> meun;
            if (meun != '1' && meun != '2' && meun != '3' && meun != '4' && meun != '5')
            {
                cout << "\t输入无效，请重新选择：" << endl;
            }
        } while (meun != '1' && meun != '2' && meun != '3' && meun != '4' && meun != '5');
        switch (meun)
        {
        case '1':
        {
            AddPatient(sign);
            sign = true;
            break;
        }

        case '2':
        {
            SortPatient();
            break;
        }
        case '3':
        {
            SearchPatient();
            break;
        }
        case '4':
        {
            AddVacInfo();
            break;
        }
        break;
        case '5':
            cout << "\t\t感谢使用！";
            system("pause");
            return 0;
        default:
            break;
        }
    } while (meun != 5);
}