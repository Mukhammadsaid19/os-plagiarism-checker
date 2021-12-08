build: py_deps back

py_deps:
	pip install -Ur requirements.txt

back:
	make -C backend

.PHONY: clean

clean:
	rm *.o output
