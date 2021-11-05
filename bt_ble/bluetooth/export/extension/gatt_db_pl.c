
/**
 *  \file gatt_db_pl.c
 *
 *  This file contains source code for the platform specific portions of
 *  GATT Database.
 */

/*
 *  Copyright (C) 2013. Mindtree Ltd.
 *  All rights reserved.
 */


/* --------------------------------------------- Header File Inclusion */
#include "BT_common.h"
#include "BT_device_queue.h"
#include "BT_hci_api.h"

#include "BT_smp_api.h"
#include "BT_att_api.h"
#include "BT_gatt_db_api.h"

#include "gatt_db_pl.h"

#ifdef GATT_DB

/* --------------------------------------------- External Global Variables */

/* --------------------------------------------- Exported Global Variables */

/* --------------------------------------------- Static Global Variables */
/* GATT DB PL Extenstion Handler Callback */
GATT_DB_PL_EXT_HANDLER_CB gatt_db_ext_handler_pl;

/* --------------------------------------------- Functions */

API_RESULT gatt_db_init_pl(GATT_DB_PL_EXT_HANDLER_CB hndlr_cb)
{
    API_RESULT retval;

    retval = API_SUCCESS;

    if (NULL != hndlr_cb)
    {
        gatt_db_ext_handler_pl = hndlr_cb;
    }
    else
    {
        retval = GATT_DB_NULL_PARAMETER_NOT_ALLOWED;
    }

    return retval;
}

API_RESULT gatt_char_handler
           (
               GATT_DB_HANDLE * handle,
               GATT_DB_PARAMS * param
           )
{
    /**
     * Invoke the registered Profile Specific GATT Char Handler.
     */
    if (NULL != gatt_db_ext_handler_pl)
    {
        return gatt_db_ext_handler_pl
               (
                   handle,
                   param
               );
    }
    else
    {
        return API_SUCCESS;
    }
}

#endif /* GATT_DB */

