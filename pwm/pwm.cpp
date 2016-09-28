#include "../include/bbb_util.h"

#define PERIOD 1000000	// 1ms
#define DUTYCYCLE 0	// 1ms

using namespace BBB;

int main(){
	cout << "PWM Start" << endl;
	char period_ch[20],dutycycle_ch[20];	// to avoid using C++11

	//string period;
	int dutycycle;
	//period=std::to_string(PERIOD);	//	available only for c++11
	//dutycycle=std::to_string(DUTYCYCLE);	//g++ --std=c++11 pwm.cpp ../include/bbb_util.cpp -o pwm
	//period=sprintf(period_ch,"%d",PERIOD);
	//dutycycle=sprintf(dutycycle_ch,"%d",DUTYCYCLE);
	prepPWM(PWM0Export,"0", PWM0Period, PERIOD, PWM0Dutycycle, DUTYCYCLE);
	startPWM(PWM0Enable);

	for(int i=0;i<10;i++){
		dutycycle=int(PERIOD*i/10);
		cout << "on " <<i <<", " <<dutycycle << endl;
		setPWMDutycycle(PWM0Dutycycle, dutycycle);
		sleep(1);
	}
	
	stopPWM(PWM0Enable);
	unexportPWM(PWM0Unexport,"0");
	cout << "PWM End" << endl;
	return 0;
}