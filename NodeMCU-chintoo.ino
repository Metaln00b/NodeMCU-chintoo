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
int a = 14;
int b = 33;
int c = 5;
int d = 16;
int e = 4;
int f = 27;
int g = 18;
int d1 = 12;
int d2 = 26;
int d3 = 25;
int d4 = 19;
int p = 17;
int SEGfreq = 2;
int winkFreq = 70;
int winkDuration = 30;

/* Counter */
unsigned long secondCount;
unsigned long lastSecondChangeTime;

/* Modes */
boolean wake = 0;
boolean showTemp = 0;
boolean showHum = 0;

void LEDred()
{
    digitalWrite(REDLEDPIN, LOW);
    digitalWrite(GREENLEDPIN, HIGH);
    digitalWrite(BLUELEDPIN, HIGH);
}

void LEDgreen()
{
    digitalWrite(REDLEDPIN, HIGH);
    digitalWrite(GREENLEDPIN, LOW);
    digitalWrite(BLUELEDPIN, HIGH);
}

void LEDblue()
{
    digitalWrite(REDLEDPIN, HIGH);
    digitalWrite(GREENLEDPIN, HIGH);
    digitalWrite(BLUELEDPIN, LOW);
}

void LEDcyan()
{
    digitalWrite(REDLEDPIN, HIGH);
    digitalWrite(GREENLEDPIN, LOW);
    digitalWrite(BLUELEDPIN, LOW);
}

void LEDmagenta()
{
    digitalWrite(REDLEDPIN, LOW);
    digitalWrite(GREENLEDPIN, HIGH);
    digitalWrite(BLUELEDPIN, LOW);
}

void LEDyellow()
{
    digitalWrite(REDLEDPIN, LOW);
    digitalWrite(GREENLEDPIN, LOW);
    digitalWrite(BLUELEDPIN, HIGH);
}

void LEDwhite()
{
    digitalWrite(REDLEDPIN, LOW);
    digitalWrite(GREENLEDPIN, LOW);
    digitalWrite(BLUELEDPIN, LOW);
}

void LEDoff()
{
    digitalWrite(REDLEDPIN, HIGH);
    digitalWrite(GREENLEDPIN, HIGH);
    digitalWrite(BLUELEDPIN, HIGH);
}

void SEGdigitClear()
{
    digitalWrite(d1, HIGH);
    digitalWrite(d2, HIGH);
    digitalWrite(d3, HIGH);
    digitalWrite(d4, HIGH);
}

void SEGclear()
{
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    digitalWrite(p, LOW);
}
 
void SEGzero()
{
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
}
 
void SEGone()
{
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
}
 
void SEGtwo()
{
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
}
 
void SEGthree()
{
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
}
 
void SEGfour()
{
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
}
 
void SEGfive()
{
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
}
 
void SEGsix()
{
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
}
 
void SEGseven()
{
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
}
 
void SEGeight()
{
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
}
 
void SEGnine()
{
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
}

void SEGT()
{
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
}

void SEGH()
{
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
}

void pickDigit(unsigned int digit)
{
    switch(digit)
    {
        case 1:
            digitalWrite(d1, LOW);
            digitalWrite(d2, HIGH);
            digitalWrite(d3, HIGH);
            digitalWrite(d4, HIGH);
            break;
        case 2:
            digitalWrite(d1, HIGH);
            digitalWrite(d2, LOW);
            digitalWrite(d3, HIGH);
            digitalWrite(d4, HIGH);
            break;
        case 3:
            digitalWrite(d1, HIGH);
            digitalWrite(d2, HIGH);
            digitalWrite(d3, LOW);
            digitalWrite(d4, HIGH);
            break;
        case 4:
            digitalWrite(d1, HIGH);
            digitalWrite(d2, HIGH);
            digitalWrite(d3, HIGH);
            digitalWrite(d4, LOW);
            break;
    }
}
 
void pickNumber(unsigned int number)
{
    switch(number)
    {
        case 0:
            SEGzero();
            break;
        case 1:
            SEGone();
            break;
        case 2:
            SEGtwo();
            break;
        case 3:
            SEGthree();
            break;
        case 4:
            SEGfour();
            break;
        case 5:
            SEGfive();
            break;
        case 6:
            SEGsix();
            break;
        case 7:
            SEGseven();
            break;
        case 8:
            SEGeight();
            break;
        case 9:
            SEGnine();
            break;
    }
}

void SEGnumber(unsigned int number)
{
    SEGclear();
    pickDigit(1);
    if ((showTemp == 1 || showHum == 1) && number < 1000)
    {
        if (showTemp == 1)
        {
            SEGT();
        }
        if (showHum == 1)
        {
            SEGH();
        }
        digitalWrite(p, HIGH);
    }
    if (number >= 1000)
    {
        pickNumber(number/1000);
    }
    delay(SEGfreq);
  
    SEGclear();
    pickDigit(2);
    if (number >= 100)
    {
        pickNumber((number%1000)/100);
    }
    delay(SEGfreq);

    SEGclear();
    pickDigit(3);
    if (number >= 10)
    {
        pickNumber((number%100)/10);
    }
    delay(SEGfreq);

    SEGclear();
    pickDigit(4);
    pickNumber(number%10);
    delay(SEGfreq);
}

