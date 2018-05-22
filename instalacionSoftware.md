# Instalación del software:

## Windows 7, Windows 10
1. Ejecutar Windows Update antes de iniciar la instalación.
2. Descargar e instalar [Atmel Studio 7](http://www.microchip.com/mplab/avr-support/atmel-studio-7), preferentemente usando el instalador _web_. 
3. Descargar [Codevision AVR](http://www.hpinfotech.ro/cvavreval.zip).
4. Descomprimir el archivo descargado `cvavreval.zip` e iniciar el instalador `CodeVisionAVR.msi`
5. En tal caso de que CodeVisionAVR no inicie, puede ser problema del Antivirus instalado. Cheque la siguiente [información](http://www.hpinfotech.ro/cvavr_download.html#wb_Text1).
6. Descargar el controlador [Zadig](http://zadig.akeo.ie/downloads/zadig-2.3.exe) de la tarjeta Usbasp.
7. Inserte la tarjeta Usbasp al puerto USB de la computadora.
8. Ejecute el archivo descargado `zadig-2.3.exe`. En el menú elija la opción `Options>List All Devices`
9. Deje las opciones como se muestran en la imagen:
![Opciones de Zadig](/images/zadigOptions.png)
10. Seleccione `Replace Driver`.
11. Descargue el software para grabación [Extreme Burner AVR](
http://digital-wizard.net/files/extreme_burner_avr_v1.4.3_setup.exe) y ejecute el archivo descargado `extreme_burner_avr_v1.4.3_setup.exe`
12. Con la tarjeta Usbasp conectada, inicie Extreme Burner AVR. En el menú seleccione `Settings>Programming Mode>ISP`. Después elija `Erase>Chip Erase`. Extreme Burner AVR tratará de borrar el microcontrolador, y al no encontrarlo mostrará varios errores pero al menos habrá reconocido a la tarjeta Usbasp. 
![Reconocimiento de la tarjeta Usbasp](/images/extremeUsbasp.png)
13. Ahora el software estará completamente instalado y funcionará correctamente.


 

