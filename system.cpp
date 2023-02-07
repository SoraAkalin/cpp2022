#include <iostream>
#include <string.h>
#define MAX 1000
using namespace std;

void ShowWelcome()
{
    cout << "\t######################################" << endl;
    cout << "\t#       欢迎使用新冠管理系统         #" << endl;
    cout << "\t######################################" << endl;
    system("pause");
    system("cls");
}

void TopInfo()
{
    cout << "\t--------------------------------------------" << endl;
    cout << "\t               新冠管理系统                 " << endl;
    cout << "\t--------------------------------------------" << endl;
}

void MenuSelect()
{
    cout << "\t\t1.新增患者记录" << endl;
    cout << "\t\t2.统计患者信息" << endl;
    cout << "\t\t3.查询患者信息" << endl;
    cout << "\t\t4.新增疫苗接种记录" << endl;
    cout << "\t\t5.退出系统" << endl;
    cout << "\n";
}

//登录界面
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
        cin >> pwd;
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

struct PatientList
{
    struct Patient patient[MAX];
    int P_size;
};

//新增患者记录
void AddPatient(PatientList *patientlist)
{
    char flag;
    do
    {
        system("cls");
        TopInfo();
        int i = patientlist->P_size;
        cout << "\t！！！！！！！新增一条患者记录！！！！！！！" << endl;
        cout << "\t\t姓名：";
        cin >> patientlist->patient[i].name;
        cout << "\t\t性别[男/女]：";
        cin >> patientlist->patient[i].sex;
        cout << "\t\t年龄：";
        cin >> patientlist->patient[i].age;
        cout << "\t\t住址：";
        cin >> patientlist->patient[i].address;
        cout << "\t\t手机：";
        cin >> patientlist->patient[i].phone;
        cout << "\t\t邮箱：";
        cin >> patientlist->patient[i].email;
        cout << "\t\t症状：";
        cin >> patientlist->patient[i].symptom;
        cout << "\t\t主治医生：";
        cin >> patientlist->patient[i].doctorname;
        patientlist->P_size++;
        cout << "\t\t……………患者信息录入成功……………" << endl;
        cout << "\t\t是否继续录用[Y/N]：";
        cin >> flag;
    } while (flag == 'Y' || flag == 'y');
    cout << "\t\t感谢使用！";
    system("pause");
    system("cls");
}

//查询患者信息
void SearchPatient(PatientList *patientlist)
{
    char retry;
    do
    {
        system("cls");
        TopInfo();
        cout << "\t！！！！！！！患者信息查询！！！！！！！" << endl;
        string pname;
        bool flag = 0;
        cout << "\t\t输入患者姓名：";
        cin >> pname;
        for (int i = 0; i < patientlist->P_size; i++)
        {
            if (pname == patientlist->patient[i].name)
            {
                flag = 1;
                cout << "姓名\t性别\t年龄\t住址\t手机\t邮箱\t症状\t主治医生" << endl;
                cout << "========================================================================" << endl;
                cout << patientlist->patient[i].name << "\t" << patientlist->patient[i].sex << "\t"
                     << patientlist->patient[i].age << "\t" << patientlist->patient[i].address << "\t"
                     << patientlist->patient[i].phone << "\t" << patientlist->patient[i].email << "\t"
                     << patientlist->patient[i].symptom << "\t" << patientlist->patient[i].doctorname;
            }
        }
        if (flag == 0)
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

// test

int main()
{
    char meun;
    PatientList patientlist;
    patientlist.patient[MAX];
    patientlist.P_size = 0;
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
            AddPatient(&patientlist);
            break;
        }

        case '2':

            break;
        case '3':

            break;
        case '4':
        {

            SearchPatient(&patientlist);
            break;
        }

        case '5':
            cout << "\t\t感谢使用！";
            system("pause");
            return 0;
        default:
            break;
        }
    } while (meun != 5);
}