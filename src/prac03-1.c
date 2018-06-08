#include <mega328p.h>
#include <delay.h>
#define xtal 1000000L

/*
  Codificación de cada dígito para display de 7 segmentos
  Dig_0=0x40, Dig_1=0x79, Dig_2=0x24, Dig_3=0x30, Dig_4=0x19
  Dig_5=0x12, Dig_6=0x02, Dig_7=0x78, Dig_8=0x00, Dig_9=0x18
*/
const unsigned char tabla7segmentos[10]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x18};

void main(void)
{
 //i=variable para conteo inicializada en 0
 unsigned char i=0;    
 
 /*  Configuración E/S
    Puerto D:
    PD7=Entrada, Pull-up  
    PD6=Salida, Estado Inicial= Vcc
    PD5=Salida, Estado Inicial= Vcc
    PD4=Salida, Estado Inicial= Vcc    
    PD3=Salida, Estado Inicial= Vcc
    PD2=Salida, Estado Inicial= Vcc
    PD1=Salida, Estado Inicial= Vcc
    PD0=Salida, Estado Inicial= Vcc
*/
 
 DDRD =0x7F;
 PORTD=0xFF;
 
while (1)
    {
     PORTD=tabla7segmentos[i]; //Obtiene la codificación del dígito i
     delay_ms(500);            //Temporización 500ms
     i++;                      //Incrementa el valor de i en 1
     if(i>9)                   //Si i es mayor a 9 resetea su valor a 0
     {
        i=0;
     }
    }
}
