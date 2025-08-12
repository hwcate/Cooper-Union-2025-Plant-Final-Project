#include "soil.h"
#include "wiring_private.h"
#include "pins_arduino.h"

uint8_t analog_reference = DEFAULT;

void analogReference(uint8_t mode)
{
	analog_reference = mode;
}

int analogRead(uint8_t pin)
{

#if defined(analogPinToChannel)
#if defined(__AVR_ATmega328P__)
	if (pin >= 14) pin -= 14; // allow for channel or pin numbers
#endif

#if defined(ADCSRB) && defined(MUX5)
	// the MUX5 bit of ADCSRB selects whether we're reading from channels
	// 0 to 7 (MUX5 low) or 8 to 15 (MUX5 high).
	ADCSRB = (ADCSRB & ~(1 << MUX5)) | (((pin >> 3) & 0x01) << MUX5);
#endif
  
	// set the analog reference (high two bits of ADMUX) and select the
	// channel (low 4 bits).  this also sets ADLAR (left-adjust result)
	// to 0 (the default).
#if defined(ADMUX)
#if defined(__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)
	ADMUX = (analog_reference << 4) | (pin & 0x07);
#else
	ADMUX = (analog_reference << 6) | (pin & 0x07);
#endif
#endif

	// without a delay, we seem to read from the wrong channel
	//delay(1);

#if defined(ADCSRA) && defined(ADC)
	// start the conversion
	ADCSRAR |= (1<<ADSC);

	// ADSC is cleared when the conversion finishes
	while (bit_is_set(ADCSRA, ADSC));

	// ADC macro takes care of reading ADC register.
	// avr-gcc implements the proper reading order: ADCL is read first.
	return ADC;
#else
	// we dont have an ADC, return 0
	return 0;
#endif
}





void reading_value(uint8_t* humidity){
    *humidity = analogRead(8)
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