/*
 * ADC_private.h
 *
 * Created: 10/23/2023 9:16:54 AM
 *  Author: DELL
 */ 


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

/*ADC Registers*/ 
#define ADMUX   *((volatile uint8*)(0x27))
#define ADCSRA  *((volatile uint8*)(0x26))
#define ADCH    *((volatile uint8*)(0x25))
#define ADCL    *((volatile uint8*)(0x24))

#define ADC     *((volatile uint16*)(0x24))

#define SFIOR     *((volatile uint8*)(0x50))

/*ADMUX bits*/
enum ADMUX_bits{
	MUX0,MUX1,MUX2,MUX3,MUX4,ADLAR,REFS0,REFS1
};
	
/*ADCSRA bits*/
enum ADCSRA_bits{
	ADPS0,ADPS1,ADPS2,ADIE,ADIF,ADATE,ADSC,ADEN
};

/*SFIOR bits*/
enum SFIOR_bits{
	ADTS0 = 5, ADTS1=6, ADTS2=7
};


#endif /* ADC_PRIVATE_H_ */
