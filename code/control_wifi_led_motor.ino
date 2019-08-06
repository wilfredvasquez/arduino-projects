#include <ESP8266WiFi.h>

const char* ssid = "dlink";
const char* password = "17960559";
WiFiServer server(80);
const int pinLED = 2; 
const int pinFAN = 5;

void setup(){
  Serial.begin(9600);
  delay(10);
  pinMode(pinLED, OUTPUT);
  pinMode(pinFAN, OUTPUT);
  digitalWrite(pinLED, LOW);
  digitalWrite(pinFAN, LOW);

  Serial.println();
  Serial.println();
  Serial.print("Conectandose a red : ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password); //Conexión a la red

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi conectado");
  
  
  server.begin(); //Iniciamos el servidor
  Serial.println("Servidor Iniciado");


  Serial.println("Ingrese desde un navegador web usando la siguiente IP:");
  Serial.println(WiFi.localIP()); //Obtenemos la IP
}

void loop(){
  WiFiClient client = server.available();
  if (client) //Si hay un cliente presente
  { 
    Serial.println("Nuevo Cliente");
    
    //esperamos hasta que hayan datos disponibles
    while(!client.available()&&client.connected())
    {
      delay(1);
    }
    
    // Leemos la primera línea de la petición del cliente.
    String linea1 = client.readStringUntil('r');
    Serial.println(linea1);
    if (linea1.indexOf("setIP")>0)
    {
      client.println("HTTP/1.1 200 OK");
    }
    if (linea1.indexOf("LED=ON")>0) //Buscamos un LED=ON en la 1°Linea
    {
      digitalWrite(pinLED,HIGH);
      client.println("HTTP/1.1 200 OK");
    }
    if (linea1.indexOf("LED=OFF")>0)//Buscamos un LED=OFF en la 1°Linea
    {
      digitalWrite(pinLED,LOW);
      client.println("HTTP/1.1 200 OK");
    }
    if (linea1.indexOf("FAN=FON")>0) //Buscamos un LED=ON en la 1°Linea
    {
      digitalWrite(pinFAN,HIGH);
      client.println("HTTP/1.1 200 OK");
    }
    if (linea1.indexOf("FAN=FOFF")>0)//Buscamos un LED=OFF en la 1°Linea
    {
      digitalWrite(pinFAN,LOW);
      client.println("HTTP/1.1 200 OK");
    }
    
    client.flush(); 
                
    Serial.println("Enviando respuesta...");   
    //Encabesado http    
    delay(1);
    Serial.println("respuesta enviada");
    Serial.println();

  }
}