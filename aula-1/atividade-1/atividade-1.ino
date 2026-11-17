int ledRed = 2;
int ledYellow = 3;
int ledGreen = 4;
int ativado = 1;
int desativado = 0;
int segundos = 1000;
int botao = 5;
int estado = 0;
int leituraAnterior = HIGH;



void setup()
{
  Serial.begin(9600);
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
}

void loop()
{
  int leitura = digitalRead(botao);
  if(leitura == LOW && leituraAnterior == HIGH){
  estado++;
    if(estado > 2){
    estado = 0;
    }
    delay(500);
  }
  leituraAnterior = leitura;
  
  if(estado == 0){
    
  digitalWrite(ledRed, ativado);
  digitalWrite(ledYellow, desativado);
  digitalWrite(ledGreen, desativado);
  Serial.println("Vermelho");
  }
  
  if(estado == 1){
    
  digitalWrite(ledRed, desativado);
  digitalWrite(ledYellow, desativado);
  digitalWrite(ledGreen, ativado);
  Serial.println("Verde");
  }
  
  if(estado == 2){
    
  digitalWrite(ledRed, desativado);
  digitalWrite(ledYellow, ativado);
  digitalWrite(ledGreen, desativado);
  Serial.println("Amarelo");
  }
  
  
}
