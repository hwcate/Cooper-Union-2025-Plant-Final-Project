#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <assert.h>
#include <avr/io.h>
#include <stdlib.h>
#include <stdbool.h>


#include "analogdriver.h"
#include "relay.h"
#include "soil.h"

int main(){
    states_t state = GOOD;
    relay_init();
    adc_init();
    while(1) {
        state = reading_value();
        soil_states(state);
    }
    
    
}
