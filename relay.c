#include "relay.h"
#include <avr/io.h>

void relay_init() {
    DDRB = DDRB|(1<<PB0);
}
void relay_start(){
    PORTB|= (1<<PB0);
}
void relay_off(){
    PORTB &= ~(1<<PB0);
}
