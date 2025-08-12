void adc_init(){
    ADMUX |= (1<<REFS1); 
    ADCSRA |= (1<ADEN)
            (0<<ADPS2) | (1<<ADPS1) | (1<<ADPS0); 

}

void adc_reading(){
    ADMUX |= (1<<ADLAR);
    ADMUX |= (ADMUX & 0xF0); 
    ADCSRA |= (1<<ADSC); 

    if (ADCSRA|= (1<<ADSC) = true){
        return 1;
    }
    return ADC;
}
