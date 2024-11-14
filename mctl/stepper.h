#pragma once

#include "common.h"

typedef struct {
    volatile uint8_t *port;
    uint8_t en;
    uint8_t m0;
    uint8_t m1;
    uint8_t m2;
    uint8_t rst;
    uint8_t slp;
    uint8_t stp;
    uint8_t dir;
} stp_drv_conf_t;

typedef struct {
    float degree;
} stp_motor_conf_t;

typedef struct {
    stp_motor_conf_t m_conf;
    stp_drv_conf_t drv_conf;
} stp_config_t;

/* Full Configurator */

stp_config_t stp_init(stp_drv_conf_t *drv_conf, stp_motor_conf_t *m_conf);

/* Motor configurator  */

stp_motor_conf_t stp_init_motor(float degree);

/* Driver configurator  */

stp_drv_conf_t stp_init_drv(volatile uint8_t *port, uint8_t m0, uint8_t m1, uint8_t m2, uint8_t stp,
                            uint8_t dir);

stp_drv_conf_t stp_init_drv_advanced(volatile uint8_t *port, uint8_t en_pin, uint8_t m0, uint8_t m1,
                                     uint8_t m2, uint8_t rst, uint8_t slp, uint8_t stp,
                                     uint8_t dir);

/* Actuators */

void stp_forward_step(stp_config_t *conf, uint64_t steps);
void stp_backward_step(stp_config_t *conf, uint64_t steps);

void stp_forward_degree(stp_config_t *conf, float degree);
void stp_backward_degree(stp_config_t *conf, float degree);
