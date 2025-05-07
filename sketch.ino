const int ldrPin = A0;
const int ledPin = 10;
const int thresholdTerang = 800;
const int thresholdGelap = 300;

int lux;
int pwmValue;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  lux = bacaRataRataLDR(10);

  pwmValue = map(lux, 0, 1023, 0, 255);
  analogWrite(ledPin, pwmValue);
  Serial.print(" | Status: ");
  tampilkanStatusCahaya(lux);
  Serial.println();

  delay(500);
}

int bacaRataRataLDR(int jumlahBaca) {
  long total = 0;
  for (int i = 0; i < jumlahBaca; i++) {
    total += analogRead(ldrPin);
    delay(10);
  }
  return total / jumlahBaca;
}

void tampilkanStatusCahaya(int nilai) {
  if (nilai >= thresholdTerang) {
    Serial.print("Gelap");
  } else if (nilai <= thresholdGelap) {
    Serial.print("Terang");
  } else {
    Serial.print("Normal");
  }
}
