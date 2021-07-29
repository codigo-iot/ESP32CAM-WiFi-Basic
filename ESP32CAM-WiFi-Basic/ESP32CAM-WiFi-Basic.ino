/*
 * Conexión simple a WiFi
 * Por: Hugo Escalpelo
 * Fecha: 27 de junio de 2021
 * 
 * Este programa muestra una conexión básica a WiFi para 
 * ESP32CAM. Para ello es necesario que cambies el SSID y 
 * contraseña por los datos correspondientes a la red que 
 * deseas conectarte. Puedes observar el estado de la conexión 
 * con el monitor serial. No se requieren componentes adicionales.
 * 
 * En este programa se usan los leds soldados sobre la placa
 * ESP32CAM, el led flash y el led de status.
 * 
 * Componente     PinESP32CAM     Estados lógicos
 * ledStatus------GPIO 33---------On=>LOW, Off=>HIGH
 * ledFlash-------GPIO 4----------On=>HIGH, Off=>LOW
 */

// Bibliotecas
#include <WiFi.h>  // Biblioteca para manejar el WiFi del ESP32CAM

// Datos de Red
const char* ssid = "********";  // Pon aquí el nombre de la red a la que deseas conectarte
const char* password = "********";  // Escribe la contraseña de dicha red

// Objetos
WiFiClient espClient; // Este objeto maneja las variables necesarias para una conexion WiFi

// Variables del programa
int statusLedPin = 33;  // Esta variable controla el led de status
int flashLedPin = 4; // Esta variable controla el led flash
double timeLast, timeNow; // Variables para el control de tiempo no bloqueante
double wait = 500;  // Espera de 500 mili segundos para consultar conexión
bool statusLed = 0;// Bandera que me dice si el led esta encendido o apagado

// Inicialización del programa
void setup() {
  //Configuración de pines
  pinMode (statusLedPin, OUTPUT);// Se configura el pin como salida
  pinMode (flashLedPin, OUTPUT);// Se configura el pin como salida
  digitalWrite (statusLedPin, HIGH);// Se comienza con el led apagado
  digitalWrite (flashLedPin, LOW);// Se comienza con el led apagado

  //Inicialización de comunicación serial
  Serial.begin (115200);
  Serial.println();
  Serial.println();
  Serial.print("Conectando a ");
  Serial.println(ssid);
 
  // Iniciar el WiFi
  WiFi.begin(ssid, password); // Esta es la función que realiz la conexión a WiFi
 
  while (WiFi.status() != WL_CONNECTED) { // Este bucle espera a que se realice la conexión
    digitalWrite (statusLedPin, HIGH);
    delay(500); //dado que es de suma importancia esperar a la conexión, debe usarse espera bloqueante
    digitalWrite (statusLedPin, LOW);
    Serial.print(".");  // Indicador de progreso
    delay (5);
  }

  // Cuando se haya logrado la conexión, el programa avanzará, por lo tanto, puede informarse lo siguiente
  Serial.println();
  Serial.println("WiFi conectado");
  Serial.println("Direccion IP: ");
  Serial.println(WiFi.localIP());

  // Si se logro la conexión, encender led
  if (WiFi.status () > 0){
  digitalWrite (flashLedPin, LOW);
  }
  timeLast = millis (); // Inicia el control de tiempo
}// Fin del void setup 

//Cuerpo del programa, bucle principal
void loop() {
  timeNow = millis ();  // Seguimiento de tiempo
  if ((timeNow - timeLast > wait) && statusLed == 0){// Comprobar el encendido del flash
    digitalWrite (flashLedPin, HIGH);// Encender el flash
    statusLed = 1;//Indicar que el led flash se encuentra encendido
    timeLast = millis (); // Inicia el control de tiempo
  }
  if ((timeNow - timeLast > wait) && statusLed == 1){
    digitalWrite (flashLedPin, LOW);// Apagar Led el flash
    statusLed = 0;//Indicar que el led flash se encuentra apagado
    timeLast = millis (); // Inicia el control de tiempo
  }
}// Fin de void loop
