/*
 * ultrasonic.h
 *
 *  Created on: Oct 15, 2021
 *      Author: kiko
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
#include "icu.h"
#include "gpio.h"
#include <avr/io.h>
#include <util/delay.h>
#define	TRIGGER_PORT_ID		PORTC_ID
#define TRIGGER_PIN_ID		PIN0_ID
/*extern variables*/
extern uint8 edge_count;
extern uint16 sensor_time;
/*functions prototypes*/
void Ultrasonic_init(void);
void Ultrasonic_Trigger(void);
uint16 Ultrasonic_readDistance(void);
void Ultrasonic_edgeProcessing(void);




#endif /* ULTRASONIC_H_ */
