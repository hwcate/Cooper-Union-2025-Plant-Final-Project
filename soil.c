#include "soil.h"
#include "analogdriver.h"



void reading_value(){
    humidity = adc_reading(9);
    if (humidity <300){
        //state = HIGH;
        printf("WET");
        _delay_ms(100);
    }
    else if (humidity <600){
        //state = GOOD;
        printf("GOOD");
        _delay_ms(100);
    }
    else {
        //state = BAD;
        printf("DRY");
        _delay_ms(100);
    }
}


// void soil_state_LOW(){
    
// }
// void soil_state_GOOD(){

// }

// void soil_state_HIGH(){

// }

typedef enum{
    LOW, 
    GOOD, 
    HIGH, 
}states_t; 

// void soil_states(static uint8_t state){
//     switch (state){
//         case LOW: 
//         {
//             state = soil_state_LOW(); 
//             break;
//         }
//         case GOOD:
//         {
//             state = soil_state_GOOD(); 
//         }
//         case HIGH:
//         {
//             state = soil_state_HIGH(); 
//         }
//         default: 
//         {
//             state = soil_state_GOOD();
//         }
//     }
// }