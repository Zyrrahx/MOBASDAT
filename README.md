# MOBASDAT
Currently the project is divided up into 2 workstations, a LINUX and WINDOWS based one.
For the foreseeable future all LINUX .hpp and .cpp files should function under a WINDOWS environment.
Essentially LINUX namespace will not use Windows based API/Libraries.

File Ruling::
Due to us using LUA or similar dependencies, .h files must be distinguished from wether they are C or C++
With this in mind, please use .hpp for .h C++ headers and .h for C headers.
Ensure that .hpp/.h files are seperated into the folder Headers, and .cpp files are placed in the folder CppFiles.
If you are going to make a massive change to the code structure, or add new dependencies please make a new branch,
or at least maintain version control.

Currently we are working on the Playable Actor, this includes but is not limited to creating functions and classes
to create a playable character in the game, this includes Abilities, Stats, the ability to read from files to
create these stats/abilities and utilize scripts to easily modify external resources to create characters without
having to program each individually inside the Solution/C++ workstation.
