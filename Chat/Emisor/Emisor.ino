    //Prueba y transmision de texto con el modulo RF para Arduino http://zygzax.com
    //TRANSMISOR
    #include <VirtualWire.h>
    int i=0;
    void setup()
    {
        vw_set_ptt_inverted(true);  // Requerido por el modulo RF
        vw_setup(2000);            // Velocidad de conexion bps
        vw_set_tx_pin(3);         // Pin en el que conectamos la patilla data del transmisor
    }
     
    void loop()
    {
       //Mensaje a enviar:
       while(Serial.available() > 0){
         const char *msg = "Serial.read()";
         vw_send((uint8_t *)msg, strlen(msg));
         vw_wait_tx();        // Esperamos a que termine de enviar el mensaje
         delay(200);         // Esperamos para enviar el siguiente mensaje                
       }
    }
