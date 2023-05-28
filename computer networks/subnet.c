#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void identify_ip_class_subnet(char *ip_address)
{

    char *octet;
    int octets[4], i = 0;
    octet = strtok(ip_address, ".");
    while (octet != NULL)
    {
        octets[i++] = atoi(octet);
        octet = strtok(NULL, ".");
    }

    char ip_class;
    char subnet_address[16];
    if (octets[0] >= 1 && octets[0] <= 127)
    {
        ip_class = 'A';
        sprintf(subnet_address, "%d.%d.%d.%d", octets[0], 0, 0, 0);
    }
    else if (octets[0] >= 128 && octets[0] <= 191)
    {
        ip_class = 'B';
        sprintf(subnet_address, "%d.%d.%d.%d", octets[0], octets[1], 0, 0);
    }
    else if (octets[0] >= 192 && octets[0] <= 223)
    {
        ip_class = 'C';
        sprintf(subnet_address, "%d.%d.%d.%d", octets[0], octets[1], octets[2], 0);
    }

    printf("IP Class: %c\n", ip_class);
    printf("Subnet Address: %s\n", subnet_address);
}

int main()
{
    char ip_address[] = "195.2.5.1";
    identify_ip_class_subnet(ip_address);
    return 0;
}