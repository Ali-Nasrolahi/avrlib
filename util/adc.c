#include "adc.h"

void adc_init(uint8_t ref_mode, uint8_t adc_no, uint8_t prescaler)
{
    ADMUX = ref_mode | (adc_no & 7);
    ADCSRA = _BV(ADATE) | prescaler;
}

uint16_t adc_read(void)
{
    SET_BIT(ADCSRA, ADEN);
    SET_BIT(ADCSRA, ADSC);
    return ADC;
}

uint16_t adc_single_read(uint8_t ref_mode, uint8_t adc_no, uint8_t prescaler)
{
    ADMUX = ref_mode | (adc_no & 7);
    ADCSRA = _BV(ADEN) | _BV(ADSC) | prescaler;
    while (bit_is_set(ADCSRA, ADSC));
    uint16_t adc_val = ADC;
    UNSET_BIT(ADCSRA, ADEN);
    return adc_val;
}