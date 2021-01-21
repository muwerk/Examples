#include "platform.h"
#include "scheduler.h"
#include "net.h"
#include "mqtt.h"
#include "ota.h"

#include "console.h"
#include "led.h"
//#include "switch.h"

void appLoop();

ustd::Scheduler sched(10, 16, 32);
ustd::SerialConsole con;
ustd::Net net(LED_BUILTIN);
ustd::Mqtt mqtt;
ustd::Ota ota;

ustd::Led led1("myLed1", 12, false, 0);
ustd::Led led2("myLed2", 27, false, 1);
ustd::Led led3("myLed3", 33, false, 2);
ustd::Led led4("myLed4", 15, false, 3);

void setup() {
#ifdef USE_SERIAL_DBG
    Serial.begin(115200);
#endif  // USE_SERIAL_DBG
    con.begin(&sched);
    net.begin(&sched);
    mqtt.begin(&sched);
    ota.begin(&sched);
    /*int tID = */ sched.add(appLoop, "main", 1000000);
    led1.begin(&sched);
    led2.begin(&sched);
    led3.begin(&sched);
    led4.begin(&sched);

    // generate software phase
    led1.setMode(ustd::Led::Mode::Wave, 2000, 0.0);
    // led1.setMinMaxWaveBrightness(0.02, 0.3);
    led2.setMode(ustd::Led::Mode::Wave, 2000, 0.5);
    // led2.setMinMaxWaveBrightness(0.02, 0.3);
    led3.setMode(ustd::Led::Mode::Wave, 500, 0.0);
    // led3.setMinMaxWaveBrightness(0.02, 0.3);
    led4.setMode(ustd::Led::Mode::Wave, 500, 0.5);
    // led4.setMinMaxWaveBrightness(0.02, 0.3);
}

void appLoop() {
}

// Never add code to this loop, use appLoop() instead.
void loop() {
    sched.loop();
}