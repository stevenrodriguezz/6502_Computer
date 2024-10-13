const char ADDR[] = {23,25,27,29,31,33,35,37,39,41,43,45,47,49,51,53};
const char DATA[] = {52, 50, 48, 46, 44, 42, 40, 38}; 
#define CLOCK 2
#define READ_WRITE 3

void setup() {
  for(int i = 0; i < 16; i++){
    pinMode( ADDR[i], INPUT );
  }
    for(int i = 0; i < 8; i++){
    pinMode( DATA[i], INPUT );
  }
  pinMode(CLOCK, INPUT);
  pinMode(READ_WRITE, INPUT);
  attachInterrupt(digitalPinToInterrupt(CLOCK), onClock, RISING); 
  Serial.begin(9600);
}

void onClock(){
  char output[15]; 

  unsigned int address = 0; 
  for(int i = 0; i < 16; i++){
    int bit = digitalRead(ADDR[i]);
    Serial.print(bit);
    address = (address << 1) + bit; 
  }
Serial.print(" ");

unsigned int data = 0;
 for(int i = 0; i < 8; i++){
    int bit = digitalRead(DATA[i]);
    Serial.print(bit);
    data = (data << 1) + bit; 
  }

  sprintf(output, " %04x %c %02x", address, digitalRead(READ_WRITE) ? 'r' : 'w', data);
  Serial.println(output); 
}

void loop() {
}
