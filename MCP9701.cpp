// License       : License.txt
// Specifications: Spec-MCP9701_MCP9701A.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : MCP9701.cpp
// Reason for change: 01.00.00 : 13/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include        "MCP9701.h"

#if     iMCP9701_ma == iSMA                             // Simple moving average filter
static float32 MCP9701_sma_buf[iMCP9701_SMA_num];
static sma_f32_t MCP9701_Phy_SMA =
{
        iInitial ,                                      // Initial state
        iMCP9701_SMA_num ,                              // Simple moving average number & buf size
        0U ,                                            // buffer position
        0.0F ,                                          // sum
        &MCP9701_sma_buf[0]                             // buffer
};

#elif   iMCP9701_ma == iEMA                             // Exponential moving average filter
static ema_f32_t MCP9701_Phy_EMA =
{
        iInitial ,                                      // Initial state
        0.0F ,                                          // Xn-1
        iMCP9701_EMA_K                                  // Exponential smoothing factor
};

#elif   iMCP9701_ma == iWMA                             // Weighted moving average filter
static float32 MCP9701_wma_buf[iMCP9701_WMA_num];
static wma_f32_t MCP9701_Phy_WMA =
{
        iInitial ,                                      // Initial state
        iMCP9701_WMA_num ,                              // Weighted moving average number & buf size
        0U ,                                            // buffer poition
        iMCP9701_WMA_num * (iMCP9701_WMA_num + 1)/2 ,   // kn sum
        &MCP9701_wma_buf[0]                             // Xn buffer
};

#else                                                   // Non-moving average filter
#endif

#define iDummy_adr       0xffffffff                     // Dummy address

const tbl_adc_t tbl_MCP9701 =
{
        iMCP9701                ,
        iMCP9701_pin            ,
        iMCP9701_xoff           ,
        iMCP9701_yoff           ,
        iMCP9701_gain           ,
        iMCP9701_max            ,
        iMCP9701_min            ,
        iMCP9701_ma             ,
        
#if     iMCP9701_ma == iSMA                             // Simple moving average filter
        &MCP9701_Phy_SMA        ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#elif   iMCP9701_ma == iEMA                             // Exponential moving average filter
        (sma_f32_t*)iDummy_adr  ,
        &MCP9701_Phy_EMA        ,
        (wma_f32_t*)iDummy_adr
#elif   iMCP9701_ma == iWMA                             // Weighted moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        &MCP9701_Phy_WMA
#else                                                   // Non-moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#endif

};
