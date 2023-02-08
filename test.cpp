#include <regex>
#include <iostream>
using namespace std;
int main()
{
    string n = "123@qq.com";
    bool res = regex_match(n, regex("^[A-Za-z0-9]+@[a-zA-Z0-9][-a-zA-Z0-9]{0,62}(?:\.com)+$"));
    cout << res << endl;
    system("pause");
    return 0;
}
