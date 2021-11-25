void SPI_MasterTransmit(void)
{
    /* Setea los dos bits del registro (MOSI & SCK) como salidas */
    DDR_SPI = (1<<DD_MOSI)|(1<<DD_SCK);
    /* Habilita la comunicación SPI, setea el dispositivo como master y selecciona la velocidad de transmisión de fosc/16, respectivamente. */
    SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

void SPI_MasterTransmit(char cData)
{
    /* Pone en el registro SPDR los datos a transmitir */
    SPDR = cData;
    /* Espera a que la flag SPIF se vuelva 0, significando que se terminó la transmisión */
    while(!(SPSR & (1<<SPIF)));
}

void CMD0(void)
{
    SPI_MasterTransmit(40);
    SPI_MasterTransmit(00);
    SPI_MasterTransmit(00);
    SPI_MasterTransmit(00);
    SPI_MasterTransmit(00);
    SPI_MasterTransmit(95);
}