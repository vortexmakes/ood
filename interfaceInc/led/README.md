# Example descriptions

## ex1
Implementaci�n de interface en C, mediante vinculaci�n din�nica, tabla de 
funciones virtuales, y m�ltiples instancias.

## ex1_1
Igual que ex1 pero cambia la ubicación del miembro 'base' de las 
clases 'Acme...' y X10...' demostrando que el método de invocar a la función 
polimórfica mediante la ayuda de la macro offset() funciona.

## ex1_2
Igual que ex1, con herencia m�ltiple en la clase 'Acme...'.

## ex2
Igual que ex1 pero utilizando 'void *' en lugar de 'LedDriver *' en las 
operaciones de LedDriver. No es totalmente compatible con ex1_1 y ex1_2, ya que 
es dependiente del layout de LedDriver.

## ex3
Igual que ex1, pero no utiliza la macro offset() en LedDriver.

## ex4
Igual que ex1, pero oculta definición de las clases 'Acme...' y 'X10...', 
usando punteros opacos. Instancia de manera estática dentro de la 
implementación. 
Desventaja: es necesario instanciar siempre dentro de la implementación.

## ex5
Igual que ex4 pero instancia estáticamente mediante un pool dentro de la 
implementación.

## ex6
Igual que ex1 pero singleton.
