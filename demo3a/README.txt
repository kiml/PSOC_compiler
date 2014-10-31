Demo 3a - LCD and LED
---------------------
This demo flashes LED2 at 0.5Hz and turns on LED1 whilst SW2 is pressed (P6_1)

Differences from demo 2d:
  * Sets up SystemTick Event and Handler and sleeps between ticks
  * Full gcc.ld (from ARM but modified)
  * Full startup_ARMCM3.S (from ARM but modified)

Key points:
  * Minimal system setup
  * Uses enhanced config format (see Demo 2c/d)
  * Full gcc.ld (from ARM but modified)
  * Full startup_ARMCM3.S (from ARM but modified)
  * Sets up SystemTick Event and Handler
  * System goes to sleep between System clock (ms) ticks

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
