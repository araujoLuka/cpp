compilador = g++

nomePrograma = main
parametros = -Wall -g

objetos = $(patsubst %.cpp, %.o, $(wildcard *.cpp))

# Lista de arquivos para distribuição
distFiles = *.cpp *.hpp makefile
distDir = 20206150

all: $(objetos)
	$(compilador) $(parametros) -o $(nomePrograma) $(objetos)

%.o: %.cpp
	$(compilador) $(parametros) -c $<

dist: purge
	@echo "Gerando arquivo de distribuição ($(distDir).tar) ..."
	@ln -s . $(distDir)
	@tar -cvf $(distDir).tar $(addprefix $(distDir)/, $(distFiles))
	@rm -f $(distDir)

clean:
	rm -f $(objetos) $(distDir).tar

purge: clean
	rm -f $(nomePrograma)
