Demo 2c - LCD and LED
---------------------
This demo flashes LED2 at 1Hz and turns on LED1 whilst SW2 is pressed (P6_1)

Differences from demo 2b:
  * Enhanced data config format

Key points:
  * Minimal system setup
  * Uses an enhanced (non-Cypress compatible) config format (see below) for config data.
  * Busy wait to drive LED

Code Dependencies:
  * Essentially no Cypress code
  * No CMSIS

Hardware Setup:
  * Requires CYC8KIT-050

  * Set up the CYC8KIT-050 as folows
      - Two wires:
          P6_0 (connector P9) to LED1 (connecor P6)
          P6_6 (connector P9) to LED2 (connecor P6)
      - Connect 2 line LCD


Config Format
-------------
This is documented in the PSOC_programmer git repo docs (also partly in the gen_config python source).
It is modelled on the Cypress idea but extends the concept to allow more sophisticated config in data, reducing custom code.
The configuration data source is a simple readable text file. This is "compiled" into binary data.
A small library (single function) is provided to parse/process the data.

In summary:
    config.conf is the source file.
    It can be "compiled" ultimately into one of three forms:
      - "freehex"
      - Intel hex
      - binary

The native format is the newly invented "freehex" format. It started out as a dump format but was convenient to use
as an intermediate file format because it supports #lines for metadata and comments, plus is (almost) human readable.
  * gen_config takes .conf files and produces freehex.
  * freehex2other takes freehex and produces  plain ascii hex dumps, Intel hex records, or binary.

Config Format Test/Demo
-----------------------
On your host machine (ie x86) do:
    make test

This will compile the app_config.c code for the _host_ environment and include debug statements.
The test will run and dump out the actions it's performing, which can be mapped easily back to the .conf file.
(It could also be used as the basis to decode binary config back into a usable .conf file).
