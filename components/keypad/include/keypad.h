#ifndef KEYPAD_H
#define KEYPAD_H

void keypad_init(void);
char keypad_scan(void);
char keypad_key(void);
void input_password(char *password);

#endif