#include <NewPing.h>

#define TRIGGER_PIN 9
#define ECHO_PIN 8
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
float duration, distance, threshold;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  threshold = 150;
  while (!Serial) {
  }
}


void loop() {
  // put your main code here, to run repeatedly:
  delay(50); // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  duration = sonar.ping();
  distance = (duration / 2) * 0.0343;
  //Serial.print("Distance = ");
  //Serial.print(distance); // Distance will be 0 when out of set max range.
  if (distance < threshold && distance != 0.0){
	Serial.println("met");
  Serial.println(distance);
	delay(2000);
 
  }
  Serial.println(distance);
}
