Demo1
-----

Read: http://dfusion.com.au/wiki/tiki-index.php?page=PSoC5+bare+metal

Download an ARM GCC Cross compiler if you don't already have one.
     https://launchpad.net/gcc-arm-embedded/+download

Put the cross compiler into your PATH - something like:
    PATH=~/software/arm-gnu-baremetal-compiler/gcc-arm-none-eabi-4_8-2014q2/bin:$PATH

Run make to compile this app.

Note (after all your effort) the app does absolutely nothing - it's an empty app to understand the compile and link process.

Note this makefile is all-in one so you can see the workings and hack it simply. Later demos use the included makefile framework.

