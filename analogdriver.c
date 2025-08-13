#include "analogdriver.h"
#include <avr/io.h>

void adc_init(){
    ADMUX |= (1 << REFS0); 
    ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); 
}

uint32_t adc_reading(uint8_t pin){
    ADMUX = (ADMUX & 0xF0) | (pin & 0x0F);
    ADCSRA |= (1 << ADSC); 
    while (ADCSRA & (1 << ADSC));

    return ADC;
}