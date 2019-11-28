EvolveA.png : plot.py datos.dat
	python plot.py

datos.dat : ejercicio32.x
	./ejercicio32.x

ejercicio32.x : ejercicio32.cpp
	c++ ejercicio32.cpp -o ejercicio32.x
	
clean:
	rm ejercicio32.x datos.dat EvolveA.png