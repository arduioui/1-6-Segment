const int buttonPin = 2;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status

int DP = 4;
int C = 5;
int B = 6;
int A = 7;
int F = 8;
int G = 9;
int E = 10;
int D = 11;

int j = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(DP, OUTPUT);
  
  pinMode(buttonPin, INPUT);
  j = 9;
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    lolclear();
    j--;
  }
  if (j<0)
    j = 9;
  showNumber(j);
  delay(500);
}

void show1() {
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

void show2() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(D, HIGH);
}

void show3() {
  show1();
  digitalWrite(A, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(D, HIGH);
}

void show4() {
  show1();
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void show5() {
  digitalWrite(A, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
}

void show6() {
  show5();
  digitalWrite(E, HIGH);
}

void show7() {
  show1();
  digitalWrite(A, HIGH);
}

void show8() {
  show6();
  digitalWrite(B, HIGH);
}

void show9() {
  show3();
  digitalWrite(F, HIGH);
}

void show0() {
  show8();
  digitalWrite(G, LOW);
}

void showPoint() {
  digitalWrite(DP, HIGH);
}

void lolclear() {
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(DP, LOW);
}

void showNumber(int i) {
  switch (i) {
    case 1:
      show1();
    break;
    case 2:
      show2();
    break;
    case 3:
      show3();
    break;
    case 4:
      show4();
    break;
    case 5:
      show5();
    break;
    case 6:
      show6();
    break;
    case 7:
      show7();
    break;
    case 8:
      show8();
    break;
    case 9:
      show9();
    break;
    case 0:
      show0();
    break;
    default:
      showPoint();
    break;
  }
}
