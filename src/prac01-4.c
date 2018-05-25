//Práctica 1, ejercicio 4
#include <mega328p.h>
#include <delay.h>

void main(void)
{
 //Todo el puerto D como salida
 //Bit 0 al 4 sacan GND
 //Bit 5 al 8 sacan VCC
 DDRD=0xFF;
 PORTD=0xF0;   
 
 while(1)
    {       
     //Alternando las señales a los Leds
     //con retardo de 200ms
     PORTD=0xA5;             
     delay_ms(200);
     PORTD=0x5A;             
     delay_ms(200);
    }
}