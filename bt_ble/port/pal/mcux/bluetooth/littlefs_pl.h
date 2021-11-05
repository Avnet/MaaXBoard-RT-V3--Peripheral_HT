/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __EDGEFAST_LITTLEFS_PL_H__
#define __EDGEFAST_LITTLEFS_PL_H__

#include "lfs.h"

#ifdef __cplusplus
extern "C" {
#endif

struct lfs_mflash_ctx
{
    uint32_t start_addr;
};
#define LITTLEFS_START_ADDR 0xdc0000

lfs_t * lfs_pl_init(void);

#ifdef __cplusplus
}
#endif

#endif /* __EDGEFAST_LITTLEFS_PL_H__ */
