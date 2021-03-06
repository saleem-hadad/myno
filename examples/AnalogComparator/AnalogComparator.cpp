#include <Arduino.h>
#include <Blinky.h>
#include <AnalogComparator.h>

Blinky led;
AnalogComparator comparator;

void comparatorCallback(bool aboveThreshold)
{
    if (! aboveThreshold) { return; }

    //blink LED only if the comparatorOutput aboveThreshold
    led.refresh();
}

void setup()
{
    comparator.init(true, true); //enabled, bandgabSelected
    comparator.callback = comparatorCallback; // very important
    led.init(Pin(PortB, 0), 600, 650);
}

void loop()
{
    comparator.refresh();
}
