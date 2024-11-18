#include <stdio.h>
#include "pico/stdlib.h"

#define GPIO_BOTAO 5
#define GPIO_LED 11

int main(){

stdio_init_all(); //Inicializa todos os tipos stdio padrão.

// inicializa as portas digitais
gpio_init(GPIO_BOTAO);
gpio_set_dir(GPIO_BOTAO, GPIO_IN);
gpio_pull_up(GPIO_BOTAO); //Ativa o resistor de pull-up interno

gpio_init(GPIO_LED);
gpio_set_dir(GPIO_LED, GPIO_OUT);

//rotina de verificação do estado do botão:
while (true){

  if(gpio_get(GPIO_BOTAO))
  {
    gpio_put(GPIO_LED,0); //Desliga o Led.
  }
  else
  {
    gpio_put(GPIO_LED,1); //Liga o Led.
  }

  sleep_ms(200); //Atraso
}

}