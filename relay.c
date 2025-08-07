#include "relay.h"
void relay_init() {
    DDRB = DDRB|(1<<PORTB);
}
void relay_start(){
    PORTB|= (1<<8);
}
void relay_off(){
    PORTB &= ~(1<<8);
}
