//#ifndef twotest
//#define twotest
#pragma once
#include<string>
//#include "User_module.h"
//#include "login_module.cpp"
// #ifndef TwoStepVerification
// #define TwoStepVerification
//#include "login_module.cpp"



class TwoStepVerification : public User
{
    public:
    std::string pin_number;
    std::string correct_pin();
};

//#endif
