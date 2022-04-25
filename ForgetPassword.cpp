#include "ForgetPassword.h"
#include<iostream>
#include<fstream>
#include "encrypted.h"
#include "User_module.h"

void ForgetPassword::forget(){
    

        std::ifstream database_file;
        database_file.open("databaseRecord.txt",std::ios::in);
        //string word;

        std::ofstream new_database_file;
        new_database_file.open("newDatabaseRecord.txt",std::ios::out);

        std::string pins;
        int times;
        std::cout<<"Enter the pin "<<std::endl;
        std::cin>>pins;
        std::cout<<"Enter the last time "<<std::endl;
        std::cin>>times;



        while(database_file >> user_id >> password >> pin >> imei_no >> location >> mobile_no >> time){
            if(encrypt(pins)==pin && times==time){
                std::string new_password;
                std::cout<<"Enter the new password"<<std::endl;
                std::cin>>new_password;
                password=encrypt(new_password);
                new_database_file<< user_id <<" "<< password <<" "<< pin <<" "<< imei_no <<" "<< location <<" "<< mobile_no <<" "<< time <<std::endl;
                while(database_file >> user_id >> password >> pin >> imei_no >> location >> mobile_no >> time){
                    new_database_file<< user_id <<" "<< password <<" "<< pin <<" "<< imei_no <<" "<< location <<" "<< mobile_no <<" "<< time <<std::endl;
                }

                std::cout<<"Reset password successfully"<<std::endl;

            }
        }

    
}
