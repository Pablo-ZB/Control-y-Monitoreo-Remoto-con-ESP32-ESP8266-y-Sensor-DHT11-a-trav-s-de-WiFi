Instrucciones
-------------------------
Recursos:
------------

ESP32 o ESP8266
Sensor de temperatura y humedad DHT11
2 LEDs

Cómo Conectar:
---------------

Sensor DHT11 al pin D4
LED1 al pin D2 y LED2 al pin D5

Pasos:
-------

1. Cambia ssid y password con el nombre y la contraseña de tu red WiFi.
2. Sube el código al ESP32
3. Abre el Serial en el IDE de Arduino para ver la dirección IP del dispositivo.
4. Abre un navegador y ve a http://<IP_ADDRESS>/webserial.


Comandos en la interfaz WebSerial para controlar los LEDs:
----------------------------------------------------------

ON1: Enciende el LED en el pin D2.
OFF1: Apaga el LED en el pin D2.
ON2: Enciende el LED en el pin D5.
OFF2: Apaga el LED en el pin D5.

La temperatura y la humedad se mostrarán automáticamente cada 2 segundos en la interfaz WebSerial.

Notas:
-------
Asegurarse de que el dispositivo y el ordenador estén en la misma red WiFi.
