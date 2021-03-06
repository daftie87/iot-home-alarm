const int armed_signal_pin = 2;
const int alarm_signal_pin = 4;
const int sensor_input_pin = 21;

void setup() {
  pinMode(armed_signal_pin, OUTPUT);
  pinMode(alarm_signal_pin, OUTPUT);
  pinMode(sensor_input_pin, INPUT);
}

void loop() {
  // Determine if doors are open
  int door_opened = abs(1 - digitalRead(sensor_input_pin));
  
  // Control alarm led
  digitalWrite(alarm_signal_pin, door_opened);  
  
  // Blink armed signal led
  digitalWrite(armed_signal_pin, HIGH);
  delay(100);
  digitalWrite(armed_signal_pin, LOW);
  delay(100);
}
