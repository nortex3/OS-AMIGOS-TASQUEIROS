CC:=gcc
CFLAGS:=-ansi -O2 -Wall -pedantic 
TARGET:=GEREVENDAS

all: $(TARGET)

$(TARGET): Main.o CatalogoClientes.o CatalogoProdutos.o avl.o 
	$(CC) $(CFLAGS) $^ -o $@ 

Main.o: Main.c 
	$(CC) $(CFLAGS) -c $^ 


CatalogoClientes.o: CatalogoClientes.c  
	$(CC) $(CFLAGS) -c $^ 

CatalogoProdutos.o: CatalogoProdutos.c  
	$(CC) $(CFLAGS) -c $^ 

avl.o: avl.c	
	$(CC) $(CFLAGS) -c $^ 

clean: 
	@$(RM) *.o
