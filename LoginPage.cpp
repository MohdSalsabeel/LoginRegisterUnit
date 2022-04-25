#include "LoginPage.h"
#include<iostream>
#include<fstream>
#include "encrypted.h"
//using namespace std;


std::string LoginPage::login(){

        std::ifstream database_file;
        database_file.open("databaseRecord.txt",std::ios::in);
        std::string word;

        std::ofstream new_database_file;
        new_database_file.open("newDatabaseRecord.txt",std::ios::out);

        std::string login_user_id;
        std::string login_password;
        int current_time;
        
        std::cout<<"Enter login user id: "<<std::endl;
        std::cin>>login_user_id;
        std::cout<<"Enter login password: "<<std::endl;
        std::cin>>login_password;
        std::cout<<"Enter the current time: "<<std::endl;
        std::cin>>current_time;

        while(database_file >> user_id >> password >> pin >> imei_no >> location >> mobile_no >> time){

            if(login_user_id==user_id && encrypt(login_password)==password){
                //cout<<"Successfully "<<endl;
                time=current_time;
                new_database_file<< user_id <<" "<< password <<" "<< pin <<" "<< imei_no <<" "<< location <<" "<< mobile_no <<" "<< time <<std::endl;
                while(database_file >> user_id >> password >> pin >> imei_no >> location >> mobile_no >> time){
                    new_database_file<< user_id <<" "<< password <<" "<< pin <<" "<< imei_no <<" "<< location <<" "<< mobile_no <<" "<< time <<std::endl;
                }
                return "Successful";
            }


        }
        return "False";

};
