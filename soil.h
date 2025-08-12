#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <assert.h>
#include <avr/io.h>
#include <stdlib.h>
#include <stdbool.h>
uint32_t humidity;
void soil_state_HIGH();
void soil_state_APPROACHING();
void soil_state_LOW();
void reading_value();
int analogRead(uint8_t pin);
void analogReference(uint8_t mode);
