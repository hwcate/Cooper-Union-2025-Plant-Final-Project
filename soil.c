#include "soil.h"
void reading_value(uint8_t* humidity, uint8_t x){
    humidity = &intx(pinB&(1<<8)1:0); 
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