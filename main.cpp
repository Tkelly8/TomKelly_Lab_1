#include "mbed.h"

// main() runs in its own thread in the OS
InterruptIn bttn(PC_13);
char flag0 = 0;

void fall_interrupt(){
    flag0 = 1;
}
void rise_interrupt(){
    flag0 = 2;
}


int main ()
{
    bttn.fall(&fall_interrupt );
    bttn.rise(&rise_interrupt );

    printf("up and running \r\n");
    while (true) {
        switch (flag0){
            case 1:
                printf("Buttn pressed \r\n");
                flag0 = 0;
                break;
            case 2:
                printf("Buttn let go \r\n");
                flag0 = 0;
                break;
        
            default:
                flag0 = 0;
                break;

    }
    ThisThread :: sleep_for(10ms);
}
}















