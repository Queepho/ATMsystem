#include "MainSystem.hpp"

void Menu()
{
    cout<<"Main Menu:"<<endl;
    cout<<"   1 - View my balance"<<endl;
    cout<<"   2 - Withdraw cash"<<endl;
    cout<<"   3 - Deposit funds"<<endl;
    cout<<"   4 - Transfer funds"<<endl;
    cout<<"   5 - Change password"<<endl;
    cout<<"   6 - Exit"<<endl;
    cout<<endl<<"Enter a choice:";
}

bool Input(User &Index, vector<User> &UserInfo, vector<User_WithDraw> &UserWithDraw)
{
    char Temp;
    cin>>Temp;
    system("cls");
    if(Temp - '1' == 0)
    {
        cout<<Index.Surplus<<endl;
        cout<<"键入任意键以返回主菜单"<<endl;
        cin>>Temp;
        return false;
    }else if(Temp - '2' == 0)
    {
        cout<<"目前该账户余额为 "<<Index.Surplus<<endl;
        cout<<"请输入取款金额(100整数倍且单次限额5000): ";
        unsigned long long cash;
        cin>>cash;
        if(cash > Index.Surplus)
        {
            cout<<"余额不足 取款失败 自动返回主菜单"<<endl;
            Delay(1*1);
            return false;
        }else
        {
            if(cash % 100 == 0 && cash <= 5000)
            {
                if(cash <= Remain(Index.UserName, UserWithDraw))
                {
                    Index.Surplus = Index.Surplus - cash;
                    Save_WithDraw(Index.UserName, cash);
                    cout<<"成功取款 "<<cash<<"元 "<<endl;
                    cout<<"目前该账户余额为 "<<Index.Surplus<<endl;
                    cout<<"键入任意键以返回主菜单"<<endl;
                    cin>>Temp;
                    User_TodayWithdraw(UserWithDraw);
                    return false;
                }else
                {
                    cout<<"取款失败 取款金额超过日次限额"<<endl;
                    cout<<"目前该账户今日剩余限额为 "<<Remain(Index.UserName, UserWithDraw)<<endl;
                    cout<<"键入任意键以返回主菜单"<<endl;
                    cin>>Temp;
                    return false;
                }
            }else if(cash % 100 == 0 && cash > 5000)
            {
                cout<<"取款失败 超过单次限额"<<endl;
                cout<<"自动返回主菜单"<<endl;
                Delay(2*1);
                return false;
            }else
            {
                cout<<"取款失败 取款金额非100整数倍"<<endl;
                cout<<"自动返回主菜单"<<endl;
                Delay(2*1);
                return false;
            }
            
        }
    }else if(Temp - '3' == 0)
    {
        cout<<"请输入存款金额";
        unsigned long long funds;
        cin>>funds;
        Save_Deposit(Index.UserName, funds);
        Index.Surplus = Index.Surplus + funds;
        cout<<"成功存款 "<<funds<<"元 "<<endl;
        cout<<"目前该账户余额为 "<<Index.Surplus<<endl;
        cout<<"键入任意键以返回主菜单"<<endl;
        cin>>Temp;
        return false;
    }else if(Temp - '4' == 0)
    {
        cout<<"目前该账户余额为 "<<Index.Surplus<<endl;
        cout<<"请输入转账目标账户账号: ";
        string TargetUser;
        string TargetUser2;
        cin>>TargetUser;
        cout<<"请再次输入目标账户账号: ";
        cin>>TargetUser2;
        if(TargetUser == TargetUser2)
        {
            Transfer(TargetUser, UserInfo, Index);
            cout<<"目前该账户余额为 "<<Index.Surplus<<endl;
            cout<<"键入任意键以返回主菜单"<<endl;
            cin>>Temp;
            return false;
        }else
        {
            cout<<"两次输入账号不一致 自动返回主菜单"<<endl;
            Delay(1*1);
            return false;
        }
    }else if(Temp - '5' == 0)
    {
        string NewPassword;
        string NewPassword2;
        cout<<"请输入新密码: ";
        cin>>NewPassword;
        cout<<"请再次输入密码: ";
        cin>>NewPassword2;
        if(NewPassword.length()==6 && IsNum(NewPassword))
        {
            if(NewPassword == NewPassword2)
            {
                Index.Password = NewPassword;
                cout<<"密码已更改 自动返回主菜单"<<endl;
                Delay(1*1);
                return false;
            }else
            {
                cout<<"两次输入的密码不一致 自动返回主菜单"<<endl;
                Delay(1*1);
                return false;
            }
        }else
        {
            cout<<"输入的密码格式非法 自动返回主菜单"<<endl;
            Delay(1*1);
            return false;
        }
    }else if(Temp - '6' == 0)
    {
        return true;
    }else
    {
        cout<<"未知命令 自动返回主菜单"<<endl;
        return false;
    }
}

void Transfer(string TargetUser, vector<User> &UserInfo, User &Index)
{
    bool value = true;
    for(unsigned int i=0;i<UserInfo.size() && value;i++)
    {
        if(TargetUser == UserInfo[i].UserName)
        {
            value = false;
            cout<<"请输入转账金额: ";
            unsigned long long funds;
            cin>>funds;
            UserInfo[i].Surplus += funds;
            Index.Surplus -= funds;
            cout<<"已转入 "<<funds<<"元 "<<endl;
            Save_Trans(Index.UserName, TargetUser, funds);
        }
    }
    if(value)
    {
        cout<<"目标账户不存在"<<endl;
        Delay(1*1);
    }
}

unsigned long long Remain(string UserName, vector<User_WithDraw> UserWithDraw)
{
    bool value = true;
    unsigned long long output = 0;
    for(unsigned int i=0;i<UserWithDraw.size() && value;i++)
    {
        if(UserName == UserWithDraw[i].UserName)
        {
            value = false;
            output = 20000 - UserWithDraw[i].cash;
        }
    }
    if(value)
    {
        output = 20000;
    }
    return output;
}
