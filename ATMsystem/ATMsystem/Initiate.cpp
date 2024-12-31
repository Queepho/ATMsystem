#include "Initiate.hpp"
#include "User.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

bool Initiate(vector<User> &Column)
{
    try{
        ifstream TestFile("D:\\PersonalData\\Documents\\ATMsystem\\UserFile.csv",ios::in);
        
        if(!TestFile)
        {
            cout<<"初始化读取用户文件失败"<<endl<<"自动重新生成空用户文件"<<endl;
            ofstream File1;
            File1.open("D:\\PersonalData\\Documents\\ATMsystem\\UserFile.csv");
            File1<<"账号"<<','
            <<"姓名"<<','
            <<"身份证"<<','
            <<"密码"<<','
            <<"余额"<<','
            <<"锁定状态"<<endl;
            File1.close();
        }else
        {
            cout<<"正在初始化获取用户信息"<<endl;
            string OutLine;
            string EachWord;
            istringstream TempLine;
            string empty;//用于放置表头
            string TempC1[6];
            int time=0;
            unsigned long UserName=0, Password=0, Surplus=10000;
            bool Lock = false;
            getline(TestFile,empty);//将表头舍去
            Column.clear();
            while(getline(TestFile, OutLine))
            {
                TempLine.clear();
                TempLine.str(OutLine);
                time = 0;
                while(getline(TempLine, EachWord, ','))
                {
                    TempC1[time] = EachWord;
                    time++;
                }
                if(time != 6)
                {
                    throw 0;
                }
                for(int i=0;i<6;i++)
                {
                    if(i==0)
                    {
                        if(TempC1[i].length()==19 && IsNum(TempC1[i]))
                        {
                            UserName = toint(TempC1[i]);
                        }else{
                            throw 1;
                        }
                    }else if(i==2)
                    {
                        if(TempC1[i].length()==18)
                        {
                            
                        }else{
                            throw 3;
                        }
                    }else if(i==3)
                    {
                        if(TempC1[i].length()==6 && IsNum(TempC1[i]))
                        {
                            Password = toint(TempC1[i]);
                        }else{
                            throw 4;
                        }
                    }else if(i==4)
                    {
                        if(IsNum(TempC1[i]))
                        {
                            Surplus = toint(TempC1[i]);
                        }else{
                            throw 5;
                        }
                    }else if(i==5)
                    {
                        if(TempC1[i]=="true")
                        {
                            Lock = true;
                        }
                    }
                }
                Column.push_back(User(TempC1[0],TempC1[1],TempC1[2],TempC1[3],Surplus,Lock));
            }
            if(Column.size()!=0)
            {
                cout<<"初始化成功"<<endl;
                return true;
            }else{
                cout<<"初始化失败:用户信息文件为空"<<endl;
                return false;
            }
        }
        return false;
    }catch(int wrong)
    {
        cout<<"初始化失败:用户信息文件存在格式错误"<<endl;
        return false;
    }
}

bool IsNum(string input)
{
    for(unsigned int i=0;i<input.length();i++)
    {
        int temp = (int)input[i];
        if(temp >=48 && temp <= 57)
        {
            continue;
        }else
        {
            return false;
        }
    }
    return true;
}

unsigned long long toint(string input)
{
    unsigned long long temp = stoll(input);
    return temp;
}

void User_TodayWithdraw(vector<User_WithDraw> &UserWithDraw)
{
    UserWithDraw.clear();
    ifstream TestFile("D:\\PersonalData\\Documents\\ATMsystem\\WithDrawLog.csv",ios::in);
    string Outline;
    string Eachword;
    istringstream TempLine;
    string Temp[5];
    int time = 0;
    while(getline(TestFile,Outline))
    {
        TempLine.clear();
        TempLine.str(Outline);
        time = 0;
        while(getline(TempLine,Eachword,','))
        {
            Temp[time] = Eachword;
            time++;
        }
        if(toint(Temp[2]) == TimeInfo_Year() && toint(Temp[3]) == TimeInfo_Month() && toint(Temp[4])==TimeInfo_Day())
        {
            bool value = true;
            for(unsigned int i=0;i<UserWithDraw.size() && value;i++)
            {
                if(UserWithDraw[i].UserName == Temp[0])
                {
                    value = false;
                    UserWithDraw[i].cash += toint(Temp[1]);
                }
            }
            if(value)
            {
                UserWithDraw.push_back(User_WithDraw(Temp[0],toint(Temp[1])));
            }
        }
    }
}
