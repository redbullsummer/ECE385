// Main.c - makes LEDG0 on DE2-115 board blink if NIOS II is set up correctly
// for ECE 385 - University of Illinois - Electrical and Computer Engineering
// Author: Zuofu Cheng

int main()
{
	int i = 0;
	// first led
	volatile unsigned int *LED_PIO = (unsigned int*)0x00000050; // make a pointer to access the PIO block
	volatile unsigned int *SW_PIO = (unsigned int*) 0x00000040; // pointer to FIRST SWITCH x40-x4f
	volatile unsigned int *KEY_PIO = (unsigned int*) 	0x00000030; // Buttons
	int sum = 0;
	int flag = 0;

	while ( (1+1) != 3) //infinite loop
	{
		if(((*SW_PIO) & 0b1000000000)==0b1000000000){
			*LED_PIO = 0; //clear all LEDs
			for (i = 0; i < 100000; i++); //software delay
				*LED_PIO |= 0x1; //set LSB
			for (i = 0; i < 100000; i++); //software delay
				*LED_PIO &= ~0x1; //clear LSB
		}
		else{
			if(*KEY_PIO == 0b01 && flag ==0){
				//*LED_PIO = 0b1111111111;
				sum+= *SW_PIO;
				sum= sum%256;
				flag =1;

				*LED_PIO = sum;

			}
			else if(*KEY_PIO== 0b11){
				flag=0;
				*LED_PIO = sum;
			}

				//*LED_PIO = 0b0000000000;



		}

	}

	return 1; //never gets here
}
