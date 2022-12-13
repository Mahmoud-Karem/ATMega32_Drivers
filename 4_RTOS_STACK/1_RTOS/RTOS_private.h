/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    RTOS_private.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Layer  : RTOS Stack
 *  SWC    : RTOS/Scheduler
 *
 */ 
 
#ifndef RTOS_PRIVATE_H_
#define RTOS_PRIVATE_H_

/*
	Hints :-
	1-the struct is used by me only so it is here (private.h)
	2-we will handle priority by another way so it is not here
		priority will be the index of tasks array
		we will check priority in voidScheduler
*/
typedef struct
{
	u16 Periodicity;
	void(*TaskFunc)(void);
	u8 State;
	u16 FirstDelay;
}Task_t;

static void voidScheduler(void);

#define TASK_RESUMED		0
#define TASK_SUSPENDED		1

#endif
