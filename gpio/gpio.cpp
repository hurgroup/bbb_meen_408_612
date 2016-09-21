#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sstream>
using namespace std;
#define MAX 64
#define GPIO "/sys/class/gpio"


FILE *LEDHandle=NULL;


//int flashGPIOLED(int,int);
int prepGPIO(int,string);
int closeGPIO(int);
int writeGPIO(int,string);

int main(){
	prepGPIO(60,"out");
	for(int i=0;i<50;i++){
		cout << i << endl;
		writeGPIO(60,"1");	
		usleep(50000);
		writeGPIO(60,"0");
		usleep(50000);
	}
	
	closeGPIO(60);
	return 0;
}

int prepGPIO(int pin,string dir){
	stringstream ss;
	string sExport;
	string sValue;
	string sDir;
	string sPin;

	ss<<GPIO<<"/export";
	sExport=ss.str();
	ss.str("");

	ss<<GPIO<<"/gpio"<<pin<<"/value";
	sValue=ss.str();
	ss.str("");

	ss<<GPIO<<"/gpio"<<pin<<"/direction";
	sDir=ss.str();
	ss.str("");

	ss<<pin;
	sPin=ss.str();
	ss.str("");

	// export 60
	if((LEDHandle=fopen(sExport.c_str(),"ab"))==NULL){
		printf("Cannot export the GPIO pin,\n");
		return 1;
	}
	//cout << sPin.c_str()<<endl;
	fwrite(sPin.c_str(),sizeof(char),2,LEDHandle);
	fclose(LEDHandle);
	usleep(10000);


	//cout <<sDir.c_str();
	// direction
	if((LEDHandle=fopen(sDir.c_str(),"rb+"))==NULL){
		printf("Cannot open direction handle.\n");
		return 1;
	}
	//dir.c_str()
	fwrite("out",sizeof(char),3,LEDHandle);
	fclose(LEDHandle);
}

int closeGPIO(int pin){
	stringstream ss;
	string sExport;
	string sPin;

	ss<<GPIO<<"/unexport";
	sExport=ss.str();
	ss.str("");

	ss<<pin;
	sPin=ss.str();
	ss.str("");

	// export 60
	if((LEDHandle=fopen(sExport.c_str(),"ab"))==NULL){
		printf("Cannot unexport the GPIO pin,\n");
		return 1;
	}
	//cout << sPin.c_str()<<endl;
	fwrite(sPin.c_str(),sizeof(char),2,LEDHandle);
	fclose(LEDHandle);
	usleep(10000);
}

int writeGPIO(int pin,string value){
	stringstream ss;
	string sValue;
	string sPin;

	ss<<GPIO<<"/gpio"<<pin<<"/value";
	sValue=ss.str();
	ss.str("");

	ss<<pin;
	sPin=ss.str();
	ss.str("");

	if((LEDHandle=fopen(sValue.c_str(),"rb+"))==NULL){
		printf("Cannot open value handle.\n");
		return 1;
	}
	fwrite(value.c_str(),sizeof(char),1,LEDHandle);
	fclose(LEDHandle);
	usleep(10000);
}

/*
int flashGPIOLED(int GPIOPin, int times)
{
	for(int i=0;i<(times*2);i++){
		if((LEDHandle=fopen(GPIOValue,"rb+"))==NULL){
			printf("Cannot open value handle.\n");
			return 1;
		}
		cout << &LEDHandle << endl;
		if(i%2==1)
			strcpy(setValue,"0");
		else 
			strcpy(setValue,"1");
		fwrite(&setValue,sizeof(char),1,LEDHandle);
		//fprintf(LEDHandle,"%d",1);
		fclose(LEDHandle);
		sleep(1);
	}

	if((LEDHandle=fopen("/sys/class/gpio/unexport","ab"))==NULL){
		printf("Cannot unexport the GPIO pin.\n");
		return 1;
	}
	strcpy(setValue,GPIOString);
	fwrite(&setValue,sizeof(char),2,LEDHandle);
	fclose(LEDHandle);

	cout << "GPIO LED Flash Pin:" << GPIOPin << " end" << endl;
	return 0;
}
*/