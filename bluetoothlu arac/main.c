/* Bluetooth Kontrollü Araç */ //ARDUİNO ICIN
const int sol_enable = 11;  // ENABLE A
const int sag_ileri = 10;   // INPUT 1
const int sag_geri = 9;     // INPUT 2
const int sol_ileri = 8;    // INPUT 3
const int sol_geri = 7;     // INPUT 4
const int sag_enable = 6;   // ENABLE B

void setup() {
  pinMode(sag_ileri, OUTPUT);
  pinMode(sag_geri, OUTPUT);
  pinMode(sol_ileri, OUTPUT);
  pinMode(sol_geri, OUTPUT);
  pinMode(sag_enable, OUTPUT);
  pinMode(sol_enable, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char gelen_veri = Serial.read();

    if (gelen_veri == 'F') { // gelen_veri 'F' ise
      /* araç ileri gitsin */
      digitalWrite(sag_ileri, HIGH);
      digitalWrite(sag_geri, LOW);
      digitalWrite(sol_ileri, HIGH);
      digitalWrite(sol_geri, LOW);
      analogWrite(sag_enable, 255); // motor hýzlarý 255 PWM
      analogWrite(sol_enable, 255);
    }
    else if (gelen_veri == 'B') { // gelen_veri 'B' ise
      /* araç geri gitsin */
      digitalWrite(sag_ileri, LOW);
      digitalWrite(sag_geri, HIGH);
      digitalWrite(sol_ileri, LOW);
      digitalWrite(sol_geri, HIGH);
      analogWrite(sag_enable, 255); // motor hýzlarý 255 PWM
      analogWrite(sol_enable, 255);
    }
    else if (gelen_veri == 'R') { // gelen_veri 'R' ise
      /* araç saða dönsün */
      digitalWrite(sag_ileri, LOW);
      digitalWrite(sag_geri, HIGH);
      digitalWrite(sol_ileri, HIGH);
      digitalWrite(sol_geri, LOW);
      analogWrite(sag_enable, 255); // motor hýzlarý 255 PWM
      analogWrite(sol_enable, 255);
    }
    else if (gelen_veri == 'L') { // gelen_veri 'L' ise
      /* araç sola dönsün */
      digitalWrite(sag_ileri, HIGH);
      digitalWrite(sag_geri, LOW);
      digitalWrite(sol_ileri, LOW);
      digitalWrite(sol_geri, HIGH);
      analogWrite(sag_enable, 255); // motor hýzlarý 255 PWM
      analogWrite(sol_enable, 255);
    }
    else if (gelen_veri == 'S') { // gelen_veri 'S' ise
      /* araç dursun */
      digitalWrite(sag_ileri, LOW);
      digitalWrite(sag_geri, LOW);
      digitalWrite(sol_ileri, LOW);
      digitalWrite(sol_geri, LOW);
      analogWrite(sag_enable, 0); // motor hýzlarý 0 PWM (durdu)
      analogWrite(sol_enable, 0);
    }
  }
}
