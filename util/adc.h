#pragma once

#include "common.h"

#define ADC_REF_AREF     (0)
#define ADC_REF_AVCC     (_BV(REFS0))
#define ADC_REF_INTERNAL (_BV(REFS0) | _BV(REFS1))

#define ADC_PRESCALER_2   (0)
#define ADC_PRESCALER_8   (_BV(ADPS0) | _BV(ADPS1))
#define ADC_PRESCALER_32  (_BV(ADPS0) | _BV(ADPS2))
#define ADC_PRESCALER_128 (_BV(ADPS0) | _BV(ADPS1) | _BV(ADPS2))

void adc_init(uint8_t ref_mode, uint8_t adc_no, uint8_t prescaler);
uint16_t adc_read(void);
uint16_t adc_single_read(uint8_t ref_mode, uint8_t adc_no, uint8_t prescaler);