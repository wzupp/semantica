all:
	g++ parser.cpp sem.cpp -o parser
	./parser
test:
	git submodule update --init --recursive
	mkdir -p build
	cd build && cmake ..
	cd build && make 
	cd build && make test 
clean:
	rm -r build && true
	rm -r vcpkg && true
	rm -r .cache && true
