/** @file

Copyright (c) 2017, Intel Corporation. All rights reserved.<BR>
This program and the accompanying materials are licensed and made available under
the terms and conditions of the BSD License that accompanies this distribution.
The full text of the license may be found at
http://opensource.org/licenses/bsd-license.php.

THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef _SILICON_POLICY_INIT_LIB_H_
#define _SILICON_POLICY_INIT_LIB_H_

/**
  Performs silicon pre-mem policy initialization.

  The meaning of Policy is defined by silicon code.
  It could be the raw data, a handle, a PPI, etc.

  The returned data must be used as input data for SiliconPolicyDonePreMem(),
  and SiliconPolicyUpdateLib.SiliconPolicyUpdatePreMem().

  1) In FSP path, the input Policy should be FspmUpd.
  Value of FspmUpd has been initialized by FSP binary default value.
  Only a subset of FspmUpd needs to be updated for different silicon sku.
  The return data is same FspmUpd.

  2) In non-FSP path, the input policy could be NULL.
  The return data is the initialized policy.

  @param[in, out] Policy       Pointer to policy.

  @return the initialized policy.
**/
VOID *
EFIAPI
SiliconPolicyInitPreMem (
  IN OUT VOID *Policy OPTIONAL
  );

/*
  The silicon pre-mem policy is finalized.
  Silicon code can do initialization based upon the policy data.

  The input Policy must be returned by SiliconPolicyInitPreMem().
  
  @param[in] Policy       Pointer to policy.

  @retval EFI_SUCCESS The policy is handled consumed by silicon code.
*/
EFI_STATUS
EFIAPI
SiliconPolicyDonePreMem (
  IN VOID *Policy
  );

/**
  Performs silicon post-mem policy initialization.

  The meaning of Policy is defined by silicon code.
  It could be the raw data, a handle, a PPI, etc.

  The returned data must be used as input data for SiliconPolicyDonePostMem(),
  and SiliconPolicyUpdateLib.SiliconPolicyUpdatePostMem().

  1) In FSP path, the input Policy should be FspsUpd.
  Value of FspsUpd has been initialized by FSP binary default value.
  Only a subset of FspsUpd needs to be updated for different silicon sku.
  The return data is same FspsUpd.

  2) In non-FSP path, the input policy could be NULL.
  The return data is the initialized policy.

  @param[in, out] Policy       Pointer to policy.

  @return the initialized policy.
**/
VOID *
EFIAPI
SiliconPolicyInitPostMem (
  IN OUT VOID *Policy OPTIONAL
  );

/*
  The silicon post-mem policy is finalized.
  Silicon code can do initialization based upon the policy data.

  The input Policy must be returned by SiliconPolicyInitPostMem().
  
  @param[in] Policy       Pointer to policy.

  @retval EFI_SUCCESS The policy is handled consumed by silicon code.
*/
EFI_STATUS
EFIAPI
SiliconPolicyDonePostMem (
  IN VOID *Policy
  );

/**
  Performs silicon late policy initialization.

  The meaning of Policy is defined by silicon code.
  It could be the raw data, a handle, a protocol, etc.

  The returned data must be used as input data for SiliconPolicyDoneLate(),
  and SiliconPolicyUpdateLib.SiliconPolicyUpdateLate().

  In FSP or non-FSP path, the input policy could be NULL.
  The return data is the initialized policy.

  @param[in, out] Policy       Pointer to policy.

  @return the initialized policy.
**/
VOID *
EFIAPI
SiliconPolicyInitLate (
  IN OUT VOID *Policy OPTIONAL
  );

/*
  The silicon late policy is finalized.
  Silicon code can do initialization based upon the policy data.

  The input Policy must be returned by SiliconPolicyInitLate().
  
  @param[in] Policy       Pointer to policy.

  @retval EFI_SUCCESS The policy is handled consumed by silicon code.
*/
EFI_STATUS
EFIAPI
SiliconPolicyDoneLate (
  IN VOID *Policy
  );

#endif
