

#ifndef User_hpp
#define User_hpp

#include <stdio.h>
#include <iostream>

class User
{
public:
    User(std::string A,std::string B,std::string C,std::string D,unsigned long long E = 10000,bool F = false);
    //若无特别定义余额则默认10000
    std::string UserName;
    std::string Name;
    std::string Id;
    std::string Password;
    unsigned long long Surplus;
    bool Lock;
};

class User_WithDraw
{
public:
    User_WithDraw(std::string UserName,unsigned long long cash = 0);
    std::string UserName;
    unsigned long long cash;
};

#endif /* User_hpp */


