#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <string>
int main(int argc, char** argv) {
    int countSubProcess = 2;
    int countProcess = argc>1?atoi(argv[1]):15;
    int subprocessNumber = 0;
    char b[15] = "file00000";
    srand(time(0));
    start:
    while(countSubProcess-- && countProcess > 0)
    {
        ++subprocessNumber;
	--countProcess;
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
    fprintf(f,"This file has been created by subprocess with number: %d\n",subprocessNumber);
    fclose(f);
    return 0;
}
