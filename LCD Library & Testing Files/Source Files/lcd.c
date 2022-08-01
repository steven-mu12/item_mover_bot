#include <xc.h>

#define _XTAL_FREQ 4000000

#define DATA_PORT PORTD
#define DATA_DIR TRISD

#define RS RC4
#define RS_DIR TRISC

#define EN RC5
#define EN_DIR TRISC

#define DATA_DEL 5
#define RESET_DEL 100





// ----------
// FUNCTIONS
// ----------

// function that sends command to LCD
void lcd_write_cmd(char cmd){
    DATA_PORT = cmd;
    RS = 0;
    EN = 1;
    asm("nop");
    EN = 0;
    __delay_ms(DATA_DEL); // 5ms, may need to change
}

// function that sends data to LCD
void lcd_write_data(char data){
    DATA_PORT = data;
    RS = 1;
    EN = 1;
    asm("nop");
    EN = 0;
    __delay_ms(DATA_DEL); // 5ms, may need to change
}


// function that initializes the LCD
void lcd_init(void){

    __delay_ms(RESET_DEL); //1000ms wait for power supply to be stable
   
    DATA_DIR = 0;
    EN_DIR = 0;
    RS_DIR = 0;
    EN = 0;
    
    lcd_write_cmd(0b00111100); // function set
    lcd_write_cmd(0b00001100); // display on
    lcd_write_cmd(0b00000110); // entry mode

}


// function to write out text
void lcd_write_text(const char* text){

    while (*text != '\0'){
        lcd_write_data(*text);
        ++text;
    }

}


void lcd_set_cursor(char col, char line){
    
    if (line == 1){
        lcd_write_cmd(0b10000000 | col);
    }
    else if (line == 2){
        lcd_write_cmd(0b11000000 | col);
    }

}


void lcd_clear(void){

    lcd_set_cursor(0,1);
    lcd_write_text("                ");  
    lcd_set_cursor(0, 2);
    lcd_write_text("                ");

}