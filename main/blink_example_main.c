
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "led_strip.h"
#include "sdkconfig.h"

static const char *TAG = "example";
#define BLINK_GPIO GPIO_NUM_2
static uint8_t s_led_state = 0;
static void blink_led(void)
{
    gpio_set_level(GPIO_NUM_2, s_led_state);
}
static void configure_led(void)
{
    ESP_LOGI(TAG, "Example configured to blink GPIO LED!");
    gpio_reset_pin(GPIO_NUM_2);
    gpio_set_direction(GPIO_NUM_2, GPIO_MODE_OUTPUT);
}
void app_main(void)
{
    configure_led();
    int *p;
    int a[5]={1,2,3,4,5};
    p=a;
    uint8_t t=10;
    ESP_LOGI(TAG,"gia tri cua t: %u",t);
    ESP_LOGI(TAG,"giá trị trả về của sizeof: %d \n",sizeof(a));
    for(unsigned int i=0;i<(sizeof(a)/sizeof(int));i++){
        ESP_LOGI(TAG,"giá trị phần tử thứ %d là %u \n",i,*(p+i));
    
    }
    while (1) {
        // ESP_LOGI(TAG, "Turning the LED %s!", s_led_state == true ? "ON" : "OFF");
        // blink_led();
        // s_led_state = !s_led_state;
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}
