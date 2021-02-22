/*
 * File:   main.c
 * Author: ratik
 *
 * Created on January 8, 2021, 5:25 PM
 */

#include "mcc_generated_files/mcc.h"
#include "distance_sensor.h"

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();
    


    while (1)
    {
        __delay_ms(1000);
        printlnFloat(getDistance());
        
    }
}