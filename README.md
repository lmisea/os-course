# Sistemas Operativos I (CI-3825)

![Made with Love](https://img.shields.io/badge/Made%20with-Love-pink?style=for-the-badge&logo=data:image/svg%2bxml;base64,PHN2ZyByb2xlPSJpbWciIHZpZXdCb3g9IjAgMCAyNCAyNCIgeG1sbnM9Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnIj48dGl0bGU+R2l0SHViIFNwb25zb3JzIGljb248L3RpdGxlPjxwYXRoIGQ9Ik0xNy42MjUgMS40OTljLTIuMzIgMC00LjM1NCAxLjIwMy01LjYyNSAzLjAzLTEuMjcxLTEuODI3LTMuMzA1LTMuMDMtNS42MjUtMy4wM0MzLjEyOSAxLjQ5OSAwIDQuMjUzIDAgOC4yNDljMCA0LjI3NSAzLjA2OCA3Ljg0NyA1LjgyOCAxMC4yMjdhMzMuMTQgMzMuMTQgMCAwIDAgNS42MTYgMy44NzZsLjAyOC4wMTcuMDA4LjAwMy0uMDAxLjAwM2MuMTYzLjA4NS4zNDIuMTI2LjUyMS4xMjUuMTc5LjAwMS4zNTgtLjA0MS41MjEtLjEyNWwtLjAwMS0uMDAzLjAwOC0uMDAzLjAyOC0uMDE3YTMzLjE0IDMzLjE0IDAgMCAwIDUuNjE2LTMuODc2QzIwLjkzMiAxNi4wOTYgMjQgMTIuNTI0IDI0IDguMjQ5YzAtMy45OTYtMy4xMjktNi43NS02LjM3NS02Ljc1em0tLjkxOSAxNS4yNzVhMzAuNzY2IDMwLjc2NiAwIDAgMS00LjcwMyAzLjMxNmwtLjAwNC0uMDAyLS4wMDQuMDAyYTMwLjk1NSAzMC45NTUgMCAwIDEtNC43MDMtMy4zMTZjLTIuNjc3LTIuMzA3LTUuMDQ3LTUuMjk4LTUuMDQ3LTguNTIzIDAtMi43NTQgMi4xMjEtNC41IDQuMTI1LTQuNSAyLjA2IDAgMy45MTQgMS40NzkgNC41NDQgMy42ODQuMTQzLjQ5NS41OTYuNzk3IDEuMDg2Ljc5Ni40OS4wMDEuOTQzLS4zMDIgMS4wODUtLjc5Ni42My0yLjIwNSAyLjQ4NC0zLjY4NCA0LjU0NC0zLjY4NCAyLjAwNCAwIDQuMTI1IDEuNzQ2IDQuMTI1IDQuNSAwIDMuMjI1LTIuMzcgNi4yMTYtNS4wNDggOC41MjN6Ii8+PC9zdmc+)

This repository contains labs, assignments, and projects for the Sistemas Operativos I (CI-3825) course at Simon Bolivar University. All the code in this repository is written in C.

## Folder structure

The repository is structured as follows:

- Every week, a new lab is added as `labx`, where `x` is the number of the week.
- Inside each `labx` folder, there are up to four folders:

  - `assign`: Contains the code for the assignment of the lab. It is optional, because not every lab has an assignment. It only contains `.c` and `.h` files and is compiled with the lab `Makefile`. Meaning that the executables for the assignment are generated in the `bin` folder of the lab.
  - `bin`: Contains the executables generated after compiling the code.
  - `build`: Contains the object files generated after compiling the code.
  - `src`: Contains the source code for the lab.

    Additionally, there is a `Makefile` at the root of the lab folder, which is used to compile all the code.

- There are also three folders for the projects:

  - `project0`: Contains the code for the first project.
  - `project1`: Contains the code for the second project.
  - `project2`: Contains the code for the third project.

    The projects are structured in the same way as the labs with a `bin`, `build`, and `src` folder. At the root of the project folder there is a `Makefile`, a `.pdf` file with the project statement and the `README.md` file

### Tree-like folder structure

```
  .
  ├── labx
  │ ├── assign (optional)
  │ │ ├── .c files
  │ │ └── .h files
  │ ├── bin
  │ │ └─ .out files (executables)
  │ ├── build
  │ │ └─ .o files (object files)
  │ ├── src
  │ │ ├── .c files
  │ │ └── .h files
  │ └── Makefile
  ├── projectx
  │ ├── bin
  │ │ └─ run.out (executable)
  │ ├── build
  │ │ └─ .o files (object files)
  │ ├── src
  │ │ ├── .c files
  │ │ └── .h files
  │ └── Makefile
  ├── LICENSE
  └── README.md
```

## Compiling and running

Every lab and project has a `Makefile` that can be used to compile the code. To compile the code, run the following command:

```bash
make
```

This will generate all the executables for the lab or project into the `bin` folder. And also, it will generate the `build` folder, which contains all the object files generated during the compilation process.

### Running the executables

All the executables are stored in the `bin` folder and have the `.out` extension. To run an executable, run the following command:

```bash
./bin/executable.out
```

> Replace `executable` with the name of the executable you want to run.

### Cleaning all the generated files

To clean all the generated files, run the following command:

```bash
make clean
```

## Laboratory group

- Luis Isea [@lmisea](https://github.com/lmisea) (19-10175).
- Jesús Prieto [@dev-jlpt18](https://github.com/dev-jlpt18) (19-10211).
