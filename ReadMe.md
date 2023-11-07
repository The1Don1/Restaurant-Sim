# The Spice Girls
<h1 align="center"> COS 214 Restaurant Simulator </h1>

[![Compilation status](https://github.com/The1Don1/Restaurant-Sim/actions/workflows/makefile.yml/badge.svg)](https://github.com/The1Don1/Restaurant-Sim/actions/workflows/makefile.yml)
[![.clang-format status](https://github.com/The1Don1/Restaurant-Sim/actions/workflows/CodeLinter.yml/badge.svg)](https://github.com/The1Don1/Restaurant-Sim/actions/workflows/CodeLinter.yml)

# Glossary

- [Members](#Members)
- [Functional Requirements](#Requirements)
- [Compilation and how to run](#compilation)
- [Implemented Patterns](#Patterns)
- [Documentation](#Documentation)
- [Final UML](#UML)
- [License](#License)

# Members

| Name | Student Email |
| ----------- | ----------- |
| Mathenda Maphasha | u20477181@tuks.co.za |
| Boloka Kgopodithate | u20456213@tuks.co.za |
| Ofentse Ramothibe | u21467422@tuks.co.za |
| Realeboga Moatshe | u19029269@tuks.co.za |
| Ntando Mazibuko | u20626160@tuks.co.za |
| Thashlene Moodley | u22628721@tuks.co.za |

# Requirements

- developed using cmake 3.27.7
- designed using Clion 2023.2.22
- Linter used : .clang-format
- make version: GNU Make 4.3
- WSL2 version: 5.10.16
- Ubuntu version: 22.04.2 LTS codename jammy
# compilation
```
Open a linux terminal into build folder
clone github into a folder named 'workspaces'
rm CMakeCache.txt
Open a linux terminal into the source folder
cmake -S Code/Project/Project -B Code/Project/build
Open a linux terminal into the build folder
make
./Project
make clean - once complete
```
# Patterns
- Singleton
- Facade
- Mediator
- Memento
- Visitor
- Chain of Responsibility
- Observer
- Template Method
- Prototype
- Composite
- State
- Iterator
- Strategy
- Decorator

# Documentation
- [Final Report](https://github.com/The1Don1/Restaurant-Sim/blob/main/Documentation)
- [Code root](https://github.com/The1Don1/Restaurant-Sim/tree/main/Code/Project/Project)
- [Diagrams](https://github.com/The1Don1/Restaurant-Sim/tree/main/Diagrams)

# UML
![UMLDiagram](https://github.com/The1Don1/Restaurant-Sim/blob/main/Diagrams/Restaurant%20Simulator.png)


# License
  Project licensed under github provided MIT license
