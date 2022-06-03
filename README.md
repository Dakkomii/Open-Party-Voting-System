# Voting System

### Compiling, Running, and Testing the Voting System

You can compile the voting system with `make` in the `src` directory of the project,
i.e., in `repo-Team12/Project2/src`.
This creates the the voting system executable named `voting-system`, which can be found in the `build/bin` directory,
assuming that you are in the `src` directory of the project.
You can execute it by typing the following:

```
./build/bin/voting-system
```

When the voting system is run, it will prompt you for your ballot files.
The path to your ballot files are relative to where the voting system is run, and are space-separated.
Suppose you have the ballot file `ballot.csv` in `repo-Team12/Project2`.
You would type the following:

```
../ballot.csv
```

Suppose you have the ballot files `ballot1.csv`, `ballot2.csv`, and `ballot3.csv` in `repo-Team12/Project2`.
You would type the following:

```
../ballot1.csv ../ballot2.csv ../ballot3.csv
```

The audit file and media report will be created in the directory where the voting system is run,
i.e., using the above command, in `repo-Team12/Project2/src`.
The names of these files will begin with `VotingSystem_AuditFile_` and `VotingSystem_MediaReport_`, respectively.

You can run all of the tests by typing the following:

```
./build/bin/unittest
```

The audit files and media reports generated from running the tests will be created in the `testing` directory of the project.
**Most of the tests are automated and depend on the relative path to the `testing` directory.**
**The tests will likely result in failure if the `src` and `testing` directories are not in the same directory.**

### Viewing the Doxygen Documentation

<!---You can generate the Doxygen webpages and UML with `make docs` at the top level of the project directory.--->
You can view the Doxygen documentation by typing the following at the top level of the project directory,
i.e., in `repo-Team12/Project2`:

```
xdg-open ./documentation/html/index.html
```

### Cleaning the Project

Finally, you can clean up a compiled build with `make clean`.
