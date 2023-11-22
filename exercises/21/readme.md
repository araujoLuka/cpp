# Exercicios - Lição 21

1. Implemente o mecanismo de cache
- Implementado com sucesso para realizar cache dos livros com shared_ptr

2. em Ementa, modificar shared_ptr para unique_ptr
- Falha ao fazer o exercicio, não consegui realizar a substituição
- Ao substituir teve muitos erros no makefile, tentei consertar modificando o shared pointer de livro para unique antes de inserir na lista, mas não obtivve sucesso

3. Verique outros locais onde pode ser usado ponteiros inteligentes
- Pode ser utilizado na classe Disciplina, para controlar a lista de alunos com shared_ptr
- Pode ser utilizado na classe Disciplina, para controlar a sala de aula com unique_ptr
- Pode ser utilizado na classe SalaAula, para controlar a lista de disciplinas ministradas com shared_ptr
