#include <iostream>
#include <stdio.h>
#include <unistd.h>
using namespace std;

#define LED0 "/sys/class/leds/beaglebone:green:usr0/brightness"
#define LED1 "/sys/class/leds/beaglebone:green:usr1/brightness"
#define LED2 "/sys/class/leds/beaglebone:green:usr2/brightness"
#define LED3 "/sys/class/leds/beaglebone:green:usr3/brightness"

FILE *LEDHandle = NULL;

void led_on(string);
void led_off(string);

int main(){
	cout << "LED Flash Start" << endl;

	for(int i=0;i<10;i++){
		cout << "on " <<i << endl;
		led_on(LED3);

		sleep(1);
		cout << "off " <<i << endl;
		led_off(LED3);
		sleep(1);
	}
	cout << "LED Flash End" << endl;
	return 0;
}

void led_on(string LEDBrightness){
	if((LEDHandle=fopen(LEDBrightness.c_str(),"r+"))!=NULL){
			fwrite("1",sizeof(char),1,LEDHandle);
			fclose(LEDHandle);
	}
}

void led_off(string LEDBrightness){
	if((LEDHandle=fopen(LEDBrightness.c_str(),"r+"))!=NULL){
			fwrite("0",sizeof(char),1,LEDHandle);
			fclose(LEDHandle);
	}
}