#include "stepper.h"

static void stp_step(stp_config_t *conf, uint64_t steps)
{
    steps <<= 1;

    while (steps--) {
        TOGGLE_BIT(*conf->drv_conf.port, conf->drv_conf.stp);
        _delay_ms(1);
    }
}

stp_motor_conf_t stp_init_motor(float degree)
{
    stp_motor_conf_t conf = {0};
    conf.degree = degree;
    return conf;
}

stp_drv_conf_t stp_init_drv(volatile uint8_t *port, uint8_t m0, uint8_t m1, uint8_t m2, uint8_t stp,
                            uint8_t dir)
{
    return stp_init_drv_advanced(port, 0, m0, m1, m2, 0, 0, stp, dir);
}

stp_drv_conf_t stp_init_drv_advanced(volatile uint8_t *port, uint8_t en, uint8_t m0, uint8_t m1,
                                     uint8_t m2, uint8_t rst, uint8_t slp, uint8_t stp, uint8_t dir)
{
    stp_drv_conf_t conf = {0};

    conf.port = port;
    conf.en = en;
    conf.m0 = m0;
    conf.m1 = m1;
    conf.m2 = m2;
    conf.rst = rst;
    conf.slp = slp;
    conf.stp = stp;
    conf.dir = dir;

    return conf;
}

void stp_forward_step(stp_config_t *conf, uint64_t steps)
{
    UNSET_BIT(*conf->drv_conf.port, conf->drv_conf.dir);
    stp_step(conf, steps);
}

void stp_backward_step(stp_config_t *conf, uint64_t steps)
{
    SET_BIT(*conf->drv_conf.port, conf->drv_conf.dir);
    stp_step(conf, steps);
}

void stp_forward_degree(stp_config_t *conf, float degree)
{
    stp_forward_step(conf, (uint64_t)(degree / conf->m_conf.degree));
}

void stp_backward_degree(stp_config_t *conf, float degree)
{
    stp_backward_step(conf, (uint64_t)(degree / conf->m_conf.degree));
}