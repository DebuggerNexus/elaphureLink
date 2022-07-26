﻿#include "pch.h"

#include <cassert>
#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "ElaphureLinkRDDIContext.h"

#define EL_FORCE_DEBUGBREAK 0


#if (EL_FORCE_DEBUGBREAK == 1)
#define EL_DEBUG_BREAK() __debugbreak()
#else
#define EL_DEBUG_BREAK()
#endif


RDDI_EXPORT int RDDI_Open(RDDIHandle *pHandle, const void *pDetails)
{
    EL_DEBUG_BREAK();


    if (kContext.get_rddi_handle() != -1) {
        // already open
        return RDDI_TOOMANYCONNECTIONS;
    }

    if (!k_shared_memory_ptr->info_page.is_proxy_ready) {
        // proxy not ready
        return RDDI_FAILED;
    }

    if (pHandle == nullptr) {
        return RDDI_BADARG;
    }

    if (*pHandle == kContext.get_rddi_handle()) {
        // already open
        return RDDI_TOOMANYCONNECTIONS;
    }

    *pHandle = 1;
    kContext.set_rddi_handle(1);

    // TODO: context status clean up

    return RDDI_SUCCESS;
}

RDDI_EXPORT int RDDI_Close(RDDIHandle handle)
{
    EL_DEBUG_BREAK();

    if (handle != kContext.get_rddi_handle()) {
        return RDDI_INVHANDLE;
    }

    kContext.set_rddi_handle(-1); // set invalid handle

    // TODO: context status clean up

    return RDDI_SUCCESS;
}

RDDI_EXPORT int RDDI_GetLastError(int *pError, char *pDetails, size_t detailsLen)
{
    //EL_TODO_IMPORTANT
    __debugbreak();
    return 8204;
}


RDDI_EXPORT void RDDI_SetLogCallback(RDDIHandle handle, RDDILogCallback pfn, void *context, int maxLogLevel)
{
    //EL_TODO_IMPORTANT
    __debugbreak();
}

RDDI_EXPORT int DAP_GetInterfaceVersion(const RDDIHandle handle, int *version)
{
    //EL_TODO_IMPORTANT
    __debugbreak();
    return 8204;
}

RDDI_EXPORT int DAP_Configure(const RDDIHandle handle, const char *configFileName)
{
    //EL_TODO_IMPORTANT
    EL_DEBUG_BREAK();

    if (handle != kContext.get_rddi_handle()) {
        return RDDI_INVHANDLE;
    }
    assert(configFileName == nullptr);
    return RDDI_SUCCESS;
}

RDDI_EXPORT int DAP_Connect(const RDDIHandle handle, RDDI_DAP_CONN_DETAILS *pConnDetails)
{
    //EL_TODO_IMPORTANT
    EL_DEBUG_BREAK();

    if (handle != kContext.get_rddi_handle()) {
        return RDDI_INVHANDLE;
    }

    return RDDI_SUCCESS;
}

RDDI_EXPORT int DAP_Disconnect(const RDDIHandle handle)
{
    //EL_TODO_IMPORTANT
    __debugbreak();
    return 8204;
}


RDDI_EXPORT int DAP_GetSupportedOptimisationLevel(const RDDIHandle handle, int *level)
{
    //EL_TODO_IMPORTANT
    __debugbreak();
    return 8204;
}


RDDI_EXPORT int DAP_GetNumberOfDAPs(const RDDIHandle handle, int *noOfDAPs)
{
    //EL_TODO_IMPORTANT
    __debugbreak();
    return 8204;
}

RDDI_EXPORT int DAP_GetDAPIDList(const RDDIHandle handle, int *DAP_ID_Array, size_t sizeOfArray)
{
    //EL_TODO_IMPORTANT
    __debugbreak();
    return 8204;
}


