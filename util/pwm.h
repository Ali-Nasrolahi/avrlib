#pragma once

#include "common.h"

#ifdef __AVR_ATmega328P__

#ifndef _AVR_IOM328P_H_
#include <avr/iom328p.h>
#endif

inline void pwm_init(volatile uint8_t *timer_reg_a, volatile uint8_t *timer_reg_b)
{
    *timer_reg_a = (_BV(WGM00) | _BV(WGM01) /* fast-mode PWM */) | _BV(COM0A1 /* non-inverting */);
    *timer_reg_b = _BV(CS01);
}

#endif