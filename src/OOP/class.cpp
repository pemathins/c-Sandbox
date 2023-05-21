#include <iostream>
#include <cstdio>
#include <cstring>

typedef struct Person
{
    const char* course[15];
    const char* name[35];
    int Course_year;
    int Course_semester;
    private:
    int age;
    float hight;
    float weight;
    public:
    Person(const char p_name[35],const char p_course[15],const int& p_Course_year,const int& p_semester)
    :Course_year(p_Course_year), Course_semester(p_semester)
    {
        strcpy((char*)(*name),p_name);
        strcpy((char*)(*course),p_course);
    }

    void getter()
    {
        std::cout << "Name : " << name << "\n";
        std::cout << "Course : " << course << "\n";
        std::cout << "Course_year : " << Course_year << "\n";
        std::cout << "Course_semester : " << Course_semester << "\n";
        
    }
    
}Person;

int main()
{
    
    Person pema("Pema Thinley Lepcha","MCA",2,2);
    pema.getter();
    scanf("%s",pema.course);
    pema.getter();
    return 0;
}