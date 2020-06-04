/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.0
        Device            :  PIC18LF45K50
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include <string.h>
#include "lora_config.h"

#define RF_OK "OK\r\n"

uint8_t tx_buf[80]; 

void send_RN2903(uint8_t *data)
{
    int count = 0;

    while(data[count-1]!=0x0A)
    {
        EUSART1_Write(data[count]);
        count++;
    }
    
}

uint8_t receive_RN2903(uint8_t *data)
{
    int count = 0;
    uint8_t rx_data[80];
    
    do{
        rx_data[count]= EUSART1_Read();
        count++;
    }while (rx_data[count-1] !=0x0A);
    if (strcmp(rx_data,data))
    {
        DELAY_milliseconds(20);
        return 0;
    }else{
        DELAY_milliseconds(20);
        return 1;
    }
        
    
}

void config_RN2903(void)
{
    
    
//    send_RN2903 ("\r\n");
//    receive_RN2903(RF_OK);
    DELAY_milliseconds(100);
    send_RN2903 ("sys reset\r\n");
    DELAY_milliseconds(1000);
    send_RN2903 ("sys get vdd\r\n"); 
    receive_RN2903(RF_OK);
    send_RN2903 ("mac set ch status 0 on\r\n");
    if (receive_RN2903(RF_OK))while(1);
    for (uint8_t count = 1; count <=71;count++)
    {
      sprintf (tx_buf,"mac set ch status %d off\r\n",count);
      send_RN2903 (tx_buf);
      receive_RN2903(RF_OK);
    }

    
  
    sprintf (tx_buf,"mac set adr off\r\n");
    send_RN2903 (tx_buf);
    if (receive_RN2903(RF_OK))while(1);    

// Configure RX Delay    
    sprintf (tx_buf,"mac set rxdelay1 %d\r\n",DEMO_RX_DELAY_1);
    send_RN2903 (tx_buf);
    if (receive_RN2903(RF_OK))while(1);

#if DEMO_APP_ACTIVATION_TYPE ==    ACTIVATION_BY_PERSONALIZATION
    uint8_t devaddr[4] = DEMO_DEVICE_ADDRESS;
    uint8_t appskey[16] = DEMO_APPLICATION_SESSION_KEY;
    uint8_t nwkskey[16] =  DEMO_NETWORK_SESSION_KEY;     
    
    sprintf (tx_buf,"mac set devaddr %02x%02x%02x%02x\r\n",devaddr[0],devaddr[1],devaddr[2],devaddr[3]);
    send_RN2903 (tx_buf);
    if (receive_RN2903(RF_OK))while(1);
    sprintf (tx_buf,"mac set appskey %02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x\r\n",appskey[0],appskey[1],appskey[2],appskey[3],appskey[4],appskey[5],appskey[6],appskey[7],appskey[8],appskey[9],appskey[10],appskey[11],appskey[12],appskey[13],appskey[14],appskey[15]);
    send_RN2903 (tx_buf);
    if (receive_RN2903(RF_OK))while(1);
    sprintf (tx_buf,"mac set nwkskey %02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x\r\n",nwkskey[0],nwkskey[1],nwkskey[2],nwkskey[3],nwkskey[4],nwkskey[5],nwkskey[6],nwkskey[7],nwkskey[8],nwkskey[9],nwkskey[10],nwkskey[11],nwkskey[12],nwkskey[13],nwkskey[14],nwkskey[15]);
    send_RN2903 (tx_buf);
    if (receive_RN2903(RF_OK))while(1);    
    
#elif DEMO_APP_ACTIVATION_TYPE ==  OVER_THE_AIR_ACTIVATION
    uint8_t deveui[8] = DEMO_DEVICE_EUI;
    uint8_t appeui[8] =  DEMO_JOIN_EUI;
    uint8_t appkey[16] = DEMO_APPLICATION_KEY;
    sprintf (tx_buf,"mac set deveui %02x%02x%02x%02x%02x%02x%02x%02x\r\n",deveui[0],deveui[1],deveui[2],deveui[3],deveui[4],deveui[5],deveui[6],deveui[7]);
    send_RN2903 (tx_buf);
    if (receive_RN2903(RF_OK))while(1);    
       sprintf (tx_buf,"mac set appeui %02x%02x%02x%02x%02x%02x%02x%02x\r\n",appeui[0],appeui[1],appeui[2],appeui[3],appeui[4],appeui[5],appeui[6],appeui[7]);
    send_RN2903 (tx_buf);
    if (receive_RN2903(RF_OK))while(1);    
    sprintf (tx_buf,"mac set appkey %02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x\r\n",appkey[0],appkey[1],appkey[2],appkey[3],appkey[4],appkey[5],appkey[6],appkey[7],appkey[8],appkey[9],appkey[10],appkey[11],appkey[12],appkey[13],appkey[14],appkey[15]);
    send_RN2903 (tx_buf);
    if (receive_RN2903(RF_OK))while(1);
#else
#error Activation Type não configurado
#endif
    
    send_RN2903 ("mac set dr 2\r\n");
    if (receive_RN2903(RF_OK))while(1);
    send_RN2903 ("mac save\r\n");
    if (receive_RN2903(RF_OK))while(1);
    DELAY_milliseconds(1000);
    send_RN2903 ("sys get vdd\r\n"); 
    receive_RN2903(RF_OK);
    DELAY_milliseconds(1000);
#if DEMO_APP_ACTIVATION_TYPE ==    ACTIVATION_BY_PERSONALIZATION    
    send_RN2903 ("mac join abp\r\n"); 
    if (receive_RN2903(RF_OK))while(1);
#elif DEMO_APP_ACTIVATION_TYPE ==  OVER_THE_AIR_ACTIVATION    
    send_RN2903 ("mac join otaa\r\n"); 
    if (receive_RN2903(RF_OK))while(1);
#else
#error Activation Type não configurado
#endif    
    DELAY_milliseconds(10000);
}

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    DELAY_milliseconds(2000);
    config_RN2903();

    while (1)
    {
        send_RN2903 ("mac get dr\r\n");
        receive_RN2903(RF_OK);
        DELAY_milliseconds(200);
        send_RN2903 ("radio get freq\r\n");
        receive_RN2903(RF_OK);
        DELAY_milliseconds(200);
        send_RN2903 ("mac set dr 2\r\n");
        receive_RN2903(RF_OK);
        DELAY_milliseconds(1000);
//        send_RN2903 ("mac set ch status 0 on\r\n");
//        receive_RN2903(RF_OK);
        
//        for (uint8_t count = 1; count <=7;count++)
//        {
//          sprintf (tx_buf,"mac set ch status %d off\r\n",count);
//          send_RN2903 (tx_buf);
//          receive_RN2903(RF_OK);
//          DELAY_milliseconds(50);
//        }

        send_RN2903 ("mac tx uncnf 1 33353536\r\n"); 
        if (receive_RN2903(RF_OK))while(1);
        DELAY_milliseconds(10000);
        // Add your application code
    }
}
/**
 End of File
*/