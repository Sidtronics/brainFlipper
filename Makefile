#
#	The MIT License (MIT)
#
#	Copyright (c) 2022 Siddhesh Dharme
#
#	Permission is hereby granted, free of charge, to any person obtaining a copy
#	of this software and associated documentation files (the "Software"), to deal
#	in the Software without restriction, including without limitation the rights
#	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
#	copies of the Software, and to permit persons to whom the Software is
#	furnished to do so, subject to the following conditions:
#
#	The above copyright notice and this permission notice shall be included in all
#	copies or substantial portions of the Software.
#
#	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
#	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
#	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
#	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
#	SOFTWARE.
#

BUILD = build
SRC = src
DEST = /usr/local/bin
######################

objects = $(BUILD)/main.o $(BUILD)/brainVM.o

.PHONY: all
all:
	mkdir -p $(BUILD)
	$(MAKE) brainc

.PHONY: brainc
brainc: $(objects)
	cc $(objects) -o $(BUILD)/brainc

$(BUILD)/main.o: $(SRC)/brainVM.h
	cc -c $(SRC)/main.c -o $(BUILD)/main.o

$(BUILD)/brainVM.o: $(SRC)/brainVM.h
	cc -c $(SRC)/brainVM.c -o $(BUILD)/brainVM.o

.PHONY: install
install: $(BUILD)/brainc
	cp $< $(DEST) 

.PHONY: uninstall
uninstall:
	rm -f $(DEST)/brainc

.PHONY: clean
clean:
	rm -f $(objects) $(BUILD)/brainc
