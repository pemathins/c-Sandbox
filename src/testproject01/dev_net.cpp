#include <iostream>
#include <algorithm>
#include <cstdint>

struct Data_Packet
{
    size_t x;
    int8_t head;
    int8_t destination_ipaddress;
    int8_t source_ipaddres;
    int32_t data;
    int8_t tail;

};

int main()
{
    Data_Packet packet{4, 23,23,23,2304,32};
    
}