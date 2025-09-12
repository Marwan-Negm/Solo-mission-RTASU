#define LED 8 
#define BUZZER 9 
float distance =100; 

void setup() { 
    pinMode(LED, OUTPUT); 
    pinMode(BUZZER, OUTPUT); 
    Serial.begin(9600); 
} 

void loop() { 
    if (Serial.available() > 0) { 
        distance = Serial.parseFloat() ; 
        if (distance <= 0) 
            distance = 100; 
        delay(1); 
    } 
    
    if(distance <= 50) { 
        digitalWrite(LED,1); 
        digitalWrite(BUZZER,1); 
        delay(distance*10); 
        digitalWrite(LED,0); 
        digitalWrite(BUZZER,0); 
        delay(distance*10); 
        if (Serial.available()>0){ 
            distance = Serial.parseFloat() ; 
            if (distance <= 0) {
                distance = 100;
            } 
            delay(1); 
        } 
    } 
    else { 
        digitalWrite(LED, LOW); 
        digitalWrite(BUZZER, LOW); 
    } 
}

