#include <circuit.h>
#include <stdint.h>
#include <stdlib.h>



void init_circuit(circuit_t* c){
	c->nl=0;
	c->n=NULL;
}



void add_battery(circuit_t* c,circuit_battery_t* b){
	b->t=CIRCUIT_NODE_TYPE_BATTERY;
	b->v=0;
	b->a=0;
	b->p=NULL;
	b->n=NULL;
	c->nl++;
	c->n=realloc(c->n,c->nl*sizeof(circuit_node_t*));
	*(c->n+c->nl-1)=(circuit_node_t*)b;
}



void add_switch(circuit_t* c,circuit_switch_t* sw){
	sw->t=CIRCUIT_NODE_TYPE_SWITCH;
	sw->st=CIRCUIT_BUTTON_STATE_UNPRESSED;
	sw->i=NULL;
	sw->o=NULL;
	c->nl++;
	c->n=realloc(c->n,c->nl*sizeof(circuit_node_t*));
	*(c->n+c->nl-1)=(circuit_node_t*)sw;
}



void add_led(circuit_t* c,circuit_led_t* led){
	led->t=CIRCUIT_NODE_TYPE_LED;
	led->a=NULL;
	led->c=NULL;
	c->nl++;
	c->n=realloc(c->n,c->nl*sizeof(circuit_node_t*));
	*(c->n+c->nl-1)=(circuit_node_t*)led;
}



void free_circuit(circuit_t* c){
	if (c->n){
		free(c->n);
		c->n=NULL;
	}
	c->nl=0;
}
