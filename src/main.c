#include <circuit.h>



int main(int argc,const char** argv){
	circuit_t c;
	init_circuit(&c);
	circuit_battery_t b;
	add_battery(&c,&b);
	circuit_switch_t sw;
	add_switch(&c,&sw);
	circuit_led_t l;
	add_led(&c,&l);
	CONNECT_NODES(&b,p,&sw,i);
	CONNECT_NODES(&sw,o,&l,a);
	CONNECT_NODES(&l,c,&b,n);
	free_circuit(&c);
	return 0;
}