RDDI_EXPORT int DAP_ReadReg(const RDDIHandle handle, const int DAP_ID, const int regID, int *value)
{
    //EL_TODO_IMPORTANT
    __debugbreak();
    return 8204;
}


RDDI_EXPORT int DAP_WriteReg(const RDDIHandle handle, const int DAP_ID, const int regID, const int value)
{
    //EL_TODO_IMPORTANT
    __debugbreak();
    return 8204;
}


RDDI_EXPORT int DAP_RegAccessBlock(const RDDIHandle handle, const int DAP_ID, const int numRegs,
                                   const int *regIDArray, int *dataArray)
{
    //EL_TODO_IMPORTANT
    __debugbreak();
    return 8204;
}


RDDI_EXPORT int DAP_RegWriteBlock(const RDDIHandle handle, const int DAP_ID, const int numRegs,
                                  const int *regIDArray, const int *dataArray)
{
    //EL_TODO_IMPORTANT
    __debugbreak();
    return 8204;
}

RDDI_EXPORT int DAP_RegReadBlock(const RDDIHandle handle, const int DAP_ID, const int numRegs,
                                 const int *regIDArray, int *dataArray)
{
    //EL_TODO_IMPORTANT
    __debugbreak();
    return 8204;
}

RDDI_EXPORT int DAP_RegWriteRepeat(const RDDIHandle handle, const int DAP_ID, const int numRepeats,
                                   const int regID, const int *dataArray)
{
    //EL_TODO_IMPORTANT
    __debugbreak();
    return 8204;
}


RDDI_EXPORT int DAP_RegReadRepeat(const RDDIHandle handle, const int DAP_ID, const int numRepeats,
                                  const int regID, int *dataArray)
{
    //EL_TODO_IMPORTANT
    __debugbreak();
    return 8204;
}


RDDI_EXPORT int DAP_RegReadWaitForValue(const RDDIHandle handle, const int DAP_ID, const int numRepeats,
                                        const int regID, const int *mask, const int *requiredValue)
{
    //EL_TODO_IMPORTANT
    __debugbreak();
    return 8204;
}

RDDI_EXPORT int DAP_Target(const RDDIHandle handle, const char *request_str, char *resp_str,
                           const int resp_len)
{
    //EL_TODO_IMPORTANT
    __debugbreak();
    return 8204;
}

RDDI_EXPORT int DAP_DefineSequence(const RDDIHandle handle, const int seqID, void *seqDef)
{
    //EL_TODO_IMPORTANT
    __debugbreak();
    return 8204;
}


RDDI_EXPORT int DAP_RunSequence(const RDDIHandle handle, const int seqID, void *seqInData, void *seqOutData)
{
    //EL_TODO_IMPORTANT
    __debugbreak();
    return 8204;
}


// This function will check the num of hardware debugger that connected to the PC.
RDDI_EXPORT int CMSIS_DAP_Detect(const RDDIHandle handle, int *noOfIFs)
{
    EL_DEBUG_BREAK();

    if (handle != kContext.get_rddi_handle()) {
        return RDDI_INVHANDLE;
    }

    // we have only one dap instance.
    *noOfIFs = 1;
    return RDDI_SUCCESS;
}

RDDI_EXPORT int CMSIS_DAP_Identify(const RDDIHandle handle, int ifNo, int idNo, char *str, const int len)
{
    EL_DEBUG_BREAK();

    if (handle != kContext.get_rddi_handle()) {
        return RDDI_INVHANDLE;
    }

    assert(idNo == 2 || idNo == 3 || idNo == 4);
    assert(len > 0);
    int src_len;

    switch (idNo) {
        case 2:
            // port identify string, must include substring "CMSIS-DAP"
            src_len = strlen(k_shared_memory_ptr->info_page.product_name);
            strncpy_s(str, len, k_shared_memory_ptr->info_page.product_name, len - 1);
            break;
        case 3:
            // Serial No string
            src_len = strlen(k_shared_memory_ptr->info_page.serial_number);
            strncpy_s(str, len, k_shared_memory_ptr->info_page.serial_number, len - 1);
            break;
        case 4:
            // Firmware string
            src_len = strlen(k_shared_memory_ptr->info_page.firmware_version);
            strncpy_s(str, len, k_shared_memory_ptr->info_page.firmware_version, len - 1);
            break;
        default:
            break;
    }

    return RDDI_SUCCESS;
}


