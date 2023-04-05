#include <iostream>
#include <fstream>
#include <string>
#include <vector>

namespace access
{
    static int count=1;
    static int16_t TOKEN=0;
    std::string tokenGenerator()
    {
        std::string token ="AAA"+std::to_string(count);
        return token;
    }
}
typedef struct UserInfo

{
    std::string token;
    std::string first_name;
    std::string middle_name;
    std::string last_name;
    std::string e_mail;
    std::string date_of_Birth;
    UserInfo(std::string& tkn, std::string& fname, std::string& mname, std::string& lname, std::string& email, std::string& dob) 
        :token(tkn), first_name(fname), middle_name(mname), last_name(lname), e_mail(email) ,date_of_Birth(dob)
    {
        access::count++;
        access::TOKEN ++;
    }

};

namespace person 
{
    class Register
    {
        
        public:
        UserInfo person(std::string token)
        {
            std::string fname,mname,lname,email,dob;
            std::cout << "\nEnter your first name : ";

            std::cin >> fname;
            std::cout << "\nEnter your middle name : ";
            std::cin >> mname;
            std::cout << "\nEnter your last name : ";
            std::cin >> lname;
            std::cout << "\nEnter your email : ";
            std::cin >> email;
            std::cout << "\nEnter your date of birth : ";
            std::cin >> dob;
            UserInfo person{token,fname,mname,lname,email,dob};
            return person;
         
        }
    };
}
int main() 
{
    int a,n =0;
    std::string fname, mnanme, lname, password, password2, code, age, user, word1, word2;
    std::cout << "\t\t  System Managment Security\n";
    std::cout << "_______________________________________________\n";
    std::cout << "|            1. Register                      |\n";
    std::cout << "|            2. Login                         |\n";
    std::cout << "|            3. Cnhange Password              |\n";
    std::cout << "|            4. End Program                   |\n";
    std::cout << "|_____________________________________________|\n";



    std::vector<UserInfo> userRegister;
    person::Register info;
    
    do {
        std::cout << "Enter your choice :-";
        std::cin >> a;
        switch(a)
        {
            case 1: 
            {
                std::cout << "_____________________________________________\n";
                std::cout << "|                                            |\n";
                std::cout << "|-----------------register-------------------|\n";
                std::cout << "|____________________________________________|\n";

                std::string token = access::tokenGenerator();
                UserInfo value = info.person(token);
                userRegister.push_back(value); 
                break;
            }
                
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                break;

        }
    }while(a!=4); 
}