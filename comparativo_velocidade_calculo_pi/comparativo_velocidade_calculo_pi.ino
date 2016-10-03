#include "math.h"

unsigned long tempoDecorrido;
unsigned long inicio;

void setup() {
  Serial.begin(9600);
}
void loop() {
  inicio = millis();

  double n, i;
  double s = 1;
  double pi = 3;


  n = 100000; //quantidade de interações

  for (i = 2; i <= n * 2; i += 2) { //loop para o cálculo de PI
    pi = pi + s * (4 / (i * (i + 1) * (i + 2)));
    s = -s;
  }

  tempoDecorrido = millis(); //retorno de tempo de execução

  //  Serial.println("Placa em execucao: Arduino UNO");
  //  Serial.println("Placa em execucao: Arduino MEGA");
  //  Serial.println("Placa em execucao: Arduino DUE");
  Serial.println("Numero aproximado de PI usando a serie de Nilakantha seculo 15");
  Serial.println("Interacoes: 100000");
  Serial.print("Iniciado em: ");
  Serial.print(inicio);
  Serial.println("ms");
  Serial.print("PI = ");
  Serial.println(pi, 16);
  Serial.print("Tempo decorrido: ");
  Serial.print(tempoDecorrido);
  Serial.println("ms");

  while (true);
}




