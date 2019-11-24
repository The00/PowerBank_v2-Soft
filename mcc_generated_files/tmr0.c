/**
  TMR0 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    tmr0.c

  @Summary
    This is the generated driver implementation file for the TMR0 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides APIs for TMR0.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC16F1459
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.05 and above
        MPLAB 	          :  MPLAB X 5.20
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

/**
  Section: Included Files
*/

#include <xc.h>
#include "tmr0.h"
#include "main.h"
/**
  Section: Global Variables Definitions
*/

volatile uint8_t  update_status_flag=0;

volatile uint8_t timer0ReloadVal;
void (*TMR0_InterruptHandler)(void);
/**
  Section: TMR0 APIs
*/

void TMR0_Initialize(void)
{
    // Set TMR0 to the options selected in the User Interface
	
    // PSA assigned; PS 1:64; TMRSE Increment_hi_lo; mask the nWPUEN and INTEDG bits
    OPTION_REG = (uint8_t)((OPTION_REG & 0xC0) | (0xD5 & 0x3F)); 
	
    // TMR0 61; 
    TMR0 = 0x3D;
	
    // Load the TMR value to reload variable
    timer0ReloadVal= 61;

    // Clear Interrupt flag before enabling the interrupt
    INTCONbits.TMR0IF = 0;

    // Enabling TMR0 interrupt
    INTCONbits.TMR0IE = 1;

    // Set Default Interrupt Handler
    TMR0_SetInterruptHandler(TMR0_DefaultInterruptHandler);
}

uint8_t TMR0_ReadTimer(void)
{
    uint8_t readVal;

    readVal = TMR0;

    return readVal;
}

void TMR0_WriteTimer(uint8_t timerVal)
{
    // Write to the Timer0 register
    TMR0 = timerVal;
}

void TMR0_Reload(void)
{
    // Write to the Timer0 register
    TMR0 = timer0ReloadVal;
}

void TMR0_ISR(void)
{
    static volatile uint16_t CountCallBack = 0;
    static uint8_t led_blink =0; // indicate if the LED should blink
    uint16_t val;
    // Clear the TMR0 interrupt flag
    INTCONbits.TMR0IF = 0;

    TMR0 = timer0ReloadVal;

   // if(update_status_flag) // if a input pin changed state
    
        // pin read is here to avoid reading during bouncing
        pin_status = 0; //reset status
        pin_status += BOOST_EN_GetValue(); // write new value 
        pin_status += (OTG_EN_GetValue()<<1); // write new value   
        update_status_flag =0;
    
    
    val = GetBattValue();
    if(val <= LOW_BATT_THRESHOLD)  led_blink =1;
    else 
    {
        led_blink =0;
        if(pin_status !=0) LED_SetLow(); //turn on LED
    }
    
    
    // callback function - called every 35th pass
    if (++CountCallBack >= TMR0_INTERRUPT_TICKER_FACTOR)
    {
        if(pin_status !=0)
        {
            if(led_blink) LED_Toggle();
            
        }
        
        // ticker function call
       // TMR0_CallBack();

        // reset ticker counter
        CountCallBack = 0;
    }

    // add your TMR0 interrupt custom code
}

void TMR0_CallBack(void)
{
    // Add your custom callback code here

    if(TMR0_InterruptHandler)
    {
        TMR0_InterruptHandler();
    }
}

void TMR0_SetInterruptHandler(void (* InterruptHandler)(void)){
    TMR0_InterruptHandler = InterruptHandler;
}

void TMR0_DefaultInterruptHandler(void){
    LED_Toggle();
}

/**
  End of File
*/
