void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(0, OUTPUT);
pinMode(1, OUTPUT);
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    int i = 0;
    while (i < 16)
    {
        if (i % 2 == 0)  
        {
            digitalWrite(0, LOW);
        }
        else 
        {
            digitalWrite(0, HIGH);
        }
        if ((i/2) % 2 == 0)
        {
            digitalWrite(1, LOW);
        }
        else 
        {
            digitalWrite(1, HIGH);
        }
        if ((i / 4) % 2 == 0)  
        {
            digitalWrite(2, LOW);
        }
        else 
        {
            digitalWrite(2, HIGH);
        }
        if ((i / 8) % 2 == 0)
        {
            digitalWrite(3, LOW);
        }
        else 
        {
            digitalWrite(3, HIGH);
        }
        delay(1000);
        i++;
    }
}
