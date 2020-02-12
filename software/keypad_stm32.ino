#include <Keypad.h>
#include <HardwareSerial.h>

HardwareSerial Serial1(D1,D0);

const byte numROWS = 4;
const byte numCOLS = 3;

char keys[numROWS][numCOLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[numROWS] = {A1,A6,A5,A3};//{7, 2, 3, 5};  
byte colPins[numCOLS] = {A2,A0,A4};//{6, 8, 4}; 

Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, numROWS, numCOLS );

void setup() {
  Serial1.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(D12, OUTPUT); // Red Light
  pinMode(D11, OUTPUT);
  pinMode(D10, OUTPUT);
  Serial1.println("Press 4 to demo correct input");
};



void loop() {

  char key = myKeypad.getKey();
  
  if (key != NO_KEY){
    Serial1.print("Key Pressed: ");
    Serial1.println(key);

    switch(key){

      case '4':
        digitalWrite(D12, HIGH);
        digitalWrite(D11, HIGH);
        //tone(D10,450);
        digitalWrite(D10, HIGH);
        break;

      case '5':
        digitalWrite(D12, LOW);
        digitalWrite(D11, LOW);
        digitalWrite(D10,LOW);
        //noTone(D10);
        break;
    }

  } 

}
