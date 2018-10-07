////////////////////////////////////
//Jake Bezold and Paul Brodhead 2018
////////////////////////////////////

#include "project.h"

int main(void)
{
    CyGlobalIntEnable; 

    for(;;)
    {
       LED2_Write( SW_Read() );     //LED2 turns off when switch is pushed
       LED_Write( ! LED_Read() );   //LED flips on and off regardless of switch
       CyDelay( 500 );              //force LED to oscillate at 1Hz
    }
}

