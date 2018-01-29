/*
 * main.c
 *
 *  Created on: Nov 10, 2017
 *      Author: zhanlei
 */
int a = 7;
int b = 0;
volatile float out_float = 0.0f;
int main(void)
{
	volatile int i = 0;
	out_float = 3.14f + a + b;
	out_float = 1.2 * out_float;
	out_float = out_float * out_float;
	while (1) {
		i++;
	}
}
