#ifndef EEMEM_H
#define EEMEM_H

#include <Arduino.h>

struct eeSet // EEPROM backed data
{
  uint16_t size;          // if size changes, use defaults
  uint16_t sum;           // if sum is different from memory struct, write
  char     szSSID[32];
  char     szSSIDPassword[64];
  uint16_t coolTemp[2]; // cool to temp *10 low/high
  uint16_t heatTemp[2]; // heat to temp *10 low/high
  int16_t  cycleThresh[2]; // temp range for cycle *10
  uint8_t  Mode;        // Off, Cool, Heat, Auto
  uint8_t  eHeatThresh; // degree threshold to switch to gas
  uint16_t cycleMin;    // min time to run
  uint16_t cycleMax;    // max time to run
  uint16_t idleMin;     // min time to not run
  uint16_t filterMinutes; // resettable minutes run timer (200 hours is standard change interval)
  uint16_t fanPostDelay[2]; // delay to run auto fan after [hp/cool] stops
  uint16_t fanPreTime[2]; // fan pre-run before [cool/heat]
  uint16_t overrideTime; // time used for an override
  uint8_t  heatMode;    // heating mode (gas, electric)
  int8_t   tz;          // current timezone and DST
  int8_t   adj;         // temp offset adjust
  uint8_t  humidMode;   // Humidifier modes
  uint16_t rhLevel[2];  // rh low/high
  int16_t  awayDelta[2]; // temp offset in away mode[cool][heat]
  uint16_t awayTime;    // time limit for away offset (in minutes)
  uint16_t fanCycleTime; // for user fan cycles
  unsigned long hostIp;
  uint16_t  hostPort;
  char     zipCode[8];  // Your zipcode
  char     password[32];
  bool     bLock;
  bool     bNotLocalFcst; // Use weather.gov server
  uint16_t ppkwh;
  uint16_t ccf;
  uint8_t  fcRange; // number in forecasts (3 hours)
  uint8_t  fcDisplay; // number in forecasts (3 hours)
  float    fCostE[12];        // cost total (elec) per month
  float    fCostG[12];        // cost total (gas)
  float    fCostDay[32][2];   // cost total day (e,g)
  char     reserved2[44]; // 600 bytes
}; // 728

extern eeSet ee;

class eeMem
{
public:
  eeMem();
  void update(void);
  bool check(void);
private:
  uint16_t Fletcher16( uint8_t* data, int count);
};

extern eeMem eemem;

#endif // EEMEM_H
