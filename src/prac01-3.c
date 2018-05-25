//Práctica 1, ejercicio 3
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
     //Led1 = prendido
     //Led2 = apagado     
     //Led3 = prendido
     //Led4 = apagado
     //Led5 = prendido
     //Led6 = apagado
     //Led7 = prendido
     //Led8 = apagado          
     PORTD=0xA5;
    }
}