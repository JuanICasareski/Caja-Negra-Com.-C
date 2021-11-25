#ifndef ADC_H
#define	ADC_H
#define ADC_start() ADCSRA |= 1 << ADSC// para iniciar la conversion
#define ADC_busy() !(ADCSRA & (1 << ADIF)) // para leer el flag
#define ADC_clear() ADCSRA |= 1 << ADIF    // para limpiar el flag

void ADC_Init(void){

	ADMUX = 0x61;                           //V micro, Justificado a la izquierda, PC1

	ADCSRA = 0x80;                          //ADC habilitado, Sin interrupcion, Prescaler clock 2

	ADCSRB = 0x00;                          //Free running mode

	DIDR0 |= 1 << PC1;                 		//Desabilitado buffer digital de PC1, esto se hacia con OR no AND
}
#endif

