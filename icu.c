 /*

 </Header file for the AVR ICU driver/>
 </ Author: korolus hany/>

*/

#include "icu.h"
#include "common_macros.h" /* To use the macros like SET_BIT */
#include <avr/io.h> /* To use ICU/Timer1 Registers */
#include <avr/interrupt.h> /* For ICU ISR */
/* variables decleration*/


static volatile void (*g_callBackPtr)(void) = NULL_PTR;

/*functions prototype*/
ISR(TIMER1_CAPT_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		(*g_callBackPtr)();
	}
}

void Icu_init(const Icu_ConfigType * Config_Ptr)
{
	/* pin input*/
	CLEAR_BIT(DDRB,PD6);

		/* We are using a non-PWM mode */
		TCCR1A = (1<<FOC1A) | (1<<FOC1B);

		/* Edge and clock prescaling dynamic configuration */
		TCCR1B = (TCCR1B & 0xBF) | ((Config_Ptr->edge) << 6);
		TCCR1B = (TCCR1B & 0xF8) | (Config_Ptr->clock);

		TCNT1 = 0;
		ICR1 = 0;

		/* Timer1 input capture interrupt enable */
		TIMSK |= (1<<TICIE1);
	}


void Icu_setCallBack(void(*a_ptr)(void))
{

	g_callBackPtr = a_ptr;
}

void Icu_setEdgeDetectionType(const Icu_EdgeType a_edgeType)
{

	TCCR1B = (TCCR1B & 0xBF) | (a_edgeType<<6);
}

uint16 Icu_getInputCaptureValue(void)
{
	return ICR1;
}

void Icu_clearTimerValue(void)
{
	TCNT1 = 0;
}

void Icu_DeInit(void)
{
	/* Clear All Timer1 Registers */
	TIMSK &= ~(1<<TICIE1);
	TCCR1A = 0;
	TCNT1 = 0;
	ICR1 = 0;
	TCCR1B = 0;
}
