#include <asf.h>
#include <string.h>
#include <proj.h>


int counter_left = 0;
int counter_right = 0;
bool current_state = false;
bool previous_state = false;

void configure_adc(void)
{
	/* Configure ADC pin for light sensor. */
	gpio_configure_pin(PIO_PB0_IDX, PIO_INPUT); //White wire on EXT2
	gpio_configure_pin(PIO_PA17_IDX, PIO_INPUT); //White wire on EXT1

	/* Enable ADC clock. */
	pmc_enable_periph_clk(ID_ADC);

	/* Configure ADC. */
	adc_init(ADC, sysclk_get_cpu_hz(), 1000000, ADC_MR_STARTUP_SUT0);
	adc_enable_channel(ADC, ADC_CHANNEL_4); //ADC Channel connected to PB0 on EXT2
	adc_enable_channel(ADC, ADC_CHANNEL_0); //ADC Channel connected to PA17 on EXT1
	adc_configure_trigger(ADC, ADC_TRIG_SW, 1);
}

void task2_left(uint32_t val) {
		counter_left++;
}

void task1_left(uint32_t val) {
	if (val > 1000 && previous_state == false)
	{
		current_state = false;
		previous_state = current_state;
	}
	else if (val == 0 && previous_state == false)
	{
		current_state = true;
		task2_left(val);
		previous_state = current_state;
	}
	else if (val > 1000 && previous_state == true)
	{
		current_state = false;
		previous_state = current_state;
	}

}

void task2_right(uint32_t val) {
		counter_right++;
}

void task1_right(uint32_t val) {
	if (val > 1000 && previous_state == false)
	{
		current_state = false;
		previous_state = current_state;
	}
	else if (val == 0 && previous_state == false)
	{
		current_state = true;
		task2_right(val);
		previous_state = current_state;
	}
	else if (val > 1000 && previous_state == true)
	{
		current_state = false;
		previous_state = current_state;
	}
}

int debug_buffer_l[1000];
int debug_buffer_i_l = 0;
int debug_buffer_r[1000];
int debug_buffer_i_r = 0;


void check_values(int val_left, int val_right) {
	uint32_t adc_value_left;
	uint32_t adc_value_right;
	uint32_t normalized_adc_value;
	uint32_t values[6];


	if(val_left > 0)
	{
		motor1_forward();
	} else
	{
		motor1_backward();
		val_left = val_left * -1;
	}

	if(val_right > 0)
	{
		motor2_forward();
	} else
	{
		motor2_backward();
		val_right = val_right * -1;
	}

	bool right_still_counting = true;
	bool left_still_counting = true;

	while ( left_still_counting || right_still_counting ){
		adc_value_right = adc_get_channel_value(ADC, ADC_CHANNEL_4);
		adc_value_left = adc_get_channel_value(ADC, ADC_CHANNEL_0);



		debug_buffer_l[debug_buffer_i_l++] = adc_value_left;
		debug_buffer_r[debug_buffer_i_r++] = adc_value_right;

		//For counting
		if(right_still_counting)
			task1_right(adc_value_right);

		if(left_still_counting)
			task1_left(adc_value_left);


		//get string with value (For printing)
		sprintf(values, "%d         %d         ", counter_left, counter_right);

		//print value
		ssd1306_set_page_address(0);
		ssd1306_set_column_address(0);
		ssd1306_write_text(values);

		if(counter_left >= val_left)
			left_still_counting = false;
		if(counter_right >= val_right)
			right_still_counting = false;

		delay_ms(10);
	}

	motor1_stop();
	motor2_stop();
	counter_left = 0;
	counter_right = 0;
}
