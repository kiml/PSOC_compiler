extern void main(void);

void SystemInit(void)
{
    // really need to set clock here
} 

void _start(void)
{
    main();
    for(;;) {}
   
}
