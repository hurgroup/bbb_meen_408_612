#include "../include/bbb_util.h"
using namespace BBB;


int main(){
	prepGPIO(60,"out",GPIO);
	for(int i=0;i<50;i++){
		cout << i << endl;
		writeGPIO(60,"1",GPIO);	
		usleep(50000);
		writeGPIO(60,"0",GPIO);
		usleep(50000);
	}
	
	closeGPIO(60,GPIO);
	return 0;
}
