#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#define USER_SIZE 25
#define USER_PASS_SIZE 25
#define EMAIL_ID_SIZE 30
#define EMAIL_DOMAIN_SIZE 20
#define DEFAULT 0

const char* PERSON_DETAILS_OUT = "%s,%s,%d,%c,%d,%s,%s,%d,%d,%d,%ld\n";

typedef unsigned long size_t;

typedef struct User{
	char name[USER_SIZE];
	char password[USER_PASS_SIZE];
	int userID;
	char sex;
	int accessLevel;
	char emailID[EMAIL_ID_SIZE];
	char emailDomain[EMAIL_DOMAIN_SIZE];
	int dobDate;
	int dobMonth;
	int dobYear;
	long int mobileNo;
} User;

User user[DEFAULT];

void userdefault(int id,User* buffer,int bulk)
{
    if(buffer==0)
    {
    User anon ={
        .name = "anon",
        .password = "0x70617373776F7264313233",
        .userID = id,
        .sex = 'M',
        .accessLevel = 001,
        .emailID = "anonperson",
        .emailDomain = "anonmail.com",
        .dobDate = 1,
        .dobMonth = 2,
        .dobYear = 2022,
        .mobileNo = 9876543210
        };
    }
    else
    {
        
    }
}

int FileLoader(int action,int id,void* buffer,size_t bufferSize)
{
    FILE* file;

    if(action==0)
    {
        fopen_s(&file,"userData.csv", "w+");
        if(file == 0)
            return -1;
    }
    
    if(action==1)
    {
        if(fprintf_s(file,PERSON_DETAILS_OUT,user[id].name, user[id].password, user[id].userID, user[id].sex, user[id].accessLevel, user[id].emailID, user[id].emailDomain, user[id].dobDate, user[id].dobMonth, user[id].dobYear, user[id].mobileNo))
            return 0;
    }
    return 0;
}

int BufferLoader()
{
    return 0;
}

long int LoginChecker(char* user,size_t uSize,char* pass, size_t pSize)
{
    return 0L;
}
