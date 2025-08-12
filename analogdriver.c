#include "analogdriver.h"
void adc_init(){
    DDRB = DDRB|(0<<PORTB);
    ADMUX |= (1<<REFS1); 
    ADCSRA |= (1<<ADEN)|
            (0<<ADPS2) | (1<<ADPS1) | (1<<ADPS0); 

}

uint32_t adc_reading(uint8_t pin){
    /*
    #if defined(analogPinToChannel)
#if defined(__AVR_ATmega328P__)

	pin = analogPinToChannel(uint8_t pin);

	if (pin >= 14) pin -= 14; // allow for channel or pin numbers
#endif
#endif

    */
    DDRB = DDRB|(0<<PORTB);
    ADMUX |= (1<<ADLAR);
    ADMUX |= (ADMUX & 0xF0); 
    ADCSRA |= (1<<ADSC); 

    if (ADCSRA && (1<<ADSC) == true){
        return 1;
    }

    return ADC;
}
