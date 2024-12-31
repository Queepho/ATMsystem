#ifndef SaveInfo_hpp
#define SaveInfo_hpp

#include <stdio.h>
#include <fstream>
#include "User.hpp"
#include <vector>
#include "TimeInfo.hpp"
using namespace std;
void Save(vector<User> &UserInfo);
void Save_Trans(string UserName1, string UserName2, unsigned long long funds);
void Save_WithDraw(string UserName, unsigned long long cash);
void Save_Deposit(string UserName, unsigned long long funds);
#endif /* SaveInfo_hpp */
