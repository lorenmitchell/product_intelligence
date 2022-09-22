const int LOUD = your_loud_threshold_value_here;
const int SOFT = your_quiet_threshold_value_here;

int soundLevel;
const byte LED_PIN = 11; // PWM pin for your LED
int brightness;

void setup () {
   pinMode(LED_PIN, OUTPUT);
   brightness = 128;
   // insert microphone initialisation code here
}

void loop () {
   // insert code to read microphone level into "soundLevel"

   if (soundLevel >= LOUD) {
      brightness -= 5;
      if (brightness < 0)
          brightness = 0;
   } else if (soundLevel <= SOFT) {
      brightness += 5;
      if (brightness > 255)
         brightness = 255;
   }
   analogWrite(LED_PIN, brightness);
   delay(50); // adjust delay as desired 
}
