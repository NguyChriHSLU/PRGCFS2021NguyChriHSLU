#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


// declare a struct, matching the dataframe
struct DataFrame {
	long long timeStamp;
 	int pressure;
 	char systemState;
 	char alarmState;
};

long long timeStamp_value;
int pressure_value;
char systemState_value;
char alarmState_value;
int ms;
char mschar[10];

int main()
{
	FILE *bin = fopen("pressureSpike.bin", "rb");
	FILE *csv = fopen("pressureSpike.csv", "w");
	// check if file opening worked
	if( bin != NULL )
	{
		// prepare a buffer of correct length
		const int BYTES_IN_LINE = 14;
		unsigned char lineBuffer[BYTES_IN_LINE]; 
		fprintf(csv,"Time Stamp, Pressure [Pa], SystemState, Alarm State \n");
		// read dataframe by dataframe 
		while( fread(lineBuffer,BYTES_IN_LINE, 1, bin) )
		{
			
			timeStamp_value = ((struct DataFrame *)lineBuffer)->timeStamp;
			
			ms = timeStamp_value % 1000;
			
			
			sprintf(mschar,"%d",ms);
			
			
			time_t rawtime = timeStamp_value / 1000;//to sec
			
			struct tm ts;
			
			char buff[100];
			char timezone[10];
			
			ts = *localtime(&rawtime);
			
			strftime(buff, sizeof buff, "%a %Y-%m-%d %H:%M:%S.", &ts);
			strftime(timezone, sizeof timezone, " %Z", &ts);
			
			
			
			pressure_value = ((struct DataFrame *)lineBuffer)->pressure;
			
			systemState_value = ((struct DataFrame *)lineBuffer)->systemState;
			
			alarmState_value = ((struct DataFrame *)lineBuffer)->alarmState;
			
			strcat(buff, mschar);
			strcat(buff, timezone);
			
			
			// the trick here is to pretend each line is a copy of a dataframe
			// --> casting the "lineBuffer" to a pointer to the struct --> each field accessible directly!
		
			printf("time: %s, ", buff);
			printf("pressure: %d, ", pressure_value);
			printf("System State: %d, ", systemState_value);
			printf("Alarm State: %d\n", alarmState_value);
			
			
			fprintf(csv,"%s,%d,%d,%d\n",buff,pressure_value,systemState_value,alarmState_value);
			
			
		}

	
	}


	return 0;
}
