#include <Adafruit_EMC2101.h>

/* incoming packet structure:
 * byte 0 - 0x71
 * byte 1 - speed (0x00-0xff)
 * 
 * outgoing packet structure:
 * byte 0 - 0x7f
 * byte 1 - photoresistor value (0x00-0xff)
 * byte 2 - fan RPM divided by 50, capped at 0xff (12750rpm)
 * byte 3 - temperature in degrees c (0x00-0xff)
 */

#define POLL_FREQ_MS 63

Adafruit_EMC2101 emc;

void setup() {
    Serial.begin(115200);
    while (!Serial) delay(5);
    
    if (!emc.begin()) Serial.write(0x10);
    
    emc.setDataRate(EMC2101_RATE_16_HZ);
    emc.enableTachInput(true);
    emc.setPWMDivisor(0);
    emc.setDutyCycle(0);
    
    pinMode(A1, INPUT);
}

void loop() {
    // header
    Serial.write(0x7f);
    
    // byte 1
    uint16_t photoresistor = analogRead(A1);
    // map it to 0-255
    uint8_t photoresistorMapped = map(photoresistor, 0, 1023, 0, 255);
    Serial.write(photoresistorMapped);
    
    // byte 2
    uint8_t rpm = emc.getFanRPM() / 50;
    Serial.write(rpm);
    
    // byte 3
    uint8_t temp = emc.getExternalTemperature();
    Serial.write(temp);
    
    // check for Serial input
    if (Serial.available() >= 2) {
        uint8_t c = 0x00;
        while (c != 0x71 && Serial.available() >= 1) {
            c = Serial.read();
        }
        if (c == 0x71 && Serial.available() >= 1) {
            uint8_t speed = Serial.read();
            uint8_t speedPercent = map(speed, 0, 255, 0, 99);
            emc.setDutyCycle(speedPercent);
        }
    }
    
    delay(POLL_FREQ_MS);
}
