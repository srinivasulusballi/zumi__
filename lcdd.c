#include <reg51.h>

// LCD control pins
sbit RS = P2^0;
sbit RW = P2^1;
sbit EN = P2^2;

// LCD data port
#define LCD P1

// Delay function
void delay(unsigned int t)
{
    unsigned int i, j;
    for(i = 0; i < t; i++)
        for(j = 0; j < 1275; j++);
}

// Command function
void lcd_cmd(unsigned char cmd)
{
    LCD = cmd;
    RS = 0;   // Command mode
    RW = 0;   // Write mode
    EN = 1;
    delay(2);
    EN = 0;
}

// Data function
void lcd_data(unsigned char data)
{
    LCD = data;
    RS = 1;   // Data mode
    RW = 0;
    EN = 1;
    delay(2);
    EN = 0;
}

// LCD initialization
void lcd_init()
{
    lcd_cmd(0x38); // 8-bit, 2 line
    lcd_cmd(0x0C); // Display ON, cursor OFF
    lcd_cmd(0x06); // Entry mode
    lcd_cmd(0x01); // Clear display
}

// Print string
void lcd_string(char *str)
{
    while(*str)
    {
        lcd_data(*str++);
    }
}

// Main function
void main()
{
    lcd_init();
    lcd_string("Hello World");

    while(1);
}
