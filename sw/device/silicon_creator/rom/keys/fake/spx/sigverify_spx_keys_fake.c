// Copyright lowRISC contributors.
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0

#include "sw/device/lib/base/macros.h"
#include "sw/device/silicon_creator/rom/keys/fake/spx/dev_key_0_spx.h"
#include "sw/device/silicon_creator/rom/keys/fake/spx/prod_key_0_spx.h"
#include "sw/device/silicon_creator/rom/keys/fake/spx/test_key_0_spx.h"
#include "sw/device/silicon_creator/rom/sigverify_keys_spx.h"

#include "otp_ctrl_regs.h"

/**
 * Number of SPX public keys.
 */
enum {
  kSigverifySpxKeysCnt_ = 3,
};
const size_t kSigverifySpxKeysCnt = kSigverifySpxKeysCnt_;

/**
 * Step size to use when checking SPX public keys.
 *
 * This must be coprime with and less than `kSigverifyNumSpxKeys`.
 * Note: Step size is not applicable when `kSigverifyNumSpxKeys` is 1.
 */
const size_t kSigverifySpxKeysStep = 1;

/**
 * Fake public keys for signature verification in tests.
 *
 * Please see sw/device/silicon_creator/rom/keys/README.md for more
 * details.
 */
const sigverify_rom_spx_key_t kSigverifySpxKeys[kSigverifySpxKeysCnt_] = {
    {
        .key = TEST_KEY_0_SPX,
        .key_type = kSigverifyKeyTypeTest,
    },
    {
        .key = DEV_KEY_0_SPX,
        .key_type = kSigverifyKeyTypeDev,
    },
    {
        .key = PROD_KEY_0_SPX,
        .key_type = kSigverifyKeyTypeProd,
    },
};

static_assert(OTP_CTRL_PARAM_CREATOR_SW_CFG_SIGVERIFY_SPX_KEY_EN_SIZE >=
                  kSigverifySpxKeysCnt_,
              "CREATOR_SW_CFG_SIGVERIFY_SPX_KEY_EN OTP item must be at least "
              "`kSigVerifyNumKeysFake` bytes.");
