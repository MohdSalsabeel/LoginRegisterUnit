#include<iostream>
#include<math.h>
#include<string>
#include<stdlib.h>
#include<fstream>
#include<bits/stdc++.h>
//#include "function_files.cpp"
//#include "login_module.cpp"
//#include "forget_module.cpp"
//#include "twostep_module.cpp"
//#include "thirdstep_module.cpp"

#include "LoginPage.h"
#include "ForgetPassword.h"
#include "TwoStepVerification.h"
#include "ThirdStepVerification.h"
#include "encrypted.h"
using std::ios;
using std::cerr;
//#pragma once
using namespace std;




int main(){
//User obj[5];
    User obj;
    loop:
    cout<<"1. Registration"<<endl;
    cout<<"2. Login"<<endl;
    cout<<"3. Forget Password"<<endl;

    int choice;
    cout<<"Enter the choice: "<<endl;
    cin>>choice;


    switch(choice){

        case 1:{

            // User::user_id = "xy97";
            // User::password = encrypt("khan345");
            // User::pin = encrypt("6789");
            // User::imei_no = encrypt("rtyu78");
            // User::location = 23;
            // User::mobile_no = 89341;
            // User::time = 10;
            //User obj[2];
            // obj[0].user_id="xy10";
            // obj[0].password=encrypt("khan345");
            // obj[0].pin=encrypt("6789");
            // obj[0].imei_no=encrypt("rtyu78");
            // obj[0].location=23;
            // obj[0].mobile_no=89341;
            // obj[0].time=10;

            // obj[1].user_id="abc12";
            // obj[1].password=encrypt("khan123");
            // obj[1].pin=encrypt("1234");
            // obj[1].imei_no=encrypt("edf78");
            // obj[1].location=29;
            // obj[1].mobile_no=34513;
            // obj[1].time=12;

            // obj[2].user_id="fgh12";
            // obj[2].password=encrypt("jad456");
            // obj[2].pin=encrypt("8910");
            // obj[2].imei_no=encrypt("klm99");
            // obj[2].location=35;
            // obj[2].mobile_no=10000;
            // obj[2].time=54;

            // obj[3].user_id="pqrs1";
            // obj[3].password=encrypt("khan345");
            // obj[3].pin=encrypt("0988");
            // obj[3].imei_no=encrypt("yuzx89");
            // obj[3].location=89;
            // obj[3].mobile_no=45678;
            // obj[3].time=67;

            // obj[4].user_id="klmn89";
            // obj[4].password=encrypt("sal456");
            // obj[4].pin=encrypt("5613");
            // obj[4].imei_no=encrypt("7845");
            // obj[4].location=90;
            // obj[4].mobile_no=87654;
            // obj[4].time=95;

            //LoginPage login_page_obj;

            ofstream database_file;
            database_file.open("databaseRecord.txt",ios::out | ios::app);

            cout<<"Enter the user id: "<<endl;
            cin>>obj.user_id;
            database_file<<obj.user_id<<" ";

            cout<<"Enter the password: "<<endl;
            cin>>obj.password;
            database_file<<encrypt(obj.password)<<" ";

            cout<<"Enter the pin: "<<endl;
            cin>>obj.pin;
            database_file<<encrypt(obj.pin)<<" ";

            cout<<"Enter the imei no: "<<endl;
            cin>>obj.imei_no;
            database_file<<encrypt(obj.imei_no)<<" ";

            cout<<"Enter the location: "<<endl;
            cin>>obj.location;
            database_file<<obj.location<<" ";

            cout<<"Enter the mobile no: "<<endl;
            cin>>obj.mobile_no;
            database_file<<obj.mobile_no<<" ";

            cout<<"Enter the time: "<<endl;
            cin>>obj.time;
            database_file<<obj.time<<endl;

            database_file.close();

            goto loop;
        }
        case 2:{
            User obj[5];



            LoginPage login_page_obj;
            

            if(login_page_obj.login()=="Successful"){
                cout<<endl;
                cout<<"Go to Second Step Verification"<<endl;
                TwoStepVerification pin_obj;
                //pin_obj.correct_pin(obj);

                if(pin_obj.correct_pin()=="Successful"){
                    cout<<endl;
                    cout<<"Go to Third Step Verification"<<endl;
                    ThirdStepVerification third_step_verification_obj;
                    third_step_verification_obj.correct_third_step();
                }else{
                    cout<<"Wrong pin number"<<endl;

                }
            }
            else{
                cout<<"You have written wrong input"<<endl;
            }

            break;
        }

        case 3:{
            //User obj[5];


            //ForgetPassword forget_password_obj;
            //forget_password_obj.forget();
            //cout<<obj[0].pin<<endl;
            break;
        }

        default:
            cout<<"Enter the correct choice"<<endl;

    }


    cout<<endl;
    
    return 0;
}

