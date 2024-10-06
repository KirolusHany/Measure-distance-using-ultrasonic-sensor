/*
 * ultrasonic.c
 *
 *  Created on: Oct 15, 2021
 *      Author: kiko
 */

#include"ultrasonic.h"

uint8 edge_count=0;

uint16 sensor_time=0;
void Ultrasonic_init(void){
	/*initialize */
	Icu_ConfigType icu_config={F_CPU_8,RISING};
	Icu_init(&icu_config);
	/*set pin direction*/
		GPIO_setupPinDirection(TRIGGER_PORT_ID,TRIGGER_PIN_ID,PIN_OUTPUT);
		/*GLOBAL INYREUPT*/
		SREG |= (1<<7);
		/* callback*/
		Icu_setCallBack(Ultrasonic_edgeProcessing);
}
void Ultrasonic_Trigger(void){
	GPIO_writePin(TRIGGER_PORT_ID,TRIGGER_PIN_ID,LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(TRIGGER_PORT_ID,TRIGGER_PIN_ID,LOGIC_LOW);

}
uint16 Ultrasonic_readDistance(void){


	Ultrasonic_Trigger();

			return sensor_time /58.5;

}
void Ultrasonic_edgeProcessing(void){
	edge_count++;
	if(edge_count == 1)
	{

		Icu_clearTimerValue();
		/* Detect falling edge */
		Icu_setEdgeDetectionType(FALLING);
	}
	else if(edge_count == 2)
	{
		/* rising time value need */
	sensor_time = Icu_getInputCaptureValue();
	Icu_setEdgeDetectionType(RISING);
	Icu_clearTimerValue();
	edge_count=0;
}



}


