unsigned long myTime;
unsigned long now;
bool statusOn;
int buttonStatus;

#define BUZZER_PIN 3
#define BUTTON_PIN 4
#define LED_PIN 2

// try it on
// https://wokwi.com/projects/384488016922221569

void setup() {
  //start serial connection
  //Serial.begin(9600);

  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  now = millis();
  statusOn = false;

}

void loop() {
    //Serial.print("---");
    now = millis();
    
    //read the pushbutton value into a variable
    int buttonStatus = digitalRead(BUTTON_PIN);

    //print out the value of the time diff
    //Serial.println( myTime - now ? myTime - now : 0 );

    if ( ! buttonStatus && (now > myTime) ) {
        SingleTone();
        myTime = millis() + 10000;
    }

    if ( now < myTime && ! statusOn ) {
      statusOn = true;
      digitalWrite(LED_PIN, true );
    }

    if ( statusOn && now > myTime ) {
      statusOn = false;
      digitalWrite(LED_PIN, false );
      TrippleTone();
    }

    delay(200);

}

void SingleTone()
{
    tone(BUZZER_PIN, 1047, 250);
    delay(150);
    noTone(BUZZER_PIN);
}

void TrippleTone()
{
    tone(BUZZER_PIN, 262, 250);
    delay(200);
    tone(BUZZER_PIN, 196, 100);
    delay(200);
    tone(BUZZER_PIN, 220, 100);
    delay(200);
    noTone(BUZZER_PIN);
}