#Example descriptions

#ex1

#ex1_2
Igual que 'ex1' pero cambia la ubicación del miembro 'base' de las 
clases 'Acme...' y X10...' demostrando que el método de invocar a la función 
polimórfica mediante la ayuda de la macro offset() funciona.

#ex1_2:

#ex2
Igual que ex1 pero utilizando 'void *' en lugar de 'LedDriver *' en las 
operaciones de LedDriver. No es totalmente compatible con ex1_1 y ex1_2, ya que 
es dependiente del layout de LedDriver.

#ex3
No utiliza la macro offset() en LedDriver.

#ex4
Oculta definición de las clases 'Acme...' y 'X10...', usando punteros 
opacos. Instancia de manera estática dentro de la implementación. Desventaja: 
es necesario instanciar siempre dentro de la implementación, permite singleton.

#ex5
Igual que ex4 pero instancia estáticamente mediante un pool dentro de la 
implementación.
