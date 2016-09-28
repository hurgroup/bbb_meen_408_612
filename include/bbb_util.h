#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sstream>

#define LED0 "/sys/class/leds/beaglebone:green:usr0/brightness"
#define LED1 "/sys/class/leds/beaglebone:green:usr1/brightness"
#define LED2 "/sys/class/leds/beaglebone:green:usr2/brightness"
#define LED3 "/sys/class/leds/beaglebone:green:usr3/brightness"

#define GPIO "/sys/class/gpio"

#define ADC0 "/sys/bus/iio/devices/iio:device0/in_voltage0_raw"
#define ADC1 "/sys/bus/iio/devices/iio:device0/in_voltage1_raw"
#define ADC2 "/sys/bus/iio/devices/iio:device0/in_voltage2_raw"
#define ADC3 "/sys/bus/iio/devices/iio:device0/in_voltage3_raw"
#define ADC4 "/sys/bus/iio/devices/iio:device0/in_voltage4_raw"
#define ADC5 "/sys/bus/iio/devices/iio:device0/in_voltage5_raw"
#define ADC6 "/sys/bus/iio/devices/iio:device0/in_voltage6_raw"

#define PWM0Export "/sys/class/pwm/pwmchip0/export"
#define PWM0Unexport "/sys/class/pwm/pwmchip0/unexport"
#define	PWM0Period "/sys/class/pwm/pwmchip0/pwm0/period"
#define PWM0Dutycycle "/sys/class/pwm/pwmchip0/pwm0/duty_cycle"
#define PWM0Enable "/sys/class/pwm/pwmchip0/pwm0/enable"


using namespace std;


namespace BBB{
	void led_on(string);
	void led_off(string);

	int prepGPIO(int,string,string);
	int closeGPIO(int,string);
	int writeGPIO(int,string,string);

	int readADC(string);

	int prepPWM(string,string,string,int,string,int);
	int exportPWM(string,string);
	int unexportPWM(string,string);
	int startPWM(string);
	int stopPWM(string);
	int setPWMPeriod(string,int);
	int setPWMDutycycle(string,int);
}