#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

// Debugging in gdb
// terminal 1: openocd -f interface/stlink.cfg -c "transport select hla_swd" -f board/st_nucleo_f4.cfg
// terminal 2: gdb-multiarch -q awesomesauce.elf 
// 				target extended-remote :3333
int main(void) {
	rcc_periph_clock_enable(RCC_GPIOA);

	gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_ALL);
	gpio_set(GPIOA, GPIO_ALL );

	while(1) {
		/* wait a little bit */
		for (int i = 0; i < 800000; i++) {
			__asm__("nop");
		}
		gpio_toggle(GPIOA, GPIO_ALL );
	}
}
