#include <stdio.h>
#include <arpa/inet.h>

int main() {
    const char* ip_address = "8.8.8.8";
    struct in_addr addr;

    // Convert the IP address from text to network byte order
    int success = inet_pton(AF_INET, ip_address, &(addr.s_addr));

    if (success > 0) {
        in_addr_t ip = addr.s_addr;
        printf("IPv4 address in network byte order: %u\n", ip);
    } else if (success == 0) {
        printf("Invalid IP address format\n");
    } else {
        perror("Failed to convert IP address");
    }

    return 0;
}