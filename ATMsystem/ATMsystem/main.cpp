#include <iostream>
#include <fstream>
#include "Initiate.hpp"
#include "User.hpp"
#include <vector>
#include "Welcome.hpp"
#include "MainSystem.hpp"
#include "SaveInfo.hpp"
using namespace std;



int main()
{
    system("chcp 65001");//防止乱码
    system("cls");
    //----------------初始化用户列表-----------------
    vector<User> UserInfo;
    bool If;
    If = Initiate(UserInfo);//进行初始化操作
    //------------------运行程序--------------------
    if(If)
    {
        vector<User_WithDraw> UserWithDraw;
        User_TodayWithdraw(UserWithDraw);
        Welcome();
        //--------------检测插卡---------------
        while(!Card())
        {
            cout<<"键入Y以重新读取卡  键入其余任意键以退出ATM程序";
            char Temp;
            cin>>Temp;
            if(Temp - 121 == 0||Temp - 89 == 0)
            {
                continue;
            }else
            {
                cout<<"已退出ATM程序 祝你愉快";
                return 0;
            }
        }
        //--------------验证密码----------------
        unsigned long long UserSequence;
        while(!CardIdentify(UserInfo, UserSequence))
        {
            cout<<"键入Y以重新读取卡  键入其余任意键以退出ATM程序";
            char Temp;
            cin>>Temp;
            if(Temp - 121 == 0||Temp - 89 == 0)
            {
                system("cls");
            }else
            {
                cout<<"已退出ATM程序 祝你愉快";
                return 0;
            }
            while(!Card())
            {
                cout<<"键入Y以重新读取卡  键入其余任意键以退出ATM程序";
                char Temp;
                cin>>Temp;
                if(Temp - 121 == 0||Temp - 89 == 0)
                {
                    system("cls");
                    continue;
                }else
                {
                    cout<<"已退出ATM程序 祝你愉快";
                    return 0;
                }
            }
        }
        //-------------主系统---------------
        Menu();
        while(!Input(UserInfo[UserSequence], UserInfo, UserWithDraw))
        {
            system("cls");
            Menu();
        }
        //--------------Exit---------------
        cout<<"正在更新用户信息 请稍后"<<endl;
        Save(UserInfo);
        Delay(1*1);
        cout<<"已退出ATM程序 祝你愉快"<<endl;
    }else//------------初始化失败-------------
    {
        cout<<"已退出ATM程序 祝你愉快";
    }
    
    return 0;
}
