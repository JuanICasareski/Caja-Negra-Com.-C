#ifndef USART_H
#define	USART_H  
void USART_Init(long baud);
void USART_Baud(long baud);
void USART_PutC(char ch);
void USART_Print(char *str);

void USART_Init(long baud){
	UCSR0A |= 1 <<U2X0;                    //Doble velocidad de clock
	UCSR0B |= 1 <<TXEN0 | ~(1<<RXEN0);       //Transmisor y receptor habilitado
	UCSR0C |= 1 << UCSZ01 | 1 << UCSZ00;  //Asincronico, 1 bit de stop, 8 bits de datos, sin pariedad
	UBRR0 = 207;
    USART_Baud(baud);
}

void USART_Baud(long baud){
   float auxBaud = (float) F_CPU / (float) baud;
   if(UCSR0A & (1<<U2X0)){
      auxBaud /= 8;
   }
   else{
      auxBaud /= 16;
   }
   UBRR0H = (int) auxBaud >> 8;
   UBRR0L = auxBaud - 1;
}

void USART_PutC(char ch){
	while(!(UCSR0A&(1 << UDRE0)));
	UDR0 = ch;
	while(!(UCSR0A&(1 << TXC0)));
	UCSR0A |= 1<<TXC0;
}

void USART_Print(char*str){
	while(*str){
		USART_PutC(*str);
		str++;
	}
}

#endif