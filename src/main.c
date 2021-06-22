#include <circuit.h>



int main(int argc,const char** argv){
	circuit_t c;
	init_circuit(&c);
	circuit_input_t i0;
	add_input(&c,&i0);
	return 0;
}
