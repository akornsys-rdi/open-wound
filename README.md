# open-wound #

                                                      _ 
         ___ _ __  ___ _ _   __ __ _____ _  _ _ _  __| |
        / _ \ '_ \/ -_) ' \  \ V  V / _ \ || | ' \/ _` |
        \___/ .__/\___|_||_|  \_/\_/\___/\_,_|_||_\__,_|
            |_|                                         

open wound, the system behind the [CUT artwork](http://arturomoyavillen.com/cut).

## ChangeLog  ##

-   Cambios generales:  
    *   Ahora open wound está bajo licencia GPLv3.  
    *   Open wound usa [versionamiento semántico](http://semver.org).  
-   Esclavos version 1.0.0:  
    *   Cambios menores en PCB.  
    *   El microcontrolador pasa a ser parte de la placa, no un módulo Arduino.  
    *   Los pines sin usar son salidas a nivel bajo no conectadas en lugar de entradas a masa.  
    *   Se añade un conector AVRISP de seis pines.  
    *   Se añade un conector de debug.  
    *   Placa diseñada en SMT..  
    *   Mejorado el método de conexión a la plancha sensora.  
    *   Ahora se usan conectores subminiatura con enclavamiento para su conexión.  
-   Maestro en versión 1.0.0-alpha:  
    *   El maestro ahora dispone de catorce canales para esclavos.  
    *   Se permiten cuatro canales para PIR compatibles con los esclavos.  
    *   Cambiado el CI amplificador.  
    *   Entrada de audio compacta medianteconector DA15F.  
    *   Buffer digital trigger-schmitt para acondicionar la señar de los esclavos.  
    *   Usa los propios LED del RJ45 para indicar conexión y dato entrante.  
    *   Ahora usa [FreeCanvas](https://github.com/synusia/freecanvas).