void SEGamazed()
{
    digitalWrite(d1, LOW);
    SEGzero();
    
    digitalWrite(d4, LOW);
    SEGzero();
}

void SEGwink()
{
    digitalWrite(d1, LOW);
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
    digitalWrite(p, LOW);

    digitalWrite(d2, HIGH);
    digitalWrite(d3, HIGH);

    digitalWrite(d4, LOW);
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
    digitalWrite(p, LOW);
}

void SEGsleep()
{
    digitalWrite(d1, LOW);
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);

    digitalWrite(d2, HIGH);
    digitalWrite(d3, HIGH);

    digitalWrite(d4, LOW);
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
}

void setup() {
    Serial.begin(9600);
  
    /* RGB-LED (Common-Anode)*/
    pinMode(REDLEDPIN, OUTPUT);
    pinMode(GREENLEDPIN, OUTPUT);
    pinMode(BLUELEDPIN, OUTPUT);
    digitalWrite(REDLEDPIN, HIGH); 
    digitalWrite(GREENLEDPIN, HIGH);
    digitalWrite(BLUELEDPIN, HIGH);
  
    /* SH5461AS (Choosing: DIGIT=LOW SEGMENT=HIGH) */
    pinMode(d1, OUTPUT);
    pinMode(d2, OUTPUT);
    pinMode(d3, OUTPUT);
    pinMode(d4, OUTPUT);
    pinMode(a, OUTPUT);
    pinMode(b, OUTPUT);
    pinMode(c, OUTPUT);
    pinMode(d, OUTPUT);
    pinMode(e, OUTPUT);
    pinMode(f, OUTPUT);
    pinMode(g, OUTPUT);
    pinMode(p, OUTPUT);
    digitalWrite(d1, HIGH);
    digitalWrite(d2, HIGH);
    digitalWrite(d3, HIGH);
    digitalWrite(d4, HIGH);
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    digitalWrite(p, LOW);
  
    /* DHT11 */
    dht.begin();
  
    /* Noise Sensor */
    pinMode(NOISESENSORLEDPIN, OUTPUT);
    pinMode(DIGITALNOISESENSORPIN, INPUT);
    pinMode(ANALOGNOISESENSORPIN, INPUT);
    digitalWrite(NOISESENSORLEDPIN, LOW);
}

void loop() {
    /* DHT11 */
    float h = dht.readHumidity();
    float t = dht.readTemperature();
  
    if (isnan(h) || isnan(t))
    {
        Serial.println(F("Failed to read from DHT sensor!"));
        return;
    }

#if 0
    float hic = dht.computeHeatIndex(t, h, false); /* More precise */
    Serial.print(F("Humidity: "));
    Serial.print(h);
    Serial.println(F("%"));
    Serial.print(F("Temperature: "));
    Serial.print(t);
    Serial.print(F("°C "));
  
    Serial.print(hic);
    Serial.println(F("°C"));
#endif

    /* Noise Sensor */
    if (digitalRead(DIGITALNOISESENSORPIN) == HIGH)
    {
        digitalWrite(NOISESENSORLEDPIN, HIGH);
        wake = 1;
        secondCount = 1;
    }

    if (wake == 1 && secondCount == winkDuration)
    {
        wake = 0;
        showTemp = 1;
    }

    if (showTemp == 1 && secondCount == (winkDuration+5))
    {
        showTemp = 0;
        showHum = 1;
    }

    if (showHum == 1 && secondCount == (winkDuration+10))
    {
        digitalWrite(NOISESENSORLEDPIN, LOW);
        showHum = 0;
        secondCount = 1;
    }
  
    if (wake == 1)
    {
        if (h < 20)
        {
            LEDred();
            SEGamazed();
        }
        if (h >= 20 && h < 40)
        {
            LEDmagenta();
            SEGamazed();
        }
        if (h >= 40 && h < 60)
        {
            LEDyellow();
            SEGamazed();
        }
        if (h >= 60 && h < 80)
        {
            LEDgreen();
            SEGamazed();
        }
        if (h >= 80 && h < 90)
        {
            LEDcyan();
            SEGamazed();
        }
        if (h >= 90)
        {
            LEDblue();
            SEGamazed();
        }
    }
    else if (showTemp == 1)
    {
        SEGnumber(t);
    }
    else if (showHum == 1)
    {
        SEGnumber(h);
    }
    else
    {
        LEDoff();
        SEGsleep();  
    }
  
    if (millis() - lastSecondChangeTime > 1000)
    {
        secondCount++;
        lastSecondChangeTime = millis();

        if (wake == 1 && (secondCount % 2 == 0) )
        {
            SEGwink();
            delay(winkFreq);
        }
    }
}
