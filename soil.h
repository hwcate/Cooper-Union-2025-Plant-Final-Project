#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <assert.h>
#include <avr/io.h>
#include <stdlib.h>
#include <stdbool.h>

void soil_state_HIGH();
void soil_state_APPROACHING();
void soil_state_LOW();
int analogRead(uint8_t pin);
void analogReference(uint8_t mode);
DDRB = DDRB | (0<<9); 