////////////////////////////////////
//Jake Bezold and Paul Brodhead 2018
////////////////////////////////////

#include "project.h"
#include <stdio.h>

int main(void)
{
    int sw1_counter = 0;
    int sw2_counter = 0;
    char hex_value[16];
    
    CyGlobalIntEnable;
    LCD_Start();                            //initializes LCD display
    LCD_Position(0, 0);                     //sets the cursor position to be row 0 column 0
    LCD_PrintString("Hello, Jake and ");    //prints the string at given position
    LCD_Position(1, 0);                     //sets cursor position to be row 2 column 0
    LCD_PrintString("Paul Welcome you");
    LED1_Write(1);
    LED2_Write(1);
    CyDelay(5000);                          //waits 5 seconds
    LCD_Position(0, 0);
    LCD_PrintString("Press a button  ");
    LCD_Position(1, 0);
    LCD_PrintString("to have some fun");
    
    for(;;)
    {

        Pin_1_Write(!sw1_Read());
        
        while(sw1_Read() && sw2_Read());    //while both switches aren't pressed, wait
        
        if (!sw1_Read())                    //if switch1 is pressed
        {
            sw1_counter++;                  //increment the counter for sw1 
            LED1_Write(!LED1_Read());       //change state of LED1
            LCD_Position(0,0);              //print button 1 count and sw1 counter to LCD
            LCD_PrintString("Button 1 count");
            LCD_Position(1,0);
            sprintf(hex_value, "In Hex: %08X)", sw1_counter);
            LCD_PrintString(hex_value);
            CyDelay(100);                   //delay 100ms for debounce delay
        }
        
        if (!sw2_Read())                    //repeat for sw2
        {
            sw2_counter++;
            LED2_Write(!LED2_Read());
            LCD_Position(0,0);
            LCD_PrintString("Button 2 count");
            LCD_Position(1,0);
            sprintf(hex_value, "In Hex: %08X)", sw2_counter);
            LCD_PrintString(hex_value);
            CyDelay(100);
        }
        
        while(!sw1_Read() || !sw2_Read());  //when either switch is pressed
        CyDelay(100);                       //wait 100ms for debounce
    }
}
