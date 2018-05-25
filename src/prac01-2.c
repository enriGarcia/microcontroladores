//Práctica 1, ejercicio 2
#include <mega328p.h>

void main(void)
{
 //Todo el puerto D como salida
 //Bit 0 al 4 sacan GND
 //Bit 5 al 8 sacan VCC
 DDRD=0xFF;
 PORTD=0xF0;   
 
 while(1)
    {       
     //Sacar datos por el puerto D
     //al mismo tiempo
     PORTD=0x0F;
    }
}
