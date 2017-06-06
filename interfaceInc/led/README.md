# Example descriptions

## ex1
Implementaci髇 de interface en C, mediante vinculaci髇 din醤ica, tabla de 
funciones virtuales, y m鷏tiples instancias.

## ex1_1
Igual que ex1 pero cambia la ubicaci贸n del miembro 'base' de las 
clases 'Acme...' y X10...' demostrando que el m茅todo de invocar a la funci贸n 
polim贸rfica mediante la ayuda de la macro offset() funciona.

## ex1_2
Igual que ex1, con herencia m鷏tiple en la clase 'Acme...'.

## ex2
Igual que ex1 pero utilizando 'void *' en lugar de 'LedDriver *' en las 
operaciones de LedDriver. No es totalmente compatible con ex1_1 y ex1_2, ya que 
es dependiente del layout de LedDriver.

## ex3
Igual que ex1, pero no utiliza la macro offset() en LedDriver.

## ex4
Igual que ex1, pero oculta definici贸n de las clases 'Acme...' y 'X10...', 
usando punteros opacos. Instancia de manera est谩tica dentro de la 
implementaci贸n. 
Desventaja: es necesario instanciar siempre dentro de la implementaci贸n.

## ex5
Igual que ex4 pero instancia est谩ticamente mediante un pool dentro de la 
implementaci贸n.

## ex6
Igual que ex1 pero singleton.
