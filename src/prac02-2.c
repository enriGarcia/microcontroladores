#include <mega328p.h>
#include <delay.h>
#define xtal 1000000L

void main(void)
{
 //Declaración de variables
 unsigned char lecturaSW;     
 const unsigned int tiempo = 500;  
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
     //Lectura de los estados de los sensores y Dip-Switch         
     sens0=PINC.0;
     sens1=PINC.1;
     lecturaSW=PIND & 0x0F;     
     
     if(lecturaSW==0x0E)
     {
      //Prende todos los Leds
      PORTD=0x00;
     }   
     else if(lecturaSW==0x0D)
     {  
      //Prende y apaga con temporización todos los Leds
      PORTD=0x00;
      delay_ms(tiempo);  
      PORTD=0xF0;
      delay_ms(tiempo);
     }        
     else if(lecturaSW==0x0B)
     {      
      //Efecto Walking
      PORTD=0xE0;
      delay_ms(tiempo); 
      PORTD=0xD0;
      delay_ms(tiempo);
      PORTD=0xB0;
      delay_ms(tiempo);
      PORTD=0x70;
      delay_ms(tiempo);
     }   
     else if(lecturaSW==0x07)
     {      
      //Efecto Walking Inverso
      PORTD=0x70;
      delay_ms(tiempo);
      PORTD=0xB0;
      delay_ms(tiempo);
      PORTD=0xD0;
      delay_ms(tiempo);  
      PORTD=0xE0;
      delay_ms(tiempo);
     }    
     else
     {        
      //Apaga todos los Leds
      PORTD=0xF0;
     }  
    
     if((sens0==0) && (sens1==0))
     {
      PORTC.2=0;
      PORTC.3=0;
     }           
     else
     {
      PORTC.2=1;
      PORTC.3=1;
     }
    }
}
