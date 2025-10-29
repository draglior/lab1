#include <xc.h>
#include <p33Fxxxx.h>
//do not change the order of the following 2 definitions
#define FCY 12800000UL 
#include <libpic30.h>

#include "lcd.h"
#include "led.h"

/* Configuration of the Chip */
// Initial Oscillator Source Selection = Primary (XT, HS, EC) Oscillator with PLL
#pragma config FNOSC = PRIPLL
// Primary Oscillator Mode Select = XT Crystal Oscillator mode
#pragma config POSCMD = XT
// Watchdog Timer Enable = Watchdog Timer enabled/disabled by user software
// (LPRC can be disabled by clearing the SWDTEN bit in the RCON register)
#pragma config FWDTEN = OFF

#define LED1
#define LED2
#define LED3
#define LED4
#define LED5

int main(){
    //Init variables
    int my_counter = 0;

    //Init LCD and LEDs
    lcd_initialize();
    led_init();

    // Clear the Screen and reset the cursor
    lcd_clear();
    lcd_locate(0, 0);
    
    // Print Group Members 
    lcd_printf("Group Members:");
    lcd_locate(0, 1);
    lcd_printf("* Lior Boulgakov");
    lcd_locate(0, 2);  
    lcd_printf("* Marc Flamen");
    lcd_locate(0, 3);    
    lcd_printf("* Ahmed Abdelghany");
    
    CLEARBIT(LED1_TRIS);
    CLEARBIT(LED2_TRIS);
    CLEARBIT(LED3_TRIS);
    CLEARBIT(LED4_TRIS);
    CLEARBIT(LED5_TRIS);
    
    while(1){
        lcd_locate(0, 5);
        lcd_printf("%d",my_counter);
        
        if (my_counter & 0x01) //AND Bit0 (If my_counter AND 0000 0001)
            SETBIT(LED5_PORT);
        else
            CLEARLED(LED5_PORT);
        
        if (my_counter & 0x02) //AND Bit1 (If my_counter AND 0000 0010)
            SETLED(LED4_PORT);
        else
            CLEARLED(LED4_PORT);
        
        if (my_counter & 0x04) //AND Bit2 (If my_counter AND 0000 0100)
            SETLED(LED3_PORT);
        else
            CLEARLED(LED3_PORT);
        
        if (my_counter & 0x08) //AND Bit3 (If my_counter AND 0000 1000)
            SETLED(LED2_PORT);
        else
            CLEARLED(LED2_PORT);
        
        if (my_counter & 0x10) //AND Bit4 (If my_counter AND 0001 0000)
            SETLED(LED1_PORT);
        else
            CLEARLED(LED1_PORT);

        my_counter++;
        __delay_ms(1000);
    }
}



