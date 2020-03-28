/* DHT 11 */
#include <DHT.h>

#define DHTPIN                  15
#define DHTTYPE                 DHT11

DHT dht(DHTPIN, DHTTYPE);

/* RGB-LED (Common-Anode)*/
#define REDLEDPIN               21
#define GREENLEDPIN             22
#define BLUELEDPIN              23

/* Noise Sensor */
#define NOISESENSORLEDPIN       2
#define DIGITALNOISESENSORPIN   13
#define ANALOGNOISESENSORPIN    36

/* SH5461AS (Choosing: DIGIT=LOW SEGMENT=HIGH) */
const unsigned int a = 14;
const unsigned int b = 33;
const unsigned int c = 5;
const unsigned int d = 16;
const unsigned int e = 4;
const unsigned int f = 27;
const unsigned int g = 18;
const unsigned int d1 = 12;
const unsigned int d2 = 26;
const unsigned int d3 = 25;
const unsigned int d4 = 19;
const unsigned int p = 17;
const unsigned int SEGfreq_ms = 2;
const unsigned int winkFreq_ms = 70;
const unsigned int winkDuration_s = 30;
