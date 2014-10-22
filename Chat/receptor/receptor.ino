    //Prueba y transmision de texto con el modulo RF para Arduino http://zygzax.com
    //RECEPTOR
    #include <VirtualWire.h>
     
    String mensaje="";
    void setup()
    {
        Serial.begin(9600);          // Configuramos la conexion serie con el ordenador
        vw_set_ptt_inverted(true);  // Requerido por el modulo RF
        vw_setup(2000);            // Velocidad de conexion bps
        vw_set_rx_pin(3);         // Pin en el que conectamos la patilla data del receptor
        vw_rx_start();           // Arrancamos el receptor
    }
     
    void loop()
    {
      uint8_t buf[VW_MAX_MESSAGE_LEN];
      uint8_t buflen = VW_MAX_MESSAGE_LEN;
      if (vw_get_message(buf, &buflen))      // Comprobamos si hemos recibido datos
      {
        int i;
        // Mensaje con un chequeo correcto.    
        for (i = 0; i < buflen; i++)
        {
             mensaje+=Serial.write(buf[i]);  // Los datos recibidos son guardados en el buffer
                                // y enviados por el puerto serie al ordenador
        }
        Serial.println(mensaje);
        mensaje="";
      }
    }
