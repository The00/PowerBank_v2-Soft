/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC16F1459
        Driver Version    :  2.11
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set BOOST_EN aliases
#define BOOST_EN_TRIS                 TRISAbits.TRISA4
#define BOOST_EN_LAT                  LATAbits.LATA4
#define BOOST_EN_PORT                 PORTAbits.RA4
#define BOOST_EN_WPU                  WPUAbits.WPUA4
#define BOOST_EN_ANS                  ANSELAbits.ANSA4
#define BOOST_EN_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define BOOST_EN_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define BOOST_EN_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define BOOST_EN_GetValue()           PORTAbits.RA4
#define BOOST_EN_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define BOOST_EN_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define BOOST_EN_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define BOOST_EN_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define BOOST_EN_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define BOOST_EN_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set OTG_EN aliases
#define OTG_EN_TRIS                 TRISBbits.TRISB6
#define OTG_EN_LAT                  LATBbits.LATB6
#define OTG_EN_PORT                 PORTBbits.RB6
#define OTG_EN_WPU                  WPUBbits.WPUB6
#define OTG_EN_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define OTG_EN_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define OTG_EN_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define OTG_EN_GetValue()           PORTBbits.RB6
#define OTG_EN_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define OTG_EN_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define OTG_EN_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define OTG_EN_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)

// get/set LED aliases
#define LED_TRIS                 TRISBbits.TRISB7
#define LED_LAT                  LATBbits.LATB7
#define LED_PORT                 PORTBbits.RB7
#define LED_WPU                  WPUBbits.WPUB7
#define LED_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define LED_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define LED_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define LED_GetValue()           PORTBbits.RB7
#define LED_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define LED_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define LED_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)

// get/set BATT_IN aliases
#define BATT_IN_TRIS                 TRISCbits.TRISC7
#define BATT_IN_LAT                  LATCbits.LATC7
#define BATT_IN_PORT                 PORTCbits.RC7
#define BATT_IN_ANS                  ANSELCbits.ANSC7
#define BATT_IN_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define BATT_IN_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define BATT_IN_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define BATT_IN_GetValue()           PORTCbits.RC7
#define BATT_IN_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define BATT_IN_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define BATT_IN_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define BATT_IN_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF4 pin functionality
 * @Example
    IOCAF4_ISR();
 */
void IOCAF4_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF4 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF4 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF4_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF4_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF4 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF4_SetInterruptHandler() method.
    This handler is called every time the IOCAF4 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF4_SetInterruptHandler(IOCAF4_InterruptHandler);

*/
extern void (*IOCAF4_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF4 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF4_SetInterruptHandler() method.
    This handler is called every time the IOCAF4 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF4_SetInterruptHandler(IOCAF4_DefaultInterruptHandler);

*/
void IOCAF4_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF6 pin functionality
 * @Example
    IOCBF6_ISR();
 */
void IOCBF6_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF6 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF6 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF6_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF6_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF6 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF6_SetInterruptHandler() method.
    This handler is called every time the IOCBF6 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF6_SetInterruptHandler(IOCBF6_InterruptHandler);

*/
extern void (*IOCBF6_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF6 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF6_SetInterruptHandler() method.
    This handler is called every time the IOCBF6 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF6_SetInterruptHandler(IOCBF6_DefaultInterruptHandler);

*/
void IOCBF6_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/