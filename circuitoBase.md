# Circuito base
El circuito base es lo mínimo necesario para comenzar a realizar las prácticas, después de ejecutar estos pasos usted podrá grabar su microcontrolador sin problemas.

## Conexión de la fuente de alimentación
1. Conecte el siguiente diagrama:
![Circuito de alimentación](/images/sourceCircuit.png)

2. Conecte su fuente de alimentación. Con un multímetro cheque que realmente `Vcc` tenga el valor de `5.0V`. Si no es así, revise sus conexiones.

## Conexión de la tarjeta Usbasp
1. Desconecte la fuente de alimentación. Complete el circuito anterior de acuerdo al siguiente diagrama, a este circuito lo llamamos _Circuito base_:
![Circuito base](/images/baseCircuit.png)
2. Los pines del conector de 10-pin de la tarjeta Usbasp tienen las siguientes señales, tenga cuidado al conectar, guíese por la muesca del conector.
![Descripción de pines](/images/usbaspPinout.png)
3. Revise de nuevo sus conexiones. Conecte de nuevo la fuente de alimentación e inicie Extreme Burner AVR. En el menú seleccione `Chip>ATmega328P`. Después elija `Erase>Chip Erase`. Extreme Burner AVR borrará la memoria del microcontrolador:
![Borrado con éxito](/images/eraseSucces.png)
4. Ha completado con éxito la conexión del circuito base.
