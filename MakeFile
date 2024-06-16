build: clean
	g++ -c main.cpp -o build/main.o
	g++ -c pkgUrl/PkgUrl.cpp -o build/PkgUrl.o
	g++ build/main.o build/PkgUrl.o -o build/main

run:
	./build/main

clean:
	rm -rf build/*