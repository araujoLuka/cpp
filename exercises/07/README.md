# C++ Program: Modifying the `Disciplina` Class

## Problem Statement
The goal of this program is to modify the `Disciplina` class by replacing the previous vector-based 
implementation of student records with an appropriate container from the C++ Standard Library (STL). 
Additionally, we need to add or modify the following member functions:

1. `void adicionarAluno(Pessoa* aluno)`: Add a student to the class.
2. `void removerAluno(Pessoa* aluno)`: Remove a student from the class based on their object pointer.
3. `void removerAluno(unsigned long cpf)`: Remove a student from the class based 
on their CPF (Brazilian identification number).
4. `std::map<int, Pessoa*> getAlunos()`: Retrieve a container containing all the students.

## Solution Overview
To address the problem statement, we will perform the following steps:

### Step 1: Choose an STL Container
We will choose an appropriate container from the C++ STL to store student records. 
The choice of container should be based on the program's requirements and efficiency considerations.

### Step 2: Modify the `Disciplina` Class
We will make necessary modifications to the `Disciplina` class, replacing the vector-based 
storage with the chosen STL container.

### Step 3: Implement Member Functions
We will implement the following member functions within the `Disciplina` class:

- `void adicionarAluno(Pessoa* aluno)`: Add a student to the container.
- `void removerAluno(Pessoa* aluno)`: Remove a student from the container based on their object pointer.
- `void removerAluno(unsigned long cpf)`: Remove a student from the container based on their CPF.
- `std::map<int, Pessoa*> getAlunos()`: Retrieve a container containing all the students.

## The Idea
In general, my idea has to use the **[map](https://cplusplus.com/reference/map/map/)** STL container, 
because it uses less memory than list, and grant an better efficiency when 
inserting, removing or accessing an element if have a unique key to each file.

For that, I needed to create a function called **geraarId()** that generate a unique ID for a student. 
This ID will be used as a unique key to the pair <key, value> in map container.

To generate the ID is simple: map sort elements by key, then I just need to take the last element using this command:

`pair<int, Pessoa*> last{*(--this->alunos.end())}`

After that, just grab the id with `last.first`. *Voalá*, the ID will be unique every time.

## Code Implementation
Below is a simplified example of the modified `Disciplina` class in C++, demonstrating the changes 
made to the class and the implementation of the required member functions using 
the **[map](https://cplusplus.com/reference/map/map/)**  STL container:

```cpp
// Disciplina.hpp
#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <map> // Include the appropriate STL container header

#define MAX_ALUNOS 50   // Define the maximum number of students in a class

class Disciplina {
  public:
    // Constructor and other member functions of Disciplina
    // ...

    // Retrieve a container of all students
    std::map<int, Pessoa*> getAlunos();

    // Add a student to the class
    bool adicionarAluno(Pessoa* aluno);

    // Remove a student based on their object pointer
    bool removerAluno(Pessoa* aluno);

    // Remove a student based on their CPF
    bool removerAluno(unsigned long cpf);

    // Remove a student based on their ID
    bool removerAluno(int id);

    // List all students in the class
    void listarAlunos();

  private:
    // ...

    // Choose an STL container to store students
    std::map<int, Pessoa*> alunos;

    // Generate a unique ID for a student
    int gerarId(Pessoa* aluno);
}; 

#endif
```

```cpp

// Disciplina.cpp

#include "Disciplina.hpp"

// Constructor and other member functions of Disciplina
// ...

std::map<int, Pessoa *> Disciplina::getAlunos() { return this->alunos; }

// Member functions

// Generate a unique ID for a student
int Disciplina::gerarId(Pessoa *aluno) {
    if (this->alunos.size() == 0) return 1;
    std::pair<int, Pessoa *> last{*(--this->alunos.end())};
    return last.first + 1;
}

// Add a student to the class
bool Disciplina::adicionarAluno(Pessoa *aluno) {
    if (this->alunos.size() >= MAX_ALUNOS) return false;

    int id = gerarId(aluno);
    
    this->alunos.insert({id, aluno});
    return true;
}

// Remove a student based on their object pointer
bool Disciplina::removerAluno(Pessoa *aluno) {
    if (this->alunos.size() == 0) return false;
    
    if (aluno == nullptr) return false;

    std::map<int, Pessoa*>::iterator it;
    for (it = this->alunos.begin(); it != this->alunos.end(); it++) {
        if (it->second == aluno) {
            this->alunos.erase(it);
            return true;
        }
    }
    return false;
}

// Remove a student based on their CPF
bool Disciplina::removerAluno(unsigned long cpf) {
    if (this->alunos.size() == 0) return false;

    if (cpf == 0) return false;

    std::map<int, Pessoa*>::iterator it;
    for (it = this->alunos.begin(); it != this->alunos.end(); it++) {
        if (it->second->getCpf() == cpf) {
            this->alunos.erase(it);
            return true;
        }
    }
    return false;
}

// Remove a student based on their ID
bool Disciplina::removerAluno(int id) {
    if (this->alunos.size() == 0) return false;

    if (id == 0) return false;

    if (this->alunos.find(id) == this->alunos.end()) return false;

    this->alunos.erase(id);
    return true;
}

// List all students in the class
void Disciplina::listarAlunos() {
    std::cout << "Alunos da disciplina " << nome << ":\n";
    // list with const_iterator, 'cause we don't want to change the students
    std::map<int, Pessoa*>::const_iterator it;
    for (it = this->alunos.cbegin(); it != this->alunos.cend(); it++) {
        std::cout << it->second->getNome() << '\t' << it->second->getIdade() << '\t'
                  << it->second->getCpf() << '\n';
    }
}
```

## Execution

Compile program with `make` and run with `./aula`
