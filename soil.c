#include "soil.h"
#include "analogdriver.h"
#include "relay.h"

states_t reading_value(){
    humidity = adc_reading(0);
    if (humidity <300){
        printf("WET");
        _delay_ms(100);
        return HIGH;

    }
    else if (humidity <450){
        printf("GOOD");
        _delay_ms(100);
        return GOOD;
    }
    else {
        printf("DRY");
        _delay_ms(100);
        return LOW;
    }
}



void soil_state_LOW(){
    DDRD = DDRD|(1<<PORTD);
    PORTD|= (1<<4);
    PORTD &= ~(1<<3);
    PORTD &= ~(1<<2);
}
void soil_state_GOOD(){
    DDRD = DDRD|(1<<PORTD);
    PORTD|= (1<<3);
    PORTD &= ~(1<<4);
    PORTD &= ~(1<<2);
}

void soil_state_HIGH(){
    DDRD = DDRD|(1<<PORTD);
    PORTD|= (1<<2);
    PORTD &= ~(1<<3);
    PORTD &= ~(1<<4);

}

void soil_states(states_t state){
    switch (state) {
        case LOW: 
            soil_state_LOW(); 
            relay_start();
            break;
        case GOOD:
            soil_state_GOOD(); 
            relay_off();
            break;
        case HIGH:
            soil_state_HIGH(); 
            relay_off();
            break;
        default: 
            soil_state_GOOD();
            relay_off();
            break;
    }

}