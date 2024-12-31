
#ifndef Welcome_hpp
#define Welcome_hpp

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "Initiate.hpp"
#include "User.hpp"
#include "SaveInfo.hpp"
using namespace std;
void Delay(int time);
void Welcome();
bool Card();
bool CardIdentify(vector<User> &UserInfo, unsigned long long &UserSequence);
bool PasswordIdentify(string UserPassword);

#endif /* Welcome_hpp */
