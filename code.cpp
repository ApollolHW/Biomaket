

// codigo deve, com um arduino ligar 4 leds em paralelo
// ao acionar um botao, fazendo um efeito de onda, esperar 1s e voltar
  int output[4] = {13,12,14,27};
void setup()
{
  for (int i = 0; i < 4; i++){
  	pinMode(output[i], OUTPUT);
  }
  pinMode(4,INPUT_PULLUP);
  Serial.begin(11500);

}

void monitor()
{
Serial.println(digitalRead(4));
delay(30);
}

bool estado;
bool estadoanterior;
int botao = 4;

void onda()
{
if (estado != estadoanterior && estado==1){
  for (int i = 0; i < 4; i++){
  	digitalWrite(output[i], 1);
    delay(250);
  }
	delay(1000);
      for (int i = 3; i >= 0; i--){
  	digitalWrite(output[i], 0);
    delay(250);
  }
  }

}

void loop(){
  monitor();
  estado = digitalRead(botao);
  delay(100);
onda();
onda();
onda();
  
  estadoanterior = estado;
}
  
  
