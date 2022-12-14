// Copyright (c) 2017-2018 Telos Foundation & contributors
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "xchain_upgrade/xchain_data_processor_v2.h"

#include "nlohmann/json.hpp"
#if defined(XBUILD_CI) || defined(XBUILD_DEV)
#include "xchain_upgrade/xchain_data_default_v2.h"
#elif defined(XBUILD_GALILEO)
#include "xchain_upgrade/xchain_data_galileo_v2.h"
#else
#include "xchain_upgrade/xchain_data_new_horizons_v2.h"
#endif
#include "xdata/xproperty.h"
#include "xvledger/xvledger.h"

using json = nlohmann::json;

// cannot modify if set
#define DATA_PROCESS_K "preprocess_accounts_data_v2"
#define DATA_PROCESS_V "true"

namespace top {
namespace chain_data {

auto unit_states_json = json::parse(unit_states_json_str);

bool xtop_chain_data_processor_v2::check_state() {
    if (DATA_PROCESS_V != base::xvchain_t::instance().get_xdbstore()->get_value(DATA_PROCESS_K)) {
        return false;
    }
    xdbg("[xtop_chain_data_processor_v2::check_state] reset already");
    return true;
}

bool xtop_chain_data_processor_v2::set_state() {
    if (!base::xvchain_t::instance().get_xdbstore()->set_value(DATA_PROCESS_K, DATA_PROCESS_V)) {
        xwarn("[xtop_chain_data_processor_v2::set_state] write db failed");
        return false;
    }
    return true;
}

std::string xtop_chain_data_processor_v2::get_unit_state_str(common::xaccount_address_t const & account) {
    auto it = unit_states_json.find(account.to_string());
    if (it == unit_states_json.end()) {
        return {};
    }
    return base::xstring_utl::base64_decode(it->get<std::string>());
}

std::vector<std::string> xtop_chain_data_processor_v2::get_unit_states_str() {
    std::vector<std::string> strs;
    strs.reserve(unit_states_json.size());
    for (auto it = unit_states_json.begin(); it != unit_states_json.end(); ++it) {
        strs.emplace_back(base::xstring_utl::base64_decode(it->get<std::string>()));
    }
    return strs;
}

}  // namespace chain_data
}  // namespace top
