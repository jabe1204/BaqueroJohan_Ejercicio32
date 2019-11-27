EvolveA.png : datos.dat graficador.py
	python graficador.py

datos.dat : ejercicio29.x
	./ejercicio29.x

ejercicio29.x : ejercicio29.cpp
	c++ ejercicio29.cpp -o ejercicio29.x
	
	
clean:
	rm ejercicio29.x datos.dat EvolveA.png