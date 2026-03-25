# ==========================================
# CONFIGURAÇÕES
# ==========================================

CC = gcc
CFLAGS = -Wall -Wextra -g

# Nome do executável final
TARGET = ted

# Todos os ficheiros fonte (O Hashing + o Unity + os Testes)
SRCS = src/hte.c src/unity.c test/hte_test.c

# ==========================================
# REGRAS DO MAKEFILE
# ==========================================

# 1. all: Compila o código e gera o executável
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# 2. test: Garante que está compilado (chama o all) e roda os testes
test: all
	./$(TARGET)

# 3. clean: Remove o executável, ficheiros .o e os ficheiros binários gerados
clean:
	rm -f $(TARGET)
	rm -f *.o src/*.o test/*.o
	rm -f *.bin diretorio.bin hte_test.bin

# Proteção das regras
.PHONY: all test clean