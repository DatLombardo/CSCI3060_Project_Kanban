CXX=clang++ 
VER=-std=c++11
EXE=output/output.exe
OBJS=src/main.o src/fileout.o src/transaction.o

.cpp.o:
	$(CC) $(VER) -c -o $@ $<

all: $(EXE)
	@echo a

$(EXE): $(OBJS)
	$(CXX) -o $(EXE) $(OBJS) $(VER)

clean:
	rm $(EXE) $(OBJS)