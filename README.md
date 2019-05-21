# proyectoTP
Proyecto de Tecnologias de programación para 1º de Ingenieria Informática.


Comando para compilar con GCC: gcc *.c -o prueba -lSDL2 -lm -std=c99 




Enrique Rodríguez López
1º Ingeniería Informática

Tecnologías de la Programación






Índice de contenidos

Pantallas
Jugabilidad
Implementación

Pantallas

Menú
La primera pantalla que observamos nada más iniciar el juego es el menú principal, en dicho menú observamos el logotipo del videojuego y tres botones principales.


“Jugar ya”: Inicia el videojuego
“Ayuda”: Inicia la pantalla de ayuda
“Salir”: Cierra el videojuego

También podemos observar que abajo a la izquierda aparece la máxima puntuación obtenida. A la derecha podemos observar un balón y el suelo dibujados como parte decorativa de la escena, pero si mueves el ratón el balón inicia una animación y sale disparado hacía el pajaro, haciendo una referencia a las mecánicas del videojuego.









Ayuda
En la pantalla de ayuda puedes encontrar unos gráficos que explican de forma muy sencilla cómo jugar al juego, podemos encontrar tres botones:

“<” y “>”: Estos botones son para pasar a la anterior y a la próxima explicación
“Volver al menú”: Botón para volver al menú principal


Juego
Esta es la pantalla principal del videojuego, nos encontramos en un escenario donde aparece una pelota sobre un fondo de un cielo y un suelo.

Arriba a la izquierda aparece los puntos que hemos conseguido, cuál es el record actual y cuantas vidas nos quedas. También, si has logrado un nuevo record te lo indica ahí.

Arriba a la derecha nos encontramos con la barra de fuerza, cuando hacemos click izquierdo e iniciamos un disparo, aparece un indicador con la fuerza con la que saldrá disparado el balón.



Post-juego
Una vez ha finalizado la partida, aparece una pantalla intermedia con información sobre cómo ha ido tu partida con datos interesantes, una vez quieras continuar solo tienes que pulsar “Volver al menú” y regresarás al menú para iniciar otra partida de nuevo.


Jugabilidad
La jugabilidad del juego es muy sencilla, el jugador controla una pelota que puede mover haciendo lanzamientos parabólicos.

El objetivo del jugador será disparar a una serie de pájaros que se irán desplazando por la pantalla de forma horizontal de derecha a izquierda.

Si has alcanzado a uno de ellos, ¡enhorabuena! acabas de sumar un punto a tu marcador, pero cuidado, que si alguno de ellos consigue cruzar toda la pantalla sin que le hayas alcanzado, te restará un punto, por lo que siempre tendrás que estar atento para alcanzar un balance positivo.

¿Parece fácil, no? No todo es tan bonito, con cierta frecuencia, unas bombas intentarán alcanzarte para quitarte vidas.

Al principio tienes 3 vidas, pero si tocas una bomba o alguna explota cerca tuyo, te quitan una vida. Cuando te quedes sin vidas, el juego terminará.

Las bombas no sólo son malas para ti, ya que si por casualidad alcanza a un pájaro este explotará y podría ayudarte… eso sí, no te sumarán puntos las muertes causadas por las bombas.

Además, cuanta más puntuación consigas, el juego se irá complicando, pues a más puntuación, la velocidad de los pájaros puede ser mayor, la frecuencia con la que aparecen las bombas o la altura a la que vuelan los pájaros...

Implementación

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




