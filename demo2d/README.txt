Demo 2d - LCD and LED
---------------------
This demo flashes LED2 at 1Hz and turns on LED1 whilst SW2 is pressed (P6_1)

Differences from demo 2c:
  * Uses CMSIS

Key points:
  * Minimal system setup
  * Uses enhanced config format (see Demo 2c)
  * Busy wait to drive LED

Code Dependencies:
  * Essentially no Cypress code
  * Use CMSIS v1.3 (provided with PSoC) for core functions

Hardware Setup:
  * Requires CYC8KIT-050

  * Set up the CYC8KIT-050 as folows
      - Two wires:
          P6_0 (connector P9) to LED1 (connecor P6)
          P6_6 (connector P9) to LED2 (connecor P6)
      - Connect 2 line LCD

