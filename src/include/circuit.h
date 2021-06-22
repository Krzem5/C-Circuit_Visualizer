#ifndef __CIRCUIT_H__
#define __CIRCUIT_H__ 1
#include <stdint.h>



#define CIRCUIT_NODE_HEADER_STRUCT uint8_t t;
#define CIRCUIT_NODE_HEADER(t) (t),
#define CIRCUIT_NODE_TYPE_INPUT 0



typedef struct __CIRCUIT_NODE{
	CIRCUIT_NODE_HEADER_STRUCT
} circuit_node_t;



typedef struct __CIRCUIT_INPUT{
	CIRCUIT_NODE_HEADER_STRUCT
	uint32_t id;
} circuit_input_t;



typedef struct __CIRCUIT{
	uint32_t nl;
	circuit_node_t** n;
	uint32_t _n_in_id;
} circuit_t;



void init_circuit(circuit_t* c);



void add_input(circuit_t* c,circuit_input_t* in);



#endif
