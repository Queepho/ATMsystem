#include "Welcome.hpp"

void Delay(int time)
{
    clock_t now = clock();
    while(clock() - now < time);
}


void Welcome()
{
    cout<<"运行中请等待"<<endl;
    Delay(3*1);
    //system("cls");
    cout<<"欢迎使用ATM程序 请插卡"<<endl;
}

bool Card()
{
    try
    {
        ifstream CardFile("D:\\PersonalData\\Documents\\ATMsystem\\CardFile.csv",ios::in);
        if(!CardFile)
        {
            cout<<"未识别卡 请重新插入卡"<<endl;
            CardFile.close();
            throw 0;
        }else
        {
            string UserName;
            getline(CardFile,UserName);
            if(UserName.length()==19 && IsNum(UserName))
            {
                cout<<"卡已读取 请等待"<<endl;
                CardFile.close();
                Delay(2*1);
                //system("cls");
            }else
            {
                cout<<"卡信息格式错误 请重新插入有效卡"<<endl;
                CardFile.close();
                throw 1;
            }
        }
    } catch (int wrong) {
        Delay(1*1);
        return false;
    }
    return true;
}

bool CardIdentify(vector<User> &UserInfo, unsigned long long &UserSequence)
{
    ifstream CardFile("D:\\PersonalData\\Documents\\ATMsystem\\CardFile.csv",ios::in);
    string UserName;
    getline(CardFile,UserName);
    bool value = true;
    for(unsigned int i=0;i<UserInfo.size() && value;i++)
    {
        if(UserName == UserInfo[i].UserName)
        {
            UserSequence = i;
            value = false;
        }
    }
    if(value)
    {
        cout<<"未知用户名 请重新插入有效卡"<<endl;
        Delay(1*1);
        return false;
    }else if(!value && !UserInfo[UserSequence].Lock)
    {
        cout<<"卡信息已获取 请输入密码"<<endl;
        int trytime = 0;
        while(!PasswordIdentify(UserInfo[UserSequence].Password))
        {
            trytime++;
            if(trytime == 3)
            {
                UserInfo[UserSequence].Lock = true;
                cout<<"密码输入错误三次 已锁卡 自动退卡"<<endl;
                Delay(1*1);
                cout<<"正在更新用户信息 请稍后"<<endl;
                Save(UserInfo);
                Delay(1*1);
                return false;
            }
        }
    }else
    {
        cout<<"当前用户已锁卡 自动退卡"<<endl;
        Delay(1*1);
        return false;
    }
    return true;
}

bool PasswordIdentify(string UserPassword)
{
    string password;
    cin>>password;
    if(password.length()==6 && IsNum(password))
    {
        if(password == UserPassword)
        {
            cout<<"核验正确 正在登陆"<<endl;
            Delay(2*1);
            //system("cls");
            return true;
        }else
        {
            cout<<"密码错误 请重新输入密码"<<endl;
            return false;
        }
    }else
    {
        cout<<"密码格式错误 请重新输入密码"<<endl;
        return false;
    }
}


