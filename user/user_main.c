/*
 * ESPRSSIF MIT License
 *
 * Copyright (c) 2015 <ESPRESSIF SYSTEMS (SHANGHAI) PTE LTD>
 *
 * Permission is hereby granted for use on ESPRESSIF SYSTEMS ESP8266 only, in which case,
 * it is free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#include "esp_common.h"

#define DEMO_STA_SSID "(((WF)))"
#define DEMO_STA_PASSWORD "linknow1987!!!"


/******************************************************************************
 * FunctionName : user_init
 * Description  : entry of user application, init user function here
 * Parameters   : none
 * Returns      : none
*******************************************************************************/
void user_init(void)
{
    uart_div_modify(0, UART_CLK_FREQ / 115200);
    uart_div_modify(1, UART_CLK_FREQ / 115200);
    printf("\nSDK version:%s\n", system_get_sdk_version());
    printf("ESP8266 chip ID:0x%x\n", system_get_chip_id());
    
    // Conexión en modo station
    wifi_set_opmode(STATION_MODE);
    struct station_config * configSTA = (struct station_config *)zalloc(sizeof(struct station_config));
    sprintf(configSTA->ssid, DEMO_STA_SSID);
    sprintf(configSTA->password, DEMO_STA_PASSWORD);
    wifi_station_set_config(configSTA);
    free(configSTA);
    wifi_station_connect();
}

