/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

/* Activation method constants */
#define OVER_THE_AIR_ACTIVATION           1
#define ACTIVATION_BY_PERSONALIZATION     0

/* Message Type constants */
#define UNCONFIRMED                       LORAWAN_UNCNF
#define CONFIRMED                         LORAWAN_CNF

/* Enable one of the activation methods */
//#define DEMO_APP_ACTIVATION_TYPE               OVER_THE_AIR_ACTIVATION
#define DEMO_APP_ACTIVATION_TYPE               ACTIVATION_BY_PERSONALIZATION

/* Select the Type of Transmission - Confirmed(CNF) / Unconfirmed(UNCNF) */
#define DEMO_APP_TRANSMISSION_TYPE              UNCONFIRMED
//#define DEMO_APP_TRANSMISSION_TYPE            CONFIRMED

/* FPORT Value (1-255) */
#define DEMO_APP_FPORT                           1

/* Device Class - Class of the device (CLASS_A/CLASS_C) */
#define DEMO_APP_ENDDEVICE_CLASS                 CLASS_A
//#define DEMO_APP_ENDDEVICE_CLASS                 CLASS_C

/* Device RX Delay 1*/
#define DEMO_RX_DELAY_1                         5000    //TTI 1S ATC 5S



/* ABP Join Parameters */
#define DEMO_DEVICE_ADDRESS                     {0x27, 0x00, 0x00, 0x46}//{0x27, 0x00, 0x00, 0xee}//
#define DEMO_APPLICATION_SESSION_KEY            {0xef, 0xfe, 0x1d, 0xad, 0x76, 0xa5, 0x81, 0x26, 0xa0, 0x59, 0xf5, 0x9c, 0xa4, 0xfc, 0x74, 0x9a}
#define DEMO_NETWORK_SESSION_KEY                {0xfc, 0xe1, 0x1e, 0xaa, 0x49, 0x0f, 0xfb, 0xf5, 0x19, 0xd4, 0xe2, 0xe5, 0x8f, 0x81, 0xdd, 0x85}


/* OTAA Join Parameters */
//ATC
//#define DEMO_DEVICE_EUI                         {0x4e, 0x82, 0x92, 0x63, 0xfe, 0x36, 0xa7, 0x17}  //ATC
//#define DEMO_JOIN_EUI                           {0x0f, 0xad, 0xe8, 0x60, 0xbc, 0xe7, 0x3e, 0x4e}

//TTI
#define DEMO_DEVICE_EUI                         {0xde, 0xaf, 0xfa, 0xce, 0xde, 0xaf, 0xfa, 0x55}    //TTI
#define DEMO_JOIN_EUI                           {0xc6, 0x39, 0x64, 0xbd, 0xcb, 0x18, 0x4e, 0xa7}//

#define DEMO_APPLICATION_KEY                    {0xD3, 0x74, 0xAD, 0x4D, 0xB6, 0x1F, 0xEE, 0x6D, 0x01, 0x46, 0x53, 0xB2, 0x6F, 0x92, 0x34, 0x65}

/* Multicast Parameters */
#define DEMO_APP_MCAST_GROUPID                  0
#define DEMO_APP_MCAST_ENABLE                   true
#define DEMO_APP_MCAST_GROUP_ADDRESS            0x0037CC56
#define DEMO_APP_MCAST_APP_SESSION_KEY          {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6}
#define DEMO_APP_MCAST_NWK_SESSION_KEY          {0x3C, 0x8F, 0x26, 0x27, 0x39, 0xBF, 0xE3, 0xB7, 0xBC, 0x08, 0x26, 0x99, 0x1A, 0xD0, 0x50, 0x4D}

/* This macro defines the application's default sleep duration in milliseconds */
#define DEMO_CONF_DEFAULT_APP_SLEEP_TIME_MS     1000

#endif	/* XC_HEADER_TEMPLATE_H */

