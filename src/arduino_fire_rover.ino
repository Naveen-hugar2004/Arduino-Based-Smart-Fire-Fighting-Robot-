/*
 * FireSense Rover - Arduino Uno.
 * Educational starter code.
 * Verify all GPIO assignments with the final circuit.
 */

const int FLAME_SENSOR = 2;
const int PUMP_PIN = 8;

const int MOTOR_ENA = 5;
const int MOTOR_IN1 = 6;
const int MOTOR_IN2 = 7;

const int MOTOR_ENB = 9;
const int MOTOR_IN3 = 10;
const int MOTOR_IN4 = 11;

void setup()
{
    Serial.begin(9600);

    pinMode(FLAME_SENSOR, INPUT);
    pinMode(PUMP_PIN, OUTPUT);

    pinMode(MOTOR_ENA, OUTPUT);
    pinMode(MOTOR_IN1, OUTPUT);
    pinMode(MOTOR_IN2, OUTPUT);

    pinMode(MOTOR_ENB, OUTPUT);
    pinMode(MOTOR_IN3, OUTPUT);
    pinMode(MOTOR_IN4, OUTPUT);

    digitalWrite(PUMP_PIN, LOW);
    stopRover();

    Serial.println("FireSense Rover Ready");
}

void loop()
{
    int fireDetected = digitalRead(FLAME_SENSOR);

    if (fireDetected == HIGH)
    {
        Serial.println("Fire detected");
        moveForward();

        // Add final navigation and servo-control logic here.
        // startPump();
    }
    else
    {
        stopRover();
        digitalWrite(PUMP_PIN, LOW);
    }

    delay(200);
}

void moveForward()
{
    analogWrite(MOTOR_ENA, 180);
    analogWrite(MOTOR_ENB, 180);

    digitalWrite(MOTOR_IN1, HIGH);
    digitalWrite(MOTOR_IN2, LOW);

    digitalWrite(MOTOR_IN3, HIGH);
    digitalWrite(MOTOR_IN4, LOW);
}

void stopRover()
{
    analogWrite(MOTOR_ENA, 0);
    analogWrite(MOTOR_ENB, 0);

    digitalWrite(MOTOR_IN1, LOW);
    digitalWrite(MOTOR_IN2, LOW);

    digitalWrite(MOTOR_IN3, LOW);
    digitalWrite(MOTOR_IN4, LOW);
}

void startPump()
{
    digitalWrite(PUMP_PIN, HIGH);
}
