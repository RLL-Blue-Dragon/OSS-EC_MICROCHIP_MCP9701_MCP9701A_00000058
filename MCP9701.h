// License       : License.txt
// Specifications: Spec-MCP9701_MCP9701A.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : MCP9701.h
// Reason for change: 01.00.00 : 13/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#ifndef __MCP9701_H__
#define __MCP9701_H__

#include "user_define.h"

// Components number
#define iMCP9701                115U                    // Microchip Technology MCP9701, MCP9701A

// MCP9700 System Parts definitions
#define iMCP9701_xoff           0.4F                    // X offset [V]
#define iMCP9701_yoff           0.0F                    // Y offset [degree celsius]
#define iMCP9701_gain           0.0195F                 // Gain [V/degree celsius]
#define iMCP9701_max            125.0F                  // Temperature Max [degree celsius]
#define iMCP9701_min            -10.0F                  // Temperature Min [degree celsius]

extern const tbl_adc_t tbl_MCP9701;

#endif /*__MCP9701_H__*/
