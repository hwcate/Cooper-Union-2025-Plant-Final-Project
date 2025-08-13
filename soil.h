#ifndef SOIL_H
#define SOIL_H

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <assert.h>
#include <avr/io.h>
#include <stdlib.h>
#include <stdbool.h>
#include <util/delay.h>

// #define HIGH 1 
// #define LOW 0

typedef enum{
    LOW, 
    GOOD, 
    HIGH, 
}states_t;


uint32_t humidity;
void soil_state_HIGH();
void soil_state_APPROACHING();
void soil_state_LOW();
states_t reading_value();
void soil_states(states_t state);

#endif