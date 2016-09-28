#include "bbb_util.h"

namespace BBB{

//////////////////////////////////////////////////////////////////////
/////////////////////// led //////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
	FILE *FILEHandle=NULL;

	void led_on(string LEDBrightness){
		if((FILEHandle=fopen(LEDBrightness.c_str(),"r+"))!=NULL){
				fwrite("1",sizeof(char),1,FILEHandle);
				fclose(FILEHandle);
		}
	}

	void led_off(string LEDBrightness){
		if((FILEHandle=fopen(LEDBrightness.c_str(),"r+"))!=NULL){
				fwrite("0",sizeof(char),1,FILEHandle);
				fclose(FILEHandle);
		}
	}

//////////////////////////////////////////////////////////////////////
/////////////////////// GPIO /////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

	int prepGPIO(int pin,string dir,string gpio){
		stringstream ss;
		string sExport;
		string sValue;
		string sDir;
		string sPin;

		ss<<gpio<<"/export";
		sExport=ss.str();
		ss.str("");

		ss<<gpio<<"/gpio"<<pin<<"/value";
		sValue=ss.str();
		ss.str("");

		ss<<gpio<<"/gpio"<<pin<<"/direction";
		sDir=ss.str();
		ss.str("");

		ss<<pin;
		sPin=ss.str();
		ss.str("");

	// export 60
		if((FILEHandle=fopen(sExport.c_str(),"ab"))==NULL){
			printf("Cannot export the GPIO pin,\n");
			return 1;
		}
	//cout << sPin.c_str()<<endl;
		fwrite(sPin.c_str(),sizeof(char),2,FILEHandle);
		fclose(FILEHandle);
		usleep(10000);


	//cout <<sDir.c_str();
	// direction
		if((FILEHandle=fopen(sDir.c_str(),"rb+"))==NULL){
			printf("Cannot open direction handle.\n");
			return 1;
		}
	//dir.c_str()
		fwrite("out",sizeof(char),3,FILEHandle);
		fclose(FILEHandle);
	}

	int closeGPIO(int pin,string gpio){
		stringstream ss;
		string sExport;
		string sPin;

		ss<<gpio<<"/unexport";
		sExport=ss.str();
		ss.str("");

		ss<<pin;
		sPin=ss.str();
		ss.str("");

	// export 60
		if((FILEHandle=fopen(sExport.c_str(),"ab"))==NULL){
			printf("Cannot unexport the GPIO pin,\n");	
			return 1;
		}
	//cout << sPin.c_str()<<endl;
		fwrite(sPin.c_str(),sizeof(char),2,FILEHandle);
		fclose(FILEHandle);
		usleep(10000);
	}

	int writeGPIO(int pin,string value,string gpio){
		stringstream ss;
		string sValue;
		string sPin;

		ss<<gpio<<"/gpio"<<pin<<"/value";
		sValue=ss.str();
		ss.str("");

		ss<<pin;
		sPin=ss.str();
		ss.str("");

		if((FILEHandle=fopen(sValue.c_str(),"rb+"))==NULL){
			printf("Cannot open value handle.\n");
			return 1;
		}
		fwrite(value.c_str(),sizeof(char),1,FILEHandle);
		fclose(FILEHandle);
	}



//////////////////////////////////////////////////////////////////////
/////////////////////// ADC //////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

	int readADC(string adcpin){
		char ADCVoltageRead[5]={0};
		int Voltage=0;

		if((FILEHandle=fopen(adcpin.c_str(),"r"))!=NULL){
			fread(ADCVoltageRead,sizeof(char),sizeof(ADCVoltageRead-1),FILEHandle);
			fclose(FILEHandle);
			stringstream ss(ADCVoltageRead);
			//cout << ADCVoltageRead << ", ";			
			ss >> Voltage;
		}
		return Voltage;
	}


//////////////////////////////////////////////////////////////////////
/////////////////////// PWM //////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

	int prepPWM(string pwmexport,string num, string pwmperiod,int period, string pwmdutycycle,int dutycycle){
		exportPWM(pwmexport,num);		
		setPWMDutycycle(pwmdutycycle,dutycycle);
		setPWMPeriod(pwmperiod,period);
	}

	int exportPWM(string pwmexport,string num){
		if((FILEHandle=fopen(pwmexport.c_str(),"ab"))!=NULL){
			fwrite(num.c_str(),sizeof(char),1,FILEHandle);
			fclose(FILEHandle);
		}
		usleep(100000);	
	}

	int unexportPWM(string pwmunexport,string num){
		if((FILEHandle=fopen(pwmunexport.c_str(),"ab"))!=NULL){
			fwrite(num.c_str(),sizeof(char),1,FILEHandle);
			fclose(FILEHandle);
		}
		usleep(100000);	
	}

	int startPWM(string pwmenable){
		if((FILEHandle=fopen(pwmenable.c_str(),"r+"))!=NULL){
			fwrite("1",sizeof(char),1,FILEHandle);
			fclose(FILEHandle);
		}	
	}

	int stopPWM(string pwmenable){
		if((FILEHandle=fopen(pwmenable.c_str(),"r+"))!=NULL){
			fwrite("0",sizeof(char),1,FILEHandle);
			fclose(FILEHandle);
		}	
	}
		
	int setPWMPeriod(string pwmperiod,int period){
		char period_ch[20];
		sprintf(period_ch,"%d",period);
		if((FILEHandle=fopen(pwmperiod.c_str(),"r+"))!=NULL){
			fwrite(period_ch,sizeof(char),strlen(period_ch),FILEHandle);
			fclose(FILEHandle);
		}		
	}

	int setPWMDutycycle(string pwmdutycycle,int dutycycle){
		char dutycycle_ch[20];
		sprintf(dutycycle_ch,"%d",dutycycle);
		if((FILEHandle=fopen(pwmdutycycle.c_str(),"r+"))!=NULL){
			fwrite(dutycycle_ch,sizeof(char),strlen(dutycycle_ch),FILEHandle);
			fclose(FILEHandle);
		}		
	}
}
