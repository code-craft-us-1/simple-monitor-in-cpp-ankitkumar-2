#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

const int MAX_TEMP =102;
const int MIN_TEMP= 95;
const int MAX_PULSE = 100;
const int MIN_PULSE = 60;
const int MIN_SP02 = 90;

void displayWarningPrompt()
{
for (int i = 0; i < 6; i++)
 {
  cout << "\r* " << flush;
  sleep_for(seconds(1));
  cout << "\r *" << flush;
  sleep_for(seconds(1));
} 
}

void displayWarningMessage(const char *vital)
{
  cout<< vital << "is critical\n";
  displayWarningPrompt();
}

bool isVitalOk(const char *vitals,float reading, float min, float max)
{
if(reading>max || reading < min)
{
  displayWarningMessage(vitals);
  return false;
}
return true;
}

int vitalsOk(float temperature, float pulseRate, float spo2)
 {  
  bool isTempratureOk = isVitalOk("Temprature", temperature,MIN_TEMP,MAX_TEMP);
  bool isPulseRateOk = isVitalOk("PulseRate",pulseRate,MIN_PULSE,MAX_PULSE);
  bool isSpo2Ok = isVitalOk("SPO2",spo2,MIN_SP02,NULL);
  return isTempratureOk && isPulseRateOk && isSpo2Ok;
}
