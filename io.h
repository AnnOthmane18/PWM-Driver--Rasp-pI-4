#ifndef IO_H_
#define IO_H_

//pin numbers Assignment

#define PB0 "17"
#define PB1 "18"   
#define PB2 "22"   
#define PB3 "23"   
#define PC1 "24"   
#define PC2 "25"   
#define PB6 "26" 
#define PB7 "27"       
//for pins values
#define LOW  0
#define HIGH 1
//for pins direction
#define IN   1
#define OUT  0

//struct that define each pin || a pin is defined by 3 things: ID - Direction - Value, each of those are represented by a specific file
struct S_GPIO_LINE {
    char id_number[4];
    int direction;
    int value;
};
typedef struct S_GPIO_LINE S_GPIO_LINE;


int load_gpio_line(S_GPIO_LINE *ps_line, char id_number[4], int i_direction);//export function, make the pin visible in the user layer
int set_gpio_direction(S_GPIO_LINE *ps_line, int i_direction);//setting its direction : Input / Output
int set_gpio_line(S_GPIO_LINE *ps_line, int value); // setting the pin value
int get_gpio_line(S_GPIO_LINE *ps_line); // reading the pin's VALUE

#endif /*IO_H_*/
