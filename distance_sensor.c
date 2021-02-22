/*
 * File:   PulseIn.c
 * Author: eoman
 *
 * Created on February 7, 2021, 4:44 PM
 */


#include <xc.h>
#include <time.h>
#include "mcc_generated_files/mcc.h"

uint32_t pulseIn(volatile uint32_t *port, uint16_t pin,uint8_t state, uint32_t timeout);

float getDistance (){
    long duration; // variable for the duration of sound wave travel
    
  // Clears the trigPin condition
    IO_RC5_SetLow();
    __delay_ms(2);
    
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
    IO_RC5_SetHigh();
    __delay_ms(10);
    IO_RC5_SetLow();
    
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(IO_RC4_GetValue(), 4, 1, 5);
  // Calculating the distance
  return (duration * 0.034 / 2); // Speed of sound wave divided by 2 (go and back)
  
}

uint32_t pulseIn(volatile uint32_t *port, uint16_t pin,uint8_t state, uint32_t timeout)
{
    unsigned long   width;
    unsigned long   numloops;
    unsigned long   maxloops;
    uint16_t stateMask;
    time_t t;
    stateMask	=	(state ? pin : 0);
    width		=	0;
    numloops	=	0;
    maxloops	=	(timeout/7)*8 + 10;

    // wait for any previous pulse to end
    while ((*port & pin) == stateMask)
    {
            if (numloops++ == maxloops)
                    return(0);
    }
    // wait for the pulse to start
    while ((*port & pin) != stateMask)
    {
            if (numloops++ == maxloops)
                    return(0);
    }
    width	=	time(&t);
    // wait for the pulse to stop
    while ((*port & pin) == stateMask)
    {
            if (numloops++ == maxloops)
                    return(0);
    }
    width	=	time(&t)-width;
    return (width+4);
}