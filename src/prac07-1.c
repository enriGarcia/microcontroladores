#include <mega328p.h>
#include <delay.h>
#include <alcd.h>

// Voltage Reference: AREF pin
#define ADC_VREF_TYPE ((0<<REFS1) | (0<<REFS0) | (0<<ADLAR))

// Read the AD conversion result
unsigned int read_adc(unsigned char adc_input)
{
 ADMUX=adc_input | ADC_VREF_TYPE;
 // Delay needed for the stabilization of the ADC input voltage
 delay_us(10);
 // Start the AD conversion
 ADCSRA|=(1<<ADSC);
 // Wait for the AD conversion to complete
 while ((ADCSRA & (1<<ADIF))==0);
 ADCSRA|=(1<<ADIF);
 return ADCW;
}

void main(void)
{
 // Analog Comparator initialization
 // Analog Comparator: Off
 // The Analog Comparator's positive input is
 // connected to the AIN0 pin
 // The Analog Comparator's negative input is
 // connected to the AIN1 pin
 ACSR=(1<<ACD) | (0<<ACBG) | (0<<ACO) | (0<<ACI) | (0<<ACIE) | (0<<ACIC) | (0<<ACIS1) | (0<<ACIS0);
 // Digital input buffer on AIN0: On
 // Digital input buffer on AIN1: On
 DIDR1=(0<<AIN0D) | (0<<AIN1D);
 
 // ADC initialization
 // ADC Clock frequency: 500.000 kHz
 // ADC Voltage Reference: AREF pin
 // ADC Auto Trigger Source: ADC Stopped
 // Digital input buffers on ADC0: On, ADC1: On, ADC2: On, ADC3: On
 // ADC4: On, ADC5: On
 DIDR0=(0<<ADC5D) | (0<<ADC4D) | (0<<ADC3D) | (0<<ADC2D) | (0<<ADC1D) | (0<<ADC0D);
 ADMUX=ADC_VREF_TYPE;
 ADCSRA=(1<<ADEN) | (0<<ADSC) | (0<<ADATE) | (0<<ADIF) | (0<<ADIE) | (0<<ADPS2) | (0<<ADPS1) | (1<<ADPS0);
 ADCSRB=(0<<ADTS2) | (0<<ADTS1) | (0<<ADTS0);
 
 // Alphanumeric LCD initialization
 // Connections are specified in the
 // Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
 // RS - PORTD Bit 0
 // RD - PORTD Bit 1
 // EN - PORTD Bit 2
 // D4 - PORTD Bit 4
 // D5 - PORTD Bit 5
 // D6 - PORTD Bit 6
 // D7 - PORTD Bit 7
 // Characters/line: 16
 lcd_init(16);

 while (1)
       {

       }
}
