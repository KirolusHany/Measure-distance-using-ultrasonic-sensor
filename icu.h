 /*

 </Header file for the AVR ICU driver/>
 </ Author: korolus hany/>

*/

#ifndef ICU_H_
#define ICU_H_

#include "std_types.h"

/*icu configurations*/
typedef enum
{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}Icu_Clock;

typedef enum
{
	FALLING,RISING
}Icu_EdgeType;

typedef struct
{
	Icu_Clock clock;
	Icu_EdgeType edge;
}Icu_ConfigType;

/*Functions Prototypes*/

void Icu_init(const Icu_ConfigType * Config_Ptr);

void Icu_setCallBack(void(*a_ptr)(void));

void Icu_setEdgeDetectionType(const Icu_EdgeType edgeType);

uint16 Icu_getInputCaptureValue(void);

void Icu_clearTimerValue(void);

void Icu_DeInit(void);

#endif
