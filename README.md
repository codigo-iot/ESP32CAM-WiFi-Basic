# ESP32CAM-WiFi-Basic
Este repositorio contiene el programa básico para conectar el ESP32CAM a WiFi, el control del led rojo de status para indicar la conexión a WiFi y el control del led flash de manera no bloqueante.

Puedes encontrar el curso correspondiente en:

https://edu.codigoiot.com/

### Requisitos
Para que el código de este repositorio funcione, es necesario contar con lo siguiente:

- ESP32CAM AI-Thinker
- Programador FTDI con su cable
- Ubuntu 20.04
- IDE de Arduino 1.8 o superior

### Guías
Para configurar correctamente la IDE de Arduino para trabajar con el ESP32CAM, puedes consultar el siguiente enlace.

https://edu.codigoiot.com/course/view.php?id=850

### Funcionamiento

Para observar el funcionamiento de este proyecto deberás realizar lo siguiente.

1. Carga el flow MQTT+ESP32CAM-Basic.json en NodeRed.

Podrás observar como el led rojo que se encuentra junto al botón reset del ESP32CAM se prende cuando se logra la conexión WiFi. Podrás observar cómo parpadea el Led flash.

Por: [Hugo Vargas](https://github.com/hugoescalpelo)