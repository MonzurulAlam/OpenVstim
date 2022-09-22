// Basic sketch for setting up stimulation trigger for OpenXstim
// For any queries please contact: md.malam@connect.polyu.hk
#define Hz 20 // set your stimulation frequency
#define burst 10 // set your pulse number in the burst

//#define LOGIC_IN1 9
//#define LOGIC_IN2 10
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  //pinMode(LOGIC_IN1, OUTPUT);
  //pinMode(LOGIC_IN2, OUTPUT); 
  DDRB = B00000110; // faster pinmode operation 
}
void loop() {
  for (int i=0; i<burst; i++) {
    // positive phase
    //digitalWrite(LOGIC_IN1, LOW);
    //digitalWrite(LOGIC_IN2, HIGH);
    PORTB = B00000010; // faster digitalwrite operation
    delayMicroseconds(50);
    
    // negetive phase
    //digitalWrite(LOGIC_IN1, HIGH);    
    //digitalWrite(LOGIC_IN2, LOW);
    PORTB = B00000100;
    delayMicroseconds(50);
  }
  
  // stimulation delay
  //digitalWrite(LOGIC_IN1, LOW);    
  //digitalWrite(LOGIC_IN2, LOW);
  PORTB = B00000000;  // faster digitalwrite operation  
  delay(1000/Hz);
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); // toggle LED 
}
