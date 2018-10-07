////////////////////////////////////
//Jake Bezold and Paul Brodhead 2018
////////////////////////////////////

#include "project.h"

int main(void)
{
    CyGlobalIntEnable;

    for(;;)
    {
       LED_Write( 0 );
       LED_Write( 1 );
    }
}
