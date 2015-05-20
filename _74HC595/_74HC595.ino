int SER_Pin = 11;     // pin 14 sur le 75HC595
int RCLK_Pin = 12;    // pin 12 sur le 75HC595
int SRCLK_Pin = 8;  // pin 11 sur le 75HC595

int DP = 0;
int G = 1;
int F = 2;
int E = 3;
int D = 4;
int C = 5;
int A = 6;
int B = 7;

// Combien combinez-vous de 74HC595 ? Ne pas toucher si 1 seul
#define number_of_74hc595s 1
// Ne pas toucher
#define numOfRegisterPins number_of_74hc595s * 8
int registers[numOfRegisterPins];

// Place tous les pins du 74HC595  l'etat "OFF"
void clearRegisters() {
  for (int i = numOfRegisterPins - 1; i >= 0; i--) {
    registers[i] = LOW;
  }
}

// Enregistrer et afficher les valeurs dans le registre
// Executer uniquement APRES que toutes les valeurs aient ete programmees
void writeRegisters() {
  digitalWrite(RCLK_Pin, LOW);
  for(int i = numOfRegisterPins - 1; i >= 0; i--) {
    digitalWrite(SRCLK_Pin, LOW);
    int val = registers[i];
    digitalWrite(SER_Pin, val);
    digitalWrite(SRCLK_Pin, HIGH);
  }
  digitalWrite(RCLK_Pin, HIGH);
}

// Place un pin du 74HC595 a l'etat HAUT ou BAS
void setRegisterPin(int index, int value) {
  registers[index] = value;
}

void setNumber(int num) {
  switch (num) {
    case 1:
    set1();
    break;    
    case 2:
    set2();
    break;
    case 3:
    set3();
    break;
    case 4:
    set4();
    break;
    case 5:
    set5();
    break;
    case 6:
    set6();
    break;
    case 7:
    set7();
    break;
    case 8:
    set8();
    break;
    case 9:
    set9();
    break;
    case 0:
    set0();
    break;
    default:
    setPoint();
  }
}

void set1() {
  setRegisterPin(B,HIGH);
  setRegisterPin(C,HIGH);
}

void set2() {
  setRegisterPin(A,HIGH);
  setRegisterPin(B,HIGH);
  setRegisterPin(G,HIGH);
  setRegisterPin(E,HIGH);
  setRegisterPin(D,HIGH);
}

void set3() {
  set1();
  setRegisterPin(A,HIGH);
  setRegisterPin(G,HIGH);
  setRegisterPin(D,HIGH);
}

void set4() {
  set1();
  setRegisterPin(F,HIGH);
  setRegisterPin(G,HIGH);
}

void set5() {
  setRegisterPin(A,HIGH);
  setRegisterPin(F,HIGH);
  setRegisterPin(G,HIGH);
  setRegisterPin(C,HIGH);
  setRegisterPin(D,HIGH);
}

void set6() {
  set5();
  setRegisterPin(E, HIGH);
}

void set7() {
  set1();
  setRegisterPin(A, HIGH);
}

void set8() {
  set6();
  setRegisterPin(B, HIGH);
}

void set9() {
  set8();
  setRegisterPin(E, LOW);
}

void set0() {
  set8();
  setRegisterPin(G, LOW);
}

void setPoint() {
  setRegisterPin(DP, HIGH);
}

void setup() {
  // setup code here, to run once:
  pinMode(SER_Pin, OUTPUT);
  pinMode(RCLK_Pin, OUTPUT);
  pinMode(SRCLK_Pin, OUTPUT);
  
  // Reset tous les pins du 74HC595
  clearRegisters();
  writeRegisters();
}

int j = 0;

void loop() {
  // main code here, to run repeatedly:
  setNumber(j);
  writeRegisters(); // Doit etre execute pour appliquer les changements
  // Executer seulement une fois que toutes les valeurs ont ete enregistrees
  delay(500);
  clearRegisters();
  j++;
  if (j>10)
    j = 0;
}
