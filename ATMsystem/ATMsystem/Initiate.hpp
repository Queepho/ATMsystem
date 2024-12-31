#ifndef Initiate_hpp
#define Initiate_hpp

#include <stdio.h>
#include <vector>
#include "User.hpp"
#include "TimeInfo.hpp"
using namespace std;
bool Initiate(vector<User> &Column);
bool IsNum(string input);
unsigned long long toint(string input);
void User_TodayWithdraw(vector<User_WithDraw> &UserWithDraw);
#endif /* Initiate_hpp */



