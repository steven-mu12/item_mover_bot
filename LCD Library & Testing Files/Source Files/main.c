// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown Out Reset Selection bits (BOR enabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)



// ------------------------------
// ------ THE MAIN PROGRAM ------
// ------------------------------

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _XTAL_FREQ 4000000

#include "LiquidCrystal.h"


int number = 523;
char sensorData[6];

// -------------
// MAIN FUNCTION
// -------------

void main(void) {
    
    sprintf(sensorData, "%d", number);
    sensorData[4] = "\0";
        
    while (1){
        lcd_init();
        
        lcd_clear();
        lcd_set_cursor(0,1);
        lcd_write_text("Welcome To  ");  
        lcd_set_cursor(0, 2);
        lcd_write_text("Item Mover Bot  ");
        
        __delay_ms(5000);
        
        lcd_clear();
        lcd_set_cursor(0,1);
        lcd_write_text("Left Sensor: ");  
        lcd_set_cursor(0, 2);
        lcd_write_text(sensorData);
        __delay_ms(5000);
        
        
    }
    
    
    return;
    
}
