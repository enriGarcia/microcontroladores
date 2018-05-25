//Práctica 1, ejercicio 1
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
     //Señales individuales
     PORTD.0=1;
     PORTD.1=1; 
     PORTD.2=1; 
     PORTD.3=1; 
     PORTD.4=0; 
     PORTD.5=0; 
     PORTD.6=0; 
     PORTD.7=0;    
    }
}
