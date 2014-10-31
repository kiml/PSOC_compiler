##PSOC_compiler

#####Summary
Demos for writing and compiling bare metal programs for PSOC5 using open source tools.

#####Purpose
To demo ARM Cortex M3 low level development with specific reference to PSoC.
To provide some open source support for the PSoC.

#####Requirements
* ARM GCC cross compiler
* A Cypress CY8CKIT-050 dev kit (to actually run programs)

#####See Also
* https://github.com/kiml/PSOC_programmer.git
* http://dfusion.com.au/wiki/  The ARM Embedded pages:
    - PSoC5 bare metal
    - PSoC5 programmer 
    - GCC Linker

#####Additional Uses
* A simple general purpose embedded LCD printf library

#####License
* All code is released under GPL v3 except for any third party files which have their original license included.

#####Raison d'Etre
* Cypress put out a free but closed source MS Windows development environment. They do provide GCC but pretty much everything else is proprietary which is fine but:
  - I like the PSoC feature set (basically ARM CPU, mxied signal FPGA, decent analogue)
  - I wanted to learn more about internals of the ARM Cortex M3 chip used
  - I wanted to program the PSoC under Unix.

Short version - the mountain was there so I climbed it :-)


#####Getting Started
To use the programmer, edit conf/programmer.mak and change the UTILSPATH to point to the directory that contains bin/ and config/ of the programmer git repo.

#####Dirs

* demo1 - A basic demo to get started with bare metal. It's more about showing the compiler/linker options and interacting with the peer programmer tools than making a working program.
* demo2* - Hello World. This is a minimal working PSOC5LP program that flashes lights and outputs to the LCD
    demo2a - no config.hex, 'std' nm.hex, all config done in code.
    demo2b - Cypress compat config.hex, 'std' nm.hex, config done in mix code/data. Basically  Cypress devkit model, but open source code.
    demo2c - My own app_data config format. Removes need for much custom register init config in code. 'std' nm.hex??. Config format is NOT Cypress compatible.
    demo2d - democ2c + cmsisv1.3

* demo3 - Compiling a Cypress devkit app (partial)
