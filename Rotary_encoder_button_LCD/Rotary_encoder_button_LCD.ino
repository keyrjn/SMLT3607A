/*     Stepper Motor using a Rotary Encoder
 *     by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
 *     Modified by Keyur Jain
 */
 #include <LiquidCrystal.h> // includes the LiquidCrystal Library 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// defines pins numbers

 #define outputA 8
 #define outputB 9
 int counter = 0;
 int aState;
 int aLastState;
   
int outputC=6;
int bState=0;
int bLastState; 

int outputD=7;
int dState=0;
int dLastState;



String myArray[] = {"1_civilian","1_civilian","2_tourist","2_tourist","3_homeless person","3_homeless person","4_cat", "4_cat","5_dog","5_dog",
"6_loitrer","6_loitrer", "7_senior citizen", "7_senior citizen","8_suspicious person","8_suspicious person","9_hipster", "9_hipster", "10_delivery person", "10_delivery person"};


void setup() {
  // Sets the two pins as Outputs

    pinMode(13, OUTPUT);


  pinMode (outputA,INPUT);
  pinMode (outputB,INPUT);
     Serial.begin (9600);

  aLastState = digitalRead(outputA);
   bLastState = digitalRead(outputB);

  lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display } 
      lcd.print("Choose Class");

}
void loop() {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)

  
  aState = digitalRead(outputA);


  
  if (aState != aLastState){     
     if (digitalRead(outputB) != aState) { 
       counter ++;
     }
     else {
       counter--;

     }
     if (counter >= 20  || counter < 1 ) {
      counter =0;
     }

     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print((myArray[(counter)]));

     Serial.print("Position:");
     Serial.println(counter);
     Serial.print((myArray[(counter)]));
       
       }   
  aLastState = aState;


 bState = digitalRead(outputC);
 if (bState == HIGH && bState != bLastState) {
   Serial.println("Recording ...     ");
    lcd.clear();
    lcd.print("Recording...      ");
    delay(800);
    lcd.clear();
    lcd.print("Recorded!      ");
    delay(400);
    lcd.clear();
    delay(200);
     lcd.print((myArray[(counter)]));
     
  //  lcd.print("Position: ");
    //lcd.print(int(counter));
    lcd.setCursor(0,0);
 }

  dState = digitalRead(outputD);
 if (dState == HIGH && dState != dLastState) {
   Serial.println("Deleted!      ");
    lcd.clear();
    lcd.print("Deleted!       ");
    delay(600);
    lcd.clear();
    delay(200);
     lcd.print((myArray[(counter)]));

    lcd.setCursor(0,0);
 }

  bLastState = bState;
  dLastState = dState;
}