RDDI_EXPORT int CMSIS_DAP_ConfigureInterface(const RDDIHandle handle, int ifNo, char *str)
{
    // parse configure string like:
    // "Master=Y;Port=SW;SWJ=Y;Clock=10000000;Trace=Off;TraceBaudrate=0;TraceTransport=None;"

    EL_DEBUG_BREAK();

    if (handle != kContext.get_rddi_handle()) {
        return RDDI_INVHANDLE;
    }

    const char *p = str;

    std::vector<std::pair<std::string, std::string>> command_list;

    int status  = 0;
    int key_len = 0, value_len = 0;
    while (*p != '\0') {
        switch (status) {
            case 0: // parse key
                if (*p == '=') {
                    status = 1;
                } else {
                    key_len++;
                }
                break;
            case 1: // parse value
                if (*p == ';') {
                    // "key=value;"
                    //  |   |_ p - value_len
                    //  |_____ p - key_len - value_len - 1
                    std::string value_str = std::string(p - value_len, value_len);
                    std::string key_str   = std::string(p - key_len - value_len - 1, key_len);
                    command_list.emplace_back(key_str, value_str);

                    // clean up
                    key_len   = 0;
                    value_len = 0;
                    status    = 0;
                } else {
                    value_len++;
                }
                break;
            default:
                break;
        }

        p++;
    }

    kContext.set_debug_configure_from_list(command_list);

    return RDDI_SUCCESS;
}


RDDI_EXPORT int CMSIS_DAP_ConfigureDAP(const RDDIHandle handle, const char *str)
{
    EL_DEBUG_BREAK();

    if (handle != kContext.get_rddi_handle()) {
        return RDDI_INVHANDLE;
    }

    const char *p = str;
    std::string value_str, key_str;

    int status  = 0;
    int key_len = 0, value_len = 0;
    while (true) {
        switch (status) {
            case 0: // parse key
                if (*p == '=') {
                    status = 1;
                } else {
                    key_len++;
                }
                break;
            case 1: // parse value
                if (*p == '\0') {
                    // "key=value\0"
                    //  |   |_ p - value_len
                    //  |_____ p - key_len - value_len - 1
                    value_str = std::string(p - value_len, value_len);
                    key_str   = std::string(p - key_len - value_len - 1, key_len);
                } else {
                    value_len++;
                }
                break;
            default:
                break;
        }
        if (*p == '\0') {
            break;
        }
        p++;
    }

    kContext.set_debug_configure(key_str, value_str);

    return RDDI_SUCCESS;
}

RDDI_EXPORT int CMSIS_DAP_GetGUID(const RDDIHandle handle, int ifNo, char *str, const int len)
{
    //EL_TODO_IMPORTANT
    EL_DEBUG_BREAK();

    if (handle != kContext.get_rddi_handle()) {
        return RDDI_INVHANDLE;
    }

    assert(ifNo == 0);

    sprintf_s(str, len, "elaphureLink"); // TODO: this field
    return RDDI_SUCCESS;
}

RDDI_EXPORT int CMSIS_DAP_Capabilities(const RDDIHandle handle, int ifNo, int *cap_info)
{
    //EL_TODO TODO: check device caps
    EL_DEBUG_BREAK();

    if (handle != kContext.get_rddi_handle()) {
        return RDDI_INVHANDLE;
    }

    assert(ifNo == 0);

    *cap_info = INFO_CAPS_SWD; // TODO: other caps

    return RDDI_SUCCESS;
}


