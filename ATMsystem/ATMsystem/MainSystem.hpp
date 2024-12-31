#ifndef MainSystem_hpp
#define MainSystem_hpp

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "User.hpp"
#include "Welcome.hpp"
#include "Initiate.hpp"
#include "SaveInfo.hpp"
using namespace std;
void Menu();
bool Input(User &Index, vector<User> &UserInfo, vector<User_WithDraw> &UserWithDraw);
void Transfer(string TargetUser, vector<User> &UserInfo, User &Index);
unsigned long long Remain(string UserName, vector<User_WithDraw> UserWithDraw);
#endif /* MainSystem_hpp */
