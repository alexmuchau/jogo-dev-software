
# **Bomberman in Terminal - C++**

Este projeto foi feito em colaboração de **Alberth Ronaldy, Alex Muchau, Gustavo Berwanger**. Para a conclusão da matéria Desenvolvimento de Software na Universidade Positivo.

O projeto conta com um jogo parecido com o Bomberman original, com inimigos aparecendo em um tempo exponencial, com inteligência para soltar as bombas e andar pelo cenário. 





## **Como Jogar**
*É necessário estar em um ambiente Linux, com o NCurses instalado.*

**Para rodar,**
* Inicialize o play.sh no terminal. *caso precise de permissão, use o comando chmod*,
* Confira se o seu tamanho do seu terminal bate com o necessário,
* Insira o seu nome,
* Agora é só diversão!

**Comandos,**
* **W, A, S, D** para andar, ou as setas,
* **E** para soltar a bomba.

Os inimigos são o caractere **B** com a coloração vermelha, já o seu bomber é um **@**. As bombas são o caractere **o**, o rastro da bomba é o **$** em amarelo. As paredes azuis são destrutíveis, e as brancas com **#** são fixas.

## **Screenshots**

![NameInput](https://github.com/alexmuchau/jogo-dev-software/blob/main/images/Image0.jpeg)
![Gameplay0](https://github.com/alexmuchau/jogo-dev-software/blob/main/images/image1.jpeg)
![Gameplay1](https://github.com/alexmuchau/jogo-dev-software/blob/main/images/image2.jpeg)
![Gameplay2](https://github.com/alexmuchau/jogo-dev-software/blob/main/images/image3.jpeg)

## **Documentação do Game**

Usamos bibliotecas externas para fazer o controle da screen e das cores. A seguir uma tabela com todas elas. *Além das bibliotecas padrão do C++.*

#### **Bibliotecas**

| Nome   | Importação
| :---------- | :---------
| `NCurses`      | `#include <ncurses.h>`
| `CTime`      | `#include <ctime>`
| `String`      | `#include <string>`
| `Chrono`      | `#include <chrono>`
| `vector`      | `#include <vector>`

