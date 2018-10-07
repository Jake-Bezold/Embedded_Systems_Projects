////////////////////////////////////
//Jake Bezold and Matt Kilcher 2018
////////////////////////////////////

#include "project.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#define TRUE 1;
#define FALSE 0;
 
#define NVIC_CPUID_BASE_ADDR 0xe000ed00;

void bubbleSort(char *list)
{
    //initializes the variables needed
    int length = 0;
    int swapped = FALSE;
    char tmp;
    char *p1 = list;
    char *p2 = list;
    char *p3;
    
    //gets the length of the given list
    while(*p1 != '\0'){
        length++;
        p1++;
    }
    
    //does the loop until swapped isn't TRUE
    do
    {
        swapped = FALSE;
        p2 = list;                          
        for (int i = 1; i < length; i++)    //increments starting at 1 up to the length
        {
            p3 = p2 + 1;                    //sets p3 to next char in list to keep track of both
            if(*p2 > *p3)                   // if the first char is greater than the second
            {
                 tmp = *p2;                 //saves p2 to temp
                 *p2 = *p3;                 //swaps p2 to p3 and then p3 to temp
                 *p3 = tmp;
                 swapped = TRUE;            //sets swapped to TRUE so it doesnt end the loop yet
            }
            p2++;                           //increments p2 to move onto the next char
        }
    }
    while(swapped);
}

int main(void)
{
    //initializes all the registers and myname
    uint32_t implementer;
    uint32_t variant;
    uint32_t partno;
    uint32_t revision;
    uint32_t reg_val;
    uint32_t volatile *my_reg_ptr;
    
    char myname[] = "Matt Jake";
    char *namePointer = myname;                         //sets a pointer to myname to be passed to bubblesort later
    
    my_reg_ptr = (uint32_t*) NVIC_CPUID_BASE_ADDR;      //sets the value of the base register to reg pointer
    reg_val = *my_reg_ptr;                              //sets the value to reg_val
    
    implementer = (reg_val >> 24) & 0xFF;               //shifts to the implementer value and ands it with 1111 1111 to only keep 1 byte
    variant = (reg_val >> 20) & 0xF;                    //shifts ti variant reg and ands it with 1111
    partno = (reg_val >> 4) & 0xFFF;                    //shifts to partno and ands with 1111 1111 1111
    revision = reg_val & 0xF;                           //shifts to revision and ands with 1111
    
    bubbleSort(namePointer);
    
    for(;;)
    {       
    }
}
