const int relayPin1 = 6;  // リレー1
const int relayPin2 = 7;  // リレー2
const int ts1 = 2;        // スイッチ1
const int ts2 = 3;        // スイッチ2
const int ts3 = 4;        // スイッチ3
const int ts4 = 5;        // スイッチ4

const int blinkCount = 17;      // 点滅回数
const int blinkInterval = 300; // 点滅間隔(ms)

void setup() {
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  pinMode(ts1, INPUT_PULLUP);
  pinMode(ts2, INPUT_PULLUP);
  pinMode(ts3, INPUT_PULLUP);
  pinMode(ts4, INPUT_PULLUP); 
}

void loop() {
  // --- リレー1の制御 ---
  if (digitalRead(ts1) == LOW) {
    digitalWrite(relayPin1, LOW);

    // 点滅
    if (digitalRead(ts2) == LOW) {
      for (int i = 0; i < blinkCount; i++) {
        digitalWrite(relayPin1, HIGH);
        delay(blinkInterval);
        digitalWrite(relayPin1, LOW);
        delay(blinkInterval);
      }
    }

  } else {
    digitalWrite(relayPin1, HIGH); 
  }

  // --- リレー2の制御 ---
  if (digitalRead(ts3) == LOW) {
    digitalWrite(relayPin2, LOW); 

    // 点滅
    if (digitalRead(ts4) == LOW) {
      for (int i = 0; i < blinkCount; i++) {
        digitalWrite(relayPin2, HIGH);
        delay(blinkInterval);
        digitalWrite(relayPin2, LOW);
        delay(blinkInterval);
      }
    }

  } else {
    digitalWrite(relayPin2, HIGH);
  }
}

