#include <mega328p.h>
#include <delay.h>
#define xtal 1000000L

/*
  Codificación de cada dígito para display de 7 segmentos
  Dig_0=0x40, Dig_1=0x79, Dig_2=0x24, Dig_3=0x30, Dig_4=0x19
  Dig_5=0x12, Dig_6=0x02, Dig_7=0x78, Dig_8=0x00, Dig_9=0x18
*/
const unsigned char tabla7segmentos[10] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x18};

// Voltage Reference: AREF pin
#define ADC_VREF_TYPE ((0<<REFS1) | (0<<REFS0) | (1<<ADLAR))

// Read the 8 most significant bits
// of the AD conversion result
unsigned char read_adc(unsigned char adc_input)
{
 ADMUX = adc_input | ADC_VREF_TYPE;
 // Delay needed for the stabilization of the ADC input voltage
 delay_us(10);
 // Start the AD conversion
 ADCSRA |= (1 << ADSC);
 // Wait for the AD conversion to complete
 while ((ADCSRA & (1 << ADIF)) == 0);
 ADCSRA |= (1 << ADIF);
 return ADCH;
}

void main(void)
{
 unsigned char lectura;

 /* Configuración E/S
    Puerto D:
    PD7=Entrada, Pull-down
    PD6=Salida, Estado Inicial= Vcc
    PD5=Salida, Estado Inicial= Vcc
    PD4=Salida, Estado Inicial= Vcc
    PD3=Salida, Estado Inicial= Vcc
    PD2=Salida, Estado Inicial= Vcc
    PD1=Salida, Estado Inicial= Vcc
    PD0=Salida, Estado Inicial= Vcc
    Puerto C:
    PC6 a PC0= Entrada, Tri-estado
 */

 DDRD = 0x7F;
 PORTD = 0x7F;
 
 DDRC = 0x00;
 PORTC = 0x00;

 // ADC initialization
 // ADC Clock frequency: 500.000 kHz
 // ADC Voltage Reference: AREF pin
 // ADC Auto Trigger Source: ADC Stopped
 // Only the 8 most significant bits of
 // the AD conversion result are used
 // Digital input buffers on ADC0: On, ADC1: On, ADC2: On, ADC3: On
 // ADC4: On, ADC5: On
 DIDR0 = (0 << ADC5D) | (0 << ADC4D) | (0 << ADC3D) | (0 << ADC2D) | (0 << ADC1D) | (0 << ADC0D);
 ADMUX = ADC_VREF_TYPE;
 ADCSRA = (1 << ADEN) | (0 << ADSC) | (0 << ADATE) | (0 << ADIF) | (0 << ADIE) | (0 << ADPS2) | (0 << ADPS1) | (1 << ADPS0);
 ADCSRB = (0 << ADTS2) | (0 << ADTS1) | (0 << ADTS0);

 while (1)
 {
  lectura = read_adc(0);
  if((lectura >= 0) && (lectura <= 25))  
  {
   PORTD = tabla7segmentos[0];
  }
  else if((lectura >= 26) && (lectura <= 50))   
  {
   PORTD = tabla7segmentos[1];           
  }
  else if((lectura >= 51) && (lectura <= 75))    
  {
   PORTD = tabla7segmentos[2];
  }
  else if((lectura >= 76) && (lectura <= 100))
  {
   PORTD = tabla7segmentos[3];
  }
  else if((lectura >= 101) && (lectura <= 125))   
  {
   PORTD = tabla7segmentos[4];
  }
  else if((lectura >= 126) && (lectura <= 150))              
  {
   PORTD = tabla7segmentos[5];
  }
  else if((lectura >= 151) && (lectura <= 175))    
  {
   PORTD = tabla7segmentos[6];
  }
  else if((lectura >= 176) && (lectura <= 200))    
  {
   PORTD = tabla7segmentos[7];
  }
  else if((lectura >= 201) && (lectura <= 225))          
  {
   PORTD = tabla7segmentos[8];
  }
  else if((lectura >= 226) && (lectura <= 250))
  {
   PORTD = tabla7segmentos[9];         
  }
  else
  {
   PORTD = tabla7segmentos[9];             
  }
 }
}
