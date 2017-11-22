#include <iostream>
#include <unistd.h>
int main() {
    int countSubProcess = 2;
    int subprocessNumber = 0;
    char b[15] = "file00000";
    srand(time(0));
    start:
    while(countSubProcess--)
    {
        ++subprocessNumber;
        switch(fork())
        {
            case 0: // subprocess code
                countSubProcess = 2;
                goto start;
            case -1:
                perror("Fork error");
            default:
                for (int i = 4; i < 9; ++i) {
                    b[i] = 'A' + rand()%26;
                }
        }
    }
    FILE* f = fopen(b,"w");
    fprintf(f,"This file has been created by subprocess with number: %c",subprocessNumber);
    fclose(f);
    return 0;
}