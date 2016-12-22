#include <iostream>
#include <ctime>
using namespace std;

int main() {
    time_t now = time(0);
    struct tm* datetime;
    datetime = localtime(&now);

    printf("%d-%02d-%02d", datetime->tm_year + 1900, datetime->tm_mon+1, datetime->tm_mday);
    return 0;
}