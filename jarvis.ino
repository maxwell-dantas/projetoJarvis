// PONTE H "A" 
int motorA_IN1 = 31;
int motorA_IN2 = 33;
int motorA_IN3 = 35;
int motorA_IN4 = 37;

// PONTE H "B" 
int motorB_IN1 = 47;
int motorB_IN2 = 49;
int motorB_IN3 = 51;
int motorB_IN4 = 53;


int motorA_ENA = 10;
int motorA_ENB = 9;

int motorB_ENA = 3;
int motorB_ENB = 2;

struct Movimentos {
  void velocidadeMax() {
    analogWrite(motorA_ENA, 255);
    analogWrite(motorA_ENB, 255);
    analogWrite(motorB_ENA, 255);
    analogWrite(motorB_ENB, 255);
  }

  void desligar() {
    // PAR DIANTEIRO
    digitalWrite(motorA_IN1, LOW);
    digitalWrite(motorA_IN2, LOW);
    digitalWrite(motorB_IN3, LOW);
    digitalWrite(motorB_IN4, LOW);

    // PAR TRASEIRO
    digitalWrite(motorA_IN3, LOW);
    digitalWrite(motorA_IN4, LOW);
    digitalWrite(motorB_IN1, LOW);
    digitalWrite(motorB_IN2, LOW);
  }

  void andarFrente(int timer) {
    // PAR DIANTEIRO
    digitalWrite(motorA_IN1, HIGH);
    digitalWrite(motorA_IN2, LOW);
    digitalWrite(motorB_IN3, LOW);
    digitalWrite(motorB_IN4, HIGH);

    // PAR TRASEIRO
    digitalWrite(motorA_IN3, LOW);
    digitalWrite(motorA_IN4, HIGH);
    digitalWrite(motorB_IN1, LOW);
    digitalWrite(motorB_IN2, HIGH);

    this->velocidadeMax();
    delay(timer);
    this->desligar();
  }

  void andarTras(int timer) {
    // PAR DIANTEIRO
    digitalWrite(motorA_IN1, LOW);
    digitalWrite(motorA_IN2, HIGH);
    digitalWrite(motorB_IN3, HIGH);
    digitalWrite(motorB_IN4, LOW);

    // PAR TRASEIRO
    digitalWrite(motorA_IN3, HIGH);
    digitalWrite(motorA_IN4, LOW);
    digitalWrite(motorB_IN1, HIGH);
    digitalWrite(motorB_IN2, LOW);

    this->velocidadeMax();
    delay(timer);
    this->desligar();
  }

  void girarDireitaFrente(int timer) {
    // RODA DA FRENTE MOTOR B
    digitalWrite(motorB_IN3, LOW);
    digitalWrite(motorB_IN4, HIGH);

    // RODA DE TRÁS MOTOR B
    digitalWrite(motorB_IN1, LOW);
    digitalWrite(motorB_IN2, HIGH);

    this->velocidadeMax();
    delay(timer);
    this->desligar();
  }

  void girarEsquerdaFrente(int timer) {
    // RODA DA FRENTE MOTOR A
    digitalWrite(motorA_IN1, HIGH);
    digitalWrite(motorA_IN2, LOW);

    // RODA DE TRÁS MOTOR A
    digitalWrite(motorA_IN3, LOW);
    digitalWrite(motorA_IN4, HIGH);

    this->velocidadeMax();
    delay(timer);
    this->desligar();
  }

  void giroPerfeitoAntiHorario(int timer) {
    // PAR DIANTEIRO
    digitalWrite(motorA_IN1, HIGH); // MOTOR A
    digitalWrite(motorA_IN2, LOW);  // MOTOR A
    digitalWrite(motorB_IN3, HIGH); // MOTOR B
    digitalWrite(motorB_IN4, LOW);  // MOTOR B

    // PAR TRASEIRO
    digitalWrite(motorA_IN3, LOW);  // MOTOR A
    digitalWrite(motorA_IN4, HIGH); // MOTOR A
    digitalWrite(motorB_IN1, HIGH); // MOTOR B
    digitalWrite(motorB_IN2, LOW);  // MOTOR B
    
    this->velocidadeMax();
    delay(timer);
    this->desligar();
  }

};


void setup() {
  // Configurando pinos das Ponte H "A" e "B" como saída
  pinMode(motorA_IN1, OUTPUT);
  pinMode(motorA_IN2, OUTPUT);
  pinMode(motorA_IN3, OUTPUT);
  pinMode(motorA_IN4, OUTPUT);

  pinMode(motorB_IN1, OUTPUT);
  pinMode(motorB_IN2, OUTPUT);
  pinMode(motorB_IN3, OUTPUT);
  pinMode(motorB_IN4, OUTPUT);

  // ENABLES MOTOR A e B
  pinMode(motorA_ENA, OUTPUT);
  pinMode(motorA_ENB, OUTPUT);
  pinMode(motorB_ENA, OUTPUT);
  pinMode(motorB_ENB, OUTPUT);

}

void loop() {
  Movimentos jarvis;
  jarvis.andarFrente(5000);
  jarvis.andarTras(5000);
  jarvis.girarDireitaFrente(5000);
  jarvis.girarEsquerdaFrente(5000);
  jarvis.giroPerfeitoAntiHorario(5000);
}