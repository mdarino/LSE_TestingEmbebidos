# LSE_TestingEmbebidos
Repositorio para guardar el TP3 de Especializacion en Sistemas Embebios - Materia Testing de sistemas embebidos.

Laboratorio de sistemas embebidos ([link](http://laboratorios.fi.uba.ar/lse/))
Facultad de Ingeniería ([link](http://www.fi.uba.ar/)) Universidad de Buenos Aires
Modulo seleccionado para trabajar en el TP3

- Modulo de control de corriente

Requerimientos adaptados/ampliado para poder completar un modulo utilizando la tecnica TDD

- REQ-01 Debe comenzar en valor cero.
- REQ-02 Debe poder configurarse valores de corriente entre 0 a 5 donde todos los valores son enteros
- REQ-03 No puede configurarse valores negativos.
- REQ-04 No puede configurarse valores mayores a 5A.
- REQ-05 Debe poder leer el valor de corriente actual que llega de la HAL.
- REQ-06 Debe poder leer el estado de la salida.
- REQ-07 Debe enviar un evento (Simulado con una variable que pasa a 1) que avise si sobrepaso la corriente configurada cuando la salida esta activa.
- REQ-08 Debe enviar un evento (Simulado con una variable que pasa a 0) que avise que dejo de estar en sobrepaso de corriente o la salida paso a inactiva.

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
