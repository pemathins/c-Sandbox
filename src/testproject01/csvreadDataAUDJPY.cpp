#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>


typedef struct Candle
{
    char data[11];
    char time[5];
    float open;
    float high;
    float low;
    float close;
    int volume;

    Candle()
    {
    }
    // User(int id,char first_name[],char last_name[],char email[],char gender[],char dob[])
    // :Id(id), First_name(first_name), Last_name(last_name), Email(email), Gender(gender), Dob(dob)
    // {
    // }

} Candle;

int FileLoader(const char *, std::vector<Candle>&);

int main(int args, char *argv[])
{
    std::vector<Candle> dataVector;
    std::cout << "argv[1] : " << argv[1];
    FileLoader(argv[1], dataVector);
    for(auto x: dataVector)
        std::cout <<"open : "<< x.open << " volume : " << x.volume << "\n";
    
}

int FileLoader(const char* path, std::vector<Candle>& data)
{
    std::cout << path;
    FILE *file = fopen(path, "r");
    if (file == 0)
    {
        std::cerr << "no Data!!\n";
        return 1;
    }
    Candle minute;

    while (!feof(file))
    {
        Candle one;

        fscanf(file, "%[^,],%[^,],%f,%f,%f,%f,%d", one.data,one.time,&one.open,&one.high,&one.low,&one.close,&one.volume);
        
        data.push_back(one);
    }
    std::printf("Line no : %d\n", ftell(file));

    return 0;
}