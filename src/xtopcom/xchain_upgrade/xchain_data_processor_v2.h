// Copyright (c) 2017-2018 Telos Foundation & contributors
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include "xcommon/xlegacy_account_address.h"
#include "xvledger/xvstate.h"

namespace top {
namespace chain_data {

class xtop_chain_data_processor_v2 {
public:
    static bool check_state();
    static bool set_state();

    static std::vector<std::string> get_unit_states_str();
    static std::string get_unit_state_str(common::xaccount_address_t const & account);
};
using xchain_data_processor_v2_t = xtop_chain_data_processor_v2;
}  // namespace chain_data
}  // namespace top
