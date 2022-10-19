// License       : License.txt
// Specifications: Spec-00000058.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : MCP9701_00000058.cpp
// BSL              : 00000058
// Model number     : Microchip Technology MCP9701, MCP9701A
// Spec               Component type       : ADC
//                    OS                   : Mbed
//                    Calculation          : Floating-point
//                    Conversion type      : Linear
//                    Moving average filter: Moving average filter select
//                    Diagnosis            : Range (Min to Max)
// Reason for change: 01.00.00 : 13/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include "MCP9701.h"

AnalogIn MCP9701_adc( iMCP9701_pin , iVref );           // AnalogIn object

// Main Function
pp2ap_adc_t MCP9701_00000058( void )
{
        pp2ap_adc_t res = pp_00000058( MCP9701_adc , tbl_MCP9701 );
        return( res );
}
