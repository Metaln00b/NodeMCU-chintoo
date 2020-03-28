#include "chintoo.h"

float humidity = 0.0;
float temperature = 0.0;

/* Counter */
unsigned long count_s;
unsigned long last_ms;

/* Modes */
boolean wake = 0;
boolean showTemp = 0;
boolean showHum = 0;

/* RGB-LED */
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

/* Segment Display */
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

void SEGselectDigit(unsigned int digit)
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
 
void SEGselectNumber(unsigned int number)
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

void SEGdisplay(unsigned int number)
{
    SEGclear();
    SEGselectDigit(1);
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
        SEGselectNumber(number/1000);
    }
    delay(SEGfreq_ms);
  
    SEGclear();
    SEGselectDigit(2);
    if (number >= 100)
    {
        SEGselectNumber((number%1000)/100);
    }
    delay(SEGfreq_ms);

    SEGclear();
    SEGselectDigit(3);
    if (number >= 10)
    {
        SEGselectNumber((number%100)/10);
    }
    delay(SEGfreq_ms);

    SEGclear();
    SEGselectDigit(4);
    SEGselectNumber(number%10);
    delay(SEGfreq_ms);
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
    if (count_s % 4 == 0)
    {
        humidity = dht.readHumidity();
        temperature = dht.readTemperature();
    }
  
    if (isnan(humidity) || isnan(temperature))
    {
        Serial.println(F("Failed to read from DHT sensor!"));
        return;
    }

    /* Noise Sensor */
    if (digitalRead(DIGITALNOISESENSORPIN) == HIGH)
    {
        digitalWrite(NOISESENSORLEDPIN, HIGH);
        wake = 1;
        count_s = 1;
    }

    if (wake == 1 && count_s == winkDuration_s)
    {
        wake = 0;
        showTemp = 1;
    }

    if (showTemp == 1 && count_s == (winkDuration_s+5))
    {
        showTemp = 0;
        showHum = 1;
    }

    if (showHum == 1 && count_s == (winkDuration_s+10))
    {
        digitalWrite(NOISESENSORLEDPIN, LOW);
        showHum = 0;
        count_s = 1;
    }
  
    if (wake == 1)
    {
        if (humidity <= 20)
        {
            LEDred();
            SEGamazed();
        }
        if (humidity >= 21 && humidity <= 30)
        {
            LEDmagenta();
            SEGamazed();
        }
        if (humidity >= 31 && humidity <= 40)
        {
            LEDyellow();
            SEGamazed();
        }
        if (humidity >= 41 && humidity <= 60)
        {
            LEDgreen();
            SEGamazed();
        }
        if (humidity >= 61 && humidity <= 80)
        {
            LEDcyan();
            SEGamazed();
        }
        if (humidity >= 81)
        {
            LEDblue();
            SEGamazed();
        }
    }
    else if (showTemp == 1)
    {
        SEGdisplay(temperature);
    }
    else if (showHum == 1)
    {
        SEGdisplay(humidity);
    }
    else
    {
        LEDoff();
        SEGsleep();  
    }
  
    if (millis() - last_ms > 1000)
    {
        count_s++;
        last_ms = millis();

        if (wake == 1 && (count_s % 2 == 0) )
        {
            SEGwink();
            delay(winkFreq_ms);
        }
    }
}
