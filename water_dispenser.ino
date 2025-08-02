#define TRIG_PIN 9  
#define ECHO_PIN 10  
#define RELAY_PIN 7  

void setup() {
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, LOW);  // Start with water off

    Serial.begin(9600);
}

long getDistance() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH);
    return duration * 0.034 / 2;  // Convert to cm
}

void loop() {
    long distance = getDistance();
    Serial.print("Distance: ");
    Serial.println(distance);

    if (distance > 0 && distance < 10) {  // If hand is detected within 10 cm
        digitalWrite(RELAY_PIN, HIGH);  // Turn on water
        Serial.println("Water ON");
    } else {
        digitalWrite(RELAY_PIN, LOW);  // Turn off water
        Serial.println("Water OFF");
    }

    delay(500);
}