RDDI_EXPORT int CMSIS_DAP_DetectNumberOfDAPs(const RDDIHandle handle, int *noOfDAPs)
{
    //EL_TODO_IMPORTANT
    EL_DEBUG_BREAK();

    // TODO: check device? // send configuration, and get the list of DAP

    if (handle != kContext.get_rddi_handle()) {
        return RDDI_INVHANDLE;
    }

    *noOfDAPs = 1; // for SWD device

    // FIXME: for multi-drop system

    return RDDI_SUCCESS;
}

RDDI_EXPORT int CMSIS_DAP_DetectDAPIDList(const RDDIHandle handle, int *DAP_ID_Array, size_t sizeOfArray)
{
    //EL_TODO_IMPORTANT
    __debugbreak();

    if (handle != kContext.get_rddi_handle()) {
        return RDDI_INVHANDLE;
    }

    DAP_ID_Array[0] = 0x1ba01477; // EL_TODO_IMPORTANT: test only


    return RDDI_SUCCESS;
}


RDDI_EXPORT int CMSIS_DAP_Commands(const RDDIHandle handle, int num, unsigned char **request, int *req_len,
                                   unsigned char **response, int *resp_len)
{
    //EL_TODO_IMPORTANT
    __debugbreak();
    return 8204;
}



//////////////
///
///
///
///
///
///
///
///
///
///
///
#if 0
RDDI_EXPORT int CMSIS_DAP_GetNumberOfDevices()
{
    __debugbreak();
    return 8204;
}
#endif

#if 0
RDDI_EXPORT int CMSIS_DAP_Connect()
{
    __debugbreak();
    return 8204;
}
#endif
#if 0
RDDI_EXPORT int CMSIS_DAP_GetDeviceIDList()
{
    __debugbreak();
    return 8204;
}
#endif

#if 0
RDDI_EXPORT int CMSIS_DAP_DetectNumberOfDevices()
{
    __debugbreak();
    return 8204;
}
#endif

///
///
///
///
///
///
RDDI_EXPORT int CMSIS_DAP_Disconnect()
{
    __debugbreak();
    return 8204;
}

RDDI_EXPORT int DAP_SetCommTimeout()
{
    __debugbreak();
    return 8204;
}
RDDI_EXPORT int CMSIS_DAP_GetInterfaceVersion()
{
    __debugbreak();
    return 8204;
}



RDDI_EXPORT int CMSIS_DAP_ResetDAP()
{
    __debugbreak();
    return 8204;
}


RDDI_EXPORT int CMSIS_DAP_SWJ_Sequence()
{
    __debugbreak();
    return 8204;
}
RDDI_EXPORT int CMSIS_DAP_JTAG_Sequence()
{
    __debugbreak();
    return 8204;
}
RDDI_EXPORT int CMSIS_DAP_Atomic_Result()
{
    __debugbreak();
    return 8204;
}
RDDI_EXPORT int CMSIS_DAP_Atomic_Control()
{
    __debugbreak();
    return 8204;
}
RDDI_EXPORT int CMSIS_DAP_WriteABORT()
{
    __debugbreak();
    return 8204;
}


RDDI_EXPORT int CMSIS_DAP_JTAG_GetIDCODEs()
{
    __debugbreak();
    return 8204;
}
RDDI_EXPORT int CMSIS_DAP_JTAG_GetIRLengths()
{
    __debugbreak();
    return 8204;
}
RDDI_EXPORT int CMSIS_DAP_Delay()
{
    __debugbreak();
    return 8204;
}

RDDI_EXPORT int CMSIS_DAP_SWJ_Pins()
{
    __debugbreak();
    return 8204;
}
RDDI_EXPORT int CMSIS_DAP_SWJ_Clock()
{
    __debugbreak();
    return 8204;
}
RDDI_EXPORT int CMSIS_DAP_ConfigureDebugger()
{
    __debugbreak();
    return 8204;
}