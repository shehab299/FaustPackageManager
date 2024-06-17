all: 
	g++ -c main.cpp -o build/main.o
	g++ -c PkgUrl/PkgUrl.cpp -o build/PkgUrl.o
	g++ -c Downloader/GithubDownloader.cpp -o build/downloader.o
	g++ -c Registry/Registry.cpp -o build/registry.o
	g++ build/main.o build/PkgUrl.o build/downloader.o build/registry.o -lcurl -o build/main

run:
	./build/main
