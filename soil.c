#include "soil.h"




void reading_value(){
    humidity = analogRead(8);
    if (humidity <300){
        state = HIGH;
        Serial.println("WET");
    }
    else if (humidity <600){
        state = GOOD;
        Serial.println("GOOD");
    }
    else {
        state = BAD;
        Serial.println("DRY");
    }
}


void soil_state_LOW(){
    
}
void soil_state_GOOD(){

}

void soil_state_HIGH(){

}

typedef enum{
    LOW, 
    GOOD, 
    HIGH, 
}states_t; 
void soil_states(static uint8_t state){
    switch (state){
        case LOW: 
        {
            state = soil_state_LOW(); 
            break;
        }
        case GOOD:
        {
            state = soil_state_GOOD(); 
        }
        case HIGH:
        {
            state = soil_state_HIGH(); 
        }
        default: 
        {
            state = soil_state_GOOD();
        }
    }
}