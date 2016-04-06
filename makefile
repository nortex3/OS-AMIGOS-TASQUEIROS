CC:=gcc
CFLAGS:=-ansi -O2 -Wall -pedantic 
TARGET:=GEREVENDAS

all: $(TARGET)
	 rm *.o

$(TARGET): main.o CatalogoClientes.o CatalogoProdutos.o avl.o avlF.o Faturacao.o leitura.o GestaoFilial.o avlFilial.o interface.o
	$(CC) $(CFLAGS) $^ -o $@ 

main.o: main.c 
	$(CC) $(CFLAGS) -c $^ 

leitura.o: leitura.c
	$(CC) $(CFLAGS) -c $^ 

CatalogoClientes.o: CatalogoClientes.c  
	$(CC) $(CFLAGS) -c $^ 

CatalogoProdutos.o: CatalogoProdutos.c  
	$(CC) $(CFLAGS) -c $^ 

avl.o: avl.c	
	$(CC) $(CFLAGS) -c $^ 

avlF.o: avlF.c
	$(CC) $(CFLAGS) -c $^

Faturacao.o: Faturacao.c
	$(CC) $(CFLAGS) -c $^

avlFilial.o: avlFilial.c
	$(CC) $(CFLAGS) -c $^

GestaoFilial.o: GestaoFilial.c
	$(CC) $(CFLAGS) -c $^

interface.o: interface.c
	$(CC) $(CFLAGS) -c $^

clean: 
	@$(RM) *.o
