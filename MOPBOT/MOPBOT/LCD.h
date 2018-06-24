/*
 * LCD.h
 *
 * Created: 5/5/2018 8:45:50 PM
 * Authors: Mohan Prabhakar and Kenneth Joel
 */ 

void lcd_port_config (void);
void lcd_set_4bit(void);
void lcd_init(void);
void lcd_wr_command(unsigned char cmd);
void lcd_wr_char(char letter);
void lcd_home(void);
void lcd_string(char *str);
void lcd_cursor (char row, char column);
void lcd_print (char row, char coloumn, unsigned int value, int digits);