#include <circuit.h>
#include <stdint.h>
#include <stdlib.h>



void init_circuit(circuit_t* c){
	c->nl=0;
	c->n=NULL;
	c->_n_in_id=0;
}



void add_input(circuit_t* c,circuit_input_t* in){
	in->t=CIRCUIT_NODE_TYPE_INPUT;
	in->id=c->_n_in_id;
	c->_n_in_id++;
	c->nl++;
	c->n=realloc(c->n,c->nl*sizeof(circuit_node_t*));
	*(c->n+c->nl-1)=(circuit_node_t*)in;
}
