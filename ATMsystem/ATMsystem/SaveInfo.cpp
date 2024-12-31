#include "SaveInfo.hpp"

void Save(vector<User> &UserInfo)
{
    ofstream TempFile;
    TempFile.open("D:\\PersonalData\\Documents\\ATMsystem\\UserFile.csv",ios::out);
    TempFile<<"账号"<<','
    <<"姓名"<<','
    <<"身份证"<<','
    <<"密码"<<','
    <<"余额"<<','
    <<"锁定状态"<<endl;
    string Lock = "false";
    string Lock2 = "true";
    for(unsigned int i=0;i<UserInfo.size();i++)
    {
        TempFile<<UserInfo[i].UserName<<','
        <<UserInfo[i].Name<<','
        <<UserInfo[i].Id<<','
        <<UserInfo[i].Password<<','
        <<UserInfo[i].Surplus<<',';
        if(UserInfo[i].Lock)
        {
            TempFile<<Lock2<<endl;
        }else
        {
            TempFile<<Lock<<endl;
        }
    }
    TempFile.close();
}

void Save_Trans(string UserName1, string UserName2, unsigned long long funds)
{
    ofstream TempFile;
    TempFile.open("D:\\PersonalData\\Documents\\ATMsystem\\TransLog.csv",ios::app);
    TempFile<<UserName1<<','
    <<UserName2<<','
    <<funds<<','
    <<TimeInfo_All()<<endl;
    TempFile.close();
}

void Save_WithDraw(string UserName, unsigned long long cash)
{
    ofstream TempFile;
    TempFile.open("D:\\PersonalData\\Documents\\ATMsystem\\WithDrawLog.csv",ios::app);
    TempFile<<UserName<<','
    <<cash<<','
    <<TimeInfo_Year()<<','
    <<TimeInfo_Month()<<','
    <<TimeInfo_Day()<<endl;
    TempFile.close();
}

void Save_Deposit(string UserName, unsigned long long funds)
{
    ofstream TempFile;
    TempFile.open("D:\\PersonalData\\Documents\\ATMsystem\\DepositLog.csv",ios::app);
    TempFile<<UserName<<','
    <<funds<<','
    <<TimeInfo_All()<<endl;
    TempFile.close();
}
