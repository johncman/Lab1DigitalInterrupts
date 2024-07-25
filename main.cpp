#include "mbed.h"
#include <cstdio>
// Using MBED OS, the code configures an interupt for the button attached to pin PC_13. 
// The int_trig flag is set to 1 by the bttnFall interrupt response when the button is pressed. 
// The software checks this flag continuously in the main loop. 
// If int_trig is 1, "it outputs bttnFall" and clears the flag, indicating button was pressed. 
// This offers a fundamental system for identifying and reacting to button presses. 

InterruptIn bluebtn(PC_13);

volatile int int_trig = 0;

void bttnFall(){
    int_trig = 1; 
}


// main() runs in its own thread in the OS
int main()
{
    bluebtn.fall(&bttnFall);
    
    // this is my program for the embedded systems module lab 1
    while (true) {
        if(int_trig ==1){
            int_trig = 0;
            printf ("bttnFall \r\n");

        }

    }
}
