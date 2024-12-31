

#include "User.hpp"

User::User(std::string A, std::string B, std::string C, std::string D, unsigned long long E, bool F)
:UserName(A), Name(B), Id(C), Password(D), Surplus(E), Lock(F)
{
    
}

User_WithDraw::User_WithDraw(std::string UserName, unsigned long long cash)
:UserName(UserName), cash(cash)
{
    
}
