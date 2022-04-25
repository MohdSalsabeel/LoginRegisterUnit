#include "TwoStepVerification.h"
#include<fstream>
#include<iostream>
#include "encrypted.h"
#include "User_module.h"


std::string TwoStepVerification::correct_pin(){
    std::string pin_number;
    
        

            std::ifstream database_file;
            database_file.open("databaseRecord.txt",std::ios::in);

            std::cout<<"Enter pin number in two minutes: "<<std::endl;
            std::cin>>pin_number;


            while(database_file >> user_id >> password >> pin >> imei_no >> location >> mobile_no >> time){
                if(encrypt(pin_number)==pin){
                    
                    return "Successful";

                }
            }
            return "False";
        
};

