#include <Ethernet.h>
#include <SPI.h>
#include "RestClient.h"

RestClient client = RestClient("shrouded-inlet-53662.herokuapp.com"); //url para solicitação http

unsigned long  tempoAtual, tempoAnterior, tempoResposta = 0;
unsigned long integrador, falha, sucesso = 0;
unsigned int contador;
String resposta;

void setup() {
  Serial.begin(9600);
  Serial.println("Conectando a internet...");
  client.dhcp(); //obtendo ip dinamico da rede local
  Serial.println("Pronto para comecar!");
}

void loop() {

  for (contador = 1; contador < 11; contador++) { // loop de solicitações

    resposta = "";
    tempoAnterior = tempoAtual;

    // método responsavel pela solicitação POST via http
    int codigoDeEstatus = client.post("/aluno", "matricula=201510331826591", &resposta);

    tempoAtual = millis(); //obtenção do tempo de execução
    tempoResposta = tempoAtual - tempoAnterior; //cálculo tempo de resposta de uma solicitação

    Serial.print("Solicitacao: #");
    Serial.println(contador);

    if (codigoDeEstatus == 200) {
      sucesso++;
      integrador += tempoResposta; //somatório de tempo de resposta
      Serial.print("Resposta em: ");
      Serial.print(tempoResposta);
      Serial.println("ms");
    } else {
      falha++;
      Serial.print("Sem resposta!");
    }

  }
  Serial.println("Placa em execucao: Arduino UNO");
  //  Serial.println("Placa em execucao: Arduino MEGA");
  //  Serial.println("Placa em execucao: Arduino DUE");
  Serial.print("Sucesso: ");
  Serial.print(sucesso);
  Serial.print(" ");
  Serial.print("Falhas: ");
  Serial.println(falha);
  Serial.print("O tempo medio de resposta: ");
  Serial.print(integrador / (sucesso)); //média de tempo de resposta
  Serial.println("ms");
  while (true);


}
