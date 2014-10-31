Demo 2b - LCD and LED
---------------------
This demo flashes LED2 at 0.5Hz and turns on LED1 whilst SW2 is pressed (P6_1)

Differences from demo 2a:
  * Uses config data

Key points:
  * Minimal system setup
  * Uses Cypress generated config.hex to replace some hardware configuration
      in main code compared to demo2a.
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

Notes
-----
It is probable that the Port6 setup code in main.c could also have been added into the config.hex file
However I do not have the Cypress window toolkit and the next demo (2c) presents an enhanced config solution.
The config.hex used was borrowed from another published Cypress project which happen to set up an LCD.
The config.hex file also sets a few other ports but they don't interfere with our use.
