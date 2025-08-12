#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <assert.h>
#include <avr/io.h>
#include <stdlib.h>
#include <stdbool.h>



#include "relay.h"
#include "soil.h"

int main(){
    relay_init();
    reading_value();
    
}
