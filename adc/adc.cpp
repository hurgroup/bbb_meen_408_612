#include "../include/bbb_util.h"
using namespace BBB;

int main(){
	cout << "ADC Start" << endl;

	while(1){
		int v=readADC(ADC5);
		cout<<v<<endl;
		usleep(50000);
	}

	cout << "ADC End" << endl;
	return 0;
}
