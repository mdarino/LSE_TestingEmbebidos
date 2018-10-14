# LSE_TestingEmbebidos
Repositorio para guardar el TP3 de Especializacion en Sistemas Embebios - Materia Testing de sistemas embebidos.

Modulo seleccionado para trabajar en el TP3

- Modulo de control de corriente

Requerimientos adaptados para poder completar un modulo utilizando la tecnica TDD

REQ- 01 No puede configurarse valores negativos.
REQ- 02 No puede configurarse valores mayores a 5A.
REQ- 03 Los valores permitidos son todos enteros.
REQ- 04 Debe porcesar el valor de corriente actual que llega de la HAL.
REQ- 05 Debe enviar un evento (Simulado con un print) que avise si sobrepaso la corriente.


--------------------------------------------------------------------------------------

SISTEMA GENERAL (Inventado para realizar el TP):

Fuente de alimentación variable con control de corriente.

Descripción del sistema:

Se eligió controlar una fuente de alimentación variable con control de corriente. La interfaz con el usuario se realiza por una comunicación serie para facilitar el desarrollo (Proyecto con fin educativo) e indicadores LED.

Requerimientos:
1. Entrada alimentación 220-110v alterna
2. Control de voltaje de 0 a 35V
3. Resolución de voltaje 1v
4. Control de corriente de 0 a 5A
5. Resolución de corriente 1 A
6. Control de corriente con opción de corte por sobre carga
7. Comando serie para subir/bajar la tensión
8. Comando serie para subir/bajar la corriente
9. Salida serie para mostrar el estado del sistema (tensión/corriente/estado de la salida)
10. Debe poseer un LED que muestre cuando se supera la corriente programada
11. Debe tener un LED que indique que la fuente esta encendida
12. Debe tener un LED que indique que la salida esta activa o no