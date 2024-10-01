

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_register.h"
#include "EXTI_config.h"

void EXTI_voidInt0Init(void)
{
	/*Set sense control for INT0 to falling edge*/
	SET_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);

	/*Peripheral interrupt enable for INT0*/
	SET_BIT(GICR,GICR_INT0);
}

