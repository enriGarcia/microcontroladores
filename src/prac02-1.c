#include <mega328p.h>

void main(void)
{
 //Declaración de variables
 bit sw0, sw1, sw2, sw3;   
 bit sens0, sens1;
 
/*  Configuración E/S
    Puerto D:
    PD7=Salida, Estado Inicial= Vcc  
    PD6=Salida, Estado Inicial= Vcc
    PD5=Salida, Estado Inicial= Vcc
    PD4=Salida, Estado Inicial= Vcc    
    PD3=Entrada, Pull-up
    PD2=Entrada, Pull-up
    PD1=Entrada, Pull-up
    PD0=Entrada, Pull-up  
    
    Puerto C:
    PC3=Salida, Estado Inicial= Vcc
    PC2=Salida, Estado Inicial= Vcc 
    PC1=Entrada, Pull-up    
    PC0=Entrada, Pull-up
*/
 DDRD=0xF0;
 PORTD=0xFF; 
 
 DDRC=0x0C;   
 PORTC=0x0F;         
  
while (1)
    {      
     //Lectura del estado del DipSwitch 
     sw0=PIND.0;
     sw1=PIND.1; 
     sw2=PIND.2;
     sw3=PIND.3;   
     
     //Lectura del estado de los sensores
     sens0=PINC.0;
     sens1=PINC.1;
         
     //Pulso de salida para los Leds (PD)
     PORTD.4=sw0; 
     PORTD.5=sw1;
     PORTD.6=sw2;
     PORTD.7=sw3;          
     
     //Pulso de salida para los Leds (PC)
     PORTC.2=sens0; 
     PORTC.3=sens1;
    }
}
