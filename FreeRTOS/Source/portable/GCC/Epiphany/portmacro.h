#ifndef PORTMACRO_H
#define PORTMACRO_H

#ifdef __cplusplus
extern "C" {
#endif

/*-----------------------------------------------------------
 * Port specific definitions.
 *
 * The settings in this file configure FreeRTOS correctly for the
 * given hardware and compiler.
 *
 * These settings should not be altered.
 *-----------------------------------------------------------
 */

/* Type definitions. */
#define portCHAR            char
#define portFLOAT           float
#define portDOUBLE          double
#define portLONG            long
#define portSHORT           int
#define portSTACK_TYPE      uint32_t
#define portBASE_TYPE       char

typedef portSTACK_TYPE StackType_t;
typedef int BaseType_t;
typedef unsigned int UBaseType_t;

#if( configUSE_16_BIT_TICKS == 1 )
    typedef uint16_t TickType_t;
    #define portMAX_DELAY ( TickType_t ) 0xffff
#else
    typedef uint32_t TickType_t;
    #define portMAX_DELAY ( TickType_t ) 0xffffffffUL
#endif

/* Critical section management. */

#define portENTER_CRITICAL()        asm volatile ( "gid" )
#define portEXIT_CRITICAL()         asm volatile ( "gie" )

#define portDISABLE_INTERRUPTS()    asm volatile ( "gid" );
#define portENABLE_INTERRUPTS()     asm volatile ( "gie" );

/* Architecture specifics. */
#define portSTACK_GROWTH            ( -1 )
#define portBYTE_ALIGNMENT          8

/* Task function macros as described on the FreeRTOS.org WEB site. */
#define portTASK_FUNCTION_PROTO( vFunction, pvParameters ) void vFunction( void *pvParameters )
#define portTASK_FUNCTION( vFunction, pvParameters ) void vFunction( void *pvParameters )

/* Kernel utilities. */
#define portYIELD()                 vPortYield()

#ifdef __cplusplus
}
#endif

#endif /* PORTMACRO_H */
