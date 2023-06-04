#include <iostream>
#include <cstdio>
#include <vector>

typedef struct User
{
    int id;
    std::string user_name_first;
    std::string user_name_last;
    std::string user_email;
    std::string user_gender;
    std::string user_dob;

    User(int id, std::string& fname, std::string& lname, std::string& email, std::string& gender, std::string& dob) :user_name_first(fname), user_name_last(lname), user_email(email), user_gender(gender), user_dob(dob)
    {}
    User()
    {}
    
} User;

int main()
{
    
    FILE* data = fopen("testSet.csv", "r");
    if(data ==0)
    {
        std::cerr << "no Data!!\n";
        return 1;
    }
    fscanf(data,"%[^\n]",stdout);
    std::vector<User> user;
    while(feof(data)!=0){
        User temp;
        fscanf(data,"%d,%[^,],%[^,],%[^,],%[^,],%[^\n]",temp.id,temp.user_name_first,temp.user_name_last,temp.user_email,temp.user_gender,temp.user_dob);
        user.push_back(temp);
    }
    fclose(data);
    for(const auto& x : user)
    {
        printf("id : %d, %s, %s, %s, %s, %s\n",x.user_name_first,x.user_name_last,x.user_email,x.user_gender,x.user_dob);
        std::cout << x.user_name_first << std::endl;
    }
    
}