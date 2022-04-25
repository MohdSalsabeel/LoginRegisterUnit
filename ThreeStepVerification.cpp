#include "ThirdStepVerification.h"
#include<fstream>
#include<iostream>
#include "encrypted.h"
#include "User_module.h"

void ThirdStepVerification::correct_third_step(){

    std::ifstream database_file;
        database_file.open("databaseRecord.txt",std::ios::in);

        std::ofstream new_database_file;
        new_database_file.open("newDatabaseRecord.txt",std::ios::out);


        std::cout<<"Enter imei number for verification: "<<std::endl;
        std::cin>>verfiy_imei_number;

        std::cout<<"Enter current location: "<<std::endl;
        std::cin>>verify_current_location;

        std::cout<<"Enter previous location where you have login last time"<<std::endl;
        std::cin>>verify_previous_location;

        std::cout<<"Enter mobile number: "<<std::endl;
        std::cin>>verify_mobile_no;


        while(database_file >> user_id >> password >> pin >> imei_no >> location >> mobile_no >> time){
            if(encrypt(verfiy_imei_number)==imei_no && verify_previous_location==location && verify_mobile_no==mobile_no){
                //cout<<"Successfully"<<endl;

                location=verify_current_location;
                new_database_file<< user_id <<" "<< password <<" "<< pin <<" "<< imei_no <<" "<< location <<" "<< mobile_no <<" "<< time <<std::endl;
                while(database_file >> user_id >> password >> pin >> imei_no >> location >> mobile_no >> time){
                    new_database_file<< user_id <<" "<< password <<" "<< pin <<" "<< imei_no <<" "<< location <<" "<< mobile_no <<" "<< time <<std::endl;
                }

                char current_location_character=(char)verify_current_location;
                char previous_location_character=(char)verify_previous_location;
                char mobile_number_character=(char)verify_mobile_no;

                std::string token=verfiy_imei_number+current_location_character+previous_location_character+mobile_number_character;
                std::cout<<"Token is generated "<<std::endl;
                std::cout<<token<<std::endl;
                std::cout<<std::endl;
                std::cout<<"Write same token character: "<<std::endl;
                //cout<<"Enter token input: "<<endl;
                std::string token_character;
                std::cin>>token_character;
                if(token==token_character){
                    std::cout<<"Welcome to Main Page"<<std::endl;
                    break;
                }else{
                    std::cout<<"Wrong token number"<<std::endl;
                    break;
                }
            }
            
        }
}
