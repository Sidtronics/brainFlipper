.PHONY: all
all:
	mkdir -p build
	$(MAKE) build/bfi

.PHONY: bfi
build/bfi: brainf_interpreter.c
	cc brainf_interpreter.c -o build/bfi

.PHONY: install
install: build/bfi
	mv build/bfi /usr/local/bin/

.PHONY: clean
clean:
	rm -f build/bfi
