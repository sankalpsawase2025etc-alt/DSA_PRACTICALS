#define RXD2 16
#define TXD2 17

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
  Serial.println("UART loop back test started.");
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial2.println("Hello,UART");
  delay(200);
  while(Serial2.available()){
    String msg = Serial2.readStringUntil('\n');
    Serial.print("Recieved:");
    Serial.println(msg);
  }
  delay(1000); // this speeds up the simulation
}
