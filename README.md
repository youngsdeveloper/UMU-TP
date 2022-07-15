![Logo Maldito Pajaro](./docs/images/logo.png)

# MalditoPajaro
Proyecto de Tecnologias de programación para 1º de Ingenieria Informática.

Se trata de un videojuego simple en el que tienes que alanzar a una serie de pajaros utilizando una pelota.

El movimiento de la pelota se basa en el movimiento parabolico.

Cuidado con las bombas, si te alcanzan, te restarán vidas.

![Gameplay](./docs/images/gameplay.gif)


# Requisitos

Para la instalacion de este juego es necesario tener instalado la libreria de SDL.

```console
enrique@pc:~$ sudo apt-get install libsdl2-dev
```


# Compilar

Para compilar solo tendrás que hacer "make", ya que está disponible el Makefile.

Una vez compilado, podrás ejecutar el juego sin problemas.

```console
enrique@pc:~$ make
enrique@pc:~$ ./MalditoPajaro
```


# Jugabilidad
La jugabilidad del juego es muy sencilla, el jugador controla una pelota que puede mover haciendo lanzamientos parabólicos.

El objetivo del jugador será disparar a una serie de pájaros que se irán desplazando por la pantalla de forma horizontal de derecha a izquierda.

Si has alcanzado a uno de ellos, ¡enhorabuena! acabas de sumar un punto a tu marcador, pero cuidado, que si alguno de ellos consigue cruzar toda la pantalla sin que le hayas alcanzado, te restará un punto, por lo que siempre tendrás que estar atento para alcanzar un balance positivo.

¿Parece fácil, no? No todo es tan bonito, con cierta frecuencia, unas bombas intentarán alcanzarte para quitarte vidas.

Al principio tienes 3 vidas, pero si tocas una bomba o alguna explota cerca tuyo, te quitan una vida. Cuando te quedes sin vidas, el juego terminará.

Las bombas no sólo son malas para ti, ya que si por casualidad alcanza a un pájaro este explotará y podría ayudarte… eso sí, no te sumarán puntos las muertes causadas por las bombas.

Además, cuanta más puntuación consigas, el juego se irá complicando, pues a más puntuación, la velocidad de los pájaros puede ser mayor, la frecuencia con la que aparecen las bombas o la altura a la que vuelan los pájaros...

# Implementación

Para implementar este juego, se ha utilizado varios modelos de datos:

1. Jugador
	
Guarda la información básica del jugador, además de información sobre la partida, como por ejemplo la puntuación conseguida.

2. Enemigo

Guarda la información básica del enemigo

3. Ejercicio

Se trata de un TDA que almacena el conjunto de enemigos, está implementada con memoria contigua.

Cómo se van generando y eliminando enemigos simultáneamente, era una buena idea utilizar memoria contigua ya que en ningún momento se iba a superar los 12 enemigos simultáneamente.

4. Bombas

Guarda la información básica de la bomba

5. Ráfaga de Bombas

Se trata de un TDA que almacena el conjunto de enemigos, está implementada con estructuras enlazadas.




