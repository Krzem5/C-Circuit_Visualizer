#ifndef __CIRCUIT_H__
#define __CIRCUIT_H__ 1
#include <stdint.h>



#define CIRCUIT_NODE_HEADER_STRUCT uint8_t t;
#define CIRCUIT_NODE_HEADER(t) (t),
#define CIRCUIT_NODE_TYPE_BATTERY 0
#define CIRCUIT_NODE_TYPE_SWITCH 1
#define CIRCUIT_NODE_TYPE_LED 2
#define CIRCUIT_BUTTON_STATE_UNPRESSED 0
#define CIRCUIT_BUTTON_STATE_PRESSED 1
#define CONNECT_NODES(a,ap,b,bp) \
	do{ \
		(a)->ap=(circuit_node_t*)(b); \
		(b)->bp=(circuit_node_t*)(a); \
	} while (0)



typedef struct __CIRCUIT_NODE{
	CIRCUIT_NODE_HEADER_STRUCT
} circuit_node_t;



typedef struct __CIRCUIT_BATTERY{
	CIRCUIT_NODE_HEADER_STRUCT
	float v;
	float a;
	circuit_node_t* p;
	circuit_node_t* n;
} circuit_battery_t;



typedef struct __CIRCUIT_SWITCH{
	CIRCUIT_NODE_HEADER_STRUCT
	uint8_t st;
	circuit_node_t* i;
	circuit_node_t* o;
} circuit_switch_t;



typedef struct __CIRCUIT_LED{
	CIRCUIT_NODE_HEADER_STRUCT
	circuit_node_t* a;
	circuit_node_t* c;
} circuit_led_t;



typedef struct __CIRCUIT{
	uint32_t nl;
	circuit_node_t** n;
} circuit_t;



void init_circuit(circuit_t* c);



void add_battery(circuit_t* c,circuit_battery_t* in);



void add_switch(circuit_t* c,circuit_switch_t* sw);



void add_led(circuit_t* c,circuit_led_t* led);



void free_circuit(circuit_t* c);



#endif
