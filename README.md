open-wound
==========

open wound, the system behind the CUT artwork

## ChangeLog  ##

New release candidate 2

- El microcontrolador pasa a ser parte de la placa, no un módulo Arduino.
- Arreglados problemas en los esclavos.
  * Los pines sin usar son salidas a nivel bajo no conectadas en lugar de entradas a masa.
  * Se añade un conector AVRISP de seis pines.
  * Se añade un conector de debug.
  * Placa diseñada en SMT.
  * Mejorado el método de conexión a la plancha sensora.
- Numerosas mejoras en el maestro.
  * El maestro ahora dispone de catorce canales.
  * Cambiado el CI amplificador.
  * Fuente de alimentación implementada.
  * Fuente con salidas independientes.
  * Usado los propios LED del RJ45 para indicar conexión y dato entrante.
  * Actualizado el procesador a *ATMEGA1280*.
  * Conexión USB a través de *FT232*.
  * Incorporado conector AVRISP de seis pines.
  * Añadidos múltiples indicadores de estado.
  * Añadida la posibilidad de conectar varios maestros en cascada.
  * Se permiten cuatro entradas para PIR, agrupadas en pares.
  * La entrada de los PIR se considera módulo independiente.

