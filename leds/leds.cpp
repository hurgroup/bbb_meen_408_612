#include "../include/bbb_util.h"
using namespace BBB;

int main(){
	cout << "LED Flash Start" << endl;

	for(int i=0;i<10;i++){
		cout << "on " <<i << endl;
		led_on(LED3);
		led_on(LED2);

		sleep(1);
		cout << "off " <<i << endl;
		led_off(LED3);
		led_off(LED2);
		sleep(1);
	}
	cout << "LED Flash End" << endl;
	return 0;
}
