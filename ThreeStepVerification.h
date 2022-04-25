// #ifndef thirdtest
// #define thirdtest
#pragma once
#include<string>
//#include "User_module.h"
//#include "twostep_module.cpp"


class ThirdStepVerification : public User
{
    std::string verfiy_imei_number;
    int verify_current_location;
    int verify_previous_location;
    int verify_mobile_no;
public:
    void correct_third_step();

};

//#endif
